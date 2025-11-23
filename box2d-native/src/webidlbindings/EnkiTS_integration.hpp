#pragma once

#include <iostream>
#include <TaskScheduler_c.h>

#define MAX_TASKS 128
#define THREAD_LIMIT 32

typedef struct TaskData {
	b2TaskCallback* box2dTask;
	void* box2dContext;
} TaskData;

static void ExecuteRangeTask(uint32_t start, uint32_t end, uint32_t threadIndex, void* context);
static void* EnqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext, void* context);
static void FinishTask(void* userTask, void* context);

class TaskManager {
public:
    TaskManager(b2WorldDef& worldDef, int threadCount) : threadCount(threadCount) {
        scheduler = enkiNewTaskScheduler();
        struct enkiTaskSchedulerConfig config = enkiGetTaskSchedulerConfig(scheduler);
        config.numTaskThreadsToCreate = threadCount - 1;
        enkiInitTaskSchedulerWithConfig(scheduler, config);

        for (int taskIndex = 0; taskIndex < MAX_TASKS; taskIndex++) {
            tasks[taskIndex] = enkiCreateTaskSet(scheduler, ExecuteRangeTask);
        }

        worldDef.enqueueTask = EnqueueTask;
        worldDef.finishTask = FinishTask;
        worldDef.workerCount = threadCount;
        worldDef.userTaskContext = this;
    }

    ~TaskManager() {
        for (int taskIndex = 0; taskIndex < MAX_TASKS; taskIndex++) {
            enkiDeleteTaskSet(scheduler, tasks[taskIndex]);
        }
        enkiDeleteTaskScheduler(scheduler);
    }

    enkiTaskSet* enqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext) {
        std::cout << "Enqueue!" << std::endl;
        if (taskCount < MAX_TASKS) {
            enkiTaskSet* task = tasks[taskCount];
            TaskData* data = taskData + taskCount;
            data->box2dTask = box2dTask;
            data->box2dContext = box2dContext;

            struct enkiParamsTaskSet params;
            params.minRange = minRange;
            params.setSize = itemCount;
            params.pArgs = data;
            params.priority = 0;

            enkiSetParamsTaskSet(task, params);
            enkiAddTaskSet(scheduler, task);

            ++taskCount;
            return task;
        } else {
            std::cout << "Too many tasks enqueued!" << std::endl;
            box2dTask(0, itemCount, 0, box2dContext);
            return NULL;
        }
    }

    void finishTask(void* userTask) {
        enkiTaskSet* task = (enkiTaskSet*) userTask;
        enkiWaitForTaskSet(scheduler, task);
    }

private:
    enkiTaskScheduler* scheduler;
    enkiTaskSet* tasks[MAX_TASKS];
    TaskData taskData[MAX_TASKS];
    int threadCount;
    int taskCount = 0;
};

static void ExecuteRangeTask(uint32_t start, uint32_t end, uint32_t threadIndex, void* context) {
	TaskData* data = (TaskData*) context;
	data->box2dTask(start, end, threadIndex, data->box2dContext);
}

static void* EnqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return taskManager->enqueueTask(box2dTask, itemCount, minRange, box2dContext);
}

static void FinishTask(void* userTask, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return taskManager->finishTask(userTask);
}
