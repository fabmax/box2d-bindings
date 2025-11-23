package de.fabmax.box2djni;

import box2d.TaskManagerImpl;
import box2d.b2WorldDef;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class DefaultTaskManager extends TaskManagerImpl {
    private final List<Task> availableTasks = new ArrayList<>();
    private final HashMap<Long, Task> taskMap = new HashMap<>();
    private final ExecutorService executor;
    private final int threadCount;

    public DefaultTaskManager(b2WorldDef worldDef, int threadCount) {
        this.threadCount = threadCount;
        executor = Executors.newFixedThreadPool(threadCount, TaskThread::new);
        install(worldDef, threadCount);
    }

    @Override
    public long enqueueTask(long box2dTask, int itemCount, int minRange, long box2dContext) {
        var task = availableTasks.isEmpty()
                ? new Task()
                : availableTasks.remove(availableTasks.size() - 1);
        task.run(box2dTask, itemCount, minRange, box2dContext);
        taskMap.put(task.id, task);
        return task.id;
    }

    @Override
    public void finishTask(long userTask) {
        var task = taskMap.remove(userTask);
        task.join();
        availableTasks.add(task);
    }

    private class Task {
        private static long nextId = 1;
        final long id = nextId++;
        final List<TaskPart> availableParts = new ArrayList<>();
        final List<TaskPart> activeParts = new ArrayList<>();

        void run(long box2dTask, int itemCount, int minRange, long box2dContext) {
            if (itemCount == 0) {
                System.out.println("no items!");
                return;
            }
            var numParts = Math.max(1, Math.min(itemCount / minRange, threadCount * 3));
            var partSize = Math.max(itemCount / numParts, minRange);
            for (int i = 0; i < itemCount; i += partSize) {
                var end = Math.min(i + partSize, itemCount);
                TaskPart part = availableParts.isEmpty()
                        ? new TaskPart()
                        : availableParts.remove(availableParts.size() - 1);
                part.setup(i, end, box2dTask, box2dContext);
                part.future = executor.submit(part);
                activeParts.add(part);
            }
        }

        void join() {
            try {
                for (int i = 0; i < activeParts.size(); i++) {
                    var part = activeParts.get(i);
                    part.future.get();
                    availableParts.add(part);
                }
                activeParts.clear();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    private class TaskPart implements Runnable {
        int start = 0;
        int end = 0;
        long box2dTask = 0;
        long box2dContext = 0;
        Future<?> future;

        void setup(int start, int end, long box2dTask, long box2dContext) {
            this.start = start;
            this.end = end;
            this.box2dTask = box2dTask;
            this.box2dContext = box2dContext;
        }

        @Override
        public void run() {
            var threadIndex = ((TaskThread) Thread.currentThread()).threadIndex;
            executeTask(start, end, threadIndex, box2dTask, box2dContext);
        }
    }

    private static class TaskThread extends Thread {
        private static int nextThreadId = 0;
        final int threadIndex = nextThreadId++;

        TaskThread(Runnable r) {
            super(r);
            setDaemon(true);
        }
    }
}
