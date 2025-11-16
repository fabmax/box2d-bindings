#pragma once

#include <box2d/box2d.h>

class B2_Body {
    public:
    static inline void defaultBodyDef(b2BodyDef& result) { result = b2DefaultBodyDef(); }
    static inline void createBody(b2WorldId worldId, b2BodyDef* def, b2BodyId& result) { result = b2CreateBody(worldId, def); }

    static inline b2Vec2 getPosition(b2BodyId bodyId) { return b2Body_GetPosition(bodyId); }
    static inline b2Rot getRotation(b2BodyId bodyId) { return b2Body_GetRotation(bodyId); }
};