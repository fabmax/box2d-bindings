# Box2D Bindings for Java / Kotlin

Provides Java / JNI bindings for [Box2D](https://github.com/erincatto/box2d).

The generated bindings contain most of the original documentation as javadoc. However, you may also want to check
out the [original documentation](https://box2d.org/documentation/) of Box2D.

## How to use
The library is published on maven central, so you can easily add this to your dependencies:

### Desktop Java
```
dependencies {
    // java bindings
    implementation("de.fabmax-box2d-jni:box2d-jni:1.0.0")
    
    // native libraries - you can add the one matching your system or all
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-windows")
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-windows-arm64")
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-linux")
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-linux-arm64")
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-macos")
    runtimeOnly("de.fabmax-box2d:box2d-jni:1.0.0:natives-macos-arm64")
}
```

### Android
The Android version of the library is packaged as a single `aar` archive containing both java classes
and native libs:
```
dependencies {
    implementation("de.fabmax-box2d:box2d-jni-android:1.0.0")
}
```

## Library Coverage

The library covers the full API of `box2d` in version `3.3.1`.

The detailed list of mapped functions is given by the [interface definition files](box2d-native/src/webidl).
These are used to generate the corresponding [Java classes](box2d-jni/box2d-jni/src/main/generated/box2d).

### Supported Platforms:
- Windows (x86_64, arm64)
- Linux (x86_64, arm64)
- macOS (x86_64, arm64)
- Android (arm-v8, arm-v7, x86_64, x86)

Moreover, there is another version for javascript/webassembly using emscripten and WebIDL Binder:
[kool-box2d-wasm](https://www.npmjs.com/package/kool-box2d-wasm). This one basically
comes for free since the WebIDL definitions are already there. However, this one is optimized for using it with
Kotlin/JS, which makes sense in Kotlin-multiplatform scenarios. If you are looking for a WASM version of Box2D to use
with your favourite web-framework, you are probably better off with [box2d3-wasm](https://github.com/Birch-san/box2d3-wasm).

### Library Structure

As a C library, Box2D only has top-level functions. The Java bindings wrap them as `public static` functions in a
couple of classes prefixed `B2_` grouped by their functionality. E.g. `B2_World` contains all functions related to
worlds: `b2CreateWorld(worldDef)` becomes `B2_World.createWorld(worldDef)`.

### Examples

You can take a look at the [MultiThreadedWorldTest.java](box2d-jni/box2d-jni/src/test/java/de/fabmax/box2djni/MultiThreadedWorldTest.java)
for a simple example of how to use the library.

### Things to consider when working with native objects
Whenever you create an instance of a wrapper class within this library, this also creates an object on the native
side. Native objects are not covered by the garbage collector, so, to avoid a memory leak, you have to
clean up these objects yourself when you are done with them.

Here is an example:
```java
// create an object of b2Vec2, this also creates a native b2Vec2
// object behind the scenes.
b2Vec2 vector = new b2Vec2();
vector.setX(1f);
vector.setY(2f);

// do something with vector...

// destroy the object once you are done with it
vector.destroy();
```

This approach has two potential problems: First, as mentioned, if you forget to call destroy(), the memory on the
native heap is not released resulting in a memory leak. Second, creating new objects on the native heap comes with
a lot of overhead and is much slower than creating a new object on the Java side.

These issues aren't a big problem for long living objects, which you create on start-up and use until you exit
the program. However, for short-lived objects like, in many cases, `b2Vec2` this can have a large impact. Therefore,
there is a second method to allocate these objects: Stack allocation. To use this, you will need some sort of
memory allocator like LWJGL's `MemoryStack`. With that one the above example could look like this:
```java
try (MemoryStack mem = MemoryStack.stackPush()) {
    // create an object of b2Vec2. The native object is allocated in memory
    // provided by MemoryStack
    b2Vec2 vector = b2Vec2.createAt(mem, MemoryStack::nmalloc);
    vector.setX(1f);
    vector.setY(2f);
    
    // do something with vector...
    // no explicit destroy needed, memory is released when we leave the scope
}
```
While the `b2Vec2.createAt()` call looks a bit more complicated, this approach is faster and comes without the
risk of leaking memory, so it should be preferred whenever possible.

### Box2D Object IDs

Box2D uses ID types like `b2WorldId`, `b2BodyId`, `b2ShapeId`, etc. to identify objects, which are passed as values.
Unfortunately, Java still doesn't support value types (Valhalla, when?). Therefore, the Java bindings use plain
`long` values to represent these IDs (using the corresponding `store*Id()` and `load*Id()` functions for conversion).
This is less type-safe than using dedicated ID types but avoids a lot of unnecessary object allocations.

In case you need the actual ID type, you can create it from the raw `long` value via the corresponding conversion
function. E.g.:
```java
try (MemoryStack mem = MemoryStack.stackPush()) {
    long someBodyId = ...

    // convert raw long id into b2BodyId
    b2BodyId typedBodyId = b2BodyId.createAt(mem, MemoryStack::nmalloc);
    B2_Base.loadBodyId(someBodyId, typedBodyId);

    // convert b2BodyId back to raw long id
    long rawBodyId = B2_Base.storeBodyId(typedBodyId);
    assert(rawBodyId == someBodyId);
}
```

Notice that `b2BodyId` is a native type and therefore needs to be either stack-allocated (like in the example using
`MemoryStack`) or explicitly `destroy()`ed.

### Java Callbacks

At a few places it is possible to register callbacks. To implement a callback, the corresponding Java callback class
has to be extended. The implementing class can then be passed into the corresponding Box2D API.

Here's an example how this might look:
```java
// implement callback
class CustomFilterCb extends b2CustomFilterFcnImpl {
    @Override
    public boolean customFilterFcn(long shapeIdA, long shapeIdB) {
        System.out.println("CustomFilterCb called for shapes " + shapeIdA + " and " + shapeIdB);
        return true;
    }
}

// register / use callback
var customFilterCb = new CustomFilterCb();
B2_World.setCustomFilterCallback(worldId, customFilterCb);
```
