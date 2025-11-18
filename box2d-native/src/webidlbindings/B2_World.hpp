#pragma once

#include <box2d/box2d.h>

class B2_World {
    public:

    /// Use this to initialize your world definition
    /// @ingroup world
    static inline void defaultWorldDef(b2WorldDef& result) {
        result = b2DefaultWorldDef(); 
    }

    /// Create a world for rigid body simulation. A world contains bodies, shapes, and constraints. You make create
    /// up to 128 worlds. Each world is completely independent and may be simulated in parallel.
    /// @return the world id.
    static inline void createWorld(const b2WorldDef* def, b2WorldId& result) {
        result = b2CreateWorld(def); 
    }

    /// Destroy a world
    static inline void destroyWorld(b2WorldId result) {
        b2DestroyWorld(result); 
    }

    /// World id validation. Provides validation for up to 64K allocations.
    static inline bool isValid(b2WorldId id) {
        return b2World_IsValid(id); 
    }

    /// Simulate a world for one time step. This performs collision detection, integration, and constraint solution.
    /// @param worldId The world to simulate
    /// @param timeStep The amount of time to simulate, this should be a fixed number. Usually 1/60.
    /// @param subStepCount The number of sub-steps, increasing the sub-step count can increase accuracy. Usually 4.
    static inline void step(b2WorldId world, float timeStep, long subStepCount) {
        b2World_Step(world, timeStep, subStepCount); 
    }

    /// Call this to draw shapes and other debug draw data
    static inline void draw(b2WorldId worldId, b2DebugDraw* draw) {
        b2World_Draw(worldId, draw); 
    }

    /// Get the body events for the current time step. The event data is transient. Do not store a reference to this data.
    static inline b2BodyEvents getBodyEvents(b2WorldId worldId) {
        return b2World_GetBodyEvents(worldId); 
    }

    /// Get sensor events for the current time step. The event data is transient. Do not store a reference to this data.
    static inline b2SensorEvents getSensorEvents(b2WorldId worldId) {
        return b2World_GetSensorEvents(worldId); 
    }

    /// Get contact events for this current time step. The event data is transient. Do not store a reference to this data.
    static inline b2ContactEvents getContactEvents(b2WorldId worldId) {
        return b2World_GetContactEvents(worldId); 
    }

    /// Overlap test for all shapes that *potentially* overlap the provided AABB
    static inline b2TreeStats overlapAABB(b2WorldId worldId, b2AABB aabb, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
        return b2World_OverlapAABB(worldId, aabb, filter, fcn, context); 
    }

    /// Overlap test for all shapes that overlap the provided shape proxy.
    static inline b2TreeStats overlapShape(b2WorldId worldId, const b2ShapeProxy* proxy, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
        return b2World_OverlapShape(worldId, proxy, filter, fcn, context); 
    }

    /// Cast a ray into the world to collect shapes in the path of the ray.
    /// Your callback function controls whether you get the closest point, any point, or n-points.
    /// @note The callback function may receive shapes in any order
    /// @param worldId The world to cast the ray against
    /// @param origin The start point of the ray
    /// @param translation The translation of the ray from the start point to the end point
    /// @param filter Contains bit flags to filter unwanted shapes from the results
    /// @param fcn A user implemented callback function
    /// @param context A user context that is passed along to the callback function
    ///	@return traversal performance counters
    static inline b2TreeStats castRay(b2WorldId worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
        return b2World_CastRay(worldId, origin, translation, filter, fcn, context); 
    }

    /// Cast a ray into the world to collect the closest hit. This is a convenience function. Ignores initial overlap.
    /// This is less general than b2World_CastRay() and does not allow for custom filtering.
    static inline b2RayResult castRayClosest(b2WorldId worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter) {
        return b2World_CastRayClosest(worldId, origin, translation, filter); 
    }

    /// Cast a shape through the world. Similar to a cast ray except that a shape is cast instead of a point.
    ///	@see b2World_CastRay
    static inline b2TreeStats castShape(b2WorldId worldId, const b2ShapeProxy* proxy, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
        return b2World_CastShape(worldId, proxy, translation, filter, fcn, context); 
    }

    /// Cast a capsule mover through the world. This is a special shape cast that handles sliding along other shapes while reducing
    /// clipping.
    static inline float castMover(b2WorldId worldId, const b2Capsule* mover, b2Vec2 translation, b2QueryFilter filter) {
        return b2World_CastMover(worldId, mover, translation, filter); 
    }

    /// Collide a capsule mover with the world, gathering collision planes that can be fed to b2SolvePlanes. Useful for
    /// kinematic character movement.
    static inline void collideMover(b2WorldId worldId, const b2Capsule* mover, b2QueryFilter filter, b2PlaneResultFcn* fcn, void* context) {
        b2World_CollideMover(worldId, mover, filter, fcn, context); 
    }

    /// Enable/disable sleep. If your application does not need sleeping, you can gain some performance
    /// by disabling sleep completely at the world level.
    /// @see b2WorldDef
    static inline void enableSleeping(b2WorldId worldId, bool flag) {
        b2World_EnableSleeping(worldId, flag); 
    }

    /// Is body sleeping enabled?
    static inline bool isSleepingEnabled(b2WorldId worldId) {
        return b2World_IsSleepingEnabled(worldId); 
    }

    /// Enable/disable continuous collision between dynamic and static bodies. Generally you should keep continuous
    /// collision enabled to prevent fast moving objects from going through static objects. The performance gain from
    /// disabling continuous collision is minor.
    /// @see b2WorldDef
    static inline void enableContinuous(b2WorldId worldId, bool flag) {
        b2World_EnableContinuous(worldId, flag); 
    }

