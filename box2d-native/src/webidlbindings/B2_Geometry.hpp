#pragma once

#include <box2d/box2d.h>

class B2_Geometry {
    public:
    
    /// The maximum number of vertices on a convex polygon.
    static const uint32_t MAX_POLYGON_VERTICES = B2_MAX_POLYGON_VERTICES;

    /// Validate ray cast input data (NaN, etc)
    static inline bool isValidRay(const b2RayCastInput* input) {
        return b2IsValidRay(input); 
    }

    /// Make a convex polygon from a convex hull. This will assert if the hull is not valid.
    /// @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull
    static inline void makePolygon(const b2Hull* hull, float radius, b2Polygon& result) {
        result = b2MakePolygon(hull, radius);
    }

    /// Make an offset convex polygon from a convex hull. This will assert if the hull is not valid.
    /// @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull
    static inline void makeOffsetPolygon(const b2Hull* hull, b2Vec2 position, b2Rot rotation, b2Polygon& result) {
        result = b2MakeOffsetPolygon(hull, position, rotation);
    }

    /// Make an offset convex polygon from a convex hull. This will assert if the hull is not valid.
    /// @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull
    static inline void makeOffsetRoundedPolygon(const b2Hull* hull, b2Vec2 position, b2Rot rotation, float radius, b2Polygon& result) {
        result = b2MakeOffsetRoundedPolygon(hull, position, rotation, radius);
    }

    /// Make a square polygon, bypassing the need for a convex hull.
    /// @param halfWidth the half-width
    static inline void makeSquare(float halfWidth, b2Polygon& result) {
        result = b2MakeSquare(halfWidth);
    }

    /// Make a box (rectangle) polygon, bypassing the need for a convex hull.
    /// @param halfWidth the half-width (x-axis)
    /// @param halfHeight the half-height (y-axis)
    static inline void makeBox(float halfWidth, float halfHeight, b2Polygon& result) {
        result = b2MakeBox(halfWidth, halfHeight);
    }

    /// Make a rounded box, bypassing the need for a convex hull.
    /// @param halfWidth the half-width (x-axis)
    /// @param halfHeight the half-height (y-axis)
    /// @param radius the radius of the rounded extension
    static inline void makeRoundedBox(float halfWidth, float halfHeight, float radius, b2Polygon& result) {
        result = b2MakeRoundedBox(halfWidth, halfHeight, radius);
    }

    /// Make an offset box, bypassing the need for a convex hull.
    /// @param halfWidth the half-width (x-axis)
    /// @param halfHeight the half-height (y-axis)
    /// @param center the local center of the box
    /// @param rotation the local rotation of the box
    static inline void makeOffsetBox(float halfWidth, float halfHeight, b2Vec2 center, b2Rot rotation, b2Polygon& result) {
        result = b2MakeOffsetBox(halfWidth, halfHeight, center, rotation);
    }

    /// Make an offset rounded box, bypassing the need for a convex hull.
    /// @param halfWidth the half-width (x-axis)
    /// @param halfHeight the half-height (y-axis)
    /// @param center the local center of the box
    /// @param rotation the local rotation of the box
    /// @param radius the radius of the rounded extension
    static inline void makeOffsetRoundedBox(float halfWidth, float halfHeight, b2Vec2 center, b2Rot rotation, float radius, b2Polygon& result) {
        result = b2MakeOffsetRoundedBox(halfWidth, halfHeight, center, rotation, radius);
    }

    /// Transform a polygon. This is useful for transferring a shape from one body to another.
    static inline void transformPolygon(b2Transform transform, const b2Polygon* polygon, b2Polygon& result) {
        result = b2TransformPolygon(transform, polygon);
    }

    /// Compute mass properties of a circle
    static inline b2MassData computeCircleMass(const b2Circle* shape, float density) {
        return b2ComputeCircleMass(shape, density); 
    }

    /// Compute mass properties of a capsule
    static inline b2MassData computeCapsuleMass(const b2Capsule* shape, float density) {
        return b2ComputeCapsuleMass(shape, density); 
    }

    /// Compute mass properties of a polygon
    static inline b2MassData computePolygonMass(const b2Polygon* shape, float density) {
        return b2ComputePolygonMass(shape, density); 
    }

