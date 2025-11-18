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
    /// b2BodyId myBodyId = b2CreateBody(myWorldId, &bodyDef);
    /// @endcode
    /// @warning This function is locked during callbacks.
    static inline void createBody(b2WorldId worldId, b2BodyDef* def, b2BodyId& result) {
        result = b2CreateBody(worldId, def);
    }

    /// Destroy a rigid body given an id. This destroys all shapes and joints attached to the body.
    /// Do not keep references to the associated shapes and joints.
    static inline void destroyBody(b2BodyId bodyId) {
        b2DestroyBody(bodyId);
    }

    /// Body identifier validation. Can be used to detect orphaned ids. Provides validation for up to 64K allocations.
    static inline bool isValid(b2BodyId id) {
        return b2Body_IsValid(id);
    }

    /// Get the body type: static, kinematic, or dynamic
    static inline b2BodyType getType(b2BodyId bodyId) {
        return b2Body_GetType(bodyId);
    }

    /// Change the body type. This is an expensive operation. This automatically updates the mass
    /// properties regardless of the automatic mass setting.
    static inline void setType(b2BodyId bodyId, b2BodyType type) {
        b2Body_SetType(bodyId, type);
    }

    /// Set the body name. Up to 31 characters excluding 0 termination.
    static inline void setName(b2BodyId bodyId, const char* name) {
        b2Body_SetName(bodyId, name);
    }

    /// Get the body name. May be null.
    static inline const char* getName(b2BodyId bodyId) {
        return b2Body_GetName(bodyId);
    }

    /// Set the user data for a body
    static inline void setUserData(b2BodyId bodyId, void* userData) {
        b2Body_SetUserData(bodyId, userData);
    }

    /// Get the user data stored in a body
    static inline void* getUserData(b2BodyId bodyId) {
        return b2Body_GetUserData(bodyId);
    }

    /// Get the world position of a body. This is the location of the body origin.
    static inline b2Vec2 getPosition(b2BodyId bodyId) {
        return b2Body_GetPosition(bodyId);
    }

    /// Get the world rotation of a body as a cosine/sine pair (complex number)
    static inline b2Rot getRotation(b2BodyId bodyId) {
        return b2Body_GetRotation(bodyId);
    }

    /// Get the world transform of a body.
    static inline b2Transform getTransform(b2BodyId bodyId) {
        return b2Body_GetTransform(bodyId);
    }

    /// Set the world transform of a body. This acts as a teleport and is fairly expensive.
    /// @note Generally you should create a body with then intended transform.
    /// @see b2BodyDef::position and b2BodyDef::angle
    static inline void setTransform(b2BodyId bodyId, b2Vec2 position, b2Rot rotation) {
        b2Body_SetTransform(bodyId, position, rotation);
    }

    /// Get a local point on a body given a world point
    static inline b2Vec2 getLocalPoint(b2BodyId bodyId, b2Vec2 worldPoint) {
        return b2Body_GetLocalPoint(bodyId, worldPoint);
    }

    /// Get a world point on a body given a local point
    static inline b2Vec2 getWorldPoint(b2BodyId bodyId, b2Vec2 localPoint) {
        return b2Body_GetWorldPoint(bodyId, localPoint);
    }

    /// Get a local vector on a body given a world vector
    static inline b2Vec2 getLocalVector(b2BodyId bodyId, b2Vec2 worldVector) {
        return b2Body_GetLocalVector(bodyId, worldVector);
    }

    /// Get a world vector on a body given a local vector
    static inline b2Vec2 getWorldVector(b2BodyId bodyId, b2Vec2 localVector) {
        return b2Body_GetWorldVector(bodyId, localVector);
    }

    /// Get the linear velocity of a body's center of mass. Usually in meters per second.
    static inline b2Vec2 getLinearVelocity(b2BodyId bodyId) {
        return b2Body_GetLinearVelocity(bodyId);
    }

    /// Get the angular velocity of a body in radians per second
    static inline float getAngularVelocity(b2BodyId bodyId) {
        return b2Body_GetAngularVelocity(bodyId);
    }

    /// Set the linear velocity of a body. Usually in meters per second.
    static inline void setLinearVelocity(b2BodyId bodyId, b2Vec2 linearVelocity) {
        b2Body_SetLinearVelocity(bodyId, linearVelocity);
    }

    /// Set the angular velocity of a body in radians per second
    static inline void setAngularVelocity(b2BodyId bodyId, float angularVelocity) {
        b2Body_SetAngularVelocity(bodyId, angularVelocity);
    }

    /// Set the velocity to reach the given transform after a given time step.
    /// The result will be close but maybe not exact. This is meant for kinematic bodies.
    /// The target is not applied if the velocity would be below the sleep threshold.
    /// This will automatically wake the body if asleep.
    static inline void setTargetTransform(b2BodyId bodyId, b2Transform target, float timeStep) {
        b2Body_SetTargetTransform(bodyId, target, timeStep);
    }

    /// Get the linear velocity of a local point attached to a body. Usually in meters per second.
    static inline b2Vec2 getLocalPointVelocity(b2BodyId bodyId, b2Vec2 localPoint) {
        return b2Body_GetLocalPointVelocity(bodyId, localPoint);
    }

    /// Get the linear velocity of a world point attached to a body. Usually in meters per second.
    static inline b2Vec2 getWorldPointVelocity(b2BodyId bodyId, b2Vec2 worldPoint) {
        return b2Body_GetWorldPointVelocity(bodyId, worldPoint);
    }

    /// Apply a force at a world point. If the force is not applied at the center of mass,
    /// it will generate a torque and affect the angular velocity. This optionally wakes up the body.
    /// The force is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param force The world force vector, usually in newtons (N)
    /// @param point The world position of the point of application
    /// @param wake Option to wake up the body
    static inline void applyForce(b2BodyId bodyId, b2Vec2 force, b2Vec2 point, bool wake) {
        b2Body_ApplyForce(bodyId, force, point, wake);
    }

    /// Apply a force to the center of mass. This optionally wakes up the body.
    /// The force is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param force the world force vector, usually in newtons (N).
    /// @param wake also wake up the body
    static inline void applyForceToCenter(b2BodyId bodyId, b2Vec2 force, bool wake) {
        b2Body_ApplyForceToCenter(bodyId, force, wake);
    }

    /// Apply a torque. This affects the angular velocity without affecting the linear velocity.
    /// This optionally wakes the body. The torque is ignored if the body is not awake.
    /// @param bodyId The body id
    /// @param torque about the z-axis (out of the screen), usually in N*m.
    /// @param wake also wake up the body
    static inline void applyTorque(b2BodyId bodyId, float torque, bool wake) {
        b2Body_ApplyTorque(bodyId, torque, wake);
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
    static inline void applyLinearImpulse(b2BodyId bodyId, b2Vec2 impulse, b2Vec2 point, bool wake) {
        b2Body_ApplyLinearImpulse(bodyId, impulse, point, wake);
    }

    /// Apply an impulse to the center of mass. This immediately modifies the velocity.
    /// The impulse is ignored if the body is not awake. This optionally wakes the body.
    /// @param bodyId The body id
    /// @param impulse the world impulse vector, usually in N*s or kg*m/s.
    /// @param wake also wake up the body
    /// @warning This should be used for one-shot impulses. If you need a steady force,
    /// use a force instead, which will work better with the sub-stepping solver.
    static inline void applyLinearImpulseToCenter(b2BodyId bodyId, b2Vec2 impulse, bool wake) {
        b2Body_ApplyLinearImpulseToCenter(bodyId, impulse, wake);
    }

    /// Apply an angular impulse. The impulse is ignored if the body is not awake.
    /// This optionally wakes the body.
    /// @param bodyId The body id
    /// @param impulse the angular impulse, usually in units of kg*m*m/s
    /// @param wake also wake up the body
    /// @warning This should be used for one-shot impulses. If you need a steady force,
    /// use a force instead, which will work better with the sub-stepping solver.
    static inline void applyAngularImpulse(b2BodyId bodyId, float impulse, bool wake) {
        b2Body_ApplyAngularImpulse(bodyId, impulse, wake);
    }

    /// Get the mass of the body, usually in kilograms
    static inline float getMass(b2BodyId bodyId) {
        return b2Body_GetMass(bodyId);
    }

    /// Get the rotational inertia of the body, usually in kg*m^2
    static inline float getRotationalInertia(b2BodyId bodyId) {
        return b2Body_GetRotationalInertia(bodyId);
    }

    /// Get the center of mass position of the body in local space
    static inline b2Vec2 getLocalCenterOfMass(b2BodyId bodyId) {
        return b2Body_GetLocalCenterOfMass(bodyId);
    }

    /// Get the center of mass position of the body in world space
    static inline b2Vec2 getWorldCenterOfMass(b2BodyId bodyId) {
        return b2Body_GetWorldCenterOfMass(bodyId);
    }

    /// Override the body's mass properties. Normally this is computed automatically using the
    /// shape geometry and density. This information is lost if a shape is added or removed or if the
    /// body type changes.
    static inline void setMassData(b2BodyId bodyId, b2MassData massData) {
        b2Body_SetMassData(bodyId, massData);
    }

    /// Get the mass data for a body
    static inline b2MassData getMassData(b2BodyId bodyId) {
        return b2Body_GetMassData(bodyId);
    }

    /// This update the mass properties to the sum of the mass properties of the shapes.
    /// This normally does not need to be called unless you called SetMassData to override
    /// the mass and you later want to reset the mass.
    /// You may also use this when automatic mass computation has been disabled.
    /// You should call this regardless of body type.
    /// Note that sensor shapes may have mass.
    static inline void applyMassFromShapes(b2BodyId bodyId) {
        b2Body_ApplyMassFromShapes(bodyId);
    }

    /// Adjust the linear damping. Normally this is set in b2BodyDef before creation.
    static inline void setLinearDamping(b2BodyId bodyId, float linearDamping) {
        b2Body_SetLinearDamping(bodyId, linearDamping);
    }

    /// Get the current linear damping.
    static inline float getLinearDamping(b2BodyId bodyId) {
        return b2Body_GetLinearDamping(bodyId);
    }

    /// Adjust the angular damping. Normally this is set in b2BodyDef before creation.
    static inline void setAngularDamping(b2BodyId bodyId, float angularDamping) {
        b2Body_SetAngularDamping(bodyId, angularDamping);
    }

    /// Get the current angular damping.
    static inline float getAngularDamping(b2BodyId bodyId) {
        return b2Body_GetAngularDamping(bodyId);
    }

    /// Adjust the gravity scale. Normally this is set in b2BodyDef before creation.
    /// @see b2BodyDef::gravityScale
    static inline void setGravityScale(b2BodyId bodyId, float gravityScale) {
        b2Body_SetGravityScale(bodyId, gravityScale);
    }

    /// Get the current gravity scale
    static inline float getGravityScale(b2BodyId bodyId) {
        return b2Body_GetGravityScale(bodyId);
    }

    /// @return true if this body is awake
    static inline bool isAwake(b2BodyId bodyId) {
        return b2Body_IsAwake(bodyId);
    }

    /// Wake a body from sleep. This wakes the entire island the body is touching.
    /// @warning Putting a body to sleep will put the entire island of bodies touching this body to sleep,
    /// which can be expensive and possibly unintuitive.
    static inline void setAwake(b2BodyId bodyId, bool awake) {
        b2Body_SetAwake(bodyId, awake);
    }

    /// Enable or disable sleeping for this body. If sleeping is disabled the body will wake.
    static inline void enableSleep(b2BodyId bodyId, bool enableSleep) {
        b2Body_EnableSleep(bodyId, enableSleep);
    }

    /// Returns true if sleeping is enabled for this body
    static inline bool isSleepEnabled(b2BodyId bodyId) {
        return b2Body_IsSleepEnabled(bodyId);
    }

    /// Set the sleep threshold, usually in meters per second
    static inline void setSleepThreshold(b2BodyId bodyId, float sleepThreshold) {
        b2Body_SetSleepThreshold(bodyId, sleepThreshold);
    }

    /// Get the sleep threshold, usually in meters per second.
    static inline float getSleepThreshold(b2BodyId bodyId) {
        return b2Body_GetSleepThreshold(bodyId);
    }

    /// Returns true if this body is enabled
    static inline bool isEnabled(b2BodyId bodyId) {
        return b2Body_IsEnabled(bodyId);
    }

    /// Disable a body by removing it completely from the simulation. This is expensive.
    static inline void disable(b2BodyId bodyId) {
        b2Body_Disable(bodyId);
    }

    /// Enable a body by adding it to the simulation. This is expensive.
    static inline void enable(b2BodyId bodyId) {
        b2Body_Enable(bodyId);
    }

    /// Set this body to have fixed rotation. This causes the mass to be reset in all cases.
    static inline void setFixedRotation(b2BodyId bodyId, bool flag) {
        b2Body_SetFixedRotation(bodyId, flag);
    }

    /// Does this body have fixed rotation?
    static inline bool isFixedRotation(b2BodyId bodyId) {
        return b2Body_IsFixedRotation(bodyId);
    }

    /// Set this body to be a bullet. A bullet does continuous collision detection
    /// against dynamic bodies (but not other bullets).
    static inline void setBullet(b2BodyId bodyId, bool flag) {
        b2Body_SetBullet(bodyId, flag);
    }

    /// Is this body a bullet?
    static inline bool isBullet(b2BodyId bodyId) {
        return b2Body_IsBullet(bodyId);
    }

    /// Enable/disable contact events on all shapes.
    /// @see b2ShapeDef::enableContactEvents
    /// @warning changing this at runtime may cause mismatched begin/end touch events
    static inline void enableContactEvents(b2BodyId bodyId, bool flag) {
        b2Body_EnableContactEvents(bodyId, flag);
    }

    /// Enable/disable hit events on all shapes
    /// @see b2ShapeDef::enableHitEvents
    static inline void enableHitEvents(b2BodyId bodyId, bool flag) {
        b2Body_EnableHitEvents(bodyId, flag);
    }

    /// Get the world that owns this body
    static inline b2WorldId getWorld(b2BodyId bodyId) {
        return b2Body_GetWorld(bodyId);
    }

    /// Get the number of shapes on this body
    static inline int getShapeCount(b2BodyId bodyId) {
        return b2Body_GetShapeCount(bodyId);
    }

    /// Get the shape ids for all shapes on this body, up to the provided capacity.
    /// @returns the number of shape ids stored in the user array
    static inline int getShapes(b2BodyId bodyId, b2ShapeId* shapeArray, int capacity) {
        return b2Body_GetShapes(bodyId, shapeArray, capacity);
    }

    /// Get the number of joints on this body
    static inline int getJointCount(b2BodyId bodyId) {
        return b2Body_GetJointCount(bodyId);
    }

    /// Get the joint ids for all joints on this body, up to the provided capacity
    /// @returns the number of joint ids stored in the user array
    static inline int getJoints(b2BodyId bodyId, b2JointId* jointArray, int capacity) {
        return b2Body_GetJoints(bodyId, jointArray, capacity);
    }

    /// Get the maximum capacity required for retrieving all the touching contacts on a body
    static inline int getContactCapacity(b2BodyId bodyId) {
        return b2Body_GetContactCapacity(bodyId);
    }

    /// Get the touching contact data for a body.
    /// @note Box2D uses speculative collision so some contact points may be separated.
    /// @returns the number of elements filled in the provided array
    /// @warning do not ignore the return value, it specifies the valid number of elements
    static inline int getContactData(b2BodyId bodyId, b2ContactData* contactData, int capacity) {
         return b2Body_GetContactData(bodyId, contactData, capacity);
    }

    /// Get the current world AABB that contains all the attached shapes. Note that this may not encompass the body origin.
    /// If there are no shapes attached then the returned AABB is empty and centered on the body origin.
    static inline b2AABB computeAABB(b2BodyId bodyId) {
        return b2Body_ComputeAABB(bodyId);
    }
};