package box2d;


public class B2_Base extends NativeObject {

    protected B2_Base() { }

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static B2_Base wrapPointer(long address) {
        return address != 0L ? new B2_Base(address) : null;
    }
    
    public static B2_Base arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected B2_Base(long address) {
        super(address);
    }

    // Functions

    /**
     * @return WebIDL type: {@link b2Version} [Value]
     */
    public static b2Version getVersion() {
        return b2Version.wrapPointer(Raw.getVersion());
    }

    /**
     * @return WebIDL type: long
     */
    public static int getByteCount() {
        return Raw.getByteCount();
    }

    /**
     * @param worldId WebIDL type: {@link b2WorldId} [Ref]
     * @return WebIDL type: unsigned long long
     */
    public static long storeWorldId(b2WorldId worldId) {
        return Raw.storeWorldId(worldId.getAddress());
    }

    /**
     * @param worldId WebIDL type: unsigned long long
     * @param result  WebIDL type: {@link b2WorldId} [Ref]
     */
    public static void loadWorldId(long worldId, b2WorldId result) {
        Raw.loadWorldId(worldId, result.getAddress());
    }

    /**
     * @param bodyId WebIDL type: {@link b2BodyId} [Ref]
     * @return WebIDL type: unsigned long long
     */
    public static long storeBodyId(b2BodyId bodyId) {
        return Raw.storeBodyId(bodyId.getAddress());
    }

    /**
     * @param bodyId WebIDL type: unsigned long long
     * @param result WebIDL type: {@link b2BodyId} [Ref]
     */
    public static void loadBodyId(long bodyId, b2BodyId result) {
        Raw.loadBodyId(bodyId, result.getAddress());
    }

    /**
     * @param shapeId WebIDL type: {@link b2ShapeId} [Ref]
     * @return WebIDL type: unsigned long long
     */
    public static long storeShapeId(b2ShapeId shapeId) {
        return Raw.storeShapeId(shapeId.getAddress());
    }

    /**
     * @param shapeId WebIDL type: unsigned long long
     * @param result  WebIDL type: {@link b2ShapeId} [Ref]
     */
    public static void loadShapeId(long shapeId, b2ShapeId result) {
        Raw.loadShapeId(shapeId, result.getAddress());
    }

    /**
     * @param chainId WebIDL type: {@link b2ChainId} [Ref]
     * @return WebIDL type: unsigned long long
     */
    public static long storeChainId(b2ChainId chainId) {
        return Raw.storeChainId(chainId.getAddress());
    }

    /**
     * @param chainId WebIDL type: unsigned long long
     * @param result  WebIDL type: {@link b2ChainId} [Ref]
     */
    public static void loadChainId(long chainId, b2ChainId result) {
        Raw.loadChainId(chainId, result.getAddress());
    }

    /**
     * @param jointId WebIDL type: {@link b2JointId} [Ref]
     * @return WebIDL type: unsigned long long
     */
    public static long storeJointId(b2JointId jointId) {
        return Raw.storeJointId(jointId.getAddress());
    }

    /**
     * @param jointId WebIDL type: unsigned long long
     * @param result  WebIDL type: {@link b2JointId} [Ref]
     */
    public static void loadJointId(long jointId, b2JointId result) {
        Raw.loadJointId(jointId, result.getAddress());
    }

    public static class Raw {
        public static native long getVersion();
        public static native int getByteCount();
        public static native long storeWorldId(long worldId);
        public static native void loadWorldId(long worldId, long result);
        public static native long storeBodyId(long bodyId);
        public static native void loadBodyId(long bodyId, long result);
        public static native long storeShapeId(long shapeId);
        public static native void loadShapeId(long shapeId, long result);
        public static native long storeChainId(long chainId);
        public static native void loadChainId(long chainId, long result);
        public static native long storeJointId(long jointId);
        public static native void loadJointId(long jointId, long result);
    }
}
