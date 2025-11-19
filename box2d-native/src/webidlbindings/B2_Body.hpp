#pragma once

#include <box2d/box2d.h>

class B2_Body {
    public:

    /// Use this to initialize your body definition
    /// @ingroup body
    static inline void defaultBodyDef(b2BodyDef& result) {
        result = b2DefaultBodyDef();
    }

    /// Create a rigid body given a definition. No reference to the definition is retained. So you can create the definition
    /// on the stack and pass it as a pointer.
    /// @code{.c}
    /// b2BodyDef bodyDef = b2DefaultBodyDef();
    /// uint64_t myBodyId = b2CreateBody(myWorldId, &bodyDef);
    /// @endcode
    /// @warning This function is locked during callbacks.
    static inline uint64_t createBody(uint64_t worldId, b2BodyDef* def) {
        return b2StoreBodyId(b2CreateBody(b2LoadWorldId(worldId), def));
    }

    /// Destroy a rigid body given an id. This destroys all shapes and joints attached to the body.
    /// Do not keep references to the associated shapes and joints.
    static inline void destroyBody(uint64_t bodyId) {
        b2DestroyBody(b2LoadBodyId(bodyId));
    }

    /// Body identifier validation. Can be used to detect orphaned ids. Provides validation for up to 64K allocations.
    static inline bool isValid(uint64_t bodyId) {
        return b2Body_IsValid(b2LoadBodyId(bodyId));
    }

    /// Get the body type: static, kinematic, or dynamic
    static inline b2BodyType getType(uint64_t bodyId) {
        return b2Body_GetType(b2LoadBodyId(bodyId));
    }

    /// Change the body type. This is an expensive operation. This automatically updates the mass
    /// properties regardless of the automatic mass setting.
    static inline void setType(uint64_t bodyId, b2BodyType type) {
        b2Body_SetType(b2LoadBodyId(bodyId), type);
    }

    /// Set the body name. Up to 31 characters excluding 0 termination.
    static inline void setName(uint64_t bodyId, const char* name) {
        b2Body_SetName(b2LoadBodyId(bodyId), name);
    }

    /// Get the body name. May be null.
    static inline const char* getName(uint64_t bodyId) {
        return b2Body_GetName(b2LoadBodyId(bodyId));
    }

    /// Set the user data for a body
    static inline void setUserData(uint64_t bodyId, void* userData) {
        b2Body_SetUserData(b2LoadBodyId(bodyId), userData);
    }

    /// Get the user data stored in a body
    static inline void* getUserData(uint64_t bodyId) {
        return b2Body_GetUserData(b2LoadBodyId(bodyId));
    }

    /// Get the world position of a body. This is the location of the body origin.
    static inline b2Vec2 getPosition(uint64_t bodyId) {
        return b2Body_GetPosition(b2LoadBodyId(bodyId));
    }

    /// Get the world rotation of a body as a cosine/sine pair (complex number)
    static inline b2Rot getRotation(uint64_t bodyId) {
        return b2Body_GetRotation(b2LoadBodyId(bodyId));
    }

    /// Get the world transform of a body.
    static inline b2Transform getTransform(uint64_t bodyId) {
        return b2Body_GetTransform(b2LoadBodyId(bodyId));
    }

    /// Set the world transform of a body. This acts as a teleport and is fairly expensive.
    /// @note Generally you should create a body with then intended transform.
    /// @see b2BodyDef::position and b2BodyDef::angle
    static inline void setTransform(uint64_t bodyId, b2Vec2 position, b2Rot rotation) {
        b2Body_SetTransform(b2LoadBodyId(bodyId), position, rotation);
    }

    /// Get a local point on a body given a world point
    static inline b2Vec2 getLocalPoint(uint64_t bodyId, b2Vec2 worldPoint) {
        return b2Body_GetLocalPoint(b2LoadBodyId(bodyId), worldPoint);
    }

    /// Get a world point on a body given a local point
    static inline b2Vec2 getWorldPoint(uint64_t bodyId, b2Vec2 localPoint) {
        return b2Body_GetWorldPoint(b2LoadBodyId(bodyId), localPoint);
    }

    /// Get a local vector on a body given a world vector
    static inline b2Vec2 getLocalVector(uint64_t bodyId, b2Vec2 worldVector) {
        return b2Body_GetLocalVector(b2LoadBodyId(bodyId), worldVector);
    }

    /// Get a world vector on a body given a local vector
    static inline b2Vec2 getWorldVector(uint64_t bodyId, b2Vec2 localVector) {
        return b2Body_GetWorldVector(b2LoadBodyId(bodyId), localVector);
    }

