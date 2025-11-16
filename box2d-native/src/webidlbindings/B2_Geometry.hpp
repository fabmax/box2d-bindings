#pragma once

#include <box2d/box2d.h>

class B2_Geometry {
    public:
    static const uint32_t MAX_POLYGON_VERTICES = B2_MAX_POLYGON_VERTICES;

    static inline void makeBox(float halfWidth, float halfHeight, b2Polygon& result) { result = b2MakeBox(halfWidth, halfHeight); }
};