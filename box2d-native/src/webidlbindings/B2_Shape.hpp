#pragma once

#include <box2d/box2d.h>

class B2_Shape {
    public:
    static inline void defaultShapeDef(b2ShapeDef& result) { result = b2DefaultShapeDef(); }
    static inline void createPolygonShape(b2BodyId bodyId, b2ShapeDef* def, b2Polygon* polygon, b2ShapeId& result) {
        result = b2CreatePolygonShape(bodyId, def, polygon);
    }
};