    /// Get the linear velocity of a body's center of mass. Usually in meters per second.
    static inline b2Vec2 getLinearVelocity(uint64_t bodyId) {
        return b2Body_GetLinearVelocity(b2LoadBodyId(bodyId));
    }

    /// Get the angular velocity of a body in radians per second
    static inline float getAngularVelocity(uint64_t bodyId) {
        return b2Body_GetAngularVelocity(b2LoadBodyId(bodyId));
    }

    /// Set the linear velocity of a body. Usually in meters per second.
    static inline void setLinearVelocity(uint64_t bodyId, b2Vec2 linearVelocity) {
        b2Body_SetLinearVelocity(b2LoadBodyId(bodyId), linearVelocity);
    }

    /// Set the angular velocity of a body in radians per second
    static inline void setAngularVelocity(uint64_t bodyId, float angularVelocity) {
        b2Body_SetAngularVelocity(b2LoadBodyId(bodyId), angularVelocity);
    }

    /// Set the velocity to reach the given transform after a given time step.
    /// The result will be close but maybe not exact. This is meant for kinematic bodies.
    /// The target is not applied if the velocity would be below the sleep threshold.
    /// This will automatically wake the body if asleep.
    static inline void setTargetTransform(uint64_t bodyId, b2Transform target, float timeStep) {
        b2Body_SetTargetTransform(b2LoadBodyId(bodyId), target, timeStep);
    }

    /// Get the linear velocity of a local point attached to a body. Usually in meters per second.
    static inline b2Vec2 getLocalPointVelocity(uint64_t bodyId, b2Vec2 localPoint) {
        return b2Body_GetLocalPointVelocity(b2LoadBodyId(bodyId), localPoint);
    }

    /// Get the linear velocity of a world point attached to a body. Usually in meters per second.
    static inline b2Vec2 getWorldPointVelocity(uint64_t bodyId, b2Vec2 worldPoint) {
        return b2Body_GetWorldPointVelocity(b2LoadBodyId(bodyId), worldPoint);
    }

    /// Apply a force at a world point. If the force is not applied at the center of mass,
    /// it will generate a torque and affect the angular velocity. This optionally wakes up the body.
    /// The force is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param force The world force vector, usually in newtons (N)
    /// @param point The world position of the point of application
    /// @param wake Option to wake up the body
    static inline void applyForce(uint64_t bodyId, b2Vec2 force, b2Vec2 point, bool wake) {
        b2Body_ApplyForce(b2LoadBodyId(bodyId), force, point, wake);
    }

    /// Apply a force to the center of mass. This optionally wakes up the body.
    /// The force is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param force the world force vector, usually in newtons (N).
    /// @param wake also wake up the body
    static inline void applyForceToCenter(uint64_t bodyId, b2Vec2 force, bool wake) {
        b2Body_ApplyForceToCenter(b2LoadBodyId(bodyId), force, wake);
    }

    /// Apply a torque. This affects the angular velocity without affecting the linear velocity.
    /// This optionally wakes the body. The torque is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param torque about the z-axis (out of the screen), usually in N*m.
    /// @param wake also wake up the body
    static inline void applyTorque(uint64_t bodyId, float torque, bool wake) {
        b2Body_ApplyTorque(b2LoadBodyId(bodyId), torque, wake);
    }

    /// Apply an impulse at a point. This immediately modifies the velocity.
    /// It also modifies the angular velocity if the point of application
    /// is not at the center of mass. This optionally wakes the body.
    /// The impulse is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param impulse the world impulse vector, usually in N*s or kg*m/s.
    /// @param point the world position of the point of application.
    /// @param wake also wake up the body
    /// @warning This should be used for one-shot impulses. If you need a steady force,
    /// use a force instead, which will work better with the sub-stepping solver.
    static inline void applyLinearImpulse(uint64_t bodyId, b2Vec2 impulse, b2Vec2 point, bool wake) {
        b2Body_ApplyLinearImpulse(b2LoadBodyId(bodyId), impulse, point, wake);
    }

    /// Apply an impulse to the center of mass. This immediately modifies the velocity.
    /// The impulse is ignored if the body is not awake. This optionally wakes the body.
    /// @param bodyId The body id
    /// @param impulse the world impulse vector, usually in N*s or kg*m/s.
    /// @param wake also wake up the body
    /// @warning This should be used for one-shot impulses. If you need a steady force,
    /// use a force instead, which will work better with the sub-stepping solver.
    static inline void applyLinearImpulseToCenter(uint64_t bodyId, b2Vec2 impulse, bool wake) {
        b2Body_ApplyLinearImpulseToCenter(b2LoadBodyId(bodyId), impulse, wake);
    }

