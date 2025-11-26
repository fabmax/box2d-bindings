package box2d;


public class b2CastResultFcnImpl extends b2CastResultFcnI {

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static b2CastResultFcnImpl wrapPointer(long address) {
        return address != 0L ? new b2CastResultFcnImpl(address) : null;
    }
    
    public static b2CastResultFcnImpl arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected b2CastResultFcnImpl(long address) {
        super(address);
    }

    protected b2CastResultFcnImpl() {
        address = _b2CastResultFcnImpl();
    }
    private native long _b2CastResultFcnImpl();
    
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
    private boolean _castResultFcn(long shapeId, long point, long normal, float fraction) {
        return castResultFcn(shapeId, b2Vec2.wrapPointer(point), b2Vec2.wrapPointer(normal), fraction);
    }

    /**
     * @param shapeId  WebIDL type: unsigned long long
     * @param point    WebIDL type: {@link b2Vec2} [Ref]
     * @param normal   WebIDL type: {@link b2Vec2} [Ref]
     * @param fraction WebIDL type: float
     * @return WebIDL type: boolean
     */
    public boolean castResultFcn(long shapeId, b2Vec2 point, b2Vec2 normal, float fraction) {
        return false;
    }

}
