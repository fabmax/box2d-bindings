/*
 * JNI glue code. You should not edit this file.
 * Generated from WebIDL model 'Box2d' by webidl-util.
 */
#include <jni.h>

            static JavaVM* javaVm = NULL;
            
            class JniThreadEnv {
                public:
                    JniThreadEnv() : shouldDetach(false), env(NULL) { }
                    JniThreadEnv(JNIEnv *env) : shouldDetach(false), env(env) { }
                    ~JniThreadEnv() {
                        if (shouldDetach) {
                            javaVm->DetachCurrentThread();
                        }
                    }
                    JNIEnv* getEnv() {
                        if (env == NULL && javaVm != NULL) {
#ifndef __ANDROID__
                            javaVm->AttachCurrentThreadAsDaemon((void**) &env, NULL);
#else
                            javaVm->AttachCurrentThreadAsDaemon(&env, NULL);
#endif
                            shouldDetach = true;
                        }
                        return env;
                    }
                    
                private:
                    bool shouldDetach;
                    JNIEnv *env;
            };
            
            static thread_local JniThreadEnv jniThreadEnv;
            
            class JavaNativeRef {
                public:
                    JavaNativeRef(JNIEnv *env, jobject javaRef) {
                        javaGlobalRef = env->NewGlobalRef(javaRef);
                    }
                    
                    ~JavaNativeRef() {
                        jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
                    }
                    
                    jobject javaGlobalRef;
            };

extern "C" {
JNIEXPORT jint JNICALL Java_box2d_NativeObject__1_1sizeOfPointer(JNIEnv*, jclass) {
    return sizeof(void*);
}

// JavaNativeRef
JNIEXPORT jlong JNICALL Java_box2d_JavaNativeRef__1new_1instance(JNIEnv* env, jclass, jobject javaRef) {
    return (jlong) new JavaNativeRef(env, javaRef);
}
JNIEXPORT void JNICALL Java_box2d_JavaNativeRef__1delete_1instance(JNIEnv*, jclass, jlong address) {
    delete (JavaNativeRef*) address;
}
JNIEXPORT jobject JNICALL Java_box2d_JavaNativeRef__1get_1java_1ref(JNIEnv*, jclass, jlong address) {
    return ((JavaNativeRef*) address)->javaGlobalRef;
}

// B2Base
JNIEXPORT jint JNICALL Java_box2d_B2Base__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2Base);
}
JNIEXPORT jlong JNICALL Java_box2d_B2Base_00024Raw_getVersion(JNIEnv*, jclass) {
    static thread_local b2Version _cache = B2Base::getVersion();
    _cache = B2Base::getVersion();
    return (jlong) &_cache;
}

// b2Version
JNIEXPORT jint JNICALL Java_box2d_b2Version__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Version);
}
JNIEXPORT void JNICALL Java_box2d_b2Version_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Version*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2Version_00024Raw_getMajor(JNIEnv*, jclass, jlong _address) {
    b2Version* _self = (b2Version*) _address;
    return (jint) _self->major;
}
JNIEXPORT void JNICALL Java_box2d_b2Version_00024Raw_setMajor(JNIEnv*, jclass, jlong _address, jint value) {
    b2Version* _self = (b2Version*) _address;
    _self->major = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Version_00024Raw_getMinor(JNIEnv*, jclass, jlong _address) {
    b2Version* _self = (b2Version*) _address;
    return (jint) _self->minor;
}
JNIEXPORT void JNICALL Java_box2d_b2Version_00024Raw_setMinor(JNIEnv*, jclass, jlong _address, jint value) {
    b2Version* _self = (b2Version*) _address;
    _self->minor = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Version_00024Raw_getRevision(JNIEnv*, jclass, jlong _address) {
    b2Version* _self = (b2Version*) _address;
    return (jint) _self->revision;
}
JNIEXPORT void JNICALL Java_box2d_b2Version_00024Raw_setRevision(JNIEnv*, jclass, jlong _address, jint value) {
    b2Version* _self = (b2Version*) _address;
    _self->revision = value;
}

// B2Math
JNIEXPORT jint JNICALL Java_box2d_B2Math__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2Math);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2Math_00024Raw_dot(JNIEnv*, jclass, jlong a, jlong b) {
    return (jfloat) B2Math::dot(*((b2Vec2*) a), *((b2Vec2*) b));
}

// b2Vec2
JNIEXPORT jint JNICALL Java_box2d_b2Vec2__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Vec2);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Vec2_00024Raw_b2Vec2_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Vec2();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Vec2_00024Raw_b2Vec2(JNIEnv*, jclass) {
    return (jlong) new b2Vec2();
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Vec2*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Vec2_00024Raw_getX(JNIEnv*, jclass, jlong _address) {
    b2Vec2* _self = (b2Vec2*) _address;
    return (jfloat) _self->x;
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2_00024Raw_setX(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Vec2* _self = (b2Vec2*) _address;
    _self->x = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Vec2_00024Raw_getY(JNIEnv*, jclass, jlong _address) {
    b2Vec2* _self = (b2Vec2*) _address;
    return (jfloat) _self->y;
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2_00024Raw_setY(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Vec2* _self = (b2Vec2*) _address;
    _self->y = value;
}


// on load callback executed by the JVM once the lib is loaded
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*) {
    javaVm = vm;
    
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    jniThreadEnv = JniThreadEnv(env);
    
    return JNI_VERSION_1_6;
}
} // /extern "C"
