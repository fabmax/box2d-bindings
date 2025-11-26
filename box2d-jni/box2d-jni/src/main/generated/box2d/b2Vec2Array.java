package box2d;


public class b2Vec2Array extends NativeObject {

    protected b2Vec2Array() { }

    private static native int __sizeOf();
    public static final int SIZEOF = __sizeOf();
    public static final int ALIGNOF = 8;
    
    public static b2Vec2Array wrapPointer(long address) {
        return address != 0L ? new b2Vec2Array(address) : null;
    }
    
    public static b2Vec2Array arrayGet(long baseAddress, int index) {
        if (baseAddress == 0L) throw new NullPointerException("baseAddress is 0");
        return wrapPointer(baseAddress + (long) SIZEOF * index);
    }
    
    protected b2Vec2Array(long address) {
        super(address);
    }

    // Placed Constructors

    /**
     * @param address Pre-allocated memory, where the object is created.
     * @param length  WebIDL type: unsigned long
     * @return Stack allocated object of b2Vec2Array
     */
    public static b2Vec2Array createAt(long address, int length) {
        Raw.b2Vec2Array_placed(address, length);
        b2Vec2Array createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    /**
     * @param <T>       Allocator class, e.g. LWJGL's MemoryStack.
     * @param allocator Object to use for allocation, e.g. an instance of LWJGL's MemoryStack.
     * @param allocate  Method to call on allocator to obtain the target address, e.g. MemoryStack::nmalloc.
     * @param length    WebIDL type: unsigned long
     * @return Stack allocated object of b2Vec2Array
     */
    public static <T> b2Vec2Array createAt(T allocator, Allocator<T> allocate, int length) {
        long address = allocate.on(allocator, ALIGNOF, SIZEOF);
        Raw.b2Vec2Array_placed(address, length);
        b2Vec2Array createdObj = wrapPointer(address);
        createdObj.isExternallyAllocated = true;
        return createdObj;
    }

    // Constructors

    /**
     * @param length WebIDL type: unsigned long
     */
    public b2Vec2Array(int length) {
        address = Raw.b2Vec2Array(length);
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
     * @param value WebIDL type: {@link b2Vec2} [Ref]
     */
    public void set(int index, b2Vec2 value) {
        checkNotNull();
        Raw.set(address, index, value.getAddress());
    }

    /**
     * @param index WebIDL type: unsigned long
     * @return WebIDL type: {@link b2Vec2}
     */
    public b2Vec2 get(int index) {
        checkNotNull();
        return b2Vec2.wrapPointer(Raw.get(address, index));
    }

    public static class Raw {
        public static native void b2Vec2Array_placed(long address, int length);
        public static native long b2Vec2Array(int length);
        public static native void destroy(long address);
        public static native int getLength(long address);
        public static native void setLength(long address, int value);
        public static native void set(long address, int index, long value);
        public static native long get(long address, int index);
    }
}
