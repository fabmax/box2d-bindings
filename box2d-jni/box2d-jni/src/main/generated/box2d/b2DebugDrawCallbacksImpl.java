package box2d;


public class b2DebugDrawCallbacksImpl extends b2DebugDrawCallbacks {

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static b2DebugDrawCallbacksImpl wrapPointer(long address) {
        return address != 0L ? new b2DebugDrawCallbacksImpl(address) : null;
    }
    
    public static b2DebugDrawCallbacksImpl arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected b2DebugDrawCallbacksImpl(long address) {
        super(address);
    }

    protected b2DebugDrawCallbacksImpl() {
        address = _b2DebugDrawCallbacksImpl();
    }
    private native long _b2DebugDrawCallbacksImpl();
    
    // Destructor
    public void destroy() {
        if (address == 0L) {
            throw new IllegalStateException(this + " is already deleted");
        }
        if (isExternallyAllocated) {
            throw new IllegalStateException(this + " is externally allocated and cannot be manually destroyed");
        }
        _destroy(address);
        address = 0L;
    }
    private static native void _destroy(long address);

    // Functions

    /*
     * Called from native code
     */
    private void _drawPolygon(long vertices, int vertexCount, int color) {
        drawPolygon(b2Vec2.wrapPointer(vertices), vertexCount, color);
    }

    /**
     * @param vertices    WebIDL type: {@link b2Vec2} [Const]
     * @param vertexCount WebIDL type: long
     * @param color       WebIDL type: long
     */
    public void drawPolygon(b2Vec2 vertices, int vertexCount, int color) { }

    /*
     * Called from native code
     */
    private void _drawSolidPolygon(long transform, long vertices, int vertexCount, float radius, int color) {
        drawSolidPolygon(b2Transform.wrapPointer(transform), b2Vec2.wrapPointer(vertices), vertexCount, radius, color);
    }

    /**
     * @param transform   WebIDL type: {@link b2Transform} [Ref]
     * @param vertices    WebIDL type: {@link b2Vec2} [Const]
     * @param vertexCount WebIDL type: long
     * @param radius      WebIDL type: float
     * @param color       WebIDL type: long
     */
    public void drawSolidPolygon(b2Transform transform, b2Vec2 vertices, int vertexCount, float radius, int color) { }

    /*
     * Called from native code
     */
    private void _drawCircle(long center, float radius, int color) {
        drawCircle(b2Vec2.wrapPointer(center), radius, color);
    }

    /**
     * @param center WebIDL type: {@link b2Vec2} [Ref]
     * @param radius WebIDL type: float
     * @param color  WebIDL type: long
     */
    public void drawCircle(b2Vec2 center, float radius, int color) { }

    /*
     * Called from native code
     */
    private void _drawSolidCircle(long transform, float radius, int color) {
        drawSolidCircle(b2Transform.wrapPointer(transform), radius, color);
    }

    /**
     * @param transform WebIDL type: {@link b2Transform} [Ref]
     * @param radius    WebIDL type: float
     * @param color     WebIDL type: long
     */
    public void drawSolidCircle(b2Transform transform, float radius, int color) { }

    /*
     * Called from native code
     */
    private void _drawSolidCapsule(long p1, long p2, float radius, int color) {
        drawSolidCapsule(b2Vec2.wrapPointer(p1), b2Vec2.wrapPointer(p2), radius, color);
    }

    /**
     * @param p1     WebIDL type: {@link b2Vec2} [Ref]
     * @param p2     WebIDL type: {@link b2Vec2} [Ref]
     * @param radius WebIDL type: float
     * @param color  WebIDL type: long
     */
    public void drawSolidCapsule(b2Vec2 p1, b2Vec2 p2, float radius, int color) { }

    /*
     * Called from native code
     */
    private void _drawSegment(long p1, long p2, int color) {
        drawSegment(b2Vec2.wrapPointer(p1), b2Vec2.wrapPointer(p2), color);
    }

    /**
     * @param p1    WebIDL type: {@link b2Vec2} [Ref]
     * @param p2    WebIDL type: {@link b2Vec2} [Ref]
     * @param color WebIDL type: long
     */
    public void drawSegment(b2Vec2 p1, b2Vec2 p2, int color) { }

    /*
     * Called from native code
     */
    private void _drawTransform(long transform) {
        drawTransform(b2Transform.wrapPointer(transform));
    }

    /**
     * @param transform WebIDL type: {@link b2Transform} [Ref]
     */
    public void drawTransform(b2Transform transform) { }

    /*
     * Called from native code
     */
    private void _drawPoint(long p, float size, int color) {
        drawPoint(b2Vec2.wrapPointer(p), size, color);
    }

    /**
     * @param p     WebIDL type: {@link b2Vec2} [Ref]
     * @param size  WebIDL type: float
     * @param color WebIDL type: long
     */
    public void drawPoint(b2Vec2 p, float size, int color) { }

    /*
     * Called from native code
     */
    private void _drawString(long p, String s, int color) {
        drawString(b2Vec2.wrapPointer(p), s, color);
    }

    /**
     * @param p     WebIDL type: {@link b2Vec2} [Ref]
     * @param s     WebIDL type: DOMString [Const]
     * @param color WebIDL type: long
     */
    public void drawString(b2Vec2 p, String s, int color) { }

}
