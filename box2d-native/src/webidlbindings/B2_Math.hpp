#pragma once

#include <box2d/box2d.h>

class B2_Vec2 {
    public:
    /// Vector dot product
    static inline float dot(b2Vec2 a, b2Vec2 b) {
        return b2Dot(a, b);
    }

    /// Vector cross product. In 2D this yields a scalar.
    static inline float cross(b2Vec2 a, b2Vec2 b) {
        return b2Cross(a, b);
    }

    /// Perform the cross product on a vector and a scalar. In 2D this produces a vector.
    static inline void crossVS(b2Vec2 v, float s, b2Vec2& result) {
        result = b2CrossVS(v, s);
    }

    /// Perform the cross product on a scalar and a vector. In 2D this produces a vector.
    static inline void crossSV(float s, b2Vec2 v, b2Vec2& result) {
        result = b2CrossSV(s, v);
    }

    /// Get a left pointing perpendicular vector. Equivalent to b2CrossSV(1.0f, v)
    static inline void leftPerp(b2Vec2 v, b2Vec2& result) {
        result = b2LeftPerp(v);
    }

    /// Get a right pointing perpendicular vector. Equivalent to b2CrossVS(v, 1.0f)
    static inline void rightPerp(b2Vec2 v, b2Vec2& result) {
        result = b2RightPerp(v);
    }

    /// Vector addition
    static inline void add(b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Add(a, b);
    }

    /// Vector subtraction
    static inline void sub(b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Sub(a, b);
    }

    /// Vector negation
    static inline void neg(b2Vec2 a, b2Vec2& result) {
        result = b2Neg(a);
    }

    /// Vector linear interpolation
    /// https://fgiesen.wordpress.com/2012/08/15/linear-interpolation-past-present-and-future/
    static inline void lerp(b2Vec2 a, b2Vec2 b, float t, b2Vec2& result) {
        result = b2Lerp(a, b, t);
    }

    /// Component-wise multiplication
    static inline void mul(b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Mul(a, b);
    }

    /// Multiply a scalar and vector
    static inline void mulSV(float s, b2Vec2 v, b2Vec2& result) {
        result = b2MulSV(s, v);
    }

    /// a + s * b
    static inline void mulAdd(b2Vec2 a, float s, b2Vec2 b, b2Vec2& result) {
        result = b2MulAdd(a, s, b);
    }

    /// a - s * b
    static inline void mulSub(b2Vec2 a, float s, b2Vec2 b, b2Vec2& result) {
        result = b2MulSub(a, s, b);
    }

    /// Component-wise absolute vector
    static inline void abs(b2Vec2 a, b2Vec2& result) {
        result = b2Abs(a);
    }

    /// Component-wise minimum vector
    static inline void min(b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Min(a, b);
    }

    /// Component-wise maximum vector
    static inline void max(b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Max(a, b);
    }

    /// Component-wise clamp vector v into the range [a, b]
    static inline void clamp(b2Vec2 v, b2Vec2 a, b2Vec2 b, b2Vec2& result) {
        result = b2Clamp(v, a, b);
    }

    /// Get the length of this vector (the norm)
    static inline float length(b2Vec2 v) {
        return b2Length(v);
    }

    /// Get the distance between two points
    static inline float distance(b2Vec2 a, b2Vec2 b) {
        return b2Distance(a, b);
    }

    /// Convert a vector into a unit vector if possible, otherwise returns the zero vector.
    static inline void normalize(b2Vec2 v, b2Vec2& result) {
        result = b2Normalize(v);
    }

    /// Determines if the provided vector is normalized (norm(a) == 1).
    static inline bool isNormalized(b2Vec2 a) {
        return b2IsNormalized(a);
    }

    /// Convert a vector into a unit vector if possible, otherwise returns the zero vector. Also
    /// outputs the length.
    static inline float getLengthAndNormalize(b2Vec2 v, b2Vec2& result) {
        float length;
        result = b2GetLengthAndNormalize(&length, v);
        return length;
    }

    /// Get the length squared of this vector
    static inline float lengthSquared(b2Vec2 v) {
        return b2LengthSquared(v);
    }

    /// Get the distance squared between points
    static inline float distanceSquared(b2Vec2 a, b2Vec2 b) {
        return b2DistanceSquared(a, b);
    }

