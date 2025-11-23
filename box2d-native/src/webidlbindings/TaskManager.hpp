#pragma once

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

static void* EnqueueTask(b2TaskCallback* box2dTask, int itemCount, int minRange, void* box2dContext, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return (void*) taskManager->enqueueTask((uint64_t) box2dTask, itemCount, minRange, (uint64_t) box2dContext);
}

static void FinishTask(void* userTask, void* context) {
    TaskManager* taskManager = (TaskManager*) context;
    return taskManager->finishTask((uint64_t) userTask);
}
