#pragma once

#include <box2d/box2d.h>

class B2Math {
    public:
    static float dot(b2Vec2 a, b2Vec2 b) { return b2Dot(a, b); }
};
