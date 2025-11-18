#pragma once

#include <box2d/box2d.h>

class B2_Shape {
    public:

    /// Use this to initialize your shape definition
    static inline void defaultShapeDef(b2ShapeDef& result) {
        result = b2DefaultShapeDef();
    }

    /// Create a circle shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline void createCircleShape(b2BodyId bodyId, b2ShapeDef* def, b2Circle* circle, b2ShapeId& result) {
        result = b2CreateCircleShape(bodyId, def, circle);
    }

    /// Create a line segment shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline void createSegmentShape(b2BodyId bodyId, b2ShapeDef* def, b2Segment* segment, b2ShapeId& result) {
        result = b2CreateSegmentShape(bodyId, def, segment);
    }

    /// Create a capsule shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline void createCapsuleShape(b2BodyId bodyId, b2ShapeDef* def, b2Capsule* capsule, b2ShapeId& result) {
        result = b2CreateCapsuleShape(bodyId, def, capsule);
    }

    /// Create a polygon shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline void createPolygonShape(b2BodyId bodyId, b2ShapeDef* def, b2Polygon* polygon, b2ShapeId& result) {
        result = b2CreatePolygonShape(bodyId, def, polygon);
    }

    /// Destroy a shape. You may defer the body mass update which can improve performance if several shapes on a
    ///	body are destroyed at once.
    ///	@see b2Body_ApplyMassFromShapes
    static inline void destroyShape(b2ShapeId shapeId, bool updateBodyMass) {
        b2DestroyShape(shapeId, updateBodyMass);
    }

    /// Shape identifier validation. Provides validation for up to 64K allocations.
    static inline bool isValid(b2ShapeId id) {
        return b2Shape_IsValid(id);
    }

    /// Get the type of a shape
    static inline b2ShapeType getType(b2ShapeId shapeId) {
        return b2Shape_GetType(shapeId);
    }

    /// Get the id of the body that a shape is attached to
    static inline b2BodyId getBody(b2ShapeId shapeId) {
        return b2Shape_GetBody(shapeId);
    }

    /// Get the world that owns this shape
    static inline b2WorldId getWorld(b2ShapeId shapeId) {
        return b2Shape_GetWorld(shapeId);
    }

    /// Returns true if the shape is a sensor. It is not possible to change a shape
    /// from sensor to solid dynamically because this breaks the contract for
    /// sensor events.
    static inline bool isSensor(b2ShapeId shapeId) {
        return b2Shape_IsSensor(shapeId);
    }

    /// Set the user data for a shape
    static inline void setUserData(b2ShapeId shapeId, void* userData) {
        b2Shape_SetUserData(shapeId, userData);
    }

    /// Get the user data for a shape. This is useful when you get a shape id
    /// from an event or query.
    static inline void* getUserData(b2ShapeId shapeId) {
        return b2Shape_GetUserData(shapeId);
    }

    /// Set the mass density of a shape, usually in kg/m^2.
    /// This will optionally update the mass properties on the parent body.
    /// @see b2ShapeDef::density, b2Body_ApplyMassFromShapes
    static inline void setDensity(b2ShapeId shapeId, float density, bool updateBodyMass) {
        b2Shape_SetDensity(shapeId, density, updateBodyMass);
    }

    /// Get the density of a shape, usually in kg/m^2
    static inline float getDensity(b2ShapeId shapeId) {
        return b2Shape_GetDensity(shapeId);
    }

    /// Set the friction on a shape
    /// @see b2ShapeDef::friction
    static inline void setFriction(b2ShapeId shapeId, float friction) {
        b2Shape_SetFriction(shapeId, friction);
    }

    /// Get the friction of a shape
    static inline float getFriction(b2ShapeId shapeId) {
        return b2Shape_GetFriction(shapeId);
    }

    /// Set the shape restitution (bounciness)
    /// @see b2ShapeDef::restitution
    static inline void setRestitution(b2ShapeId shapeId, float restitution) {
        b2Shape_SetRestitution(shapeId, restitution);
    }

    /// Get the shape restitution
    static inline float getRestitution(b2ShapeId shapeId) {
        return b2Shape_GetRestitution(shapeId);
    }

    /// Set the shape material identifier
    /// @see b2ShapeDef::material
    static inline void setMaterial(b2ShapeId shapeId, int material) {
        b2Shape_SetMaterial(shapeId, material);
    }

    /// Get the shape material identifier
    static inline int getMaterial(b2ShapeId shapeId) {
        return b2Shape_GetMaterial(shapeId);
    }

    /// Set the shape surface material
    static inline void setSurfaceMaterial(b2ShapeId shapeId, b2SurfaceMaterial surfaceMaterial) {
        b2Shape_SetSurfaceMaterial(shapeId, surfaceMaterial);
    }

    /// Get the shape surface material
    static inline b2SurfaceMaterial getSurfaceMaterial(b2ShapeId shapeId) {
        return b2Shape_GetSurfaceMaterial(shapeId);
    }

    /// Get the shape filter
    static inline b2Filter getFilter(b2ShapeId shapeId) {
        return b2Shape_GetFilter(shapeId);
    }

    /// Set the current filter. This is almost as expensive as recreating the shape. This may cause
    /// contacts to be immediately destroyed. However contacts are not created until the next world step.
    /// Sensor overlap state is also not updated until the next world step.
    /// @see b2ShapeDef::filter
    static inline void setFilter(b2ShapeId shapeId, b2Filter filter) {
        b2Shape_SetFilter(shapeId, filter);
    }

    /// Enable sensor events for this shape.
    /// @see b2ShapeDef::enableSensorEvents
    static inline void enableSensorEvents(b2ShapeId shapeId, bool flag) {
        b2Shape_EnableSensorEvents(shapeId, flag);
    }

    /// Returns true if sensor events are enabled.
    static inline bool areSensorEventsEnabled(b2ShapeId shapeId) {
        return b2Shape_AreSensorEventsEnabled(shapeId);
    }

    /// Enable contact events for this shape. Only applies to kinematic and dynamic bodies. Ignored for sensors.
    /// @see b2ShapeDef::enableContactEvents
    /// @warning changing this at run-time may lead to lost begin/end events
    static inline void enableContactEvents(b2ShapeId shapeId, bool flag) {
        b2Shape_EnableContactEvents(shapeId, flag);
    }

    /// Returns true if contact events are enabled
    static inline bool areContactEventsEnabled(b2ShapeId shapeId) {
        return b2Shape_AreContactEventsEnabled(shapeId);
    }

    /// Enable pre-solve contact events for this shape. Only applies to dynamic bodies. These are expensive
    /// and must be carefully handled due to multithreading. Ignored for sensors.
    /// @see b2PreSolveFcn
    static inline void enablePreSolveEvents(b2ShapeId shapeId, bool flag) {
        b2Shape_EnablePreSolveEvents(shapeId, flag);
    }

    /// Returns true if pre-solve events are enabled
    static inline bool arePreSolveEventsEnabled(b2ShapeId shapeId) {
        return b2Shape_ArePreSolveEventsEnabled(shapeId);
    }

    /// Enable contact hit events for this shape. Ignored for sensors.
    /// @see b2WorldDef.hitEventThreshold
    static inline void enableHitEvents(b2ShapeId shapeId, bool flag) {
        b2Shape_EnableHitEvents(shapeId, flag);
    }

    /// Returns true if hit events are enabled
    static inline bool areHitEventsEnabled(b2ShapeId shapeId) {
        return b2Shape_AreHitEventsEnabled(shapeId);
    }

    /// Test a point for overlap with a shape
    static inline bool testPoint(b2ShapeId shapeId, b2Vec2 point) {
        return b2Shape_TestPoint(shapeId, point);
    }

    /// Ray cast a shape directly
    static inline b2CastOutput rayCast(b2ShapeId shapeId, b2RayCastInput* input) {
        return b2Shape_RayCast(shapeId, input);
    }

    /// Get a copy of the shape's circle. Asserts the type is correct.
    static inline b2Circle getCircle(b2ShapeId shapeId) {
        return b2Shape_GetCircle(shapeId);
    }

    /// Get a copy of the shape's line segment. Asserts the type is correct.
    static inline b2Segment getSegment(b2ShapeId shapeId) {
        return b2Shape_GetSegment(shapeId);
    }

    /// Get a copy of the shape's chain segment. These come from chain shapes.
    /// Asserts the type is correct.
    static inline b2ChainSegment getChainSegment(b2ShapeId shapeId) {
        return b2Shape_GetChainSegment(shapeId);
    }

    /// Get a copy of the shape's capsule. Asserts the type is correct.
    static inline b2Capsule getCapsule(b2ShapeId shapeId) {
        return b2Shape_GetCapsule(shapeId);
    }

    /// Get a copy of the shape's convex polygon. Asserts the type is correct.
    static inline b2Polygon getPolygon(b2ShapeId shapeId) {
        return b2Shape_GetPolygon(shapeId);
    }

    /// Allows you to change a shape to be a circle or update the current circle.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setCircle(b2ShapeId shapeId, b2Circle* circle) {
        b2Shape_SetCircle(shapeId, circle);
    }

    /// Allows you to change a shape to be a capsule or update the current capsule.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setCapsule(b2ShapeId shapeId, b2Capsule* capsule) {
        b2Shape_SetCapsule(shapeId, capsule);
    }

    /// Allows you to change a shape to be a segment or update the current segment.
    static inline void setSegment(b2ShapeId shapeId, b2Segment* segment) {
        b2Shape_SetSegment(shapeId, segment);
    }

    /// Allows you to change a shape to be a polygon or update the current polygon.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setPolygon(b2ShapeId shapeId, b2Polygon* polygon) {
        b2Shape_SetPolygon(shapeId, polygon);
    }

    /// Get the parent chain id if the shape type is a chain segment, otherwise
    /// returns b2_nullChainId.
    static inline b2ChainId getParentChain(b2ShapeId shapeId) {
        return b2Shape_GetParentChain(shapeId);
    }

    /// Get the maximum capacity required for retrieving all the touching contacts on a shape
    static inline int getContactCapacity(b2ShapeId shapeId) {
        return b2Shape_GetContactCapacity(shapeId);
    }

    /// Get the touching contact data for a shape. The provided shapeId will be either shapeIdA or shapeIdB on the contact data.
    /// @note Box2D uses speculative collision so some contact points may be separated.
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    static inline int getContactData(b2ShapeId shapeId, b2ContactData* contactData, int capacity) {
        return b2Shape_GetContactData(shapeId, contactData, capacity);
    }

    /// Get the maximum capacity required for retrieving all the overlapped shapes on a sensor shape.
    /// This returns 0 if the provided shape is not a sensor.
    /// @param shapeId the id of a sensor shape
    /// @returns the required capacity to get all the overlaps in b2Shape_GetSensorOverlaps
    static inline int getSensorCapacity(b2ShapeId shapeId) {
        return b2Shape_GetSensorCapacity(shapeId);
    }

    /// Get the overlapped shapes for a sensor shape.
    /// @param shapeId the id of a sensor shape
    /// @param overlaps a user allocated array that is filled with the overlapping shapes
    /// @param capacity the capacity of overlappedShapes
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    /// @warning overlaps may contain destroyed shapes so use b2Shape_IsValid to confirm each overlap
    static inline int getSensorOverlaps(b2ShapeId shapeId, b2ShapeId* overlaps, int capacity) {
        return b2Shape_GetSensorOverlaps(shapeId, overlaps, capacity);
    }

    /// Get the current world AABB
    static inline b2AABB getAABB(b2ShapeId shapeId) {
        return b2Shape_GetAABB(shapeId);
    }

    /// Get the mass data for a shape
    static inline b2MassData getMassData(b2ShapeId shapeId) {
        return b2Shape_GetMassData(shapeId);
    }

    /// Get the closest point on a shape to a target point. Target and result are in world space.
    static inline b2Vec2 getClosestPoint(b2ShapeId shapeId, b2Vec2 target) {
        return b2Shape_GetClosestPoint(shapeId, target);
    }
};