    /// Is continuous collision enabled?
    static inline bool isContinuousEnabled(b2WorldId worldId) {
        return b2World_IsContinuousEnabled(worldId); 
    }

    /// Adjust the restitution threshold. It is recommended not to make this value very small
    /// because it will prevent bodies from sleeping. Usually in meters per second.
    /// @see b2WorldDef
    static inline void setRestitutionThreshold(b2WorldId worldId, float value) {
        b2World_SetRestitutionThreshold(worldId, value); 
    }

    /// Get the the restitution speed threshold. Usually in meters per second.
    static inline float getRestitutionThreshold(b2WorldId worldId) {
        return b2World_GetRestitutionThreshold(worldId); 
    }

    /// Adjust the hit event threshold. This controls the collision speed needed to generate a b2ContactHitEvent.
    /// Usually in meters per second.
    /// @see b2WorldDef::hitEventThreshold
    static inline void setHitEventThreshold(b2WorldId worldId, float value) {
        b2World_SetHitEventThreshold(worldId, value); 
    }

    /// Get the the hit event speed threshold. Usually in meters per second.
    static inline float getHitEventThreshold(b2WorldId worldId) {
        return b2World_GetHitEventThreshold(worldId); 
    }

    /// Set the gravity vector for the entire world. Box2D has no concept of an up direction and this
    /// is left as a decision for the application. Usually in m/s^2.
    /// @see b2WorldDef
    static inline void setGravity(b2WorldId worldId, b2Vec2 gravity) {
        b2World_SetGravity(worldId, gravity); 
    }

    /// Get the gravity vector
    static inline b2Vec2 getGravity(b2WorldId worldId) {
        return b2World_GetGravity(worldId); 
    }

    /// Register the custom filter callback. This is optional.
    static inline void setCustomFilterCallback(b2WorldId worldId, b2CustomFilterFcn* fcn, void* context) {
        b2World_SetCustomFilterCallback(worldId, fcn, context); 
    }

    /// Register the pre-solve callback. This is optional.
    static inline void setPreSolveCallback(b2WorldId worldId, b2PreSolveFcn* fcn, void* context) {
        b2World_SetPreSolveCallback(worldId, fcn, context); 
    }

    /// Set the friction callback. Passing NULL resets to default.
    static inline void setFrictionCallback(b2WorldId worldId, b2FrictionCallback* callback) {
        b2World_SetFrictionCallback(worldId, callback); 
    }

    /// Set the restitution callback. Passing NULL resets to default.
    static inline void setRestitutionCallback(b2WorldId worldId, b2RestitutionCallback* callback) {
        b2World_SetRestitutionCallback(worldId, callback); 
    }

    /// Apply a radial explosion
    /// @param worldId The world id
    /// @param explosionDef The explosion definition
    static inline void explode(b2WorldId worldId, const b2ExplosionDef* explosionDef) {
        b2World_Explode(worldId, explosionDef); 
    }

    /// Adjust contact tuning parameters
    /// @param worldId The world id
    /// @param hertz The contact stiffness (cycles per second)
    /// @param dampingRatio The contact bounciness with 1 being critical damping (non-dimensional)
    /// @param pushSpeed The maximum contact constraint push out speed (meters per second)
    /// @note Advanced feature
    static inline void setContactTuning(b2WorldId worldId, float hertz, float dampingRatio, float pushSpeed) {
        b2World_SetContactTuning(worldId, hertz, dampingRatio, pushSpeed); 
    }

    /// Set the maximum linear speed. Usually in m/s.
    static inline void setMaximumLinearSpeed(b2WorldId worldId, float maximumLinearSpeed) {
        b2World_SetMaximumLinearSpeed(worldId, maximumLinearSpeed); 
    }

    /// Get the maximum linear speed. Usually in m/s.
    static inline float getMaximumLinearSpeed(b2WorldId worldId) {
        return b2World_GetMaximumLinearSpeed(worldId); 
    }

    /// Enable/disable constraint warm starting. Advanced feature for testing. Disabling
    /// warm starting greatly reduces stability and provides no performance gain.
    static inline void enableWarmStarting(b2WorldId worldId, bool flag) {
        b2World_EnableWarmStarting(worldId, flag); 
    }

    /// Is constraint warm starting enabled?
    static inline bool isWarmStartingEnabled(b2WorldId worldId) {
        return b2World_IsWarmStartingEnabled(worldId); 
    }

    /// Get the number of awake bodies.
    static inline int getAwakeBodyCount(b2WorldId worldId) {
        return b2World_GetAwakeBodyCount(worldId); 
    }

    /// Get the current world performance profile
    static inline b2Profile getProfile(b2WorldId worldId) {
        return b2World_GetProfile(worldId); 
    }

    /// Get world counters and sizes
    static inline b2Counters getCounters(b2WorldId worldId) {
        return b2World_GetCounters(worldId); 
    }

    /// Dump memory stats to box2d_memory.txt
    static inline void dumpMemoryStats(b2WorldId worldId) {
        b2World_DumpMemoryStats(worldId); 
    }

    /// Set the user data pointer.
    static inline void setUserData(b2WorldId worldId, void* userData) {
        b2World_SetUserData(worldId, userData); 
    }

    /// Get the user data pointer.
    static inline void* getUserData(b2WorldId worldId) {
        return b2World_GetUserData(worldId); 
    }

    /// This is for internal testing
    static inline void rebuildStaticTree(b2WorldId worldId) {
        b2World_RebuildStaticTree(worldId); 
    }

    /// This is for internal testing
    static inline void enableSpeculative(b2WorldId worldId, bool flag) {
        b2World_EnableSpeculative(worldId, flag); 
    }
};