    /// Apply an angular impulse. The impulse is ignored if the body is not awake.
    /// This optionally wakes the body.
    /// @param bodyId The body id
    /// @param impulse the angular impulse, usually in units of kg*m*m/s
    /// @param wake also wake up the body
    /// @warning This should be used for one-shot impulses. If you need a steady force,
    /// use a force instead, which will work better with the sub-stepping solver.
    static inline void applyAngularImpulse(uint64_t bodyId, float impulse, bool wake) {
        b2Body_ApplyAngularImpulse(b2LoadBodyId(bodyId), impulse, wake);
    }

    /// Get the mass of the body, usually in kilograms
    static inline float getMass(uint64_t bodyId) {
        return b2Body_GetMass(b2LoadBodyId(bodyId));
    }

    /// Get the rotational inertia of the body, usually in kg*m^2
    static inline float getRotationalInertia(uint64_t bodyId) {
        return b2Body_GetRotationalInertia(b2LoadBodyId(bodyId));
    }

    /// Get the center of mass position of the body in local space
    static inline b2Vec2 getLocalCenterOfMass(uint64_t bodyId) {
        return b2Body_GetLocalCenterOfMass(b2LoadBodyId(bodyId));
    }

    /// Get the center of mass position of the body in world space
    static inline b2Vec2 getWorldCenterOfMass(uint64_t bodyId) {
        return b2Body_GetWorldCenterOfMass(b2LoadBodyId(bodyId));
    }

    /// Override the body's mass properties. Normally this is computed automatically using the
    /// shape geometry and density. This information is lost if a shape is added or removed or if the
    /// body type changes.
    static inline void setMassData(uint64_t bodyId, b2MassData massData) {
        b2Body_SetMassData(b2LoadBodyId(bodyId), massData);
    }

    /// Get the mass data for a body
    static inline b2MassData getMassData(uint64_t bodyId) {
        return b2Body_GetMassData(b2LoadBodyId(bodyId));
    }

    /// This update the mass properties to the sum of the mass properties of the shapes.
    /// This normally does not need to be called unless you called SetMassData to override
    /// the mass and you later want to reset the mass.
    /// You may also use this when automatic mass computation has been disabled.
    /// You should call this regardless of body type.
    /// Note that sensor shapes may have mass.
    static inline void applyMassFromShapes(uint64_t bodyId) {
        b2Body_ApplyMassFromShapes(b2LoadBodyId(bodyId));
    }

    /// Adjust the linear damping. Normally this is set in b2BodyDef before creation.
    static inline void setLinearDamping(uint64_t bodyId, float linearDamping) {
        b2Body_SetLinearDamping(b2LoadBodyId(bodyId), linearDamping);
    }

    /// Get the current linear damping.
    static inline float getLinearDamping(uint64_t bodyId) {
        return b2Body_GetLinearDamping(b2LoadBodyId(bodyId));
    }

    /// Adjust the angular damping. Normally this is set in b2BodyDef before creation.
    static inline void setAngularDamping(uint64_t bodyId, float angularDamping) {
        b2Body_SetAngularDamping(b2LoadBodyId(bodyId), angularDamping);
    }

    /// Get the current angular damping.
    static inline float getAngularDamping(uint64_t bodyId) {
        return b2Body_GetAngularDamping(b2LoadBodyId(bodyId));
    }

    /// Adjust the gravity scale. Normally this is set in b2BodyDef before creation.
    /// @see b2BodyDef::gravityScale
    static inline void setGravityScale(uint64_t bodyId, float gravityScale) {
        b2Body_SetGravityScale(b2LoadBodyId(bodyId), gravityScale);
    }

    /// Get the current gravity scale
    static inline float getGravityScale(uint64_t bodyId) {
        return b2Body_GetGravityScale(b2LoadBodyId(bodyId));
    }

    /// @return true if this body is awake
    static inline bool isAwake(uint64_t bodyId) {
        return b2Body_IsAwake(b2LoadBodyId(bodyId));
    }

    /// Wake a body from sleep. This wakes the entire island the body is touching.
    /// @warning Putting a body to sleep will put the entire island of bodies touching this body to sleep,
    /// which can be expensive and possibly unintuitive.
    static inline void setAwake(uint64_t bodyId, bool awake) {
        b2Body_SetAwake(b2LoadBodyId(bodyId), awake);
    }

    /// Enable or disable sleeping for this body. If sleeping is disabled the body will wake.
    static inline void enableSleep(uint64_t bodyId, bool enableSleep) {
        b2Body_EnableSleep(b2LoadBodyId(bodyId), enableSleep);
    }

    /// Returns true if sleeping is enabled for this body
    static inline bool isSleepEnabled(uint64_t bodyId) {
        return b2Body_IsSleepEnabled(b2LoadBodyId(bodyId));
    }

