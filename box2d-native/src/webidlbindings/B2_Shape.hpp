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
    static inline uint64_t createCircleShape(uint64_t bodyId, const b2ShapeDef* def, const b2Circle* circle) {
        return b2StoreShapeId(b2CreateCircleShape(b2LoadBodyId(bodyId), def, circle));
    }

    /// Create a line segment shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline uint64_t createSegmentShape(uint64_t bodyId, const b2ShapeDef* def, const b2Segment* segment) {
        return b2StoreShapeId(b2CreateSegmentShape(b2LoadBodyId(bodyId), def, segment));
    }

    /// Create a capsule shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline uint64_t createCapsuleShape(uint64_t bodyId, const b2ShapeDef* def, const b2Capsule* capsule) {
        return b2StoreShapeId(b2CreateCapsuleShape(b2LoadBodyId(bodyId), def, capsule));
    }

    /// Create a polygon shape and attach it to a body. The shape definition and geometry are fully cloned.
    /// Contacts are not created until the next time step.
    /// @return the shape id for accessing the shape
    static inline uint64_t createPolygonShape(uint64_t bodyId, const b2ShapeDef* def, const b2Polygon* polygon) {
        return b2StoreShapeId(b2CreatePolygonShape(b2LoadBodyId(bodyId), def, polygon));
    }

    /// Destroy a shape. You may defer the body mass update which can improve performance if several shapes on a
    ///	body are destroyed at once.
    ///	@see b2Body_ApplyMassFromShapes
    static inline void destroyShape(uint64_t shapeId, bool updateBodyMass) {
        b2DestroyShape(b2LoadShapeId(shapeId), updateBodyMass);
    }

    /// Shape identifier validation. Provides validation for up to 64K allocations.
    static inline bool isValid(uint64_t shapeId) {
        return b2Shape_IsValid(b2LoadShapeId(shapeId));
    }

    /// Get the type of a shape
    static inline b2ShapeType getType(uint64_t shapeId) {
        return b2Shape_GetType(b2LoadShapeId(shapeId));
    }

    /// Get the id of the body that a shape is attached to
    static inline uint64_t getBody(uint64_t shapeId) {
        return b2StoreBodyId(b2Shape_GetBody(b2LoadShapeId(shapeId)));
    }

    /// Get the world that owns this shape
    static inline b2WorldId getWorld(uint64_t shapeId) {
        return b2Shape_GetWorld(b2LoadShapeId(shapeId));
    }

    /// Returns true if the shape is a sensor. It is not possible to change a shape
    /// from sensor to solid dynamically because this breaks the contract for
    /// sensor events.
    static inline bool isSensor(uint64_t shapeId) {
        return b2Shape_IsSensor(b2LoadShapeId(shapeId));
    }

    /// Set the user data for a shape
    static inline void setUserData(uint64_t shapeId, void* userData) {
        b2Shape_SetUserData(b2LoadShapeId(shapeId), userData);
    }

    /// Get the user data for a shape. This is useful when you get a shape id
    /// from an event or query.
    static inline void* getUserData(uint64_t shapeId) {
        return b2Shape_GetUserData(b2LoadShapeId(shapeId));
    }

    /// Set the mass density of a shape, usually in kg/m^2.
    /// This will optionally update the mass properties on the parent body.
    /// @see b2ShapeDef::density, b2Body_ApplyMassFromShapes
    static inline void setDensity(uint64_t shapeId, float density, bool updateBodyMass) {
        b2Shape_SetDensity(b2LoadShapeId(shapeId), density, updateBodyMass);
    }

    /// Get the density of a shape, usually in kg/m^2
    static inline float getDensity(uint64_t shapeId) {
        return b2Shape_GetDensity(b2LoadShapeId(shapeId));
    }

    /// Set the friction on a shape
    /// @see b2ShapeDef::friction
    static inline void setFriction(uint64_t shapeId, float friction) {
        b2Shape_SetFriction(b2LoadShapeId(shapeId), friction);
    }

    /// Get the friction of a shape
    static inline float getFriction(uint64_t shapeId) {
        return b2Shape_GetFriction(b2LoadShapeId(shapeId));
    }

    /// Set the shape restitution (bounciness)
    /// @see b2ShapeDef::restitution
    static inline void setRestitution(uint64_t shapeId, float restitution) {
        b2Shape_SetRestitution(b2LoadShapeId(shapeId), restitution);
    }

    /// Get the shape restitution
    static inline float getRestitution(uint64_t shapeId) {
        return b2Shape_GetRestitution(b2LoadShapeId(shapeId));
    }

    /// Set the shape material identifier
    /// @see b2ShapeDef::material
    static inline void setMaterial(uint64_t shapeId, int material) {
        b2Shape_SetMaterial(b2LoadShapeId(shapeId), material);
    }

    /// Get the shape material identifier
    static inline int getMaterial(uint64_t shapeId) {
        return b2Shape_GetMaterial(b2LoadShapeId(shapeId));
    }

    /// Set the shape surface material
    static inline void setSurfaceMaterial(uint64_t shapeId, b2SurfaceMaterial surfaceMaterial) {
        b2Shape_SetSurfaceMaterial(b2LoadShapeId(shapeId), surfaceMaterial);
    }

    /// Get the shape surface material
    static inline b2SurfaceMaterial getSurfaceMaterial(uint64_t shapeId) {
        return b2Shape_GetSurfaceMaterial(b2LoadShapeId(shapeId));
    }

    /// Get the shape filter
    static inline b2Filter getFilter(uint64_t shapeId) {
        return b2Shape_GetFilter(b2LoadShapeId(shapeId));
    }

    /// Set the current filter. This is almost as expensive as recreating the shape. This may cause
    /// contacts to be immediately destroyed. However contacts are not created until the next world step.
    /// Sensor overlap state is also not updated until the next world step.
    /// @see b2ShapeDef::filter
    static inline void setFilter(uint64_t shapeId, b2Filter filter) {
        b2Shape_SetFilter(b2LoadShapeId(shapeId), filter);
    }

    /// Enable sensor events for this shape.
    /// @see b2ShapeDef::enableSensorEvents
    static inline void enableSensorEvents(uint64_t shapeId, bool flag) {
        b2Shape_EnableSensorEvents(b2LoadShapeId(shapeId), flag);
    }

    /// Returns true if sensor events are enabled.
    static inline bool areSensorEventsEnabled(uint64_t shapeId) {
        return b2Shape_AreSensorEventsEnabled(b2LoadShapeId(shapeId));
    }

    /// Enable contact events for this shape. Only applies to kinematic and dynamic bodies. Ignored for sensors.
    /// @see b2ShapeDef::enableContactEvents
    /// @warning changing this at run-time may lead to lost begin/end events
    static inline void enableContactEvents(uint64_t shapeId, bool flag) {
        b2Shape_EnableContactEvents(b2LoadShapeId(shapeId), flag);
    }

    /// Returns true if contact events are enabled
    static inline bool areContactEventsEnabled(uint64_t shapeId) {
        return b2Shape_AreContactEventsEnabled(b2LoadShapeId(shapeId));
    }

    /// Enable pre-solve contact events for this shape. Only applies to dynamic bodies. These are expensive
    /// and must be carefully handled due to multithreading. Ignored for sensors.
    /// @see b2PreSolveFcn
    static inline void enablePreSolveEvents(uint64_t shapeId, bool flag) {
        b2Shape_EnablePreSolveEvents(b2LoadShapeId(shapeId), flag);
    }

    /// Returns true if pre-solve events are enabled
    static inline bool arePreSolveEventsEnabled(uint64_t shapeId) {
        return b2Shape_ArePreSolveEventsEnabled(b2LoadShapeId(shapeId));
    }

    /// Enable contact hit events for this shape. Ignored for sensors.
    /// @see b2WorldDef.hitEventThreshold
    static inline void enableHitEvents(uint64_t shapeId, bool flag) {
        b2Shape_EnableHitEvents(b2LoadShapeId(shapeId), flag);
    }

    /// Returns true if hit events are enabled
    static inline bool areHitEventsEnabled(uint64_t shapeId) {
        return b2Shape_AreHitEventsEnabled(b2LoadShapeId(shapeId));
    }

    /// Test a point for overlap with a shape
    static inline bool testPoint(uint64_t shapeId, b2Vec2 point) {
        return b2Shape_TestPoint(b2LoadShapeId(shapeId), point);
    }

    /// Ray cast a shape directly
    static inline b2CastOutput rayCast(uint64_t shapeId, const b2RayCastInput* input) {
        return b2Shape_RayCast(b2LoadShapeId(shapeId), input);
    }

    /// Get a copy of the shape's circle. Asserts the type is correct.
    static inline b2Circle getCircle(uint64_t shapeId) {
        return b2Shape_GetCircle(b2LoadShapeId(shapeId));
    }

    /// Get a copy of the shape's line segment. Asserts the type is correct.
    static inline b2Segment getSegment(uint64_t shapeId) {
        return b2Shape_GetSegment(b2LoadShapeId(shapeId));
    }

    /// Get a copy of the shape's chain segment. These come from chain shapes.
    /// Asserts the type is correct.
    static inline b2ChainSegment getChainSegment(uint64_t shapeId) {
        return b2Shape_GetChainSegment(b2LoadShapeId(shapeId));
    }

    /// Get a copy of the shape's capsule. Asserts the type is correct.
    static inline b2Capsule getCapsule(uint64_t shapeId) {
        return b2Shape_GetCapsule(b2LoadShapeId(shapeId));
    }

    /// Get a copy of the shape's convex polygon. Asserts the type is correct.
    static inline b2Polygon getPolygon(uint64_t shapeId) {
        return b2Shape_GetPolygon(b2LoadShapeId(shapeId));
    }

    /// Allows you to change a shape to be a circle or update the current circle.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setCircle(uint64_t shapeId, const b2Circle* circle) {
        b2Shape_SetCircle(b2LoadShapeId(shapeId), circle);
    }

    /// Allows you to change a shape to be a capsule or update the current capsule.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setCapsule(uint64_t shapeId, const b2Capsule* capsule) {
        b2Shape_SetCapsule(b2LoadShapeId(shapeId), capsule);
    }

    /// Allows you to change a shape to be a segment or update the current segment.
    static inline void setSegment(uint64_t shapeId, const b2Segment* segment) {
        b2Shape_SetSegment(b2LoadShapeId(shapeId), segment);
    }

    /// Allows you to change a shape to be a polygon or update the current polygon.
    /// This does not modify the mass properties.
    /// @see b2Body_ApplyMassFromShapes
    static inline void setPolygon(uint64_t shapeId, const b2Polygon* polygon) {
        b2Shape_SetPolygon(b2LoadShapeId(shapeId), polygon);
    }

    /// Get the parent chain id if the shape type is a chain segment, otherwise
    /// returns b2_nullChainId.
    static inline uint64_t getParentChain(uint64_t shapeId) {
        return b2StoreChainId(b2Shape_GetParentChain(b2LoadShapeId(shapeId)));
    }

    /// Get the maximum capacity required for retrieving all the touching contacts on a shape
    static inline int getContactCapacity(uint64_t shapeId) {
        return b2Shape_GetContactCapacity(b2LoadShapeId(shapeId));
    }

    /// Get the touching contact data for a shape. The provided shapeId will be either shapeIdA or shapeIdB on the contact data.
    /// @note Box2D uses speculative collision so some contact points may be separated.
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    static inline int getContactData(uint64_t shapeId, b2ContactDataArray* contactData) {
        return b2Shape_GetContactData(b2LoadShapeId(shapeId), contactData->array, contactData->length);
    }

    /// Get the maximum capacity required for retrieving all the overlapped shapes on a sensor shape.
    /// This returns 0 if the provided shape is not a sensor.
    /// @param shapeId the id of a sensor shape
    /// @returns the required capacity to get all the overlaps in b2Shape_GetSensorOverlaps
    static inline int getSensorCapacity(uint64_t shapeId) {
        return b2Shape_GetSensorCapacity(b2LoadShapeId(shapeId));
    }

    /// Get the overlapped shapes for a sensor shape.
    /// @param shapeId the id of a sensor shape
    /// @param overlaps a user allocated array that is filled with the overlapping shapes
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    /// @warning overlaps may contain destroyed shapes so use b2Shape_IsValid to confirm each overlap
    static inline int getSensorOverlaps(uint64_t shapeId, b2ShapeIdArray* overlaps) {
        return b2Shape_GetSensorOverlaps(b2LoadShapeId(shapeId), overlaps->array, overlaps->length);
    }

    /// Get the current world AABB
    static inline b2AABB getAABB(uint64_t shapeId) {
        return b2Shape_GetAABB(b2LoadShapeId(shapeId));
    }

    /// Get the mass data for a shape
    static inline b2MassData getMassData(uint64_t shapeId) {
        return b2Shape_GetMassData(b2LoadShapeId(shapeId));
    }

    /// Get the closest point on a shape to a target point. Target and result are in world space.
    static inline b2Vec2 getClosestPoint(uint64_t shapeId, b2Vec2 target) {
        return b2Shape_GetClosestPoint(b2LoadShapeId(shapeId), target);
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
    static inline uint64_t createChain(uint64_t bodyId, const b2ChainDef* def) {
        return b2StoreChainId(b2CreateChain(b2LoadBodyId(bodyId), def));
    }

    /// Destroy a chain shape
    static inline void destroyChain(uint64_t chainId) {
        b2DestroyChain(b2LoadChainId(chainId));
    }

    /// Chain identifier validation. Provides validation for up to 64K allocations.
    static inline bool isValid(uint64_t chainId) {
        return b2Chain_IsValid(b2LoadChainId(chainId));
    }

    /// Get the world that owns this chain shape
    static inline b2WorldId getWorld(uint64_t chainId) {
        return b2Chain_GetWorld(b2LoadChainId(chainId));
    }

    /// Get the number of segments on this chain
    static inline int getSegmentCount(uint64_t chainId) {
        return b2Chain_GetSegmentCount(b2LoadChainId(chainId));
    }

    /// Fill a user array with chain segment shape ids up to the specified capacity. Returns
    /// the actual number of segments returned.
    static inline int getSegments(uint64_t chainId, b2ShapeIdArray* segmentArray) {
        return b2Chain_GetSegments(b2LoadChainId(chainId), segmentArray->array, segmentArray->length);
    }

    /// Set the chain friction
    /// @see b2ChainDef::friction
    static inline void setFriction(uint64_t chainId, float friction) {
        b2Chain_SetFriction(b2LoadChainId(chainId), friction);
    }

    /// Get the chain friction
    static inline float getFriction(uint64_t chainId) {
        return b2Chain_GetFriction(b2LoadChainId(chainId));
    }

    /// Set the chain restitution (bounciness)
    /// @see b2ChainDef::restitution
    static inline void setRestitution(uint64_t chainId, float restitution) {
        b2Chain_SetRestitution(b2LoadChainId(chainId), restitution);
    }

    /// Get the chain restitution
    static inline float getRestitution(uint64_t chainId) {
        return b2Chain_GetRestitution(b2LoadChainId(chainId));
    }

    /// Set the chain material
    /// @see b2ChainDef::material
    static inline void setMaterial(uint64_t chainId, int material) {
        b2Chain_SetMaterial(b2LoadChainId(chainId), material);
    }

    /// Get the chain material
    static inline int getMaterial(uint64_t chainId) {
        return b2Chain_GetMaterial(b2LoadChainId(chainId));
    }
};