    /// Compute the bounding box of a transformed circle
    static inline b2AABB computeCircleAABB(const b2Circle* shape, b2Transform transform) {
        return b2ComputeCircleAABB(shape, transform); 
    }

    /// Compute the bounding box of a transformed capsule
    static inline b2AABB computeCapsuleAABB(const b2Capsule* shape, b2Transform transform) {
        return b2ComputeCapsuleAABB(shape, transform); 
    }

    /// Compute the bounding box of a transformed polygon
    static inline b2AABB computePolygonAABB(const b2Polygon* shape, b2Transform transform) {
        return b2ComputePolygonAABB(shape, transform); 
    }

    /// Compute the bounding box of a transformed line segment
    static inline b2AABB computeSegmentAABB(const b2Segment* shape, b2Transform transform) {
        return b2ComputeSegmentAABB(shape, transform); 
    }

    /// Test a point for overlap with a circle in local space
    static inline bool pointInCircle(b2Vec2 point, const b2Circle* shape) {
        return b2PointInCircle(point, shape); 
    }

    /// Test a point for overlap with a capsule in local space
    static inline bool pointInCapsule(b2Vec2 point, const b2Capsule* shape) {
        return b2PointInCapsule(point, shape); 
    }

    /// Test a point for overlap with a convex polygon in local space
    static inline bool pointInPolygon(b2Vec2 point, const b2Polygon* shape) {
        return b2PointInPolygon(point, shape); 
    }

    /// Ray cast versus circle shape in local space. Initial overlap is treated as a miss.
    static inline b2CastOutput rayCastCircle(const b2RayCastInput* input, const b2Circle* shape) {
        return b2RayCastCircle(input, shape); 
    }

    /// Ray cast versus capsule shape in local space. Initial overlap is treated as a miss.
    static inline b2CastOutput rayCastCapsule(const b2RayCastInput* input, const b2Capsule* shape) {
        return b2RayCastCapsule(input, shape); 
    }

    /// Ray cast versus segment shape in local space. Optionally treat the segment as one-sided with hits from
    /// the left side being treated as a miss.
    static inline b2CastOutput rayCastSegment(const b2RayCastInput* input, const b2Segment* shape, bool oneSided) {
        return b2RayCastSegment(input, shape, oneSided); 
    }

    /// Ray cast versus polygon shape in local space. Initial overlap is treated as a miss.
    static inline b2CastOutput rayCastPolygon(const b2RayCastInput* input, const b2Polygon* shape) {
        return b2RayCastPolygon(input, shape); 
    }

    /// Shape cast versus a circle. Initial overlap is treated as a miss.
    static inline b2CastOutput shapeCastCircle(const b2ShapeCastInput* input, const b2Circle* shape) {
        return b2ShapeCastCircle(input, shape); 
    }

    /// Shape cast versus a capsule. Initial overlap is treated as a miss.
    static inline b2CastOutput shapeCastCapsule(const b2ShapeCastInput* input, const b2Capsule* shape) {
        return b2ShapeCastCapsule(input, shape); 
    }

    /// Shape cast versus a line segment. Initial overlap is treated as a miss.
    static inline b2CastOutput shapeCastSegment(const b2ShapeCastInput* input, const b2Segment* shape) {
        return b2ShapeCastSegment(input, shape); 
    }

    /// Shape cast versus a convex polygon. Initial overlap is treated as a miss.
    static inline b2CastOutput shapeCastPolygon(const b2ShapeCastInput* input, const b2Polygon* shape) {
        return b2ShapeCastPolygon(input, shape); 
    }

    /// Compute the convex hull of a set of points. Returns an empty hull if it fails.
    /// Some failure cases:
    /// - all points very close together
    /// - all points on a line
    /// - less than 3 points
    /// - more than B2_MAX_POLYGON_VERTICES points
    /// This welds close points and removes collinear points.
    /// @warning Do not modify a hull once it has been computed
    static inline void computeHull(const b2Vec2* points, int count, b2Hull& result) {
        result = b2ComputeHull(points, count);
    }

    /// This determines if a hull is valid. Checks for:
    /// - convexity
    /// - collinear points
    /// This is expensive and should not be called at runtime.
    static inline bool validateHull(const b2Hull* hull) {
        return b2ValidateHull(hull); 
    }
};