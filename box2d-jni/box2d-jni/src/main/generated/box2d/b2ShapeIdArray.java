package box2d;


public class b2ShapeIdArray extends NativeObject {

    protected b2ShapeIdArray() { }

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static b2ShapeIdArray wrapPointer(long address) {
        return address != 0L ? new b2ShapeIdArray(address) : null;
    }
    
    public static b2ShapeIdArray arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected b2ShapeIdArray(long address) {
        super(address);
    }

    // Placed Constructors

    /**
     * @param address Pre-allocated memory, where the object is created.
     * @param length  WebIDL type: unsigned long
     * @return Stack allocated object of b2ShapeIdArray
     */
    public static b2ShapeIdArray createAt(long address, int length) {
        Raw.b2ShapeIdArray_placed(address, length);
        b2ShapeIdArray createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    /**
     * @param <T>       Allocator class, e.g. LWJGL's MemoryStack.
     * @param allocator Object to use for allocation, e.g. an instance of LWJGL's MemoryStack.
     * @param allocate  Method to call on allocator to obtain the target address, e.g. MemoryStack::nmalloc.
     * @param length    WebIDL type: unsigned long
     * @return Stack allocated object of b2ShapeIdArray
     */
    public static <T> b2ShapeIdArray createAt(T allocator, Allocator<T> allocate, int length) {
        long address = allocate.on(allocator, ALIGNOF, SIZEOF);
        Raw.b2ShapeIdArray_placed(address, length);
        b2ShapeIdArray createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    // Constructors

    /**
     * @param length WebIDL type: unsigned long
     */
    public b2ShapeIdArray(int length) {
        address = Raw.b2ShapeIdArray(length);
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
     * @param value WebIDL type: {@link b2ShapeId} [Ref]
     */
    public void set(int index, b2ShapeId value) {
        checkNotNull();
        Raw.set(address, index, value.getAddress());
    }

    /**
     * @param index WebIDL type: unsigned long
     * @return WebIDL type: {@link b2ShapeId}
     */
    public b2ShapeId get(int index) {
        checkNotNull();
        return b2ShapeId.wrapPointer(Raw.get(address, index));
    }

    public static class Raw {
        public static native void b2ShapeIdArray_placed(long address, int length);
        public static native long b2ShapeIdArray(int length);
        public static native void destroy(long address);
        public static native int getLength(long address);
        public static native void setLength(long address, int value);
        public static native void set(long address, int index, long value);
        public static native long get(long address, int index);
    }
}