    /// Is this a valid vector? Not NaN or infinity.
    static inline bool isValid(b2Vec2 v) {
        return b2IsValidVec2(v);
    }
};

class B2_Rot {
    public:
    /// Get the angle in radians in the range [-pi, pi]
    static inline float getAngle(b2Rot q) {
        return b2Rot_GetAngle(q);
    }

    /// Get the x-axis
    static inline void getXAxis(b2Rot q, b2Vec2& result) {
        result = b2Rot_GetXAxis(q);
    }

    /// Get the y-axis
    static inline void getYAxis(b2Rot q, b2Vec2& result) {
        result = b2Rot_GetYAxis(q);
    }

    /// Make a rotation using an angle in radians
    static inline void makeRot(float radians, b2Rot& result) {
        result = b2MakeRot(radians);
    }

    /// Normalize rotation
    static inline void normalize(b2Rot q, b2Rot& result) {
        result = b2NormalizeRot(q);
    }

    /// Is this rotation normalized?
    static inline bool isNormalized(b2Rot q) {
        return b2IsNormalizedRot(q);
    }

    /// Integrate rotation from angular velocity
    /// @param q1 initial rotation
    /// @param deltaAngle the angular displacement in radians
    static inline void integrateRotation(b2Rot q1, float deltaAngle, b2Rot& result) {
        result = b2IntegrateRotation(q1, deltaAngle);
    }

    /// Normalized linear interpolation
    /// https://fgiesen.wordpress.com/2012/08/15/linear-interpolation-past-present-and-future/
    /// https://web.archive.org/web/20170825184056/http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/
    static inline void nLerp(b2Rot q1, b2Rot q2, float t, b2Rot& result) {
        result = b2NLerp(q1, q2, t);
    }

    /// Multiply two rotations: q * r
    static inline void mulRot(b2Rot q, b2Rot r, b2Rot& result) {
        result = b2MulRot(q, r);
    }

    /// Transpose multiply two rotations: qT * r
    static inline void invMulRot(b2Rot q, b2Rot r, b2Rot& result) {
        result = b2InvMulRot(q, r);
    }

    /// relative angle between b and a (rot_b * inv(rot_a))
    static inline float relativeAngle(b2Rot b, b2Rot a) {
        return b2RelativeAngle(b, a);
    }

    /// Convert any angle into the range [-pi, pi]
    static inline float unwindAngle(float radians) {
        return b2UnwindAngle(radians);
    }

    /// Rotate a vector
    static inline void rotateVector(b2Rot q, b2Vec2 v, b2Vec2& result) {
        result = b2RotateVector(q, v);
    }

    /// Inverse rotate a vector
    static inline void invRotateVector(b2Rot q, b2Vec2 v, b2Vec2& result) {
        result = b2InvRotateVector(q, v);
    }

    /// Compute the angular velocity necessary to rotate between two rotations over a give time
    /// @param q1 initial rotation
    /// @param q2 final rotation
    /// @param inv_h inverse time step
    static inline float computeAngularVelocity(b2Rot q1, b2Rot q2, float inv_h) {
        return b2ComputeAngularVelocity(q1, q2, inv_h);
    }

    /// Compute the rotation between two unit vectors
    static inline void computeRotationBetweenUnitVectors(b2Vec2 v1, b2Vec2 v2, b2Rot& result) {
        result = b2ComputeRotationBetweenUnitVectors(v1, v2);
    }

    /// Is this a valid rotation? Not NaN or infinity. Is normalized.
    static inline bool isValid(b2Rot q) {
        return b2IsValidRotation(q);
    }
};

class B2_Transform {
    public:
    /// Transform a point (e.g. local space to world space)
    static inline void transformPoint(b2Transform t, b2Vec2 p, b2Vec2& result) {
        result = b2TransformPoint(t, p);
    }

    /// Inverse transform a point (e.g. world space to local space)
    static inline void invTransformPoint(b2Transform t, b2Vec2 p, b2Vec2& result) {
        result = b2InvTransformPoint(t, p);
    }

