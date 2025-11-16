#pragma once

#include <box2d/box2d.h>

class B2_World {
    public:
    static inline void defaultWorldDef(b2WorldDef& result) { result = b2DefaultWorldDef(); }
    static inline void createWorld(const b2WorldDef* def, b2WorldId& result) { result = b2CreateWorld(def); }
    static inline void destroyWorld(b2WorldId result) { b2DestroyWorld(result); }
    static inline void step(b2WorldId world, float timeStep, long subStepCount) { b2World_Step(world, timeStep, subStepCount); }
};