    /// Set the sleep threshold, usually in meters per second
    static inline void setSleepThreshold(uint64_t bodyId, float sleepThreshold) {
        b2Body_SetSleepThreshold(b2LoadBodyId(bodyId), sleepThreshold);
    }

    /// Get the sleep threshold, usually in meters per second.
    static inline float getSleepThreshold(uint64_t bodyId) {
        return b2Body_GetSleepThreshold(b2LoadBodyId(bodyId));
    }

    /// Returns true if this body is enabled
    static inline bool isEnabled(uint64_t bodyId) {
        return b2Body_IsEnabled(b2LoadBodyId(bodyId));
    }

    /// Disable a body by removing it completely from the simulation. This is expensive.
    static inline void disable(uint64_t bodyId) {
        b2Body_Disable(b2LoadBodyId(bodyId));
    }

    /// Enable a body by adding it to the simulation. This is expensive.
    static inline void enable(uint64_t bodyId) {
        b2Body_Enable(b2LoadBodyId(bodyId));
    }

    /// Set this body to have fixed rotation. This causes the mass to be reset in all cases.
    static inline void setFixedRotation(uint64_t bodyId, bool flag) {
        b2Body_SetFixedRotation(b2LoadBodyId(bodyId), flag);
    }

    /// Does this body have fixed rotation?
    static inline bool isFixedRotation(uint64_t bodyId) {
        return b2Body_IsFixedRotation(b2LoadBodyId(bodyId));
    }

    /// Set this body to be a bullet. A bullet does continuous collision detection
    /// against dynamic bodies (but not other bullets).
    static inline void setBullet(uint64_t bodyId, bool flag) {
        b2Body_SetBullet(b2LoadBodyId(bodyId), flag);
    }

    /// Is this body a bullet?
    static inline bool isBullet(uint64_t bodyId) {
        return b2Body_IsBullet(b2LoadBodyId(bodyId));
    }

    /// Enable/disable contact events on all shapes.
    /// @see b2ShapeDef::enableContactEvents
    /// @warning changing this at runtime may cause mismatched begin/end touch events
    static inline void enableContactEvents(uint64_t bodyId, bool flag) {
        b2Body_EnableContactEvents(b2LoadBodyId(bodyId), flag);
    }

    /// Enable/disable hit events on all shapes
    /// @see b2ShapeDef::enableHitEvents
    static inline void enableHitEvents(uint64_t bodyId, bool flag) {
        b2Body_EnableHitEvents(b2LoadBodyId(bodyId), flag);
    }

    /// Get the world that owns this body
    static inline b2WorldId getWorld(uint64_t bodyId) {
        return b2Body_GetWorld(b2LoadBodyId(bodyId));
    }

    /// Get the number of shapes on this body
    static inline int getShapeCount(uint64_t bodyId) {
        return b2Body_GetShapeCount(b2LoadBodyId(bodyId));
    }

    /// Get the shape ids for all shapes on this body, up to the provided capacity.
    /// @returns the number of shape ids stored in the user array
    static inline int getShapes(uint64_t bodyId, b2ShapeId* shapeArray, int capacity) {
        return b2Body_GetShapes(b2LoadBodyId(bodyId), shapeArray, capacity);
    }

    /// Get the number of joints on this body
    static inline int getJointCount(uint64_t bodyId) {
        return b2Body_GetJointCount(b2LoadBodyId(bodyId));
    }

    /// Get the joint ids for all joints on this body, up to the provided capacity
    /// @returns the number of joint ids stored in the user array
    static inline int getJoints(uint64_t bodyId, b2JointId* jointArray, int capacity) {
        return b2Body_GetJoints(b2LoadBodyId(bodyId), jointArray, capacity);
    }

    /// Get the maximum capacity required for retrieving all the touching contacts on a body
    static inline int getContactCapacity(uint64_t bodyId) {
        return b2Body_GetContactCapacity(b2LoadBodyId(bodyId));
    }

    /// Get the touching contact data for a body.
    /// @note Box2D uses speculative collision so some contact points may be separated.
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    static inline int getContactData(uint64_t bodyId, b2ContactData* contactData, int capacity) {
         return b2Body_GetContactData(b2LoadBodyId(bodyId), contactData, capacity);
    }

    /// Get the current world AABB that contains all the attached shapes. Note that this may not encompass the body origin.
    /// If there are no shapes attached then the returned AABB is empty and centered on the body origin.
    static inline b2AABB computeAABB(uint64_t bodyId) {
        return b2Body_ComputeAABB(b2LoadBodyId(bodyId));
    }
};