    /// Multiply two transforms. If the result is applied to a point p local to frame B,
    /// the transform would first convert p to a point local to frame A, then into a point
    /// in the world frame.
    /// v2 = A.q.Rot(B.q.Rot(v1) + B.p) + A.p
    ///    = (A.q * B.q).Rot(v1) + A.q.Rot(B.p) + A.p
    static inline void mulTransforms(b2Transform A, b2Transform B, b2Transform& result) {
        result = b2MulTransforms(A, B);
    }

    /// Creates a transform that converts a local point in frame B to a local point in frame A.
    /// v2 = A.q' * (B.q * v1 + B.p - A.p)
    ///    = A.q' * B.q * v1 + A.q' * (B.p - A.p)
    static inline void invMulTransforms(b2Transform A, b2Transform B, b2Transform& result) {
        result = b2InvMulTransforms(A, B);
    }
};

class B2_Mat22 {
    public:
    /// Multiply a 2-by-2 matrix times a 2D vector
    static inline void mulMV(b2Mat22 A, b2Vec2 v, b2Vec2& result) {
        result = b2MulMV(A, v);
    }

    /// Get the inverse of a 2-by-2 matrix
    static inline void getInverse22(b2Mat22 A, b2Mat22& result) {
        result = b2GetInverse22(A);
    }

    /// Solve A * x = b, where b is a column vector. This is more efficient
    /// than computing the inverse in one-shot cases.
    static inline void solve22(b2Mat22 A, b2Vec2 b, b2Vec2& result) {
        result = b2Solve22(A, b);
    }
};

class B2_AABB {
    public:
    /// Does a fully contain b
    static inline bool contains(b2AABB a, b2AABB b) {
        return b2AABB_Contains(a, b);
    }

    /// Get the center of the AABB.
    static inline void center(b2AABB a, b2Vec2& result) {
        result = b2AABB_Center(a);
    }

    /// Get the extents of the AABB (half-widths).
    static inline void extents(b2AABB a, b2Vec2& result) {
        result = b2AABB_Extents(a);
    }

    /// Union of two AABBs
    static inline void unionAABB(b2AABB a, b2AABB b, b2AABB& result) {
        result = b2AABB_Union(a, b);
    }

    /// Do a and b overlap
    static inline bool overlaps(b2AABB a, b2AABB b) {
        return b2AABB_Overlaps(a, b);
    }

    /// Compute the bounding box of an array of circles
    static inline void makeAABB(const b2Vec2* points, int count, float radius, b2AABB& result) {
        result = b2MakeAABB(points, count, radius);
    }

    /// Is this a valid bounding box? Not Nan or infinity. Upper bound greater than or equal to lower bound.
    static inline bool isValid(b2AABB aabb) {
        return b2IsValidAABB(aabb);
    }
};

class B2_Plane {
    public:
    /// Signed separation of a point from a plane
    /// separation = dot(normal, point) - offset
    static inline float planeSeparation(b2Plane plane, b2Vec2 point) {
        return b2PlaneSeparation(plane, point);
    }

    /// Is this a valid plane? Normal is a unit vector. Not Nan or infinity.
    static inline bool isValid(b2Plane a) {
        return b2IsValidPlane(a);
    }
};

class B2_Math {
    public:
    /// Compute the cosine and sine of an angle in radians. Implemented
    /// for cross-platform determinism.
    static inline void computeCosSin(float radians, b2CosSin& result) {
        result = b2ComputeCosSin(radians);
    }

    /// One-dimensional mass-spring-damper simulation. Returns the new velocity given the position and time step.
    /// You can then compute the new position using:
    /// position += timeStep * newVelocity
    /// This drives towards a zero position. By using implicit integration we get a stable solution
    /// that doesn't require transcendental functions.
    static inline float springDamper(float hertz, float dampingRatio, float position, float velocity, float timeStep) {
        return b2SpringDamper(hertz, dampingRatio, position, velocity, timeStep);
    }

    /// Box2D bases all length units on meters, but you may need different units for your game.
    /// You can set this value to use different units. This should be done at application startup
    /// and only modified once. Default value is 1.
    /// @warning This must be modified before any calls to Box2D
    static inline void setLengthUnitsPerMeter(float lengthUnits) {
        b2SetLengthUnitsPerMeter(lengthUnits);
    }

    /// Get the current length units per meter.
    static inline float getLengthUnitsPerMeter() {
        return b2GetLengthUnitsPerMeter();
    }
};
