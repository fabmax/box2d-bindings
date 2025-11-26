package box2d;


public class B2_World extends NativeObject {

    protected B2_World() { }

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static B2_World wrapPointer(long address) {
        return address != 0L ? new B2_World(address) : null;
    }
    
    public static B2_World arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected B2_World(long address) {
        super(address);
    }

    // Functions

    /**
     * Use this to initialize your world definition
     * @ingroup world
     */
    public static void defaultWorldDef(b2WorldDef result) {
        Raw.defaultWorldDef(result.getAddress());
    }

    /**
     * Create a world for rigid body simulation. A world contains bodies, shapes, and constraints. You make create
     * up to 128 worlds. Each world is completely independent and may be simulated in parallel.
     * @return the world id.
     */
    public static long createWorld(b2WorldDef def) {
        return Raw.createWorld(def.getAddress());
    }

    /**
     * Destroy a world
     */
    public static void destroyWorld(long worldId) {
        Raw.destroyWorld(worldId);
    }

    /**
     * World id validation. Provides validation for up to 64K allocations.
     */
    public static boolean isValid(long worldId) {
        return Raw.isValid(worldId);
    }

    /**
     * Simulate a world for one time step. This performs collision detection, integration, and constraint solution.
     * @param worldId The world to simulate
     * @param timeStep The amount of time to simulate, this should be a fixed number. Usually 1/60.
     * @param subStepCount The number of sub-steps, increasing the sub-step count can increase accuracy. Usually 4.
     */
    public static void step(long worldId, float timeStep, int subStepCount) {
        Raw.step(worldId, timeStep, subStepCount);
    }

    /**
     * Call this to draw shapes and other debug draw data
     */
    public static void draw(long worldId, b2DebugDraw draw, b2DebugDrawCallbacks callbacks) {
        Raw.draw(worldId, draw.getAddress(), callbacks.getAddress());
    }

    /**
     * Get the body events for the current time step. The event data is transient. Do not store a reference to this data.
     */
    public static b2BodyEvents getBodyEvents(long worldId) {
        return b2BodyEvents.wrapPointer(Raw.getBodyEvents(worldId));
    }

    /**
     * Get sensor events for the current time step. The event data is transient. Do not store a reference to this data.
     */
    public static b2SensorEvents getSensorEvents(long worldId) {
        return b2SensorEvents.wrapPointer(Raw.getSensorEvents(worldId));
    }

    /**
     * Get contact events for this current time step. The event data is transient. Do not store a reference to this data.
     */
    public static b2ContactEvents getContactEvents(long worldId) {
        return b2ContactEvents.wrapPointer(Raw.getContactEvents(worldId));
    }

    /**
     * Overlap test for all shapes that *potentially* overlap the provided AABB
     */
    public static b2TreeStats overlapAABB(long worldId, b2AABB aabb, b2QueryFilter filter, b2OverlapResultFcnI fcn) {
        return b2TreeStats.wrapPointer(Raw.overlapAABB(worldId, aabb.getAddress(), filter.getAddress(), fcn.getAddress()));
    }

    /**
     * Overlap test for all shapes that overlap the provided shape proxy.
     */
    public static b2TreeStats overlapShape(long worldId, b2ShapeProxy proxy, b2QueryFilter filter, b2OverlapResultFcnI fcn) {
        return b2TreeStats.wrapPointer(Raw.overlapShape(worldId, proxy.getAddress(), filter.getAddress(), fcn.getAddress()));
    }

    /**
     * Cast a ray into the world to collect shapes in the path of the ray.
     * Your callback function controls whether you get the closest point, any point, or n-points.
     * @note The callback function may receive shapes in any order
     * @param worldId The world to cast the ray against
     * @param origin The start point of the ray
     * @param translation The translation of the ray from the start point to the end point
     * @param filter Contains bit flags to filter unwanted shapes from the results
     * @param fcn A user implemented callback function
     * @return traversal performance counters
     */
    public static b2TreeStats castRay(long worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcnI fcn) {
        return b2TreeStats.wrapPointer(Raw.castRay(worldId, origin.getAddress(), translation.getAddress(), filter.getAddress(), fcn.getAddress()));
    }

    /**
     * Cast a ray into the world to collect the closest hit. This is a convenience function. Ignores initial overlap.
     * This is less general than b2World_CastRay() and does not allow for custom filtering.
     */
    public static b2RayResult castRayClosest(long worldId, b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter) {
        return b2RayResult.wrapPointer(Raw.castRayClosest(worldId, origin.getAddress(), translation.getAddress(), filter.getAddress()));
    }

    /**
     * Cast a shape through the world. Similar to a cast ray except that a shape is cast instead of a point.
     */
    public static b2TreeStats castShape(long worldId, b2ShapeProxy proxy, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcnI fcn) {
        return b2TreeStats.wrapPointer(Raw.castShape(worldId, proxy.getAddress(), translation.getAddress(), filter.getAddress(), fcn.getAddress()));
    }