class B2_Chain {
    public:

    /// Use this to initialize your chain definition
    static inline void defaultChainDef(b2ChainDef& result) {
        result = b2DefaultChainDef();
    }

    /// Create a chain shape
    /// @see b2ChainDef for details
    static inline void createChain(b2BodyId bodyId, b2ChainDef* def, b2ChainId& result) {
        result = b2CreateChain(bodyId, def);
    }

    /// Destroy a chain shape
    static inline void destroyChain(b2ChainId chainId) {
        b2DestroyChain(chainId);
    }

    /// Chain identifier validation. Provides validation for up to 64K allocations.
    static inline bool isValid(b2ChainId id) {
        return b2Chain_IsValid(id);
    }

    /// Get the world that owns this chain shape
    static inline b2WorldId getWorld(b2ChainId chainId) {
        return b2Chain_GetWorld(chainId);
    }

    /// Get the number of segments on this chain
    static inline int getSegmentCount(b2ChainId chainId) {
        return b2Chain_GetSegmentCount(chainId);
    }

    /// Fill a user array with chain segment shape ids up to the specified capacity. Returns
    /// the actual number of segments returned.
    static inline int getSegments(b2ChainId chainId, b2ShapeId* segmentArray, int capacity) {
        return b2Chain_GetSegments(chainId, segmentArray, capacity);
    }

    /// Set the chain friction
    /// @see b2ChainDef::friction
    static inline void setFriction(b2ChainId chainId, float friction) {
        b2Chain_SetFriction(chainId, friction);
    }

    /// Get the chain friction
    static inline float getFriction(b2ChainId chainId) {
        return b2Chain_GetFriction(chainId);
    }

    /// Set the chain restitution (bounciness)
    /// @see b2ChainDef::restitution
    static inline void setRestitution(b2ChainId chainId, float restitution) {
        b2Chain_SetRestitution(chainId, restitution);
    }

    /// Get the chain restitution
    static inline float getRestitution(b2ChainId chainId) {
        return b2Chain_GetRestitution(chainId);
    }

    /// Set the chain material
    /// @see b2ChainDef::material
    static inline void setMaterial(b2ChainId chainId, int material) {
        b2Chain_SetMaterial(chainId, material);
    }

    /// Get the chain material
    static inline int getMaterial(b2ChainId chainId) {
        return b2Chain_GetMaterial(chainId);
    }
};