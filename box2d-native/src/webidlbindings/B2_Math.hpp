#pragma once

#include <box2d/box2d.h>

class B2_Vec2 {
    public:
    static inline float dot(b2Vec2 a, b2Vec2 b) { return b2Dot(a, b); }
};

class B2_Rot {
    public:
    static inline float getAngle(b2Rot q) { return b2Rot_GetAngle(q); }
};