    /**
     * Cast a capsule mover through the world. This is a special shape cast that handles sliding along other shapes while reducing
     * clipping.
     */
    public static float castMover(long worldId, b2Capsule mover, b2Vec2 translation, b2QueryFilter filter) {
        return Raw.castMover(worldId, mover.getAddress(), translation.getAddress(), filter.getAddress());
    }

    /**
     * Collide a capsule mover with the world, gathering collision planes that can be fed to b2SolvePlanes. Useful for
     * kinematic character movement.
     */
    public static void collideMover(long worldId, b2Capsule mover, b2QueryFilter filter, b2PlaneResultFcnI fcn) {
        Raw.collideMover(worldId, mover.getAddress(), filter.getAddress(), fcn.getAddress());
    }

    /**
     * Enable/disable sleep. If your application does not need sleeping, you can gain some performance
     * by disabling sleep completely at the world level.
     * @see b2WorldDef
     */
    public static void enableSleeping(long worldId, boolean flag) {
        Raw.enableSleeping(worldId, flag);
    }

    /**
     * Is body sleeping enabled?
     */
    public static boolean isSleepingEnabled(long worldId) {
        return Raw.isSleepingEnabled(worldId);
    }

    /**
     * Enable/disable continuous collision between dynamic and static bodies. Generally you should keep continuous
     * collision enabled to prevent fast moving objects from going through static objects. The performance gain from
     * disabling continuous collision is minor.
     * @see b2WorldDef
     */
    public static void enableContinuous(long worldId, boolean flag) {
        Raw.enableContinuous(worldId, flag);
    }

    /**
     * Is continuous collision enabled?
     */
    public static boolean isContinuousEnabled(long worldId) {
        return Raw.isContinuousEnabled(worldId);
    }

    /**
     * Adjust the restitution threshold. It is recommended not to make this value very small
     * because it will prevent bodies from sleeping. Usually in meters per second.
     * @see b2WorldDef
     */
    public static void setRestitutionThreshold(long worldId, float value) {
        Raw.setRestitutionThreshold(worldId, value);
    }

    /**
     * Get the the restitution speed threshold. Usually in meters per second.
     */
    public static float getRestitutionThreshold(long worldId) {
        return Raw.getRestitutionThreshold(worldId);
    }

    /**
     * Adjust the hit event threshold. This controls the collision speed needed to generate a b2ContactHitEvent.
     * Usually in meters per second.
     */
    public static void setHitEventThreshold(long worldId, float value) {
        Raw.setHitEventThreshold(worldId, value);
    }

    /**
     * Get the the hit event speed threshold. Usually in meters per second.
     */
    public static float getHitEventThreshold(long worldId) {
        return Raw.getHitEventThreshold(worldId);
    }

    /**
     * Set the gravity vector for the entire world. Box2D has no concept of an up direction and this
     * is left as a decision for the application. Usually in m/s^2.
     * @see b2WorldDef
     */
    public static void setGravity(long worldId, b2Vec2 gravity) {
        Raw.setGravity(worldId, gravity.getAddress());
    }

    /**
     * Get the gravity vector
     */
    public static b2Vec2 getGravity(long worldId) {
        return b2Vec2.wrapPointer(Raw.getGravity(worldId));
    }

    /**
     * Register the custom filter callback. This is optional.
     */
    public static void setCustomFilterCallback(long worldId, b2CustomFilterFcnI fcn) {
        Raw.setCustomFilterCallback(worldId, fcn.getAddress());
    }

    /**
     * Register the pre-solve callback. This is optional.
     */
    public static void setPreSolveCallback(long worldId, b2PreSolveFcnI fcn) {
        Raw.setPreSolveCallback(worldId, fcn.getAddress());
    }

    /**
     * Set the friction callback. Passing NULL resets to default.
     */
    public static void setFrictionCallback(long worldId, b2FrictionCallbackI callback) {
        Raw.setFrictionCallback(worldId, callback.getAddress());
    }

    /**
     * Set the restitution callback. Passing NULL resets to default.
     */
    public static void setRestitutionCallback(long worldId, b2RestitutionCallbackI callback) {
        Raw.setRestitutionCallback(worldId, callback.getAddress());
    }

    /**
     * Apply a radial explosion
     * @param worldId The world id
     * @param explosionDef The explosion definition
     */
    public static void explode(long worldId, b2ExplosionDef explosionDef) {
        Raw.explode(worldId, explosionDef.getAddress());
    }

    /**
     * Adjust contact tuning parameters
     * @param worldId The world id
     * @param hertz The contact stiffness (cycles per second)
     * @param dampingRatio The contact bounciness with 1 being critical damping (non-dimensional)
     * @param pushSpeed The maximum contact constraint push out speed (meters per second)
     * @note Advanced feature
     */
    public static void setContactTuning(long worldId, float hertz, float dampingRatio, float pushSpeed) {
        Raw.setContactTuning(worldId, hertz, dampingRatio, pushSpeed);
    }

