package box2d;


public class b2JointIdArray extends NativeObject {

    protected b2JointIdArray() { }

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static b2JointIdArray wrapPointer(long address) {
        return address != 0L ? new b2JointIdArray(address) : null;
    }
    
    public static b2JointIdArray arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected b2JointIdArray(long address) {
        super(address);
    }

    // Placed Constructors

    /**
     * @param address Pre-allocated memory, where the object is created.
     * @param length  WebIDL type: unsigned long
     * @return Stack allocated object of b2JointIdArray
     */
    public static b2JointIdArray createAt(long address, int length) {
        Raw.b2JointIdArray_placed(address, length);
        b2JointIdArray createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    /**
     * @param <T>       Allocator class, e.g. LWJGL's MemoryStack.
     * @param allocator Object to use for allocation, e.g. an instance of LWJGL's MemoryStack.
     * @param allocate  Method to call on allocator to obtain the target address, e.g. MemoryStack::nmalloc.
     * @param length    WebIDL type: unsigned long
     * @return Stack allocated object of b2JointIdArray
     */
    public static <T> b2JointIdArray createAt(T allocator, Allocator<T> allocate, int length) {
        long address = allocate.on(allocator, ALIGNOF, SIZEOF);
        Raw.b2JointIdArray_placed(address, length);
        b2JointIdArray createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    // Constructors

    /**
     * @param length WebIDL type: unsigned long
     */
    public b2JointIdArray(int length) {
        address = Raw.b2JointIdArray(length);
    }

    // Destructor

    public void destroy() {
        if (address == 0L) {
            throw new IllegalStateException(this + " is already deleted");
        }
        if (isExternallyAllocated) {
            throw new IllegalStateException(this + " is externally allocated and cannot be manually destroyed");
        }
        Raw.destroy(address);
        address = 0L;
    }

    // Attributes

    /**
     * @return WebIDL type: unsigned long
     */
    public int getLength() {
        checkNotNull();
        return Raw.getLength(address);
    }

    /**
     * @param value WebIDL type: unsigned long
     */
    public void setLength(int value) {
        checkNotNull();
        Raw.setLength(address, value);
    }

    // Functions

    /**
     * @param index WebIDL type: unsigned long
     * @param value WebIDL type: {@link b2JointId} [Ref]
     */
    public void set(int index, b2JointId value) {
        checkNotNull();
        Raw.set(address, index, value.getAddress());
    }

    /**
     * @param index WebIDL type: unsigned long
     * @return WebIDL type: {@link b2JointId}
     */
    public b2JointId get(int index) {
        checkNotNull();
        return b2JointId.wrapPointer(Raw.get(address, index));
    }

    public static class Raw {
        public static native void b2JointIdArray_placed(long address, int length);
        public static native long b2JointIdArray(int length);
        public static native void destroy(long address);
        public static native int getLength(long address);
        public static native void setLength(long address, int value);
        public static native void set(long address, int index, long value);
        public static native long get(long address, int index);
    }
}
