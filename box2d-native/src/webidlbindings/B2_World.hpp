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
    static inline uint64_t createWorld(const b2WorldDef* def) {
        return b2StoreWorldId(b2CreateWorld(def)); 
    }

    /// Destroy a world
    static inline void destroyWorld(uint64_t worldId) {
        b2DestroyWorld(b2LoadWorldId(worldId)); 
    }

    /// World id validation. Provides validation for up to 64K allocations.
    static inline bool isValid(uint64_t worldId) {
        return b2World_IsValid(b2LoadWorldId(worldId)); 
    }

    /// Simulate a world for one time step. This performs collision detection, integration, and constraint solution.
    /// @param worldId The world to simulate
    /// @param timeStep The amount of time to simulate, this should be a fixed number. Usually 1/60.
    /// @param subStepCount The number of sub-steps, increasing the sub-step count can increase accuracy. Usually 4.
    static inline void step(uint64_t worldId, float timeStep, long subStepCount) {
        b2World_Step(b2LoadWorldId(worldId), timeStep, subStepCount);
    }

    /// Call this to draw shapes and other debug draw data
    static inline void draw(uint64_t worldId, b2DebugDraw* draw) {
        b2World_Draw(b2LoadWorldId(worldId), draw); 
    }

    /// Get the body events for the current time step. The event data is transient. Do not store a reference to this data.
    static inline b2BodyEvents getBodyEvents(uint64_t worldId) {
        return b2World_GetBodyEvents(b2LoadWorldId(worldId)); 
    }

    /// Get sensor events for the current time step. The event data is transient. Do not store a reference to this data.
    static inline b2SensorEvents getSensorEvents(uint64_t worldId) {
        return b2World_GetSensorEvents(b2LoadWorldId(worldId)); 
    }

    /// Get contact events for this current time step. The event data is transient. Do not store a reference to this data.
    static inline b2ContactEvents getContactEvents(uint64_t worldId) {
        return b2World_GetContactEvents(b2LoadWorldId(worldId)); 
    }

    /// Overlap test for all shapes that *potentially* overlap the provided AABB
    static inline b2TreeStats overlapAABB(uint64_t worldId, b2AABB aabb, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
        return b2World_OverlapAABB(b2LoadWorldId(worldId), aabb, filter, fcn, context); 
    }

    /// Overlap test for all shapes that overlap the provided shape proxy.
    static inline b2TreeStats overlapShape(uint64_t worldId, const b2ShapeProxy* proxy, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
        return b2World_OverlapShape(b2LoadWorldId(worldId), proxy, filter, fcn, context); 
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
    static inline b2TreeStats castRay(uint64_t worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
        return b2World_CastRay(b2LoadWorldId(worldId), origin, translation, filter, fcn, context); 
    }

    /// Cast a ray into the world to collect the closest hit. This is a convenience function. Ignores initial overlap.
    /// This is less general than b2World_CastRay() and does not allow for custom filtering.
    static inline b2RayResult castRayClosest(uint64_t worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter) {
        return b2World_CastRayClosest(b2LoadWorldId(worldId), origin, translation, filter); 
    }

    /// Cast a shape through the world. Similar to a cast ray except that a shape is cast instead of a point.
    ///	@see b2World_CastRay
    static inline b2TreeStats castShape(uint64_t worldId, const b2ShapeProxy* proxy, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
        return b2World_CastShape(b2LoadWorldId(worldId), proxy, translation, filter, fcn, context); 
    }

    /// Cast a capsule mover through the world. This is a special shape cast that handles sliding along other shapes while reducing
    /// clipping.
    static inline float castMover(uint64_t worldId, const b2Capsule* mover, b2Vec2 translation, b2QueryFilter filter) {
        return b2World_CastMover(b2LoadWorldId(worldId), mover, translation, filter); 
    }

    /// Collide a capsule mover with the world, gathering collision planes that can be fed to b2SolvePlanes. Useful for
    /// kinematic character movement.
    static inline void collideMover(uint64_t worldId, const b2Capsule* mover, b2QueryFilter filter, b2PlaneResultFcn* fcn, void* context) {
        b2World_CollideMover(b2LoadWorldId(worldId), mover, filter, fcn, context); 
    }

    /// Enable/disable sleep. If your application does not need sleeping, you can gain some performance
    /// by disabling sleep completely at the world level.
    /// @see b2WorldDef
    static inline void enableSleeping(uint64_t worldId, bool flag) {
        b2World_EnableSleeping(b2LoadWorldId(worldId), flag); 
    }

    /// Is body sleeping enabled?
    static inline bool isSleepingEnabled(uint64_t worldId) {
        return b2World_IsSleepingEnabled(b2LoadWorldId(worldId)); 
    }

    /// Enable/disable continuous collision between dynamic and static bodies. Generally you should keep continuous
    /// collision enabled to prevent fast moving objects from going through static objects. The performance gain from
    /// disabling continuous collision is minor.
    /// @see b2WorldDef
    static inline void enableContinuous(uint64_t worldId, bool flag) {
        b2World_EnableContinuous(b2LoadWorldId(worldId), flag); 
    }

    /// Is continuous collision enabled?
    static inline bool isContinuousEnabled(uint64_t worldId) {
        return b2World_IsContinuousEnabled(b2LoadWorldId(worldId)); 
    }

    /// Adjust the restitution threshold. It is recommended not to make this value very small
    /// because it will prevent bodies from sleeping. Usually in meters per second.
    /// @see b2WorldDef
    static inline void setRestitutionThreshold(uint64_t worldId, float value) {
        b2World_SetRestitutionThreshold(b2LoadWorldId(worldId), value); 
    }

    /// Get the the restitution speed threshold. Usually in meters per second.
    static inline float getRestitutionThreshold(uint64_t worldId) {
        return b2World_GetRestitutionThreshold(b2LoadWorldId(worldId)); 
    }

    /// Adjust the hit event threshold. This controls the collision speed needed to generate a b2ContactHitEvent.
    /// Usually in meters per second.
    /// @see b2WorldDef::hitEventThreshold
    static inline void setHitEventThreshold(uint64_t worldId, float value) {
        b2World_SetHitEventThreshold(b2LoadWorldId(worldId), value); 
    }

    /// Get the the hit event speed threshold. Usually in meters per second.
    static inline float getHitEventThreshold(uint64_t worldId) {
        return b2World_GetHitEventThreshold(b2LoadWorldId(worldId)); 
    }

    /// Set the gravity vector for the entire world. Box2D has no concept of an up direction and this
    /// is left as a decision for the application. Usually in m/s^2.
    /// @see b2WorldDef
    static inline void setGravity(uint64_t worldId, b2Vec2 gravity) {
        b2World_SetGravity(b2LoadWorldId(worldId), gravity); 
    }

    /// Get the gravity vector
    static inline b2Vec2 getGravity(uint64_t worldId) {
        return b2World_GetGravity(b2LoadWorldId(worldId)); 
    }

    /// Register the custom filter callback. This is optional.
    static inline void setCustomFilterCallback(uint64_t worldId, b2CustomFilterFcn* fcn, void* context) {
        b2World_SetCustomFilterCallback(b2LoadWorldId(worldId), fcn, context); 
    }

    /// Register the pre-solve callback. This is optional.
    static inline void setPreSolveCallback(uint64_t worldId, b2PreSolveFcn* fcn, void* context) {
        b2World_SetPreSolveCallback(b2LoadWorldId(worldId), fcn, context); 
    }

    /// Set the friction callback. Passing NULL resets to default.
    static inline void setFrictionCallback(uint64_t worldId, b2FrictionCallback* callback) {
        b2World_SetFrictionCallback(b2LoadWorldId(worldId), callback); 
    }

    /// Set the restitution callback. Passing NULL resets to default.
    static inline void setRestitutionCallback(uint64_t worldId, b2RestitutionCallback* callback) {
        b2World_SetRestitutionCallback(b2LoadWorldId(worldId), callback); 
    }

    /// Apply a radial explosion
    /// @param worldId The world id
    /// @param explosionDef The explosion definition
    static inline void explode(uint64_t worldId, const b2ExplosionDef* explosionDef) {
        b2World_Explode(b2LoadWorldId(worldId), explosionDef); 
    }

    /// Adjust contact tuning parameters
    /// @param worldId The world id
    /// @param hertz The contact stiffness (cycles per second)
    /// @param dampingRatio The contact bounciness with 1 being critical damping (non-dimensional)
    /// @param pushSpeed The maximum contact constraint push out speed (meters per second)
    /// @note Advanced feature
    static inline void setContactTuning(uint64_t worldId, float hertz, float dampingRatio, float pushSpeed) {
        b2World_SetContactTuning(b2LoadWorldId(worldId), hertz, dampingRatio, pushSpeed); 
    }

    /// Set the maximum linear speed. Usually in m/s.
    static inline void setMaximumLinearSpeed(uint64_t worldId, float maximumLinearSpeed) {
        b2World_SetMaximumLinearSpeed(b2LoadWorldId(worldId), maximumLinearSpeed); 
    }

    /// Get the maximum linear speed. Usually in m/s.
    static inline float getMaximumLinearSpeed(uint64_t worldId) {
        return b2World_GetMaximumLinearSpeed(b2LoadWorldId(worldId)); 
    }

    /// Enable/disable constraint warm starting. Advanced feature for testing. Disabling
    /// warm starting greatly reduces stability and provides no performance gain.
    static inline void enableWarmStarting(uint64_t worldId, bool flag) {
        b2World_EnableWarmStarting(b2LoadWorldId(worldId), flag); 
    }

    /// Is constraint warm starting enabled?
    static inline bool isWarmStartingEnabled(uint64_t worldId) {
        return b2World_IsWarmStartingEnabled(b2LoadWorldId(worldId)); 
    }

    /// Get the number of awake bodies.
    static inline int getAwakeBodyCount(uint64_t worldId) {
        return b2World_GetAwakeBodyCount(b2LoadWorldId(worldId)); 
    }

    /// Get the current world performance profile
    static inline b2Profile getProfile(uint64_t worldId) {
        return b2World_GetProfile(b2LoadWorldId(worldId)); 
    }

    /// Get world counters and sizes
    static inline b2Counters getCounters(uint64_t worldId) {
        return b2World_GetCounters(b2LoadWorldId(worldId)); 
    }

    /// Dump memory stats to box2d_memory.txt
    static inline void dumpMemoryStats(uint64_t worldId) {
        b2World_DumpMemoryStats(b2LoadWorldId(worldId)); 
    }

    /// Set the user data pointer.
    static inline void setUserData(uint64_t worldId, void* userData) {
        b2World_SetUserData(b2LoadWorldId(worldId), userData); 
    }

    /// Get the user data pointer.
    static inline void* getUserData(uint64_t worldId) {
        return b2World_GetUserData(b2LoadWorldId(worldId)); 
    }

    /// This is for internal testing
    static inline void rebuildStaticTree(uint64_t worldId) {
        b2World_RebuildStaticTree(b2LoadWorldId(worldId)); 
    }

    /// This is for internal testing
    static inline void enableSpeculative(uint64_t worldId, bool flag) {
        b2World_EnableSpeculative(b2LoadWorldId(worldId), flag); 
    }
};