    /**
     * Set the maximum linear speed. Usually in m/s.
     */
    public static void setMaximumLinearSpeed(long worldId, float maximumLinearSpeed) {
        Raw.setMaximumLinearSpeed(worldId, maximumLinearSpeed);
    }

    /**
     * Get the maximum linear speed. Usually in m/s.
     */
    public static float getMaximumLinearSpeed(long worldId) {
        return Raw.getMaximumLinearSpeed(worldId);
    }

    /**
     * Enable/disable constraint warm starting. Advanced feature for testing. Disabling
     * warm starting greatly reduces stability and provides no performance gain.
     */
    public static void enableWarmStarting(long worldId, boolean flag) {
        Raw.enableWarmStarting(worldId, flag);
    }

    /**
     * Is constraint warm starting enabled?
     */
    public static boolean isWarmStartingEnabled(long worldId) {
        return Raw.isWarmStartingEnabled(worldId);
    }

    /**
     * Get the number of awake bodies.
     */
    public static int getAwakeBodyCount(long worldId) {
        return Raw.getAwakeBodyCount(worldId);
    }

    /**
     * Get the current world performance profile
     */
    public static b2Profile getProfile(long worldId) {
        return b2Profile.wrapPointer(Raw.getProfile(worldId));
    }

    /**
     * Get world counters and sizes
     */
    public static b2Counters getCounters(long worldId) {
        return b2Counters.wrapPointer(Raw.getCounters(worldId));
    }

    /**
     * Dump memory stats to box2d_memory.txt
     */
    public static void dumpMemoryStats(long worldId) {
        Raw.dumpMemoryStats(worldId);
    }

    /**
     * Set the user data pointer.
     */
    public static void setUserData(long worldId, NativeObject userData) {
        Raw.setUserData(worldId, userData.getAddress());
    }

    /**
     * Get the user data pointer.
     */
    public static NativeObject getUserData(long worldId) {
        return NativeObject.wrapPointer(Raw.getUserData(worldId));
    }

    /**
     * This is for internal testing
     */
    public static void rebuildStaticTree(long worldId) {
        Raw.rebuildStaticTree(worldId);
    }

    /**
     * This is for internal testing
     */
    public static void enableSpeculative(long worldId, boolean flag) {
        Raw.enableSpeculative(worldId, flag);
    }

    public static class Raw {
        public static native void defaultWorldDef(long result);
        public static native long createWorld(long def);
        public static native void destroyWorld(long worldId);
        public static native boolean isValid(long worldId);
        public static native void step(long worldId, float timeStep, int subStepCount);
        public static native void draw(long worldId, long draw, long callbacks);
        public static native long getBodyEvents(long worldId);
        public static native long getSensorEvents(long worldId);
        public static native long getContactEvents(long worldId);
        public static native long overlapAABB(long worldId, long aabb, long filter, long fcn);
        public static native long overlapShape(long worldId, long proxy, long filter, long fcn);
        public static native long castRay(long worldId, long origin, long translation, long filter, long fcn);
        public static native long castRayClosest(long worldId, long origin, long translation, long filter);
        public static native long castShape(long worldId, long proxy, long translation, long filter, long fcn);
        public static native float castMover(long worldId, long mover, long translation, long filter);
        public static native void collideMover(long worldId, long mover, long filter, long fcn);
        public static native void enableSleeping(long worldId, boolean flag);
        public static native boolean isSleepingEnabled(long worldId);
        public static native void enableContinuous(long worldId, boolean flag);
        public static native boolean isContinuousEnabled(long worldId);
        public static native void setRestitutionThreshold(long worldId, float value);
        public static native float getRestitutionThreshold(long worldId);
        public static native void setHitEventThreshold(long worldId, float value);
        public static native float getHitEventThreshold(long worldId);
        public static native void setGravity(long worldId, long gravity);
        public static native long getGravity(long worldId);
        public static native void setCustomFilterCallback(long worldId, long fcn);
        public static native void setPreSolveCallback(long worldId, long fcn);
        public static native void setFrictionCallback(long worldId, long callback);
        public static native void setRestitutionCallback(long worldId, long callback);
        public static native void explode(long worldId, long explosionDef);
        public static native void setContactTuning(long worldId, float hertz, float dampingRatio, float pushSpeed);
        public static native void setMaximumLinearSpeed(long worldId, float maximumLinearSpeed);
        public static native float getMaximumLinearSpeed(long worldId);
        public static native void enableWarmStarting(long worldId, boolean flag);
        public static native boolean isWarmStartingEnabled(long worldId);
        public static native int getAwakeBodyCount(long worldId);
        public static native long getProfile(long worldId);
        public static native long getCounters(long worldId);
        public static native void dumpMemoryStats(long worldId);
        public static native void setUserData(long worldId, long userData);
        public static native long getUserData(long worldId);
        public static native void rebuildStaticTree(long worldId);
        public static native void enableSpeculative(long worldId, boolean flag);
    }
}
