#pragma once

#include <iostream>
#include <TaskScheduler_c.h>

#define MAX_TASKS 128
#define THREAD_LIMIT 32

static void* EnqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext, void* context);
static void FinishTask(void* userTask, void* context);

class TaskManager {
public:
	virtual ~TaskManager() = default;

	void install(b2WorldDef& worldDef, int threadCount) {
	    this->threadCount = threadCount;
		worldDef.enqueueTask = EnqueueTask;
		worldDef.finishTask = FinishTask;
		worldDef.workerCount = threadCount;
		worldDef.userTaskContext = this;
	}

    virtual void stepWorld(uint64_t worldId, float timeStep, int subStepCount) {
        b2World_Step(b2LoadWorldId(worldId), timeStep, subStepCount);
    }

    void executeTask(uint32_t start, uint32_t end, uint32_t threadIndex, uint64_t box2dTask, uint64_t box2dContext) {
        ((b2TaskCallback*) box2dTask)(start, end, threadIndex, (void*) box2dContext);
    }

    virtual uint64_t enqueueTask(uint64_t box2dTask, int itemCount, int minRange, uint64_t box2dContext) = 0;
    virtual void finishTask(uint64_t userTask) = 0;

    int threadCount;
};

typedef struct TaskData {
	b2TaskCallback* box2dTask;
	void* box2dContext;
} TaskData;

static void ExecuteRangeTask(uint32_t start, uint32_t end, uint32_t threadIndex, void* context);

class EnkiTaskManager : TaskManager {
public:
    EnkiTaskManager(b2WorldDef& worldDef, int threadCount) {
        scheduler = enkiNewTaskScheduler();
        struct enkiTaskSchedulerConfig config = enkiGetTaskSchedulerConfig(scheduler);
        config.numTaskThreadsToCreate = threadCount - 1;
        enkiInitTaskSchedulerWithConfig(scheduler, config);

        for (int taskIndex = 0; taskIndex < MAX_TASKS; taskIndex++) {
            tasks[taskIndex] = enkiCreateTaskSet(scheduler, ExecuteRangeTask);
        }
        install(worldDef, threadCount);
    }

    virtual ~EnkiTaskManager() {
        for (int taskIndex = 0; taskIndex < MAX_TASKS; taskIndex++) {
            enkiDeleteTaskSet(scheduler, tasks[taskIndex]);
        }
        enkiDeleteTaskScheduler(scheduler);
    }

    virtual void stepWorld(uint64_t worldId, float timeStep, int subStepCount) {
        TaskManager::stepWorld(worldId, timeStep, subStepCount);
        taskCount = 0;
    }

    virtual uint64_t enqueueTask(uint64_t box2dTask, int itemCount, int minRange, uint64_t box2dContext) {
        if (taskCount < MAX_TASKS) {
            enkiTaskSet* task = tasks[taskCount];
            TaskData* data = taskData + taskCount;
            data->box2dTask = (b2TaskCallback*) box2dTask;
            data->box2dContext = (void*) box2dContext;

            struct enkiParamsTaskSet params;
            params.minRange = minRange;
            params.setSize = itemCount;
            params.pArgs = data;
            params.priority = 0;

            enkiSetParamsTaskSet(task, params);
            enkiAddTaskSet(scheduler, task);

            ++taskCount;
            return (uint64_t) task;
        } else {
            std::cerr << "[Box2D] Too many tasks enqueued! You should use TaskManager.stepWorld() to run a multi-threaded simulation" << std::endl;
            ((b2TaskCallback*) box2dTask)(0, itemCount, 0, (void*) box2dContext);
            return 0L;
        }
    }

    virtual void finishTask(uint64_t userTask) {
        enkiTaskSet* task = (enkiTaskSet*) userTask;
        enkiWaitForTaskSet(scheduler, task);
    }

private:
    enkiTaskScheduler* scheduler;
    enkiTaskSet* tasks[MAX_TASKS];
    TaskData taskData[MAX_TASKS];
    int taskCount = 0;
};

static void ExecuteRangeTask(uint32_t start, uint32_t end, uint32_t threadIndex, void* context) {
	TaskData* data = (TaskData*) context;
	data->box2dTask(start, end, threadIndex, data->box2dContext);
}

static void* EnqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return (void*) taskManager->enqueueTask((uint64_t) box2dTask, itemCount, minRange, (uint64_t) box2dContext);
}

static void FinishTask(void* userTask, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return taskManager->finishTask((uint64_t) userTask);
}
