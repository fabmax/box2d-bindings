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

class TaskManagerImpl : TaskManager {
    public:
        TaskManagerImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            enqueueTaskMethodId = env->GetMethodID(javaClass, "_enqueueTask", "(JIIJ)J");
            finishTaskMethodId = env->GetMethodID(javaClass, "_finishTask", "(J)V");
        }
        
        ~TaskManagerImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual unsigned long long enqueueTask(unsigned long long box2dTask, int itemCount, int minRange, unsigned long long box2dContext) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallLongMethod(javaGlobalRef, enqueueTaskMethodId, (jlong) box2dTask, (jint) itemCount, (jint) minRange, (jlong) box2dContext);
        }

        virtual void finishTask(unsigned long long userTask) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, finishTaskMethodId, (jlong) userTask);
        }

    private:
        jobject javaGlobalRef;
        jmethodID enqueueTaskMethodId;
        jmethodID finishTaskMethodId;
};

class b2DebugDrawCallbacksImpl : b2DebugDrawCallbacks {
    public:
        b2DebugDrawCallbacksImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            drawPolygonMethodId = env->GetMethodID(javaClass, "_drawPolygon", "(JII)V");
            drawSolidPolygonMethodId = env->GetMethodID(javaClass, "_drawSolidPolygon", "(JJIFI)V");
            drawCircleMethodId = env->GetMethodID(javaClass, "_drawCircle", "(JFI)V");
            drawSolidCircleMethodId = env->GetMethodID(javaClass, "_drawSolidCircle", "(JFI)V");
            drawSolidCapsuleMethodId = env->GetMethodID(javaClass, "_drawSolidCapsule", "(JJFI)V");
            drawSegmentMethodId = env->GetMethodID(javaClass, "_drawSegment", "(JJI)V");
            drawTransformMethodId = env->GetMethodID(javaClass, "_drawTransform", "(J)V");
            drawPointMethodId = env->GetMethodID(javaClass, "_drawPoint", "(JFI)V");
            drawStringMethodId = env->GetMethodID(javaClass, "_drawString", "(JLjava/lang/String;I)V");
        }
        
        ~b2DebugDrawCallbacksImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void drawPolygon(const b2Vec2* vertices, int vertexCount, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawPolygonMethodId, (jlong) vertices, (jint) vertexCount, (jint) color);
        }

        virtual void drawSolidPolygon(b2Transform& transform, const b2Vec2* vertices, int vertexCount, float radius, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawSolidPolygonMethodId, (jlong) &transform, (jlong) vertices, (jint) vertexCount, (jfloat) radius, (jint) color);
        }

        virtual void drawCircle(b2Vec2& center, float radius, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawCircleMethodId, (jlong) &center, (jfloat) radius, (jint) color);
        }

        virtual void drawSolidCircle(b2Transform& transform, float radius, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawSolidCircleMethodId, (jlong) &transform, (jfloat) radius, (jint) color);
        }

        virtual void drawSolidCapsule(b2Vec2& p1, b2Vec2& p2, float radius, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawSolidCapsuleMethodId, (jlong) &p1, (jlong) &p2, (jfloat) radius, (jint) color);
        }

        virtual void drawSegment(b2Vec2& p1, b2Vec2& p2, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawSegmentMethodId, (jlong) &p1, (jlong) &p2, (jint) color);
        }

        virtual void drawTransform(b2Transform& transform) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawTransformMethodId, (jlong) &transform);
        }

        virtual void drawPoint(b2Vec2& p, float size, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawPointMethodId, (jlong) &p, (jfloat) size, (jint) color);
        }

        virtual void drawString(b2Vec2& p, const char* s, int color) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, drawStringMethodId, (jlong) &p, _env->NewStringUTF(s), (jint) color);
        }

    private:
        jobject javaGlobalRef;
        jmethodID drawPolygonMethodId;
        jmethodID drawSolidPolygonMethodId;
        jmethodID drawCircleMethodId;
        jmethodID drawSolidCircleMethodId;
        jmethodID drawSolidCapsuleMethodId;
        jmethodID drawSegmentMethodId;
        jmethodID drawTransformMethodId;
        jmethodID drawPointMethodId;
        jmethodID drawStringMethodId;
};

class b2CustomFilterFcnImpl : b2CustomFilterFcnI {
    public:
        b2CustomFilterFcnImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            customFilterFcnMethodId = env->GetMethodID(javaClass, "_customFilterFcn", "(JJ)Z");
        }
        
        ~b2CustomFilterFcnImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool customFilterFcn(unsigned long long shapeIdA, unsigned long long shapeIdB) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, customFilterFcnMethodId, (jlong) shapeIdA, (jlong) shapeIdB);
        }

    private:
        jobject javaGlobalRef;
        jmethodID customFilterFcnMethodId;
};

class b2PreSolveFcnImpl : b2PreSolveFcnI {
    public:
        b2PreSolveFcnImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            preSolveFcnMethodId = env->GetMethodID(javaClass, "_preSolveFcn", "(JJJ)Z");
        }
        
        ~b2PreSolveFcnImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool preSolveFcn(unsigned long long shapeIdA, unsigned long long shapeIdB, b2Manifold* manifold) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, preSolveFcnMethodId, (jlong) shapeIdA, (jlong) shapeIdB, (jlong) manifold);
        }

    private:
        jobject javaGlobalRef;
        jmethodID preSolveFcnMethodId;
};

class b2FrictionCallbackImpl : b2FrictionCallbackI {
    public:
        b2FrictionCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            frictionCallbackMethodId = env->GetMethodID(javaClass, "_frictionCallback", "(FIFI)F");
        }
        
        ~b2FrictionCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual float frictionCallback(float frictionA, int userMaterialIdA, float frictionB, int userMaterialIdB) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallFloatMethod(javaGlobalRef, frictionCallbackMethodId, (jfloat) frictionA, (jint) userMaterialIdA, (jfloat) frictionB, (jint) userMaterialIdB);
        }

    private:
        jobject javaGlobalRef;
        jmethodID frictionCallbackMethodId;
};

class b2RestitutionCallbackImpl : b2RestitutionCallbackI {
    public:
        b2RestitutionCallbackImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            restitutionCallbackMethodId = env->GetMethodID(javaClass, "_restitutionCallback", "(FIFI)F");
        }
        
        ~b2RestitutionCallbackImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual float restitutionCallback(float restitutionA, int userMaterialIdA, float restitutionB, int userMaterialIdB) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallFloatMethod(javaGlobalRef, restitutionCallbackMethodId, (jfloat) restitutionA, (jint) userMaterialIdA, (jfloat) restitutionB, (jint) userMaterialIdB);
        }

    private:
        jobject javaGlobalRef;
        jmethodID restitutionCallbackMethodId;
};

class b2OverlapResultFcnImpl : b2OverlapResultFcnI {
    public:
        b2OverlapResultFcnImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            overlapResultFcnMethodId = env->GetMethodID(javaClass, "_overlapResultFcn", "(J)Z");
        }
        
        ~b2OverlapResultFcnImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool overlapResultFcn(unsigned long long shapeId) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, overlapResultFcnMethodId, (jlong) shapeId);
        }

    private:
        jobject javaGlobalRef;
        jmethodID overlapResultFcnMethodId;
};

class b2CastResultFcnImpl : b2CastResultFcnI {
    public:
        b2CastResultFcnImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            castResultFcnMethodId = env->GetMethodID(javaClass, "_castResultFcn", "(JJJF)Z");
        }
        
        ~b2CastResultFcnImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool castResultFcn(unsigned long long shapeId, b2Vec2& point, b2Vec2& normal, float fraction) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, castResultFcnMethodId, (jlong) shapeId, (jlong) &point, (jlong) &normal, (jfloat) fraction);
        }

    private:
        jobject javaGlobalRef;
        jmethodID castResultFcnMethodId;
};

class b2PlaneResultFcnImpl : b2PlaneResultFcnI {
    public:
        b2PlaneResultFcnImpl(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            planeResultFcnMethodId = env->GetMethodID(javaClass, "_planeResultFcn", "(JJ)Z");
        }
        
        ~b2PlaneResultFcnImpl() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual bool planeResultFcn(unsigned long long shapeId, const b2PlaneResult* plane) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            return _env->CallBooleanMethod(javaGlobalRef, planeResultFcnMethodId, (jlong) shapeId, (jlong) plane);
        }

    private:
        jobject javaGlobalRef;
        jmethodID planeResultFcnMethodId;
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

// B2_Shape
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Shape);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_defaultShapeDef(JNIEnv*, jclass, jlong result) {
    B2_Shape::defaultShapeDef(*((b2ShapeDef*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_createCircleShape(JNIEnv*, jclass, jlong bodyId, jlong def, jlong circle) {
    return (jlong) B2_Shape::createCircleShape(bodyId, (b2ShapeDef*) def, (b2Circle*) circle);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_createSegmentShape(JNIEnv*, jclass, jlong bodyId, jlong def, jlong segment) {
    return (jlong) B2_Shape::createSegmentShape(bodyId, (b2ShapeDef*) def, (b2Segment*) segment);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_createCapsuleShape(JNIEnv*, jclass, jlong bodyId, jlong def, jlong capsule) {
    return (jlong) B2_Shape::createCapsuleShape(bodyId, (b2ShapeDef*) def, (b2Capsule*) capsule);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_createPolygonShape(JNIEnv*, jclass, jlong bodyId, jlong def, jlong polygon) {
    return (jlong) B2_Shape::createPolygonShape(bodyId, (b2ShapeDef*) def, (b2Polygon*) polygon);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_destroyShape(JNIEnv*, jclass, jlong shapeId, jboolean updateBodyMass) {
    B2_Shape::destroyShape(shapeId, updateBodyMass);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_isValid(JNIEnv*, jclass, jlong id) {
    return (jboolean) B2_Shape::isValid(id);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getType(JNIEnv*, jclass, jlong shapeId) {
    return (jint) B2_Shape::getType(shapeId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getBody(JNIEnv*, jclass, jlong shapeId) {
    return (jlong) B2_Shape::getBody(shapeId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getWorld(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2WorldId _cache = B2_Shape::getWorld(shapeId);
    _cache = B2_Shape::getWorld(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_isSensor(JNIEnv*, jclass, jlong shapeId) {
    return (jboolean) B2_Shape::isSensor(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setUserData(JNIEnv*, jclass, jlong shapeId, jlong userData) {
    B2_Shape::setUserData(shapeId, (void*) userData);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getUserData(JNIEnv*, jclass, jlong shapeId) {
    return (jlong) B2_Shape::getUserData(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setDensity(JNIEnv*, jclass, jlong shapeId, jfloat density, jboolean updateBodyMass) {
    B2_Shape::setDensity(shapeId, density, updateBodyMass);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Shape_00024Raw_getDensity(JNIEnv*, jclass, jlong shapeId) {
    return (jfloat) B2_Shape::getDensity(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setFriction(JNIEnv*, jclass, jlong shapeId, jfloat friction) {
    B2_Shape::setFriction(shapeId, friction);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Shape_00024Raw_getFriction(JNIEnv*, jclass, jlong shapeId) {
    return (jfloat) B2_Shape::getFriction(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setRestitution(JNIEnv*, jclass, jlong shapeId, jfloat restitution) {
    B2_Shape::setRestitution(shapeId, restitution);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Shape_00024Raw_getRestitution(JNIEnv*, jclass, jlong shapeId) {
    return (jfloat) B2_Shape::getRestitution(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setMaterial(JNIEnv*, jclass, jlong shapeId, jint material) {
    B2_Shape::setMaterial(shapeId, material);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getMaterial(JNIEnv*, jclass, jlong shapeId) {
    return (jint) B2_Shape::getMaterial(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setSurfaceMaterial(JNIEnv*, jclass, jlong shapeId, jlong surfaceMaterial) {
    B2_Shape::setSurfaceMaterial(shapeId, *((b2SurfaceMaterial*) surfaceMaterial));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getSurfaceMaterial(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2SurfaceMaterial _cache = B2_Shape::getSurfaceMaterial(shapeId);
    _cache = B2_Shape::getSurfaceMaterial(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getFilter(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2Filter _cache = B2_Shape::getFilter(shapeId);
    _cache = B2_Shape::getFilter(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setFilter(JNIEnv*, jclass, jlong shapeId, jlong filter) {
    B2_Shape::setFilter(shapeId, *((b2Filter*) filter));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_enableSensorEvents(JNIEnv*, jclass, jlong shapeId, jboolean flag) {
    B2_Shape::enableSensorEvents(shapeId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_areSensorEventsEnabled(JNIEnv*, jclass, jlong shapeId) {
    return (jboolean) B2_Shape::areSensorEventsEnabled(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_enableContactEvents(JNIEnv*, jclass, jlong shapeId, jboolean flag) {
    B2_Shape::enableContactEvents(shapeId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_areContactEventsEnabled(JNIEnv*, jclass, jlong shapeId) {
    return (jboolean) B2_Shape::areContactEventsEnabled(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_enablePreSolveEvents(JNIEnv*, jclass, jlong shapeId, jboolean flag) {
    B2_Shape::enablePreSolveEvents(shapeId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_arePreSolveEventsEnabled(JNIEnv*, jclass, jlong shapeId) {
    return (jboolean) B2_Shape::arePreSolveEventsEnabled(shapeId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_enableHitEvents(JNIEnv*, jclass, jlong shapeId, jboolean flag) {
    B2_Shape::enableHitEvents(shapeId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_areHitEventsEnabled(JNIEnv*, jclass, jlong shapeId) {
    return (jboolean) B2_Shape::areHitEventsEnabled(shapeId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Shape_00024Raw_testPoint(JNIEnv*, jclass, jlong shapeId, jlong point) {
    return (jboolean) B2_Shape::testPoint(shapeId, *((b2Vec2*) point));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_rayCast(JNIEnv*, jclass, jlong shapeId, jlong input) {
    static thread_local b2CastOutput _cache = B2_Shape::rayCast(shapeId, (b2RayCastInput*) input);
    _cache = B2_Shape::rayCast(shapeId, (b2RayCastInput*) input);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getCircle(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2Circle _cache = B2_Shape::getCircle(shapeId);
    _cache = B2_Shape::getCircle(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getSegment(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2Segment _cache = B2_Shape::getSegment(shapeId);
    _cache = B2_Shape::getSegment(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getChainSegment(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2ChainSegment _cache = B2_Shape::getChainSegment(shapeId);
    _cache = B2_Shape::getChainSegment(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getCapsule(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2Capsule _cache = B2_Shape::getCapsule(shapeId);
    _cache = B2_Shape::getCapsule(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getPolygon(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2Polygon _cache = B2_Shape::getPolygon(shapeId);
    _cache = B2_Shape::getPolygon(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setCircle(JNIEnv*, jclass, jlong shapeId, jlong circle) {
    B2_Shape::setCircle(shapeId, (b2Circle*) circle);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setCapsule(JNIEnv*, jclass, jlong shapeId, jlong capsule) {
    B2_Shape::setCapsule(shapeId, (b2Capsule*) capsule);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setSegment(JNIEnv*, jclass, jlong shapeId, jlong segment) {
    B2_Shape::setSegment(shapeId, (b2Segment*) segment);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_setPolygon(JNIEnv*, jclass, jlong shapeId, jlong polygon) {
    B2_Shape::setPolygon(shapeId, (b2Polygon*) polygon);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getParentChain(JNIEnv*, jclass, jlong shapeId) {
    return (jlong) B2_Shape::getParentChain(shapeId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getContactCapacity(JNIEnv*, jclass, jlong shapeId) {
    return (jint) B2_Shape::getContactCapacity(shapeId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getContactData(JNIEnv*, jclass, jlong shapeId, jlong contactData) {
    return (jint) B2_Shape::getContactData(shapeId, (b2ContactDataArray*) contactData);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getSensorCapacity(JNIEnv*, jclass, jlong shapeId) {
    return (jint) B2_Shape::getSensorCapacity(shapeId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape_00024Raw_getSensorOverlaps(JNIEnv*, jclass, jlong shapeId, jlong overlaps) {
    return (jint) B2_Shape::getSensorOverlaps(shapeId, (b2ShapeIdArray*) overlaps);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getAABB(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2AABB _cache = B2_Shape::getAABB(shapeId);
    _cache = B2_Shape::getAABB(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getMassData(JNIEnv*, jclass, jlong shapeId) {
    static thread_local b2MassData _cache = B2_Shape::getMassData(shapeId);
    _cache = B2_Shape::getMassData(shapeId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Shape_00024Raw_getClosestPoint(JNIEnv*, jclass, jlong shapeId, jlong target) {
    static thread_local b2Vec2 _cache = B2_Shape::getClosestPoint(shapeId, *((b2Vec2*) target));
    _cache = B2_Shape::getClosestPoint(shapeId, *((b2Vec2*) target));
    return (jlong) &_cache;
}

// B2_Chain
JNIEXPORT jint JNICALL Java_box2d_B2_1Chain__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Chain);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Chain_00024Raw_defaultChainDef(JNIEnv*, jclass, jlong result) {
    B2_Chain::defaultChainDef(*((b2ChainDef*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Chain_00024Raw_createChain(JNIEnv*, jclass, jlong bodyId, jlong def) {
    return (jlong) B2_Chain::createChain(bodyId, (b2ChainDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Chain_00024Raw_destroyChain(JNIEnv*, jclass, jlong chainId) {
    B2_Chain::destroyChain(chainId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Chain_00024Raw_isValid(JNIEnv*, jclass, jlong id) {
    return (jboolean) B2_Chain::isValid(id);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Chain_00024Raw_getWorld(JNIEnv*, jclass, jlong chainId) {
    static thread_local b2WorldId _cache = B2_Chain::getWorld(chainId);
    _cache = B2_Chain::getWorld(chainId);
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Chain_00024Raw_getSegmentCount(JNIEnv*, jclass, jlong chainId) {
    return (jint) B2_Chain::getSegmentCount(chainId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Chain_00024Raw_getSegments(JNIEnv*, jclass, jlong chainId, jlong segmentArray) {
    return (jint) B2_Chain::getSegments(chainId, (b2ShapeIdArray*) segmentArray);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Chain_00024Raw_setFriction(JNIEnv*, jclass, jlong chainId, jfloat friction) {
    B2_Chain::setFriction(chainId, friction);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Chain_00024Raw_getFriction(JNIEnv*, jclass, jlong chainId) {
    return (jfloat) B2_Chain::getFriction(chainId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Chain_00024Raw_setRestitution(JNIEnv*, jclass, jlong chainId, jfloat restitution) {
    B2_Chain::setRestitution(chainId, restitution);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Chain_00024Raw_getRestitution(JNIEnv*, jclass, jlong chainId) {
    return (jfloat) B2_Chain::getRestitution(chainId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Chain_00024Raw_setMaterial(JNIEnv*, jclass, jlong chainId, jint material) {
    B2_Chain::setMaterial(chainId, material);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Chain_00024Raw_getMaterial(JNIEnv*, jclass, jlong chainId) {
    return (jint) B2_Chain::getMaterial(chainId);
}

// b2ShapeDef
JNIEXPORT jint JNICALL Java_box2d_b2ShapeDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeDef_00024Raw_b2ShapeDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ShapeDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeDef_00024Raw_b2ShapeDef(JNIEnv*, jclass) {
    return (jlong) new b2ShapeDef();
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ShapeDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeDef_00024Raw_getMaterial(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jlong) &_self->material;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setMaterial(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->material = *((b2SurfaceMaterial*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ShapeDef_00024Raw_getDensity(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jfloat) _self->density;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setDensity(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->density = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeDef_00024Raw_getFilter(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jlong) &_self->filter;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setFilter(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->filter = *((b2Filter*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getIsSensor(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->isSensor;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setIsSensor(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->isSensor = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getEnableSensorEvents(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->enableSensorEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setEnableSensorEvents(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->enableSensorEvents = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getEnableContactEvents(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->enableContactEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setEnableContactEvents(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->enableContactEvents = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getEnableHitEvents(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->enableHitEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setEnableHitEvents(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->enableHitEvents = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getEnablePreSolveEvents(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->enablePreSolveEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setEnablePreSolveEvents(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->enablePreSolveEvents = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getInvokeContactCreation(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->invokeContactCreation;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setInvokeContactCreation(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->invokeContactCreation = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeDef_00024Raw_getUpdateBodyMass(JNIEnv*, jclass, jlong _address) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    return (jboolean) _self->updateBodyMass;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeDef_00024Raw_setUpdateBodyMass(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeDef* _self = (b2ShapeDef*) _address;
    _self->updateBodyMass = value;
}

// b2ChainDef
JNIEXPORT jint JNICALL Java_box2d_b2ChainDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ChainDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_b2ChainDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ChainDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_b2ChainDef(JNIEnv*, jclass) {
    return (jlong) new b2ChainDef();
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ChainDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_getPoints(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jlong) _self->points;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setPoints(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->points = (b2Vec2*) value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ChainDef_00024Raw_getCount(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->count = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_getMaterials(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jlong) _self->materials;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setMaterials(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->materials = (b2SurfaceMaterial*) value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ChainDef_00024Raw_getMaterialCount(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jint) _self->materialCount;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setMaterialCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->materialCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainDef_00024Raw_getFilter(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jlong) &_self->filter;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setFilter(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->filter = *((b2Filter*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ChainDef_00024Raw_getIsLoop(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jboolean) _self->isLoop;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setIsLoop(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->isLoop = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ChainDef_00024Raw_getEnableSensorEvents(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jboolean) _self->enableSensorEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setEnableSensorEvents(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->enableSensorEvents = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ChainDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2ChainDef* _self = (b2ChainDef*) _address;
    _self->internalValue = value;
}

// b2Filter
JNIEXPORT jint JNICALL Java_box2d_b2Filter__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Filter);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Filter_00024Raw_b2Filter_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Filter();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Filter_00024Raw_b2Filter(JNIEnv*, jclass) {
    return (jlong) new b2Filter();
}
JNIEXPORT void JNICALL Java_box2d_b2Filter_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Filter*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Filter_00024Raw_getCategoryBits(JNIEnv*, jclass, jlong _address) {
    b2Filter* _self = (b2Filter*) _address;
    return (jlong) _self->categoryBits;
}
JNIEXPORT void JNICALL Java_box2d_b2Filter_00024Raw_setCategoryBits(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Filter* _self = (b2Filter*) _address;
    _self->categoryBits = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Filter_00024Raw_getGroupIndex(JNIEnv*, jclass, jlong _address) {
    b2Filter* _self = (b2Filter*) _address;
    return (jint) _self->groupIndex;
}
JNIEXPORT void JNICALL Java_box2d_b2Filter_00024Raw_setGroupIndex(JNIEnv*, jclass, jlong _address, jint value) {
    b2Filter* _self = (b2Filter*) _address;
    _self->groupIndex = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Filter_00024Raw_getMaskBits(JNIEnv*, jclass, jlong _address) {
    b2Filter* _self = (b2Filter*) _address;
    return (jlong) _self->maskBits;
}
JNIEXPORT void JNICALL Java_box2d_b2Filter_00024Raw_setMaskBits(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Filter* _self = (b2Filter*) _address;
    _self->maskBits = value;
}

// b2QueryFilter
JNIEXPORT jint JNICALL Java_box2d_b2QueryFilter__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2QueryFilter);
}
JNIEXPORT jlong JNICALL Java_box2d_b2QueryFilter_00024Raw_b2QueryFilter_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2QueryFilter();
}
JNIEXPORT jlong JNICALL Java_box2d_b2QueryFilter_00024Raw_b2QueryFilter(JNIEnv*, jclass) {
    return (jlong) new b2QueryFilter();
}
JNIEXPORT void JNICALL Java_box2d_b2QueryFilter_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2QueryFilter*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2QueryFilter_00024Raw_getCategoryBits(JNIEnv*, jclass, jlong _address) {
    b2QueryFilter* _self = (b2QueryFilter*) _address;
    return (jlong) _self->categoryBits;
}
JNIEXPORT void JNICALL Java_box2d_b2QueryFilter_00024Raw_setCategoryBits(JNIEnv*, jclass, jlong _address, jlong value) {
    b2QueryFilter* _self = (b2QueryFilter*) _address;
    _self->categoryBits = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2QueryFilter_00024Raw_getMaskBits(JNIEnv*, jclass, jlong _address) {
    b2QueryFilter* _self = (b2QueryFilter*) _address;
    return (jlong) _self->maskBits;
}
JNIEXPORT void JNICALL Java_box2d_b2QueryFilter_00024Raw_setMaskBits(JNIEnv*, jclass, jlong _address, jlong value) {
    b2QueryFilter* _self = (b2QueryFilter*) _address;
    _self->maskBits = value;
}

// b2SurfaceMaterial
JNIEXPORT jint JNICALL Java_box2d_b2SurfaceMaterial__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2SurfaceMaterial);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_b2SurfaceMaterial_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2SurfaceMaterial();
}
JNIEXPORT jlong JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_b2SurfaceMaterial(JNIEnv*, jclass) {
    return (jlong) new b2SurfaceMaterial();
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2SurfaceMaterial*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getCustomColor(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jint) _self->customColor;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setCustomColor(JNIEnv*, jclass, jlong _address, jint value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->customColor = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getFriction(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jfloat) _self->friction;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->friction = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getRestitution(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->restitution = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getRollingResistance(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jfloat) _self->rollingResistance;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setRollingResistance(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->rollingResistance = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getTangentSpeed(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jfloat) _self->tangentSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setTangentSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->tangentSpeed = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_getUserMaterialId(JNIEnv*, jclass, jlong _address) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    return (jint) _self->userMaterialId;
}
JNIEXPORT void JNICALL Java_box2d_b2SurfaceMaterial_00024Raw_setUserMaterialId(JNIEnv*, jclass, jlong _address, jint value) {
    b2SurfaceMaterial* _self = (b2SurfaceMaterial*) _address;
    _self->userMaterialId = value;
}

// b2ContactData
JNIEXPORT jint JNICALL Java_box2d_b2ContactData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactData);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactData_00024Raw_b2ContactData_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ContactData();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactData_00024Raw_b2ContactData(JNIEnv*, jclass) {
    return (jlong) new b2ContactData();
}
JNIEXPORT void JNICALL Java_box2d_b2ContactData_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactData*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactData_00024Raw_getManifold(JNIEnv*, jclass, jlong _address) {
    b2ContactData* _self = (b2ContactData*) _address;
    return (jlong) &_self->manifold;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactData_00024Raw_setManifold(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactData* _self = (b2ContactData*) _address;
    _self->manifold = *((b2Manifold*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactData_00024Raw_getShapeIdA(JNIEnv*, jclass, jlong _address) {
    b2ContactData* _self = (b2ContactData*) _address;
    return (jlong) &_self->shapeIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactData_00024Raw_setShapeIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactData* _self = (b2ContactData*) _address;
    _self->shapeIdA = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactData_00024Raw_getShapeIdB(JNIEnv*, jclass, jlong _address) {
    b2ContactData* _self = (b2ContactData*) _address;
    return (jlong) &_self->shapeIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactData_00024Raw_setShapeIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactData* _self = (b2ContactData*) _address;
    _self->shapeIdB = *((b2ShapeId*) value);
}

// B2_Vec2
JNIEXPORT jint JNICALL Java_box2d_B2_1Vec2__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Vec2);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_dot(JNIEnv*, jclass, jlong a, jlong b) {
    return (jfloat) B2_Vec2::dot(*((b2Vec2*) a), *((b2Vec2*) b));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_cross(JNIEnv*, jclass, jlong a, jlong b) {
    return (jfloat) B2_Vec2::cross(*((b2Vec2*) a), *((b2Vec2*) b));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_crossVS(JNIEnv*, jclass, jlong v, jfloat s, jlong result) {
    B2_Vec2::crossVS(*((b2Vec2*) v), s, *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_crossSV(JNIEnv*, jclass, jfloat s, jlong v, jlong result) {
    B2_Vec2::crossSV(s, *((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_leftPerp(JNIEnv*, jclass, jlong v, jlong result) {
    B2_Vec2::leftPerp(*((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_rightPerp(JNIEnv*, jclass, jlong v, jlong result) {
    B2_Vec2::rightPerp(*((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_add(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_Vec2::add(*((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_sub(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_Vec2::sub(*((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_neg(JNIEnv*, jclass, jlong a, jlong result) {
    B2_Vec2::neg(*((b2Vec2*) a), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_lerp(JNIEnv*, jclass, jlong a, jlong b, jfloat t, jlong result) {
    B2_Vec2::lerp(*((b2Vec2*) a), *((b2Vec2*) b), t, *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_mul(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_Vec2::mul(*((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_mulSV(JNIEnv*, jclass, jfloat s, jlong v, jlong result) {
    B2_Vec2::mulSV(s, *((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_mulAdd(JNIEnv*, jclass, jlong a, jfloat s, jlong b, jlong result) {
    B2_Vec2::mulAdd(*((b2Vec2*) a), s, *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_mulSub(JNIEnv*, jclass, jlong a, jfloat s, jlong b, jlong result) {
    B2_Vec2::mulSub(*((b2Vec2*) a), s, *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_abs(JNIEnv*, jclass, jlong a, jlong result) {
    B2_Vec2::abs(*((b2Vec2*) a), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_min(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_Vec2::min(*((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_max(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_Vec2::max(*((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_clamp(JNIEnv*, jclass, jlong v, jlong a, jlong b, jlong result) {
    B2_Vec2::clamp(*((b2Vec2*) v), *((b2Vec2*) a), *((b2Vec2*) b), *((b2Vec2*) result));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_length(JNIEnv*, jclass, jlong v) {
    return (jfloat) B2_Vec2::length(*((b2Vec2*) v));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_distance(JNIEnv*, jclass, jlong a, jlong b) {
    return (jfloat) B2_Vec2::distance(*((b2Vec2*) a), *((b2Vec2*) b));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Vec2_00024Raw_normalize(JNIEnv*, jclass, jlong v, jlong result) {
    B2_Vec2::normalize(*((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Vec2_00024Raw_isNormalized(JNIEnv*, jclass, jlong a) {
    return (jboolean) B2_Vec2::isNormalized(*((b2Vec2*) a));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_getLengthAndNormalize(JNIEnv*, jclass, jlong v, jlong result) {
    return (jfloat) B2_Vec2::getLengthAndNormalize(*((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_lengthSquared(JNIEnv*, jclass, jlong v) {
    return (jfloat) B2_Vec2::lengthSquared(*((b2Vec2*) v));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Vec2_00024Raw_isValid(JNIEnv*, jclass, jlong v) {
    return (jboolean) B2_Vec2::isValid(*((b2Vec2*) v));
}

// B2_Rot
JNIEXPORT jint JNICALL Java_box2d_B2_1Rot__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Rot);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Rot_00024Raw_getAngle(JNIEnv*, jclass, jlong q) {
    return (jfloat) B2_Rot::getAngle(*((b2Rot*) q));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_getXAxis(JNIEnv*, jclass, jlong q, jlong result) {
    B2_Rot::getXAxis(*((b2Rot*) q), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_getYAxis(JNIEnv*, jclass, jlong q, jlong result) {
    B2_Rot::getYAxis(*((b2Rot*) q), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_makeRot(JNIEnv*, jclass, jfloat radians, jlong result) {
    B2_Rot::makeRot(radians, *((b2Rot*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_normalize(JNIEnv*, jclass, jlong q, jlong result) {
    B2_Rot::normalize(*((b2Rot*) q), *((b2Rot*) result));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Rot_00024Raw_isNormalized(JNIEnv*, jclass, jlong q) {
    return (jboolean) B2_Rot::isNormalized(*((b2Rot*) q));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_integrateRotation(JNIEnv*, jclass, jlong q1, jfloat deltaAngle, jlong result) {
    B2_Rot::integrateRotation(*((b2Rot*) q1), deltaAngle, *((b2Rot*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_nLerp(JNIEnv*, jclass, jlong q1, jlong q2, jfloat t, jlong result) {
    B2_Rot::nLerp(*((b2Rot*) q1), *((b2Rot*) q2), t, *((b2Rot*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_mulRot(JNIEnv*, jclass, jlong q, jlong r, jlong result) {
    B2_Rot::mulRot(*((b2Rot*) q), *((b2Rot*) r), *((b2Rot*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_invMulRot(JNIEnv*, jclass, jlong q, jlong r, jlong result) {
    B2_Rot::invMulRot(*((b2Rot*) q), *((b2Rot*) r), *((b2Rot*) result));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Rot_00024Raw_relativeAngle(JNIEnv*, jclass, jlong b, jlong a) {
    return (jfloat) B2_Rot::relativeAngle(*((b2Rot*) b), *((b2Rot*) a));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Rot_00024Raw_unwindAngle(JNIEnv*, jclass, jfloat radians) {
    return (jfloat) B2_Rot::unwindAngle(radians);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_rotateVector(JNIEnv*, jclass, jlong q, jlong v, jlong result) {
    B2_Rot::rotateVector(*((b2Rot*) q), *((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_invRotateVector(JNIEnv*, jclass, jlong q, jlong v, jlong result) {
    B2_Rot::invRotateVector(*((b2Rot*) q), *((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Rot_00024Raw_computeAngularVelocity(JNIEnv*, jclass, jlong q1, jlong q2, jfloat inv_h) {
    return (jfloat) B2_Rot::computeAngularVelocity(*((b2Rot*) q1), *((b2Rot*) q2), inv_h);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Rot_00024Raw_computeRotationBetweenUnitVectors(JNIEnv*, jclass, jlong v1, jlong v2, jlong result) {
    B2_Rot::computeRotationBetweenUnitVectors(*((b2Vec2*) v1), *((b2Vec2*) v2), *((b2Rot*) result));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Rot_00024Raw_isValid(JNIEnv*, jclass, jlong q) {
    return (jboolean) B2_Rot::isValid(*((b2Rot*) q));
}

// B2_Transform
JNIEXPORT jint JNICALL Java_box2d_B2_1Transform__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Transform);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Transform_00024Raw_transformPoint(JNIEnv*, jclass, jlong t, jlong p, jlong result) {
    B2_Transform::transformPoint(*((b2Transform*) t), *((b2Vec2*) p), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Transform_00024Raw_invTransformPoint(JNIEnv*, jclass, jlong t, jlong p, jlong result) {
    B2_Transform::invTransformPoint(*((b2Transform*) t), *((b2Vec2*) p), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Transform_00024Raw_mulTransforms(JNIEnv*, jclass, jlong A, jlong B, jlong result) {
    B2_Transform::mulTransforms(*((b2Transform*) A), *((b2Transform*) B), *((b2Transform*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Transform_00024Raw_invMulTransforms(JNIEnv*, jclass, jlong A, jlong B, jlong result) {
    B2_Transform::invMulTransforms(*((b2Transform*) A), *((b2Transform*) B), *((b2Transform*) result));
}

// B2_Mat22
JNIEXPORT jint JNICALL Java_box2d_B2_1Mat22__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Mat22);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Mat22_00024Raw_mulMV(JNIEnv*, jclass, jlong A, jlong v, jlong result) {
    B2_Mat22::mulMV(*((b2Mat22*) A), *((b2Vec2*) v), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Mat22_00024Raw_getInverse22(JNIEnv*, jclass, jlong A, jlong result) {
    B2_Mat22::getInverse22(*((b2Mat22*) A), *((b2Mat22*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Mat22_00024Raw_solve22(JNIEnv*, jclass, jlong A, jlong b, jlong result) {
    B2_Mat22::solve22(*((b2Mat22*) A), *((b2Vec2*) b), *((b2Vec2*) result));
}

// B2_AABB
JNIEXPORT jint JNICALL Java_box2d_B2_1AABB__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_AABB);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1AABB_00024Raw_contains(JNIEnv*, jclass, jlong a, jlong b) {
    return (jboolean) B2_AABB::contains(*((b2AABB*) a), *((b2AABB*) b));
}
JNIEXPORT void JNICALL Java_box2d_B2_1AABB_00024Raw_center(JNIEnv*, jclass, jlong a, jlong result) {
    B2_AABB::center(*((b2AABB*) a), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1AABB_00024Raw_extents(JNIEnv*, jclass, jlong a, jlong result) {
    B2_AABB::extents(*((b2AABB*) a), *((b2Vec2*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1AABB_00024Raw_unionAABB(JNIEnv*, jclass, jlong a, jlong b, jlong result) {
    B2_AABB::unionAABB(*((b2AABB*) a), *((b2AABB*) b), *((b2AABB*) result));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1AABB_00024Raw_overlaps(JNIEnv*, jclass, jlong a, jlong b) {
    return (jboolean) B2_AABB::overlaps(*((b2AABB*) a), *((b2AABB*) b));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1AABB_00024Raw_isValid(JNIEnv*, jclass, jlong aabb) {
    return (jboolean) B2_AABB::isValid(*((b2AABB*) aabb));
}

// B2_Plane
JNIEXPORT jint JNICALL Java_box2d_B2_1Plane__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Plane);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Plane_00024Raw_planeSeparation(JNIEnv*, jclass, jlong plane, jlong point) {
    return (jfloat) B2_Plane::planeSeparation(*((b2Plane*) plane), *((b2Vec2*) point));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Plane_00024Raw_isValid(JNIEnv*, jclass, jlong plane) {
    return (jboolean) B2_Plane::isValid(*((b2Plane*) plane));
}

// B2_Math
JNIEXPORT jint JNICALL Java_box2d_B2_1Math__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Math);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Math_00024Raw_computeCosSin(JNIEnv*, jclass, jfloat radians, jlong result) {
    B2_Math::computeCosSin(radians, *((b2CosSin*) result));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Math_00024Raw_springDamper(JNIEnv*, jclass, jfloat hertz, jfloat dampingRatio, jfloat position, jfloat velocity, jfloat timeStep) {
    return (jfloat) B2_Math::springDamper(hertz, dampingRatio, position, velocity, timeStep);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Math_00024Raw_setLengthUnitsPerMeter(JNIEnv*, jclass, jfloat lengthUnits) {
    B2_Math::setLengthUnitsPerMeter(lengthUnits);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Math_00024Raw_getLengthUnitsPerMeter(JNIEnv*, jclass) {
    return (jfloat) B2_Math::getLengthUnitsPerMeter();
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

// b2CosSin
JNIEXPORT jint JNICALL Java_box2d_b2CosSin__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CosSin);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CosSin_00024Raw_b2CosSin_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2CosSin();
}
JNIEXPORT jlong JNICALL Java_box2d_b2CosSin_00024Raw_b2CosSin(JNIEnv*, jclass) {
    return (jlong) new b2CosSin();
}
JNIEXPORT void JNICALL Java_box2d_b2CosSin_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CosSin*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2CosSin_00024Raw_getCosine(JNIEnv*, jclass, jlong _address) {
    b2CosSin* _self = (b2CosSin*) _address;
    return (jfloat) _self->cosine;
}
JNIEXPORT void JNICALL Java_box2d_b2CosSin_00024Raw_setCosine(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2CosSin* _self = (b2CosSin*) _address;
    _self->cosine = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2CosSin_00024Raw_getSine(JNIEnv*, jclass, jlong _address) {
    b2CosSin* _self = (b2CosSin*) _address;
    return (jfloat) _self->sine;
}
JNIEXPORT void JNICALL Java_box2d_b2CosSin_00024Raw_setSine(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2CosSin* _self = (b2CosSin*) _address;
    _self->sine = value;
}

// b2Rot
JNIEXPORT jint JNICALL Java_box2d_b2Rot__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Rot);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Rot_00024Raw_b2Rot_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Rot();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Rot_00024Raw_b2Rot(JNIEnv*, jclass) {
    return (jlong) new b2Rot();
}
JNIEXPORT void JNICALL Java_box2d_b2Rot_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Rot*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Rot_00024Raw_getC(JNIEnv*, jclass, jlong _address) {
    b2Rot* _self = (b2Rot*) _address;
    return (jfloat) _self->c;
}
JNIEXPORT void JNICALL Java_box2d_b2Rot_00024Raw_setC(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Rot* _self = (b2Rot*) _address;
    _self->c = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Rot_00024Raw_getS(JNIEnv*, jclass, jlong _address) {
    b2Rot* _self = (b2Rot*) _address;
    return (jfloat) _self->s;
}
JNIEXPORT void JNICALL Java_box2d_b2Rot_00024Raw_setS(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Rot* _self = (b2Rot*) _address;
    _self->s = value;
}

// b2Transform
JNIEXPORT jint JNICALL Java_box2d_b2Transform__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Transform);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Transform_00024Raw_b2Transform_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Transform();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Transform_00024Raw_b2Transform(JNIEnv*, jclass) {
    return (jlong) new b2Transform();
}
JNIEXPORT void JNICALL Java_box2d_b2Transform_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Transform*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Transform_00024Raw_getP(JNIEnv*, jclass, jlong _address) {
    b2Transform* _self = (b2Transform*) _address;
    return (jlong) &_self->p;
}
JNIEXPORT void JNICALL Java_box2d_b2Transform_00024Raw_setP(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Transform* _self = (b2Transform*) _address;
    _self->p = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Transform_00024Raw_getQ(JNIEnv*, jclass, jlong _address) {
    b2Transform* _self = (b2Transform*) _address;
    return (jlong) &_self->q;
}
JNIEXPORT void JNICALL Java_box2d_b2Transform_00024Raw_setQ(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Transform* _self = (b2Transform*) _address;
    _self->q = *((b2Rot*) value);
}

// b2Mat22
JNIEXPORT jint JNICALL Java_box2d_b2Mat22__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Mat22);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Mat22_00024Raw_b2Mat22_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Mat22();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Mat22_00024Raw_b2Mat22(JNIEnv*, jclass) {
    return (jlong) new b2Mat22();
}
JNIEXPORT void JNICALL Java_box2d_b2Mat22_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Mat22*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Mat22_00024Raw_getCx(JNIEnv*, jclass, jlong _address) {
    b2Mat22* _self = (b2Mat22*) _address;
    return (jlong) &_self->cx;
}
JNIEXPORT void JNICALL Java_box2d_b2Mat22_00024Raw_setCx(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Mat22* _self = (b2Mat22*) _address;
    _self->cx = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Mat22_00024Raw_getCy(JNIEnv*, jclass, jlong _address) {
    b2Mat22* _self = (b2Mat22*) _address;
    return (jlong) &_self->cy;
}
JNIEXPORT void JNICALL Java_box2d_b2Mat22_00024Raw_setCy(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Mat22* _self = (b2Mat22*) _address;
    _self->cy = *((b2Vec2*) value);
}

// b2AABB
JNIEXPORT jint JNICALL Java_box2d_b2AABB__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2AABB);
}
JNIEXPORT jlong JNICALL Java_box2d_b2AABB_00024Raw_b2AABB_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2AABB();
}
JNIEXPORT jlong JNICALL Java_box2d_b2AABB_00024Raw_b2AABB(JNIEnv*, jclass) {
    return (jlong) new b2AABB();
}
JNIEXPORT void JNICALL Java_box2d_b2AABB_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2AABB*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2AABB_00024Raw_getLowerBound(JNIEnv*, jclass, jlong _address) {
    b2AABB* _self = (b2AABB*) _address;
    return (jlong) &_self->lowerBound;
}
JNIEXPORT void JNICALL Java_box2d_b2AABB_00024Raw_setLowerBound(JNIEnv*, jclass, jlong _address, jlong value) {
    b2AABB* _self = (b2AABB*) _address;
    _self->lowerBound = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2AABB_00024Raw_getUpperBound(JNIEnv*, jclass, jlong _address) {
    b2AABB* _self = (b2AABB*) _address;
    return (jlong) &_self->upperBound;
}
JNIEXPORT void JNICALL Java_box2d_b2AABB_00024Raw_setUpperBound(JNIEnv*, jclass, jlong _address, jlong value) {
    b2AABB* _self = (b2AABB*) _address;
    _self->upperBound = *((b2Vec2*) value);
}

// b2Plane
JNIEXPORT jint JNICALL Java_box2d_b2Plane__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Plane);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Plane_00024Raw_b2Plane_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Plane();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Plane_00024Raw_b2Plane(JNIEnv*, jclass) {
    return (jlong) new b2Plane();
}
JNIEXPORT void JNICALL Java_box2d_b2Plane_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Plane*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Plane_00024Raw_getNormal(JNIEnv*, jclass, jlong _address) {
    b2Plane* _self = (b2Plane*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_box2d_b2Plane_00024Raw_setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Plane* _self = (b2Plane*) _address;
    _self->normal = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Plane_00024Raw_getOffset(JNIEnv*, jclass, jlong _address) {
    b2Plane* _self = (b2Plane*) _address;
    return (jfloat) _self->offset;
}
JNIEXPORT void JNICALL Java_box2d_b2Plane_00024Raw_setOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Plane* _self = (b2Plane*) _address;
    _self->offset = value;
}

// B2_World
JNIEXPORT jint JNICALL Java_box2d_B2_1World__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_World);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_defaultWorldDef(JNIEnv*, jclass, jlong result) {
    B2_World::defaultWorldDef(*((b2WorldDef*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_createWorld(JNIEnv*, jclass, jlong def) {
    return (jlong) B2_World::createWorld((b2WorldDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_destroyWorld(JNIEnv*, jclass, jlong worldId) {
    B2_World::destroyWorld(worldId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1World_00024Raw_isValid(JNIEnv*, jclass, jlong worldId) {
    return (jboolean) B2_World::isValid(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_step(JNIEnv*, jclass, jlong worldId, jfloat timeStep, jint subStepCount) {
    B2_World::step(worldId, timeStep, subStepCount);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_draw(JNIEnv*, jclass, jlong worldId, jlong draw, jlong callbacks) {
    B2_World::draw(worldId, (b2DebugDraw*) draw, (b2DebugDrawCallbacks*) callbacks);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getBodyEvents(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2BodyEvents _cache = B2_World::getBodyEvents(worldId);
    _cache = B2_World::getBodyEvents(worldId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getSensorEvents(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2SensorEvents _cache = B2_World::getSensorEvents(worldId);
    _cache = B2_World::getSensorEvents(worldId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getContactEvents(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2ContactEvents _cache = B2_World::getContactEvents(worldId);
    _cache = B2_World::getContactEvents(worldId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_overlapAABB(JNIEnv*, jclass, jlong worldId, jlong aabb, jlong filter, jlong fcn) {
    static thread_local b2TreeStats _cache = B2_World::overlapAABB(worldId, *((b2AABB*) aabb), *((b2QueryFilter*) filter), (b2OverlapResultFcnI*) fcn);
    _cache = B2_World::overlapAABB(worldId, *((b2AABB*) aabb), *((b2QueryFilter*) filter), (b2OverlapResultFcnI*) fcn);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_overlapShape(JNIEnv*, jclass, jlong worldId, jlong proxy, jlong filter, jlong fcn) {
    static thread_local b2TreeStats _cache = B2_World::overlapShape(worldId, (b2ShapeProxy*) proxy, *((b2QueryFilter*) filter), (b2OverlapResultFcnI*) fcn);
    _cache = B2_World::overlapShape(worldId, (b2ShapeProxy*) proxy, *((b2QueryFilter*) filter), (b2OverlapResultFcnI*) fcn);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_castRay(JNIEnv*, jclass, jlong worldId, jlong origin, jlong translation, jlong filter, jlong fcn) {
    static thread_local b2TreeStats _cache = B2_World::castRay(worldId, *((b2Vec2*) origin), *((b2Vec2*) translation), *((b2QueryFilter*) filter), (b2CastResultFcnI*) fcn);
    _cache = B2_World::castRay(worldId, *((b2Vec2*) origin), *((b2Vec2*) translation), *((b2QueryFilter*) filter), (b2CastResultFcnI*) fcn);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_castRayClosest(JNIEnv*, jclass, jlong worldId, jlong origin, jlong translation, jlong filter) {
    static thread_local b2RayResult _cache = B2_World::castRayClosest(worldId, *((b2Vec2*) origin), *((b2Vec2*) translation), *((b2QueryFilter*) filter));
    _cache = B2_World::castRayClosest(worldId, *((b2Vec2*) origin), *((b2Vec2*) translation), *((b2QueryFilter*) filter));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_castShape(JNIEnv*, jclass, jlong worldId, jlong proxy, jlong translation, jlong filter, jlong fcn) {
    static thread_local b2TreeStats _cache = B2_World::castShape(worldId, (b2ShapeProxy*) proxy, *((b2Vec2*) translation), *((b2QueryFilter*) filter), (b2CastResultFcnI*) fcn);
    _cache = B2_World::castShape(worldId, (b2ShapeProxy*) proxy, *((b2Vec2*) translation), *((b2QueryFilter*) filter), (b2CastResultFcnI*) fcn);
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1World_00024Raw_castMover(JNIEnv*, jclass, jlong worldId, jlong mover, jlong translation, jlong filter) {
    return (jfloat) B2_World::castMover(worldId, (b2Capsule*) mover, *((b2Vec2*) translation), *((b2QueryFilter*) filter));
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_collideMover(JNIEnv*, jclass, jlong worldId, jlong mover, jlong filter, jlong fcn) {
    B2_World::collideMover(worldId, (b2Capsule*) mover, *((b2QueryFilter*) filter), (b2PlaneResultFcnI*) fcn);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_enableSleeping(JNIEnv*, jclass, jlong worldId, jboolean flag) {
    B2_World::enableSleeping(worldId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1World_00024Raw_isSleepingEnabled(JNIEnv*, jclass, jlong worldId) {
    return (jboolean) B2_World::isSleepingEnabled(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_enableContinuous(JNIEnv*, jclass, jlong worldId, jboolean flag) {
    B2_World::enableContinuous(worldId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1World_00024Raw_isContinuousEnabled(JNIEnv*, jclass, jlong worldId) {
    return (jboolean) B2_World::isContinuousEnabled(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setRestitutionThreshold(JNIEnv*, jclass, jlong worldId, jfloat value) {
    B2_World::setRestitutionThreshold(worldId, value);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1World_00024Raw_getRestitutionThreshold(JNIEnv*, jclass, jlong worldId) {
    return (jfloat) B2_World::getRestitutionThreshold(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setHitEventThreshold(JNIEnv*, jclass, jlong worldId, jfloat value) {
    B2_World::setHitEventThreshold(worldId, value);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1World_00024Raw_getHitEventThreshold(JNIEnv*, jclass, jlong worldId) {
    return (jfloat) B2_World::getHitEventThreshold(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setGravity(JNIEnv*, jclass, jlong worldId, jlong gravity) {
    B2_World::setGravity(worldId, *((b2Vec2*) gravity));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getGravity(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2Vec2 _cache = B2_World::getGravity(worldId);
    _cache = B2_World::getGravity(worldId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setCustomFilterCallback(JNIEnv*, jclass, jlong worldId, jlong fcn) {
    B2_World::setCustomFilterCallback(worldId, (b2CustomFilterFcnI*) fcn);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setPreSolveCallback(JNIEnv*, jclass, jlong worldId, jlong fcn) {
    B2_World::setPreSolveCallback(worldId, (b2PreSolveFcnI*) fcn);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setFrictionCallback(JNIEnv*, jclass, jlong worldId, jlong callback) {
    B2_World::setFrictionCallback(worldId, (b2FrictionCallbackI*) callback);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setRestitutionCallback(JNIEnv*, jclass, jlong worldId, jlong callback) {
    B2_World::setRestitutionCallback(worldId, (b2RestitutionCallbackI*) callback);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_explode(JNIEnv*, jclass, jlong worldId, jlong explosionDef) {
    B2_World::explode(worldId, (b2ExplosionDef*) explosionDef);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setContactTuning(JNIEnv*, jclass, jlong worldId, jfloat hertz, jfloat dampingRatio, jfloat pushSpeed) {
    B2_World::setContactTuning(worldId, hertz, dampingRatio, pushSpeed);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setMaximumLinearSpeed(JNIEnv*, jclass, jlong worldId, jfloat maximumLinearSpeed) {
    B2_World::setMaximumLinearSpeed(worldId, maximumLinearSpeed);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1World_00024Raw_getMaximumLinearSpeed(JNIEnv*, jclass, jlong worldId) {
    return (jfloat) B2_World::getMaximumLinearSpeed(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_enableWarmStarting(JNIEnv*, jclass, jlong worldId, jboolean flag) {
    B2_World::enableWarmStarting(worldId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1World_00024Raw_isWarmStartingEnabled(JNIEnv*, jclass, jlong worldId) {
    return (jboolean) B2_World::isWarmStartingEnabled(worldId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1World_00024Raw_getAwakeBodyCount(JNIEnv*, jclass, jlong worldId) {
    return (jint) B2_World::getAwakeBodyCount(worldId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getProfile(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2Profile _cache = B2_World::getProfile(worldId);
    _cache = B2_World::getProfile(worldId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getCounters(JNIEnv*, jclass, jlong worldId) {
    static thread_local b2Counters _cache = B2_World::getCounters(worldId);
    _cache = B2_World::getCounters(worldId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_dumpMemoryStats(JNIEnv*, jclass, jlong worldId) {
    B2_World::dumpMemoryStats(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_setUserData(JNIEnv*, jclass, jlong worldId, jlong userData) {
    B2_World::setUserData(worldId, (void*) userData);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1World_00024Raw_getUserData(JNIEnv*, jclass, jlong worldId) {
    return (jlong) B2_World::getUserData(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_rebuildStaticTree(JNIEnv*, jclass, jlong worldId) {
    B2_World::rebuildStaticTree(worldId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_enableSpeculative(JNIEnv*, jclass, jlong worldId, jboolean flag) {
    B2_World::enableSpeculative(worldId, flag);
}

// TaskManager
JNIEXPORT jint JNICALL Java_box2d_TaskManager__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(TaskManager);
}
JNIEXPORT void JNICALL Java_box2d_TaskManager_00024Raw_install(JNIEnv*, jclass, jlong _address, jlong worldDef, jint threadCount) {
    TaskManager* self = (TaskManager*) _address;
    self->install(*((b2WorldDef*) worldDef), threadCount);
}
JNIEXPORT void JNICALL Java_box2d_TaskManager_00024Raw_executeTask(JNIEnv*, jclass, jlong _address, jint start, jint end, jint threadIndex, jlong box2dTask, jlong box2dContext) {
    TaskManager* self = (TaskManager*) _address;
    self->executeTask(start, end, threadIndex, box2dTask, box2dContext);
}
JNIEXPORT void JNICALL Java_box2d_TaskManager_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (TaskManager*) _address;
}

// TaskManagerImpl
JNIEXPORT jint JNICALL Java_box2d_TaskManagerImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(TaskManagerImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_TaskManagerImpl__1TaskManagerImpl(JNIEnv* env, jobject obj) {
    return (jlong) new TaskManagerImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_TaskManagerImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (TaskManagerImpl*) address;
}

// b2BodyEvents
JNIEXPORT jint JNICALL Java_box2d_b2BodyEvents__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2BodyEvents);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyEvents_00024Raw_b2BodyEvents_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2BodyEvents();
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyEvents_00024Raw_b2BodyEvents(JNIEnv*, jclass) {
    return (jlong) new b2BodyEvents();
}
JNIEXPORT void JNICALL Java_box2d_b2BodyEvents_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2BodyEvents*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2BodyEvents_00024Raw_getMoveCount(JNIEnv*, jclass, jlong _address) {
    b2BodyEvents* _self = (b2BodyEvents*) _address;
    return (jint) _self->moveCount;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyEvents_00024Raw_setMoveCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2BodyEvents* _self = (b2BodyEvents*) _address;
    _self->moveCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyEvents_00024Raw_getMoveEvents(JNIEnv*, jclass, jlong _address) {
    b2BodyEvents* _self = (b2BodyEvents*) _address;
    return (jlong) _self->moveEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyEvents_00024Raw_setMoveEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyEvents* _self = (b2BodyEvents*) _address;
    _self->moveEvents = (b2BodyMoveEvent*) value;
}

// b2BodyMoveEvent
JNIEXPORT jint JNICALL Java_box2d_b2BodyMoveEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2BodyMoveEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_b2BodyMoveEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2BodyMoveEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_b2BodyMoveEvent(JNIEnv*, jclass) {
    return (jlong) new b2BodyMoveEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2BodyMoveEvent*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_getBodyId(JNIEnv*, jclass, jlong _address) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    return (jlong) &_self->bodyId;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_setBodyId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    _self->bodyId = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_getFellAsleep(JNIEnv*, jclass, jlong _address) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    return (jboolean) _self->fellAsleep;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_setFellAsleep(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    _self->fellAsleep = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_getTransform(JNIEnv*, jclass, jlong _address) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    return (jlong) &_self->transform;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_setTransform(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    _self->transform = *((b2Transform*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyMoveEvent_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyMoveEvent* _self = (b2BodyMoveEvent*) _address;
    _self->userData = (void*) value;
}

// b2SensorEvents
JNIEXPORT jint JNICALL Java_box2d_b2SensorEvents__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2SensorEvents);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEvents_00024Raw_b2SensorEvents_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2SensorEvents();
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEvents_00024Raw_b2SensorEvents(JNIEnv*, jclass) {
    return (jlong) new b2SensorEvents();
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEvents_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2SensorEvents*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2SensorEvents_00024Raw_getBeginCount(JNIEnv*, jclass, jlong _address) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    return (jint) _self->beginCount;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEvents_00024Raw_setBeginCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    _self->beginCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEvents_00024Raw_getBeginEvents(JNIEnv*, jclass, jlong _address) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    return (jlong) _self->beginEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEvents_00024Raw_setBeginEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    _self->beginEvents = (b2SensorBeginTouchEvent*) value;
}
JNIEXPORT jint JNICALL Java_box2d_b2SensorEvents_00024Raw_getEndCount(JNIEnv*, jclass, jlong _address) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    return (jint) _self->endCount;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEvents_00024Raw_setEndCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    _self->endCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEvents_00024Raw_getEndEvents(JNIEnv*, jclass, jlong _address) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    return (jlong) _self->endEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEvents_00024Raw_setEndEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorEvents* _self = (b2SensorEvents*) _address;
    _self->endEvents = (b2SensorEndTouchEvent*) value;
}

// b2SensorBeginTouchEvent
JNIEXPORT jint JNICALL Java_box2d_b2SensorBeginTouchEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2SensorBeginTouchEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_b2SensorBeginTouchEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2SensorBeginTouchEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_b2SensorBeginTouchEvent(JNIEnv*, jclass) {
    return (jlong) new b2SensorBeginTouchEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2SensorBeginTouchEvent*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_getSensorShapeId(JNIEnv*, jclass, jlong _address) {
    b2SensorBeginTouchEvent* _self = (b2SensorBeginTouchEvent*) _address;
    return (jlong) &_self->sensorShapeId;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_setSensorShapeId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorBeginTouchEvent* _self = (b2SensorBeginTouchEvent*) _address;
    _self->sensorShapeId = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_getVisitorShapeId(JNIEnv*, jclass, jlong _address) {
    b2SensorBeginTouchEvent* _self = (b2SensorBeginTouchEvent*) _address;
    return (jlong) &_self->visitorShapeId;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorBeginTouchEvent_00024Raw_setVisitorShapeId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorBeginTouchEvent* _self = (b2SensorBeginTouchEvent*) _address;
    _self->visitorShapeId = *((b2ShapeId*) value);
}

// b2SensorEndTouchEvent
JNIEXPORT jint JNICALL Java_box2d_b2SensorEndTouchEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2SensorEndTouchEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_b2SensorEndTouchEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2SensorEndTouchEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_b2SensorEndTouchEvent(JNIEnv*, jclass) {
    return (jlong) new b2SensorEndTouchEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2SensorEndTouchEvent*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_getSensorShapeId(JNIEnv*, jclass, jlong _address) {
    b2SensorEndTouchEvent* _self = (b2SensorEndTouchEvent*) _address;
    return (jlong) &_self->sensorShapeId;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_setSensorShapeId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorEndTouchEvent* _self = (b2SensorEndTouchEvent*) _address;
    _self->sensorShapeId = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_getVisitorShapeId(JNIEnv*, jclass, jlong _address) {
    b2SensorEndTouchEvent* _self = (b2SensorEndTouchEvent*) _address;
    return (jlong) &_self->visitorShapeId;
}
JNIEXPORT void JNICALL Java_box2d_b2SensorEndTouchEvent_00024Raw_setVisitorShapeId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2SensorEndTouchEvent* _self = (b2SensorEndTouchEvent*) _address;
    _self->visitorShapeId = *((b2ShapeId*) value);
}

// b2ContactEvents
JNIEXPORT jint JNICALL Java_box2d_b2ContactEvents__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactEvents);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEvents_00024Raw_b2ContactEvents_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ContactEvents();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEvents_00024Raw_b2ContactEvents(JNIEnv*, jclass) {
    return (jlong) new b2ContactEvents();
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactEvents*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2ContactEvents_00024Raw_getBeginCount(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jint) _self->beginCount;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setBeginCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->beginCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEvents_00024Raw_getBeginEvents(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jlong) _self->beginEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setBeginEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->beginEvents = (b2ContactBeginTouchEvent*) value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ContactEvents_00024Raw_getEndCount(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jint) _self->endCount;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setEndCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->endCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEvents_00024Raw_getEndEvents(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jlong) _self->endEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setEndEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->endEvents = (b2ContactEndTouchEvent*) value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ContactEvents_00024Raw_getHitCount(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jint) _self->hitCount;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setHitCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->hitCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEvents_00024Raw_getHitEvents(JNIEnv*, jclass, jlong _address) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    return (jlong) _self->hitEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEvents_00024Raw_setHitEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactEvents* _self = (b2ContactEvents*) _address;
    _self->hitEvents = (b2ContactHitEvent*) value;
}

// b2ContactBeginTouchEvent
JNIEXPORT jint JNICALL Java_box2d_b2ContactBeginTouchEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactBeginTouchEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_b2ContactBeginTouchEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ContactBeginTouchEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_b2ContactBeginTouchEvent(JNIEnv*, jclass) {
    return (jlong) new b2ContactBeginTouchEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactBeginTouchEvent*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_getManifold(JNIEnv*, jclass, jlong _address) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    return (jlong) &_self->manifold;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_setManifold(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    _self->manifold = *((b2Manifold*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_getShapeIdA(JNIEnv*, jclass, jlong _address) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    return (jlong) &_self->shapeIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_setShapeIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    _self->shapeIdA = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_getShapeIdB(JNIEnv*, jclass, jlong _address) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    return (jlong) &_self->shapeIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactBeginTouchEvent_00024Raw_setShapeIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactBeginTouchEvent* _self = (b2ContactBeginTouchEvent*) _address;
    _self->shapeIdB = *((b2ShapeId*) value);
}

// b2ContactEndTouchEvent
JNIEXPORT jint JNICALL Java_box2d_b2ContactEndTouchEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactEndTouchEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_b2ContactEndTouchEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ContactEndTouchEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_b2ContactEndTouchEvent(JNIEnv*, jclass) {
    return (jlong) new b2ContactEndTouchEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactEndTouchEvent*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_getShapeIdA(JNIEnv*, jclass, jlong _address) {
    b2ContactEndTouchEvent* _self = (b2ContactEndTouchEvent*) _address;
    return (jlong) &_self->shapeIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_setShapeIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactEndTouchEvent* _self = (b2ContactEndTouchEvent*) _address;
    _self->shapeIdA = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_getShapeIdB(JNIEnv*, jclass, jlong _address) {
    b2ContactEndTouchEvent* _self = (b2ContactEndTouchEvent*) _address;
    return (jlong) &_self->shapeIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactEndTouchEvent_00024Raw_setShapeIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactEndTouchEvent* _self = (b2ContactEndTouchEvent*) _address;
    _self->shapeIdB = *((b2ShapeId*) value);
}

// b2ContactHitEvent
JNIEXPORT jint JNICALL Java_box2d_b2ContactHitEvent__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactHitEvent);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_b2ContactHitEvent_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ContactHitEvent();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_b2ContactHitEvent(JNIEnv*, jclass) {
    return (jlong) new b2ContactHitEvent();
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactHitEvent*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ContactHitEvent_00024Raw_getApproachSpeed(JNIEnv*, jclass, jlong _address) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    return (jfloat) _self->approachSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_setApproachSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    _self->approachSpeed = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_getNormal(JNIEnv*, jclass, jlong _address) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    _self->normal = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_getPoint(JNIEnv*, jclass, jlong _address) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    return (jlong) &_self->point;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_setPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    _self->point = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_getShapeIdA(JNIEnv*, jclass, jlong _address) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    return (jlong) &_self->shapeIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_setShapeIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    _self->shapeIdA = *((b2ShapeId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactHitEvent_00024Raw_getShapeIdB(JNIEnv*, jclass, jlong _address) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    return (jlong) &_self->shapeIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactHitEvent_00024Raw_setShapeIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ContactHitEvent* _self = (b2ContactHitEvent*) _address;
    _self->shapeIdB = *((b2ShapeId*) value);
}

// b2Manifold
JNIEXPORT jint JNICALL Java_box2d_b2Manifold__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Manifold);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Manifold_00024Raw_b2Manifold_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Manifold();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Manifold_00024Raw_b2Manifold(JNIEnv*, jclass) {
    return (jlong) new b2Manifold();
}
JNIEXPORT void JNICALL Java_box2d_b2Manifold_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Manifold*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Manifold_00024Raw_getNormal(JNIEnv*, jclass, jlong _address) {
    b2Manifold* _self = (b2Manifold*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_box2d_b2Manifold_00024Raw_setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Manifold* _self = (b2Manifold*) _address;
    _self->normal = *((b2Vec2*) value);
}
JNIEXPORT jint JNICALL Java_box2d_b2Manifold_00024Raw_getPointCount(JNIEnv*, jclass, jlong _address) {
    b2Manifold* _self = (b2Manifold*) _address;
    return (jint) _self->pointCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Manifold_00024Raw_setPointCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Manifold* _self = (b2Manifold*) _address;
    _self->pointCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Manifold_00024Raw_getPoints(JNIEnv*, jclass, jlong _address, jint _index) {
    b2Manifold* _self = (b2Manifold*) _address;
    return (jlong) &_self->points[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2Manifold_00024Raw_setPoints(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    b2Manifold* _self = (b2Manifold*) _address;
    _self->points[_index] = *((b2ManifoldPoint*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Manifold_00024Raw_getRollingImpulse(JNIEnv*, jclass, jlong _address) {
    b2Manifold* _self = (b2Manifold*) _address;
    return (jfloat) _self->rollingImpulse;
}
JNIEXPORT void JNICALL Java_box2d_b2Manifold_00024Raw_setRollingImpulse(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Manifold* _self = (b2Manifold*) _address;
    _self->rollingImpulse = value;
}

// b2ManifoldPoint
JNIEXPORT jint JNICALL Java_box2d_b2ManifoldPoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ManifoldPoint);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ManifoldPoint_00024Raw_b2ManifoldPoint_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ManifoldPoint();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ManifoldPoint_00024Raw_b2ManifoldPoint(JNIEnv*, jclass) {
    return (jlong) new b2ManifoldPoint();
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ManifoldPoint*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getAnchorA(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jlong) &_self->anchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->anchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getAnchorB(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jlong) &_self->anchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->anchorB = *((b2Vec2*) value);
}
JNIEXPORT jshort JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getId(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jshort) _self->id;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setId(JNIEnv*, jclass, jlong _address, jshort value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->id = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getNormalImpulse(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jfloat) _self->normalImpulse;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setNormalImpulse(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->normalImpulse = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getNormalVelocity(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jfloat) _self->normalVelocity;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setNormalVelocity(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->normalVelocity = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getPersisted(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jboolean) _self->persisted;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setPersisted(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->persisted = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getPoint(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jlong) &_self->point;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->point = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getSeparation(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jfloat) _self->separation;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->separation = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getTangentImpulse(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jfloat) _self->tangentImpulse;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setTangentImpulse(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->tangentImpulse = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ManifoldPoint_00024Raw_getTotalNormalImpulse(JNIEnv*, jclass, jlong _address) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    return (jfloat) _self->totalNormalImpulse;
}
JNIEXPORT void JNICALL Java_box2d_b2ManifoldPoint_00024Raw_setTotalNormalImpulse(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ManifoldPoint* _self = (b2ManifoldPoint*) _address;
    _self->totalNormalImpulse = value;
}

// b2RayResult
JNIEXPORT jint JNICALL Java_box2d_b2RayResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2RayResult);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayResult_00024Raw_b2RayResult_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2RayResult();
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayResult_00024Raw_b2RayResult(JNIEnv*, jclass) {
    return (jlong) new b2RayResult();
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2RayResult*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RayResult_00024Raw_getFraction(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jfloat) _self->fraction;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setFraction(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->fraction = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2RayResult_00024Raw_getHit(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jboolean) _self->hit;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setHit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->hit = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2RayResult_00024Raw_getLeafVisits(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jint) _self->leafVisits;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setLeafVisits(JNIEnv*, jclass, jlong _address, jint value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->leafVisits = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2RayResult_00024Raw_getNodeVisits(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jint) _self->nodeVisits;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setNodeVisits(JNIEnv*, jclass, jlong _address, jint value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->nodeVisits = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayResult_00024Raw_getNormal(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->normal = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayResult_00024Raw_getPoint(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jlong) &_self->point;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->point = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayResult_00024Raw_getShapeId(JNIEnv*, jclass, jlong _address) {
    b2RayResult* _self = (b2RayResult*) _address;
    return (jlong) &_self->shapeId;
}
JNIEXPORT void JNICALL Java_box2d_b2RayResult_00024Raw_setShapeId(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RayResult* _self = (b2RayResult*) _address;
    _self->shapeId = *((b2ShapeId*) value);
}

// b2TreeStats
JNIEXPORT jint JNICALL Java_box2d_b2TreeStats__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2TreeStats);
}
JNIEXPORT jlong JNICALL Java_box2d_b2TreeStats_00024Raw_b2TreeStats_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2TreeStats();
}
JNIEXPORT jlong JNICALL Java_box2d_b2TreeStats_00024Raw_b2TreeStats(JNIEnv*, jclass) {
    return (jlong) new b2TreeStats();
}
JNIEXPORT void JNICALL Java_box2d_b2TreeStats_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2TreeStats*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2TreeStats_00024Raw_getLeafVisits(JNIEnv*, jclass, jlong _address) {
    b2TreeStats* _self = (b2TreeStats*) _address;
    return (jint) _self->leafVisits;
}
JNIEXPORT void JNICALL Java_box2d_b2TreeStats_00024Raw_setLeafVisits(JNIEnv*, jclass, jlong _address, jint value) {
    b2TreeStats* _self = (b2TreeStats*) _address;
    _self->leafVisits = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2TreeStats_00024Raw_getNodeVisits(JNIEnv*, jclass, jlong _address) {
    b2TreeStats* _self = (b2TreeStats*) _address;
    return (jint) _self->nodeVisits;
}
JNIEXPORT void JNICALL Java_box2d_b2TreeStats_00024Raw_setNodeVisits(JNIEnv*, jclass, jlong _address, jint value) {
    b2TreeStats* _self = (b2TreeStats*) _address;
    _self->nodeVisits = value;
}

// b2ExplosionDef
JNIEXPORT jint JNICALL Java_box2d_b2ExplosionDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ExplosionDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ExplosionDef_00024Raw_b2ExplosionDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ExplosionDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ExplosionDef_00024Raw_b2ExplosionDef(JNIEnv*, jclass) {
    return (jlong) new b2ExplosionDef();
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ExplosionDef*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ExplosionDef_00024Raw_getFalloff(JNIEnv*, jclass, jlong _address) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    return (jfloat) _self->falloff;
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_setFalloff(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    _self->falloff = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ExplosionDef_00024Raw_getImpulsePerLength(JNIEnv*, jclass, jlong _address) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    return (jfloat) _self->impulsePerLength;
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_setImpulsePerLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    _self->impulsePerLength = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ExplosionDef_00024Raw_getMaskBits(JNIEnv*, jclass, jlong _address) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    return (jlong) _self->maskBits;
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_setMaskBits(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    _self->maskBits = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ExplosionDef_00024Raw_getPosition(JNIEnv*, jclass, jlong _address) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    _self->position = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ExplosionDef_00024Raw_getRadius(JNIEnv*, jclass, jlong _address) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_box2d_b2ExplosionDef_00024Raw_setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ExplosionDef* _self = (b2ExplosionDef*) _address;
    _self->radius = value;
}

// b2WorldDef
JNIEXPORT jint JNICALL Java_box2d_b2WorldDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2WorldDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldDef_00024Raw_b2WorldDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2WorldDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldDef_00024Raw_b2WorldDef(JNIEnv*, jclass) {
    return (jlong) new b2WorldDef();
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2WorldDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldDef_00024Raw_getGravity(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jlong) &_self->gravity;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setGravity(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->gravity = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getRestitutionThreshold(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->restitutionThreshold;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setRestitutionThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->restitutionThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getHitEventThreshold(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->hitEventThreshold;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setHitEventThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->hitEventThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getContactHertz(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->contactHertz;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setContactHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->contactHertz = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getContactDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->contactDampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setContactDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->contactDampingRatio = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getMaxContactPushSpeed(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->maxContactPushSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setMaxContactPushSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->maxContactPushSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WorldDef_00024Raw_getMaximumLinearSpeed(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jfloat) _self->maximumLinearSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setMaximumLinearSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->maximumLinearSpeed = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WorldDef_00024Raw_getEnableSleep(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jboolean) _self->enableSleep;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setEnableSleep(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->enableSleep = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WorldDef_00024Raw_getEnableContinuous(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jboolean) _self->enableContinuous;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setEnableContinuous(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->enableContinuous = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WorldDef* _self = (b2WorldDef*) _address;
    _self->userData = (void*) value;
}

// b2DebugDraw
JNIEXPORT jint JNICALL Java_box2d_b2DebugDraw__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2DebugDraw);
}
JNIEXPORT jlong JNICALL Java_box2d_b2DebugDraw_00024Raw_b2DebugDraw_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2DebugDraw();
}
JNIEXPORT jlong JNICALL Java_box2d_b2DebugDraw_00024Raw_b2DebugDraw(JNIEnv*, jclass) {
    return (jlong) new b2DebugDraw();
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2DebugDraw*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawingBounds(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jlong) &_self->drawingBounds;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawingBounds(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawingBounds = *((b2AABB*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getUseDrawingBounds(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->useDrawingBounds;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setUseDrawingBounds(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->useDrawingBounds = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawShapes(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawShapes;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawShapes(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawShapes = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawJoints(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawJoints;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawJoints(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawJoints = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawJointExtras(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawJointExtras;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawJointExtras(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawJointExtras = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawBounds(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawBounds;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawBounds(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawBounds = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawMass(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawMass;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawMass(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawMass = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawBodyNames(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawBodyNames;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawBodyNames(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawBodyNames = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawContacts(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawContacts;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawContacts(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawContacts = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawGraphColors(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawGraphColors;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawGraphColors(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawGraphColors = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawContactNormals(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawContactNormals;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawContactNormals(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawContactNormals = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawContactImpulses(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawContactImpulses;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawContactImpulses(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawContactImpulses = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawContactFeatures(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawContactFeatures;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawContactFeatures(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawContactFeatures = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawFrictionImpulses(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawFrictionImpulses;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawFrictionImpulses(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawFrictionImpulses = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DebugDraw_00024Raw_getDrawIslands(JNIEnv*, jclass, jlong _address) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    return (jboolean) _self->drawIslands;
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDraw_00024Raw_setDrawIslands(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DebugDraw* _self = (b2DebugDraw*) _address;
    _self->drawIslands = value;
}

// b2DebugDrawCallbacks
JNIEXPORT jint JNICALL Java_box2d_b2DebugDrawCallbacks__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2DebugDrawCallbacks);
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDrawCallbacks_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2DebugDrawCallbacks*) _address;
}

// b2CustomFilterFcnI
JNIEXPORT jint JNICALL Java_box2d_b2CustomFilterFcnI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CustomFilterFcnI);
}
JNIEXPORT void JNICALL Java_box2d_b2CustomFilterFcnI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CustomFilterFcnI*) _address;
}

// b2PreSolveFcnI
JNIEXPORT jint JNICALL Java_box2d_b2PreSolveFcnI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PreSolveFcnI);
}
JNIEXPORT void JNICALL Java_box2d_b2PreSolveFcnI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2PreSolveFcnI*) _address;
}

// b2FrictionCallbackI
JNIEXPORT jint JNICALL Java_box2d_b2FrictionCallbackI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2FrictionCallbackI);
}
JNIEXPORT void JNICALL Java_box2d_b2FrictionCallbackI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2FrictionCallbackI*) _address;
}

// b2RestitutionCallbackI
JNIEXPORT jint JNICALL Java_box2d_b2RestitutionCallbackI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2RestitutionCallbackI);
}
JNIEXPORT void JNICALL Java_box2d_b2RestitutionCallbackI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2RestitutionCallbackI*) _address;
}

// b2OverlapResultFcnI
JNIEXPORT jint JNICALL Java_box2d_b2OverlapResultFcnI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2OverlapResultFcnI);
}
JNIEXPORT void JNICALL Java_box2d_b2OverlapResultFcnI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2OverlapResultFcnI*) _address;
}

// b2CastResultFcnI
JNIEXPORT jint JNICALL Java_box2d_b2CastResultFcnI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CastResultFcnI);
}
JNIEXPORT void JNICALL Java_box2d_b2CastResultFcnI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CastResultFcnI*) _address;
}

// b2PlaneResultFcnI
JNIEXPORT jint JNICALL Java_box2d_b2PlaneResultFcnI__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PlaneResultFcnI);
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneResultFcnI_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2PlaneResultFcnI*) _address;
}

// b2DebugDrawCallbacksImpl
JNIEXPORT jint JNICALL Java_box2d_b2DebugDrawCallbacksImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2DebugDrawCallbacksImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2DebugDrawCallbacksImpl__1b2DebugDrawCallbacksImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2DebugDrawCallbacksImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2DebugDrawCallbacksImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2DebugDrawCallbacksImpl*) address;
}

// b2CustomFilterFcnImpl
JNIEXPORT jint JNICALL Java_box2d_b2CustomFilterFcnImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CustomFilterFcnImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CustomFilterFcnImpl__1b2CustomFilterFcnImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2CustomFilterFcnImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2CustomFilterFcnImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2CustomFilterFcnImpl*) address;
}

// b2PreSolveFcnImpl
JNIEXPORT jint JNICALL Java_box2d_b2PreSolveFcnImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PreSolveFcnImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PreSolveFcnImpl__1b2PreSolveFcnImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2PreSolveFcnImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2PreSolveFcnImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2PreSolveFcnImpl*) address;
}

// b2FrictionCallbackImpl
JNIEXPORT jint JNICALL Java_box2d_b2FrictionCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2FrictionCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2FrictionCallbackImpl__1b2FrictionCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2FrictionCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2FrictionCallbackImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2FrictionCallbackImpl*) address;
}

// b2RestitutionCallbackImpl
JNIEXPORT jint JNICALL Java_box2d_b2RestitutionCallbackImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2RestitutionCallbackImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RestitutionCallbackImpl__1b2RestitutionCallbackImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2RestitutionCallbackImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2RestitutionCallbackImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2RestitutionCallbackImpl*) address;
}

// b2OverlapResultFcnImpl
JNIEXPORT jint JNICALL Java_box2d_b2OverlapResultFcnImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2OverlapResultFcnImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2OverlapResultFcnImpl__1b2OverlapResultFcnImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2OverlapResultFcnImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2OverlapResultFcnImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2OverlapResultFcnImpl*) address;
}

// b2CastResultFcnImpl
JNIEXPORT jint JNICALL Java_box2d_b2CastResultFcnImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CastResultFcnImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CastResultFcnImpl__1b2CastResultFcnImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2CastResultFcnImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2CastResultFcnImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2CastResultFcnImpl*) address;
}

// b2PlaneResultFcnImpl
JNIEXPORT jint JNICALL Java_box2d_b2PlaneResultFcnImpl__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PlaneResultFcnImpl);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneResultFcnImpl__1b2PlaneResultFcnImpl(JNIEnv* env, jobject obj) {
    return (jlong) new b2PlaneResultFcnImpl(env, obj);
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneResultFcnImpl__1destroy(JNIEnv*, jclass, jlong address) {
    delete (b2PlaneResultFcnImpl*) address;
}

// b2Counters
JNIEXPORT jint JNICALL Java_box2d_b2Counters__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Counters);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Counters_00024Raw_b2Counters(JNIEnv*, jclass) {
    return (jlong) new b2Counters();
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Counters*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getBodyCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->bodyCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setBodyCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->bodyCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getShapeCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->shapeCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setShapeCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->shapeCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getContactCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->contactCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setContactCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->contactCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getJointCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->jointCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setJointCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->jointCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getIslandCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->islandCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setIslandCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->islandCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getStackUsed(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->stackUsed;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setStackUsed(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->stackUsed = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getStaticTreeHeight(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->staticTreeHeight;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setStaticTreeHeight(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->staticTreeHeight = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getTreeHeight(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->treeHeight;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setTreeHeight(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->treeHeight = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getByteCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->byteCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setByteCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->byteCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getTaskCount(JNIEnv*, jclass, jlong _address) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->taskCount;
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setTaskCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->taskCount = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Counters_00024Raw_getColorCounts(JNIEnv*, jclass, jlong _address, jint _index) {
    b2Counters* _self = (b2Counters*) _address;
    return (jint) _self->colorCounts[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2Counters_00024Raw_setColorCounts(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    b2Counters* _self = (b2Counters*) _address;
    _self->colorCounts[_index] = value;
}

// b2Profile
JNIEXPORT jint JNICALL Java_box2d_b2Profile__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Profile);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Profile_00024Raw_b2Profile(JNIEnv*, jclass) {
    return (jlong) new b2Profile();
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Profile*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getStep(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->step;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setStep(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->step = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getPairs(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->pairs;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setPairs(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->pairs = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getCollide(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->collide;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setCollide(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->collide = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSolve(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->solve;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSolve(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->solve = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getMergeIslands(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->mergeIslands;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setMergeIslands(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->mergeIslands = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getPrepareStages(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->prepareStages;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setPrepareStages(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->prepareStages = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSolveConstraints(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->solveConstraints;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSolveConstraints(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->solveConstraints = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getPrepareConstraints(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->prepareConstraints;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setPrepareConstraints(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->prepareConstraints = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getIntegrateVelocities(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->integrateVelocities;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setIntegrateVelocities(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->integrateVelocities = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getWarmStart(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->warmStart;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setWarmStart(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->warmStart = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSolveImpulses(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->solveImpulses;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSolveImpulses(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->solveImpulses = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getIntegratePositions(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->integratePositions;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setIntegratePositions(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->integratePositions = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getRelaxImpulses(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->relaxImpulses;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setRelaxImpulses(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->relaxImpulses = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getApplyRestitution(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->applyRestitution;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setApplyRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->applyRestitution = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getStoreImpulses(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->storeImpulses;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setStoreImpulses(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->storeImpulses = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSplitIslands(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->splitIslands;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSplitIslands(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->splitIslands = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getTransforms(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->transforms;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setTransforms(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->transforms = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getHitEvents(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->hitEvents;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setHitEvents(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->hitEvents = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getRefit(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->refit;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setRefit(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->refit = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getBullets(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->bullets;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setBullets(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->bullets = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSleepIslands(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->sleepIslands;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSleepIslands(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->sleepIslands = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Profile_00024Raw_getSensors(JNIEnv*, jclass, jlong _address) {
    b2Profile* _self = (b2Profile*) _address;
    return (jfloat) _self->sensors;
}
JNIEXPORT void JNICALL Java_box2d_b2Profile_00024Raw_setSensors(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Profile* _self = (b2Profile*) _address;
    _self->sensors = value;
}

// B2_Base
JNIEXPORT jint JNICALL Java_box2d_B2_1Base__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Base);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_getVersion(JNIEnv*, jclass) {
    static thread_local b2Version _cache = B2_Base::getVersion();
    _cache = B2_Base::getVersion();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Base_00024Raw_getByteCount(JNIEnv*, jclass) {
    return (jint) B2_Base::getByteCount();
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_storeWorldId(JNIEnv*, jclass, jlong worldId) {
    return (jlong) B2_Base::storeWorldId(*((b2WorldId*) worldId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Base_00024Raw_loadWorldId(JNIEnv*, jclass, jlong worldId, jlong result) {
    B2_Base::loadWorldId(worldId, *((b2WorldId*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_storeBodyId(JNIEnv*, jclass, jlong bodyId) {
    return (jlong) B2_Base::storeBodyId(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Base_00024Raw_loadBodyId(JNIEnv*, jclass, jlong bodyId, jlong result) {
    B2_Base::loadBodyId(bodyId, *((b2BodyId*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_storeShapeId(JNIEnv*, jclass, jlong shapeId) {
    return (jlong) B2_Base::storeShapeId(*((b2ShapeId*) shapeId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Base_00024Raw_loadShapeId(JNIEnv*, jclass, jlong shapeId, jlong result) {
    B2_Base::loadShapeId(shapeId, *((b2ShapeId*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_storeChainId(JNIEnv*, jclass, jlong chainId) {
    return (jlong) B2_Base::storeChainId(*((b2ChainId*) chainId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Base_00024Raw_loadChainId(JNIEnv*, jclass, jlong chainId, jlong result) {
    B2_Base::loadChainId(chainId, *((b2ChainId*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_storeJointId(JNIEnv*, jclass, jlong jointId) {
    return (jlong) B2_Base::storeJointId(*((b2JointId*) jointId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Base_00024Raw_loadJointId(JNIEnv*, jclass, jlong jointId, jlong result) {
    B2_Base::loadJointId(jointId, *((b2JointId*) result));
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

// b2WorldId
JNIEXPORT jint JNICALL Java_box2d_b2WorldId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2WorldId);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldId_00024Raw_b2WorldId_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2WorldId();
}
JNIEXPORT jlong JNICALL Java_box2d_b2WorldId_00024Raw_b2WorldId(JNIEnv*, jclass) {
    return (jlong) new b2WorldId();
}
JNIEXPORT void JNICALL Java_box2d_b2WorldId_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2WorldId*) _address;
}
JNIEXPORT jshort JNICALL Java_box2d_b2WorldId_00024Raw_getGeneration(JNIEnv*, jclass, jlong _address) {
    b2WorldId* _self = (b2WorldId*) _address;
    return (jshort) _self->generation;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldId_00024Raw_setGeneration(JNIEnv*, jclass, jlong _address, jshort value) {
    b2WorldId* _self = (b2WorldId*) _address;
    _self->generation = value;
}
JNIEXPORT jshort JNICALL Java_box2d_b2WorldId_00024Raw_getIndex1(JNIEnv*, jclass, jlong _address) {
    b2WorldId* _self = (b2WorldId*) _address;
    return (jshort) _self->index1;
}
JNIEXPORT void JNICALL Java_box2d_b2WorldId_00024Raw_setIndex1(JNIEnv*, jclass, jlong _address, jshort value) {
    b2WorldId* _self = (b2WorldId*) _address;
    _self->index1 = value;
}

// b2BodyId
JNIEXPORT jint JNICALL Java_box2d_b2BodyId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2BodyId);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyId_00024Raw_b2BodyId_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2BodyId();
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyId_00024Raw_b2BodyId(JNIEnv*, jclass) {
    return (jlong) new b2BodyId();
}
JNIEXPORT void JNICALL Java_box2d_b2BodyId_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2BodyId*) _address;
}
JNIEXPORT jshort JNICALL Java_box2d_b2BodyId_00024Raw_getGeneration(JNIEnv*, jclass, jlong _address) {
    b2BodyId* _self = (b2BodyId*) _address;
    return (jshort) _self->generation;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyId_00024Raw_setGeneration(JNIEnv*, jclass, jlong _address, jshort value) {
    b2BodyId* _self = (b2BodyId*) _address;
    _self->generation = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2BodyId_00024Raw_getIndex1(JNIEnv*, jclass, jlong _address) {
    b2BodyId* _self = (b2BodyId*) _address;
    return (jint) _self->index1;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyId_00024Raw_setIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    b2BodyId* _self = (b2BodyId*) _address;
    _self->index1 = value;
}
JNIEXPORT jshort JNICALL Java_box2d_b2BodyId_00024Raw_getWorld0(JNIEnv*, jclass, jlong _address) {
    b2BodyId* _self = (b2BodyId*) _address;
    return (jshort) _self->world0;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyId_00024Raw_setWorld0(JNIEnv*, jclass, jlong _address, jshort value) {
    b2BodyId* _self = (b2BodyId*) _address;
    _self->world0 = value;
}

// b2ShapeId
JNIEXPORT jint JNICALL Java_box2d_b2ShapeId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeId);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeId_00024Raw_b2ShapeId_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ShapeId();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeId_00024Raw_b2ShapeId(JNIEnv*, jclass) {
    return (jlong) new b2ShapeId();
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeId_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ShapeId*) _address;
}
JNIEXPORT jshort JNICALL Java_box2d_b2ShapeId_00024Raw_getGeneration(JNIEnv*, jclass, jlong _address) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    return (jshort) _self->generation;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeId_00024Raw_setGeneration(JNIEnv*, jclass, jlong _address, jshort value) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    _self->generation = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeId_00024Raw_getIndex1(JNIEnv*, jclass, jlong _address) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    return (jint) _self->index1;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeId_00024Raw_setIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    _self->index1 = value;
}
JNIEXPORT jshort JNICALL Java_box2d_b2ShapeId_00024Raw_getWorld0(JNIEnv*, jclass, jlong _address) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    return (jshort) _self->world0;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeId_00024Raw_setWorld0(JNIEnv*, jclass, jlong _address, jshort value) {
    b2ShapeId* _self = (b2ShapeId*) _address;
    _self->world0 = value;
}

// b2ChainId
JNIEXPORT jint JNICALL Java_box2d_b2ChainId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ChainId);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainId_00024Raw_b2ChainId_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ChainId();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainId_00024Raw_b2ChainId(JNIEnv*, jclass) {
    return (jlong) new b2ChainId();
}
JNIEXPORT void JNICALL Java_box2d_b2ChainId_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ChainId*) _address;
}
JNIEXPORT jshort JNICALL Java_box2d_b2ChainId_00024Raw_getGeneration(JNIEnv*, jclass, jlong _address) {
    b2ChainId* _self = (b2ChainId*) _address;
    return (jshort) _self->generation;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainId_00024Raw_setGeneration(JNIEnv*, jclass, jlong _address, jshort value) {
    b2ChainId* _self = (b2ChainId*) _address;
    _self->generation = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2ChainId_00024Raw_getIndex1(JNIEnv*, jclass, jlong _address) {
    b2ChainId* _self = (b2ChainId*) _address;
    return (jint) _self->index1;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainId_00024Raw_setIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    b2ChainId* _self = (b2ChainId*) _address;
    _self->index1 = value;
}
JNIEXPORT jshort JNICALL Java_box2d_b2ChainId_00024Raw_getWorld0(JNIEnv*, jclass, jlong _address) {
    b2ChainId* _self = (b2ChainId*) _address;
    return (jshort) _self->world0;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainId_00024Raw_setWorld0(JNIEnv*, jclass, jlong _address, jshort value) {
    b2ChainId* _self = (b2ChainId*) _address;
    _self->world0 = value;
}

// b2JointId
JNIEXPORT jint JNICALL Java_box2d_b2JointId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2JointId);
}
JNIEXPORT jlong JNICALL Java_box2d_b2JointId_00024Raw_b2JointId_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2JointId();
}
JNIEXPORT jlong JNICALL Java_box2d_b2JointId_00024Raw_b2JointId(JNIEnv*, jclass) {
    return (jlong) new b2JointId();
}
JNIEXPORT void JNICALL Java_box2d_b2JointId_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2JointId*) _address;
}
JNIEXPORT jshort JNICALL Java_box2d_b2JointId_00024Raw_getGeneration(JNIEnv*, jclass, jlong _address) {
    b2JointId* _self = (b2JointId*) _address;
    return (jshort) _self->generation;
}
JNIEXPORT void JNICALL Java_box2d_b2JointId_00024Raw_setGeneration(JNIEnv*, jclass, jlong _address, jshort value) {
    b2JointId* _self = (b2JointId*) _address;
    _self->generation = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointId_00024Raw_getIndex1(JNIEnv*, jclass, jlong _address) {
    b2JointId* _self = (b2JointId*) _address;
    return (jint) _self->index1;
}
JNIEXPORT void JNICALL Java_box2d_b2JointId_00024Raw_setIndex1(JNIEnv*, jclass, jlong _address, jint value) {
    b2JointId* _self = (b2JointId*) _address;
    _self->index1 = value;
}
JNIEXPORT jshort JNICALL Java_box2d_b2JointId_00024Raw_getWorld0(JNIEnv*, jclass, jlong _address) {
    b2JointId* _self = (b2JointId*) _address;
    return (jshort) _self->world0;
}
JNIEXPORT void JNICALL Java_box2d_b2JointId_00024Raw_setWorld0(JNIEnv*, jclass, jlong _address, jshort value) {
    b2JointId* _self = (b2JointId*) _address;
    _self->world0 = value;
}

// b2ShapeIdArray
JNIEXPORT jint JNICALL Java_box2d_b2ShapeIdArray__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeIdArray);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeIdArray_00024Raw_b2ShapeIdArray_1placed(JNIEnv*, jclass, jlong _placement_address, jint length) {
    return (jlong) new((void*)_placement_address) b2ShapeIdArray(length);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeIdArray_00024Raw_b2ShapeIdArray(JNIEnv*, jclass, jint length) {
    return (jlong) new b2ShapeIdArray(length);
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeIdArray_00024Raw_set(JNIEnv*, jclass, jlong _address, jint index, jlong value) {
    b2ShapeIdArray* self = (b2ShapeIdArray*) _address;
    self->set(index, *((b2ShapeId*) value));
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeIdArray_00024Raw_get(JNIEnv*, jclass, jlong _address, jint index) {
    b2ShapeIdArray* self = (b2ShapeIdArray*) _address;
    return (jlong) self->get(index);
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeIdArray_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ShapeIdArray*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeIdArray_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2ShapeIdArray* _self = (b2ShapeIdArray*) _address;
    return (jint) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeIdArray_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jint value) {
    b2ShapeIdArray* _self = (b2ShapeIdArray*) _address;
    _self->length = value;
}

// b2JointIdArray
JNIEXPORT jint JNICALL Java_box2d_b2JointIdArray__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2JointIdArray);
}
JNIEXPORT jlong JNICALL Java_box2d_b2JointIdArray_00024Raw_b2JointIdArray_1placed(JNIEnv*, jclass, jlong _placement_address, jint length) {
    return (jlong) new((void*)_placement_address) b2JointIdArray(length);
}
JNIEXPORT jlong JNICALL Java_box2d_b2JointIdArray_00024Raw_b2JointIdArray(JNIEnv*, jclass, jint length) {
    return (jlong) new b2JointIdArray(length);
}
JNIEXPORT void JNICALL Java_box2d_b2JointIdArray_00024Raw_set(JNIEnv*, jclass, jlong _address, jint index, jlong value) {
    b2JointIdArray* self = (b2JointIdArray*) _address;
    self->set(index, *((b2JointId*) value));
}
JNIEXPORT jlong JNICALL Java_box2d_b2JointIdArray_00024Raw_get(JNIEnv*, jclass, jlong _address, jint index) {
    b2JointIdArray* self = (b2JointIdArray*) _address;
    return (jlong) self->get(index);
}
JNIEXPORT void JNICALL Java_box2d_b2JointIdArray_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2JointIdArray*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointIdArray_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2JointIdArray* _self = (b2JointIdArray*) _address;
    return (jint) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2JointIdArray_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jint value) {
    b2JointIdArray* _self = (b2JointIdArray*) _address;
    _self->length = value;
}

// b2ContactDataArray
JNIEXPORT jint JNICALL Java_box2d_b2ContactDataArray__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ContactDataArray);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactDataArray_00024Raw_b2ContactDataArray_1placed(JNIEnv*, jclass, jlong _placement_address, jint length) {
    return (jlong) new((void*)_placement_address) b2ContactDataArray(length);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactDataArray_00024Raw_b2ContactDataArray(JNIEnv*, jclass, jint length) {
    return (jlong) new b2ContactDataArray(length);
}
JNIEXPORT void JNICALL Java_box2d_b2ContactDataArray_00024Raw_set(JNIEnv*, jclass, jlong _address, jint index, jlong value) {
    b2ContactDataArray* self = (b2ContactDataArray*) _address;
    self->set(index, *((b2ContactData*) value));
}
JNIEXPORT jlong JNICALL Java_box2d_b2ContactDataArray_00024Raw_get(JNIEnv*, jclass, jlong _address, jint index) {
    b2ContactDataArray* self = (b2ContactDataArray*) _address;
    return (jlong) self->get(index);
}
JNIEXPORT void JNICALL Java_box2d_b2ContactDataArray_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ContactDataArray*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2ContactDataArray_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2ContactDataArray* _self = (b2ContactDataArray*) _address;
    return (jint) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2ContactDataArray_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jint value) {
    b2ContactDataArray* _self = (b2ContactDataArray*) _address;
    _self->length = value;
}

// b2CollisionPlaneArray
JNIEXPORT jint JNICALL Java_box2d_b2CollisionPlaneArray__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CollisionPlaneArray);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_b2CollisionPlaneArray_1placed(JNIEnv*, jclass, jlong _placement_address, jint length) {
    return (jlong) new((void*)_placement_address) b2CollisionPlaneArray(length);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_b2CollisionPlaneArray(JNIEnv*, jclass, jint length) {
    return (jlong) new b2CollisionPlaneArray(length);
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_set(JNIEnv*, jclass, jlong _address, jint index, jlong value) {
    b2CollisionPlaneArray* self = (b2CollisionPlaneArray*) _address;
    self->set(index, *((b2CollisionPlane*) value));
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_get(JNIEnv*, jclass, jlong _address, jint index) {
    b2CollisionPlaneArray* self = (b2CollisionPlaneArray*) _address;
    return (jlong) self->get(index);
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CollisionPlaneArray*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2CollisionPlaneArray* _self = (b2CollisionPlaneArray*) _address;
    return (jint) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlaneArray_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jint value) {
    b2CollisionPlaneArray* _self = (b2CollisionPlaneArray*) _address;
    _self->length = value;
}

// b2Vec2Array
JNIEXPORT jint JNICALL Java_box2d_b2Vec2Array__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Vec2Array);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Vec2Array_00024Raw_b2Vec2Array_1placed(JNIEnv*, jclass, jlong _placement_address, jint length) {
    return (jlong) new((void*)_placement_address) b2Vec2Array(length);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Vec2Array_00024Raw_b2Vec2Array(JNIEnv*, jclass, jint length) {
    return (jlong) new b2Vec2Array(length);
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2Array_00024Raw_set(JNIEnv*, jclass, jlong _address, jint index, jlong value) {
    b2Vec2Array* self = (b2Vec2Array*) _address;
    self->set(index, *((b2Vec2*) value));
}
JNIEXPORT jlong JNICALL Java_box2d_b2Vec2Array_00024Raw_get(JNIEnv*, jclass, jlong _address, jint index) {
    b2Vec2Array* self = (b2Vec2Array*) _address;
    return (jlong) self->get(index);
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2Array_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Vec2Array*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2Vec2Array_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2Vec2Array* _self = (b2Vec2Array*) _address;
    return (jint) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2Vec2Array_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jint value) {
    b2Vec2Array* _self = (b2Vec2Array*) _address;
    _self->length = value;
}

// B2_Body
JNIEXPORT jint JNICALL Java_box2d_B2_1Body__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Body);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_defaultBodyDef(JNIEnv*, jclass, jlong result) {
    B2_Body::defaultBodyDef(*((b2BodyDef*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_createBody(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_Body::createBody(worldId, (b2BodyDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_destroyBody(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::destroyBody(bodyId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isValid(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isValid(bodyId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getType(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getType(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setType(JNIEnv*, jclass, jlong bodyId, jint type) {
    B2_Body::setType(bodyId, (b2BodyType) type);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getPosition(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getPosition(bodyId);
    _cache = B2_Body::getPosition(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getRotation(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Rot _cache = B2_Body::getRotation(bodyId);
    _cache = B2_Body::getRotation(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getTransform(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Transform _cache = B2_Body::getTransform(bodyId);
    _cache = B2_Body::getTransform(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setTransform(JNIEnv*, jclass, jlong bodyId, jlong position, jlong rotation) {
    B2_Body::setTransform(bodyId, *((b2Vec2*) position), *((b2Rot*) rotation));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_computeAABB(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2AABB _cache = B2_Body::computeAABB(bodyId);
    _cache = B2_Body::computeAABB(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalPoint(JNIEnv*, jclass, jlong bodyId, jlong worldPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalPoint(bodyId, *((b2Vec2*) worldPoint));
    _cache = B2_Body::getLocalPoint(bodyId, *((b2Vec2*) worldPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldPoint(JNIEnv*, jclass, jlong bodyId, jlong localPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldPoint(bodyId, *((b2Vec2*) localPoint));
    _cache = B2_Body::getWorldPoint(bodyId, *((b2Vec2*) localPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalVector(JNIEnv*, jclass, jlong bodyId, jlong worldVector) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalVector(bodyId, *((b2Vec2*) worldVector));
    _cache = B2_Body::getLocalVector(bodyId, *((b2Vec2*) worldVector));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldVector(JNIEnv*, jclass, jlong bodyId, jlong localVector) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldVector(bodyId, *((b2Vec2*) localVector));
    _cache = B2_Body::getWorldVector(bodyId, *((b2Vec2*) localVector));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLinearVelocity(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getLinearVelocity(bodyId);
    _cache = B2_Body::getLinearVelocity(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getAngularVelocity(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getAngularVelocity(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setLinearVelocity(JNIEnv*, jclass, jlong bodyId, jlong linearVelocity) {
    B2_Body::setLinearVelocity(bodyId, *((b2Vec2*) linearVelocity));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAngularVelocity(JNIEnv*, jclass, jlong bodyId, jfloat angularVelocity) {
    B2_Body::setAngularVelocity(bodyId, angularVelocity);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setTargetTransform(JNIEnv*, jclass, jlong bodyId, jlong target, jfloat timeStep) {
    B2_Body::setTargetTransform(bodyId, *((b2Transform*) target), timeStep);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalPointVelocity(JNIEnv*, jclass, jlong bodyId, jlong localPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalPointVelocity(bodyId, *((b2Vec2*) localPoint));
    _cache = B2_Body::getLocalPointVelocity(bodyId, *((b2Vec2*) localPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldPointVelocity(JNIEnv*, jclass, jlong bodyId, jlong worldPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldPointVelocity(bodyId, *((b2Vec2*) worldPoint));
    _cache = B2_Body::getWorldPointVelocity(bodyId, *((b2Vec2*) worldPoint));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyForce(JNIEnv*, jclass, jlong bodyId, jlong force, jlong point, jboolean wake) {
    B2_Body::applyForce(bodyId, *((b2Vec2*) force), *((b2Vec2*) point), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyForceToCenter(JNIEnv*, jclass, jlong bodyId, jlong force, jboolean wake) {
    B2_Body::applyForceToCenter(bodyId, *((b2Vec2*) force), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyTorque(JNIEnv*, jclass, jlong bodyId, jfloat torque, jboolean wake) {
    B2_Body::applyTorque(bodyId, torque, wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyLinearImpulse(JNIEnv*, jclass, jlong bodyId, jlong impulse, jlong point, jboolean wake) {
    B2_Body::applyLinearImpulse(bodyId, *((b2Vec2*) impulse), *((b2Vec2*) point), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyLinearImpulseToCenter(JNIEnv*, jclass, jlong bodyId, jlong impulse, jboolean wake) {
    B2_Body::applyLinearImpulseToCenter(bodyId, *((b2Vec2*) impulse), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyAngularImpulse(JNIEnv*, jclass, jlong bodyId, jfloat impulse, jboolean wake) {
    B2_Body::applyAngularImpulse(bodyId, impulse, wake);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getMass(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getMass(bodyId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getRotationalInertia(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getRotationalInertia(bodyId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalCenterOfMass(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalCenterOfMass(bodyId);
    _cache = B2_Body::getLocalCenterOfMass(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldCenterOfMass(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldCenterOfMass(bodyId);
    _cache = B2_Body::getWorldCenterOfMass(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setMassData(JNIEnv*, jclass, jlong bodyId, jlong massData) {
    B2_Body::setMassData(bodyId, *((b2MassData*) massData));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getMassData(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2MassData _cache = B2_Body::getMassData(bodyId);
    _cache = B2_Body::getMassData(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyMassFromShapes(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::applyMassFromShapes(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setLinearDamping(JNIEnv*, jclass, jlong bodyId, jfloat linearDamping) {
    B2_Body::setLinearDamping(bodyId, linearDamping);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getLinearDamping(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getLinearDamping(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAngularDamping(JNIEnv*, jclass, jlong bodyId, jfloat angularDamping) {
    B2_Body::setAngularDamping(bodyId, angularDamping);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getAngularDamping(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getAngularDamping(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setGravityScale(JNIEnv*, jclass, jlong bodyId, jfloat gravityScale) {
    B2_Body::setGravityScale(bodyId, gravityScale);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getGravityScale(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getGravityScale(bodyId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isAwake(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isAwake(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAwake(JNIEnv*, jclass, jlong bodyId, jboolean awake) {
    B2_Body::setAwake(bodyId, awake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableSleep(JNIEnv*, jclass, jlong bodyId, jboolean enableSleep) {
    B2_Body::enableSleep(bodyId, enableSleep);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isSleepEnabled(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isSleepEnabled(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setSleepThreshold(JNIEnv*, jclass, jlong bodyId, jfloat sleepThreshold) {
    B2_Body::setSleepThreshold(bodyId, sleepThreshold);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getSleepThreshold(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getSleepThreshold(bodyId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isEnabled(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isEnabled(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_disable(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::disable(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enable(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::enable(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setFixedRotation(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::setFixedRotation(bodyId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isFixedRotation(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isFixedRotation(bodyId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setBullet(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::setBullet(bodyId, flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isBullet(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isBullet(bodyId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorld(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2WorldId _cache = B2_Body::getWorld(bodyId);
    _cache = B2_Body::getWorld(bodyId);
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getShapeCount(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getShapeCount(bodyId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getShapes(JNIEnv*, jclass, jlong bodyId, jlong shapeArray) {
    return (jint) B2_Body::getShapes(bodyId, (b2ShapeIdArray*) shapeArray);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getJointCount(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getJointCount(bodyId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getJoints(JNIEnv*, jclass, jlong bodyId, jlong jointArray) {
    return (jint) B2_Body::getJoints(bodyId, (b2JointIdArray*) jointArray);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableContactEvents(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::enableContactEvents(bodyId, flag);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableHitEvents(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::enableHitEvents(bodyId, flag);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getContactCapacity(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getContactCapacity(bodyId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getContactData(JNIEnv*, jclass, jlong bodyId, jlong contactData) {
    return (jint) B2_Body::getContactData(bodyId, (b2ContactDataArray*) contactData);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setName(JNIEnv* _env, jclass, jlong bodyId, jstring name) {
    B2_Body::setName(bodyId, _env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_box2d_B2_1Body_00024Raw_getName(JNIEnv* _env, jclass, jlong bodyId) {
    return _env->NewStringUTF(B2_Body::getName(bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setUserData(JNIEnv*, jclass, jlong bodyId, jlong userData) {
    B2_Body::setUserData(bodyId, (void*) userData);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getUserData(JNIEnv*, jclass, jlong bodyId) {
    return (jlong) B2_Body::getUserData(bodyId);
}

// b2BodyDef
JNIEXPORT jint JNICALL Java_box2d_b2BodyDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2BodyDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_b2BodyDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2BodyDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_b2BodyDef(JNIEnv*, jclass) {
    return (jlong) new b2BodyDef();
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2BodyDef*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2BodyDef_00024Raw_getType(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jint) _self->type;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setType(JNIEnv*, jclass, jlong _address, jint value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->type = (b2BodyType) value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_getPosition(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->position = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_getRotation(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jlong) &_self->rotation;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setRotation(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->rotation = *((b2Rot*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_getLinearVelocity(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jlong) &_self->linearVelocity;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setLinearVelocity(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->linearVelocity = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2BodyDef_00024Raw_getAngularVelocity(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jfloat) _self->angularVelocity;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setAngularVelocity(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->angularVelocity = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2BodyDef_00024Raw_getLinearDamping(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jfloat) _self->linearDamping;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setLinearDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->linearDamping = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2BodyDef_00024Raw_getAngularDamping(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jfloat) _self->angularDamping;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setAngularDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->angularDamping = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2BodyDef_00024Raw_getGravityScale(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jfloat) _self->gravityScale;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setGravityScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->gravityScale = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2BodyDef_00024Raw_getSleepThreshold(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jfloat) _self->sleepThreshold;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setSleepThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->sleepThreshold = value;
}
JNIEXPORT jstring JNICALL Java_box2d_b2BodyDef_00024Raw_getName(JNIEnv* _env, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return _env->NewStringUTF(_self->name);
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setName(JNIEnv* _env, jclass, jlong _address, jstring value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->name = _env->GetStringUTFChars(value, 0);
}
JNIEXPORT jlong JNICALL Java_box2d_b2BodyDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getEnableSleep(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->enableSleep;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setEnableSleep(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->enableSleep = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getIsAwake(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->isAwake;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setIsAwake(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->isAwake = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getFixedRotation(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->fixedRotation;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setFixedRotation(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->fixedRotation = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getIsBullet(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->isBullet;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setIsBullet(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->isBullet = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getIsEnabled(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->isEnabled;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setIsEnabled(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->isEnabled = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2BodyDef_00024Raw_getAllowFastRotation(JNIEnv*, jclass, jlong _address) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    return (jboolean) _self->allowFastRotation;
}
JNIEXPORT void JNICALL Java_box2d_b2BodyDef_00024Raw_setAllowFastRotation(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2BodyDef* _self = (b2BodyDef*) _address;
    _self->allowFastRotation = value;
}

// B2_CharacterMover
JNIEXPORT jint JNICALL Java_box2d_B2_1CharacterMover__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_CharacterMover);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1CharacterMover_00024Raw_solvePlanes(JNIEnv*, jclass, jlong targetDelta, jlong planes) {
    static thread_local b2PlaneSolverResult _cache = B2_CharacterMover::solvePlanes(*((b2Vec2*) targetDelta), (b2CollisionPlaneArray*) planes);
    _cache = B2_CharacterMover::solvePlanes(*((b2Vec2*) targetDelta), (b2CollisionPlaneArray*) planes);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1CharacterMover_00024Raw_clipVector(JNIEnv*, jclass, jlong vector, jlong planes) {
    static thread_local b2Vec2 _cache = B2_CharacterMover::clipVector(*((b2Vec2*) vector), (b2CollisionPlaneArray*) planes);
    _cache = B2_CharacterMover::clipVector(*((b2Vec2*) vector), (b2CollisionPlaneArray*) planes);
    return (jlong) &_cache;
}

// b2PlaneResult
JNIEXPORT jint JNICALL Java_box2d_b2PlaneResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PlaneResult);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneResult_00024Raw_b2PlaneResult_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2PlaneResult();
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneResult_00024Raw_b2PlaneResult(JNIEnv*, jclass) {
    return (jlong) new b2PlaneResult();
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneResult_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2PlaneResult*) _address;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2PlaneResult_00024Raw_getHit(JNIEnv*, jclass, jlong _address) {
    b2PlaneResult* _self = (b2PlaneResult*) _address;
    return (jboolean) _self->hit;
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneResult_00024Raw_setHit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2PlaneResult* _self = (b2PlaneResult*) _address;
    _self->hit = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneResult_00024Raw_getPlane(JNIEnv*, jclass, jlong _address) {
    b2PlaneResult* _self = (b2PlaneResult*) _address;
    return (jlong) &_self->plane;
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneResult_00024Raw_setPlane(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PlaneResult* _self = (b2PlaneResult*) _address;
    _self->plane = *((b2Plane*) value);
}

// b2CollisionPlane
JNIEXPORT jint JNICALL Java_box2d_b2CollisionPlane__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CollisionPlane);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlane_00024Raw_b2CollisionPlane_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2CollisionPlane();
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlane_00024Raw_b2CollisionPlane(JNIEnv*, jclass) {
    return (jlong) new b2CollisionPlane();
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlane_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CollisionPlane*) _address;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2CollisionPlane_00024Raw_getClipVelocity(JNIEnv*, jclass, jlong _address) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    return (jboolean) _self->clipVelocity;
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlane_00024Raw_setClipVelocity(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    _self->clipVelocity = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2CollisionPlane_00024Raw_getPlane(JNIEnv*, jclass, jlong _address) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    return (jlong) &_self->plane;
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlane_00024Raw_setPlane(JNIEnv*, jclass, jlong _address, jlong value) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    _self->plane = *((b2Plane*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2CollisionPlane_00024Raw_getPush(JNIEnv*, jclass, jlong _address) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    return (jfloat) _self->push;
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlane_00024Raw_setPush(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    _self->push = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2CollisionPlane_00024Raw_getPushLimit(JNIEnv*, jclass, jlong _address) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    return (jfloat) _self->pushLimit;
}
JNIEXPORT void JNICALL Java_box2d_b2CollisionPlane_00024Raw_setPushLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2CollisionPlane* _self = (b2CollisionPlane*) _address;
    _self->pushLimit = value;
}

// b2PlaneSolverResult
JNIEXPORT jint JNICALL Java_box2d_b2PlaneSolverResult__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PlaneSolverResult);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_b2PlaneSolverResult_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2PlaneSolverResult();
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_b2PlaneSolverResult(JNIEnv*, jclass) {
    return (jlong) new b2PlaneSolverResult();
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2PlaneSolverResult*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_getIterationCount(JNIEnv*, jclass, jlong _address) {
    b2PlaneSolverResult* _self = (b2PlaneSolverResult*) _address;
    return (jint) _self->iterationCount;
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_setIterationCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2PlaneSolverResult* _self = (b2PlaneSolverResult*) _address;
    _self->iterationCount = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_getTranslation(JNIEnv*, jclass, jlong _address) {
    b2PlaneSolverResult* _self = (b2PlaneSolverResult*) _address;
    return (jlong) &_self->translation;
}
JNIEXPORT void JNICALL Java_box2d_b2PlaneSolverResult_00024Raw_setTranslation(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PlaneSolverResult* _self = (b2PlaneSolverResult*) _address;
    _self->translation = *((b2Vec2*) value);
}

// B2_Joint
JNIEXPORT jint JNICALL Java_box2d_B2_1Joint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Joint);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_destroyJoint(JNIEnv*, jclass, jlong jointId) {
    B2_Joint::destroyJoint(jointId);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Joint_00024Raw_isValid(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_Joint::isValid(jointId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Joint_00024Raw_getType(JNIEnv*, jclass, jlong jointId) {
    return (jint) B2_Joint::getType(jointId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getBodyA(JNIEnv*, jclass, jlong jointId) {
    return (jlong) B2_Joint::getBodyA(jointId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getBodyB(JNIEnv*, jclass, jlong jointId) {
    return (jlong) B2_Joint::getBodyB(jointId);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Joint_00024Raw_getWorld(JNIEnv*, jclass, jlong jointId) {
    return (jint) B2_Joint::getWorld(jointId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_Joint::getLocalAnchorA(jointId);
    _cache = B2_Joint::getLocalAnchorA(jointId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_Joint::getLocalAnchorB(jointId);
    _cache = B2_Joint::getLocalAnchorB(jointId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong jointId, jlong localAnchor) {
    B2_Joint::setLocalAnchorA(jointId, *((b2Vec2*) localAnchor));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong jointId, jlong localAnchor) {
    B2_Joint::setLocalAnchorB(jointId, *((b2Vec2*) localAnchor));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getReferenceAngle(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getReferenceAngle(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setReferenceAngle(JNIEnv*, jclass, jlong jointId, jfloat angleInRadians) {
    B2_Joint::setReferenceAngle(jointId, angleInRadians);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setLocalAxisA(JNIEnv*, jclass, jlong jointId, jlong localAxis) {
    B2_Joint::setLocalAxisA(jointId, *((b2Vec2*) localAxis));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getLocalAxisA(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_Joint::getLocalAxisA(jointId);
    _cache = B2_Joint::getLocalAxisA(jointId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong jointId, jboolean shouldCollide) {
    B2_Joint::setCollideConnected(jointId, shouldCollide);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Joint_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_Joint::getCollideConnected(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setUserData(JNIEnv*, jclass, jlong jointId, jlong userData) {
    B2_Joint::setUserData(jointId, (void*) userData);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getUserData(JNIEnv*, jclass, jlong jointId) {
    return (jlong) B2_Joint::getUserData(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_wakeBodies(JNIEnv*, jclass, jlong jointId) {
    B2_Joint::wakeBodies(jointId);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Joint_00024Raw_getConstraintForce(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_Joint::getConstraintForce(jointId);
    _cache = B2_Joint::getConstraintForce(jointId);
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getConstraintTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getConstraintTorque(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getLinearSeparation(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getLinearSeparation(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getAngularSeparation(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getAngularSeparation(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getConstraintTuningHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getConstraintTuningHertz(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Joint_00024Raw_getConstraintTuningDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_Joint::getConstraintTuningDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Joint_00024Raw_setConstraintTuning(JNIEnv*, jclass, jlong jointId, jfloat hertz, jfloat dampingRatio) {
    B2_Joint::setConstraintTuning(jointId, hertz, dampingRatio);
}

// B2_DistanceJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1DistanceJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_DistanceJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_createDistanceJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_DistanceJoint::createDistanceJoint(worldId, (b2DistanceJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_defaultDistanceJointDef(JNIEnv*, jclass, jlong result) {
    B2_DistanceJoint::defaultDistanceJointDef(*((b2DistanceJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setLength(JNIEnv*, jclass, jlong jointId, jfloat length) {
    B2_DistanceJoint::setLength(jointId, length);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getLength(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getLength(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_enableSpring(JNIEnv*, jclass, jlong jointId, jboolean enableSpring) {
    B2_DistanceJoint::enableSpring(jointId, enableSpring);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_isSpringEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_DistanceJoint::isSpringEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setSpringHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_DistanceJoint::setSpringHertz(jointId, hertz);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setSpringDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_DistanceJoint::setSpringDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getSpringHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getSpringHertz(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getSpringDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getSpringDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_enableLimit(JNIEnv*, jclass, jlong jointId, jboolean enableLimit) {
    B2_DistanceJoint::enableLimit(jointId, enableLimit);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_isLimitEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_DistanceJoint::isLimitEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setLengthRange(JNIEnv*, jclass, jlong jointId, jfloat minLength, jfloat maxLength) {
    B2_DistanceJoint::setLengthRange(jointId, minLength, maxLength);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getMinLength(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getMinLength(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getMaxLength(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getMaxLength(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getCurrentLength(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getCurrentLength(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_enableMotor(JNIEnv*, jclass, jlong jointId, jboolean enableMotor) {
    B2_DistanceJoint::enableMotor(jointId, enableMotor);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_isMotorEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_DistanceJoint::isMotorEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong jointId, jfloat motorSpeed) {
    B2_DistanceJoint::setMotorSpeed(jointId, motorSpeed);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getMotorSpeed(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_setMaxMotorForce(JNIEnv*, jclass, jlong jointId, jfloat force) {
    B2_DistanceJoint::setMaxMotorForce(jointId, force);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getMaxMotorForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getMaxMotorForce(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1DistanceJoint_00024Raw_getMotorForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_DistanceJoint::getMotorForce(jointId);
}

// b2DistanceJointDef
JNIEXPORT jint JNICALL Java_box2d_b2DistanceJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2DistanceJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_b2DistanceJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2DistanceJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_b2DistanceJointDef(JNIEnv*, jclass) {
    return (jlong) new b2DistanceJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2DistanceJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->dampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->dampingRatio = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getEnableLimit(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jboolean) _self->enableLimit;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setEnableLimit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->enableLimit = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getEnableMotor(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jboolean) _self->enableMotor;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setEnableMotor(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->enableMotor = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getEnableSpring(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jboolean) _self->enableSpring;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setEnableSpring(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->enableSpring = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getHertz(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->hertz;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->hertz = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getLength(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->length;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->length = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jlong) &_self->localAnchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->localAnchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jlong) &_self->localAnchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->localAnchorB = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getMaxLength(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->maxLength;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setMaxLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->maxLength = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getMaxMotorForce(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->maxMotorForce;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setMaxMotorForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->maxMotorForce = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getMinLength(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->minLength;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setMinLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->minLength = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jfloat) _self->motorSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->motorSpeed = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2DistanceJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2DistanceJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2DistanceJointDef* _self = (b2DistanceJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_FilterJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1FilterJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_FilterJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1FilterJoint_00024Raw_createFilterJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_FilterJoint::createFilterJoint(worldId, (b2FilterJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1FilterJoint_00024Raw_defaultFilterJointDef(JNIEnv*, jclass, jlong result) {
    B2_FilterJoint::defaultFilterJointDef(*((b2FilterJointDef*) result));
}

// b2FilterJointDef
JNIEXPORT jint JNICALL Java_box2d_b2FilterJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2FilterJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2FilterJointDef_00024Raw_b2FilterJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2FilterJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2FilterJointDef_00024Raw_b2FilterJointDef(JNIEnv*, jclass) {
    return (jlong) new b2FilterJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2FilterJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2FilterJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2FilterJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2FilterJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2FilterJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2FilterJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2FilterJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2FilterJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2FilterJointDef* _self = (b2FilterJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_MotorJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1MotorJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_MotorJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1MotorJoint_00024Raw_createMotorJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_MotorJoint::createMotorJoint(worldId, (b2MotorJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_defaultMotorJointDef(JNIEnv*, jclass, jlong result) {
    B2_MotorJoint::defaultMotorJointDef(*((b2MotorJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_setLinearOffset(JNIEnv*, jclass, jlong jointId, jlong linearOffset) {
    B2_MotorJoint::setLinearOffset(jointId, *((b2Vec2*) linearOffset));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1MotorJoint_00024Raw_getLinearOffset(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_MotorJoint::getLinearOffset(jointId);
    _cache = B2_MotorJoint::getLinearOffset(jointId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_setAngularOffset(JNIEnv*, jclass, jlong jointId, jfloat angularOffset) {
    B2_MotorJoint::setAngularOffset(jointId, angularOffset);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MotorJoint_00024Raw_getAngularOffset(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MotorJoint::getAngularOffset(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_setMaxForce(JNIEnv*, jclass, jlong jointId, jfloat maxForce) {
    B2_MotorJoint::setMaxForce(jointId, maxForce);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MotorJoint_00024Raw_getMaxForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MotorJoint::getMaxForce(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_setMaxTorque(JNIEnv*, jclass, jlong jointId, jfloat maxTorque) {
    B2_MotorJoint::setMaxTorque(jointId, maxTorque);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MotorJoint_00024Raw_getMaxTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MotorJoint::getMaxTorque(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MotorJoint_00024Raw_setCorrectionFactor(JNIEnv*, jclass, jlong jointId, jfloat correctionFactor) {
    B2_MotorJoint::setCorrectionFactor(jointId, correctionFactor);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MotorJoint_00024Raw_getCorrectionFactor(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MotorJoint::getCorrectionFactor(jointId);
}

// b2MotorJointDef
JNIEXPORT jint JNICALL Java_box2d_b2MotorJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2MotorJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_b2MotorJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2MotorJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_b2MotorJointDef(JNIEnv*, jclass) {
    return (jlong) new b2MotorJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2MotorJointDef*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MotorJointDef_00024Raw_getAngularOffset(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jfloat) _self->angularOffset;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setAngularOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->angularOffset = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2MotorJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MotorJointDef_00024Raw_getCorrectionFactor(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jfloat) _self->correctionFactor;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setCorrectionFactor(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->correctionFactor = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2MotorJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_getLinearOffset(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jlong) &_self->linearOffset;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setLinearOffset(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->linearOffset = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MotorJointDef_00024Raw_getMaxForce(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jfloat) _self->maxForce;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setMaxForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->maxForce = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MotorJointDef_00024Raw_getMaxTorque(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jfloat) _self->maxTorque;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setMaxTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->maxTorque = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MotorJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2MotorJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MotorJointDef* _self = (b2MotorJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_MouseJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1MouseJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_MouseJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1MouseJoint_00024Raw_createMouseJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_MouseJoint::createMouseJoint(worldId, (b2MouseJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MouseJoint_00024Raw_defaultMouseJointDef(JNIEnv*, jclass, jlong result) {
    B2_MouseJoint::defaultMouseJointDef(*((b2MouseJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1MouseJoint_00024Raw_setTarget(JNIEnv*, jclass, jlong jointId, jlong target) {
    B2_MouseJoint::setTarget(jointId, *((b2Vec2*) target));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1MouseJoint_00024Raw_getTarget(JNIEnv*, jclass, jlong jointId) {
    static thread_local b2Vec2 _cache = B2_MouseJoint::getTarget(jointId);
    _cache = B2_MouseJoint::getTarget(jointId);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1MouseJoint_00024Raw_setSpringHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_MouseJoint::setSpringHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MouseJoint_00024Raw_getSpringHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MouseJoint::getSpringHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MouseJoint_00024Raw_setSpringDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_MouseJoint::setSpringDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MouseJoint_00024Raw_getSpringDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MouseJoint::getSpringDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1MouseJoint_00024Raw_setMaxForce(JNIEnv*, jclass, jlong jointId, jfloat maxForce) {
    B2_MouseJoint::setMaxForce(jointId, maxForce);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1MouseJoint_00024Raw_getMaxForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_MouseJoint::getMaxForce(jointId);
}

// b2MouseJointDef
JNIEXPORT jint JNICALL Java_box2d_b2MouseJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2MouseJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_b2MouseJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2MouseJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_b2MouseJointDef(JNIEnv*, jclass) {
    return (jlong) new b2MouseJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2MouseJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2MouseJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MouseJointDef_00024Raw_getDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jfloat) _self->dampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->dampingRatio = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MouseJointDef_00024Raw_getHertz(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jfloat) _self->hertz;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->hertz = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2MouseJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MouseJointDef_00024Raw_getMaxForce(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jfloat) _self->maxForce;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setMaxForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->maxForce = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_getTarget(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jlong) &_self->target;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setTarget(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->target = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MouseJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2MouseJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MouseJointDef* _self = (b2MouseJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_PrismaticJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1PrismaticJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_PrismaticJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_createPrismaticJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_PrismaticJoint::createPrismaticJoint(worldId, (b2PrismaticJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_defaultPrismaticJointDef(JNIEnv*, jclass, jlong result) {
    B2_PrismaticJoint::defaultPrismaticJointDef(*((b2PrismaticJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_enableSpring(JNIEnv*, jclass, jlong jointId, jboolean enableSpring) {
    B2_PrismaticJoint::enableSpring(jointId, enableSpring);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_isSpringEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_PrismaticJoint::isSpringEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setSpringHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_PrismaticJoint::setSpringHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getSpringHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getSpringHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setSpringDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_PrismaticJoint::setSpringDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getSpringDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getSpringDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setTargetTranslation(JNIEnv*, jclass, jlong jointId, jfloat translation) {
    B2_PrismaticJoint::setTargetTranslation(jointId, translation);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getTargetTranslation(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getTargetTranslation(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_enableLimit(JNIEnv*, jclass, jlong jointId, jboolean enableLimit) {
    B2_PrismaticJoint::enableLimit(jointId, enableLimit);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_isLimitEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_PrismaticJoint::isLimitEnabled(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getLowerLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getLowerLimit(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getUpperLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getUpperLimit(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setLimits(JNIEnv*, jclass, jlong jointId, jfloat lower, jfloat upper) {
    B2_PrismaticJoint::setLimits(jointId, lower, upper);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_enableMotor(JNIEnv*, jclass, jlong jointId, jboolean enableMotor) {
    B2_PrismaticJoint::enableMotor(jointId, enableMotor);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_isMotorEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_PrismaticJoint::isMotorEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong jointId, jfloat motorSpeed) {
    B2_PrismaticJoint::setMotorSpeed(jointId, motorSpeed);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getMotorSpeed(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_setMaxMotorForce(JNIEnv*, jclass, jlong jointId, jfloat force) {
    B2_PrismaticJoint::setMaxMotorForce(jointId, force);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getMaxMotorForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getMaxMotorForce(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getMotorForce(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getMotorForce(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getTranslation(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getTranslation(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1PrismaticJoint_00024Raw_getSpeed(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_PrismaticJoint::getSpeed(jointId);
}

// b2PrismaticJointDef
JNIEXPORT jint JNICALL Java_box2d_b2PrismaticJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2PrismaticJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_b2PrismaticJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2PrismaticJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_b2PrismaticJointDef(JNIEnv*, jclass) {
    return (jlong) new b2PrismaticJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2PrismaticJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->dampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->dampingRatio = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getEnableLimit(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jboolean) _self->enableLimit;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setEnableLimit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->enableLimit = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getEnableMotor(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jboolean) _self->enableMotor;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setEnableMotor(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->enableMotor = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getEnableSpring(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jboolean) _self->enableSpring;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setEnableSpring(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->enableSpring = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getHertz(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->hertz;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->hertz = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) &_self->localAnchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->localAnchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) &_self->localAnchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->localAnchorB = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getLocalAxisA(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) &_self->localAxisA;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setLocalAxisA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->localAxisA = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getLowerTranslation(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->lowerTranslation;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setLowerTranslation(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->lowerTranslation = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getMaxMotorForce(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->maxMotorForce;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setMaxMotorForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->maxMotorForce = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->motorSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->motorSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getReferenceAngle(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->referenceAngle;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setReferenceAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->referenceAngle = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getUpperTranslation(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jfloat) _self->upperTranslation;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setUpperTranslation(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->upperTranslation = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2PrismaticJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2PrismaticJointDef* _self = (b2PrismaticJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_RevoluteJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1RevoluteJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_RevoluteJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_createRevoluteJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_RevoluteJoint::createRevoluteJoint(worldId, (b2RevoluteJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_defaultRevoluteJointDef(JNIEnv*, jclass, jlong result) {
    B2_RevoluteJoint::defaultRevoluteJointDef(*((b2RevoluteJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_enableSpring(JNIEnv*, jclass, jlong jointId, jboolean enableSpring) {
    B2_RevoluteJoint::enableSpring(jointId, enableSpring);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_isSpringEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_RevoluteJoint::isSpringEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setSpringHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_RevoluteJoint::setSpringHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getSpringHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getSpringHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setSpringDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_RevoluteJoint::setSpringDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getSpringDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getSpringDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setTargetAngle(JNIEnv*, jclass, jlong jointId, jfloat angle) {
    B2_RevoluteJoint::setTargetAngle(jointId, angle);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getTargetAngle(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getTargetAngle(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getAngle(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getAngle(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_enableLimit(JNIEnv*, jclass, jlong jointId, jboolean enableLimit) {
    B2_RevoluteJoint::enableLimit(jointId, enableLimit);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_isLimitEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_RevoluteJoint::isLimitEnabled(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getLowerLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getLowerLimit(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getUpperLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getUpperLimit(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setLimits(JNIEnv*, jclass, jlong jointId, jfloat lower, jfloat upper) {
    B2_RevoluteJoint::setLimits(jointId, lower, upper);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_enableMotor(JNIEnv*, jclass, jlong jointId, jboolean enableMotor) {
    B2_RevoluteJoint::enableMotor(jointId, enableMotor);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_isMotorEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_RevoluteJoint::isMotorEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong jointId, jfloat motorSpeed) {
    B2_RevoluteJoint::setMotorSpeed(jointId, motorSpeed);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getMotorSpeed(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getMotorTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getMotorTorque(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_setMaxMotorTorque(JNIEnv*, jclass, jlong jointId, jfloat torque) {
    B2_RevoluteJoint::setMaxMotorTorque(jointId, torque);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1RevoluteJoint_00024Raw_getMaxMotorTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_RevoluteJoint::getMaxMotorTorque(jointId);
}

// b2RevoluteJointDef
JNIEXPORT jint JNICALL Java_box2d_b2RevoluteJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2RevoluteJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_b2RevoluteJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2RevoluteJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_b2RevoluteJointDef(JNIEnv*, jclass) {
    return (jlong) new b2RevoluteJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2RevoluteJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->dampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->dampingRatio = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getDrawSize(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->drawSize;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setDrawSize(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->drawSize = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getEnableLimit(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jboolean) _self->enableLimit;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setEnableLimit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->enableLimit = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getEnableMotor(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jboolean) _self->enableMotor;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setEnableMotor(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->enableMotor = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getEnableSpring(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jboolean) _self->enableSpring;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setEnableSpring(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->enableSpring = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getHertz(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->hertz;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->hertz = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jlong) &_self->localAnchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->localAnchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jlong) &_self->localAnchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->localAnchorB = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getLowerAngle(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->lowerAngle;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setLowerAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->lowerAngle = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getMaxMotorTorque(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->maxMotorTorque;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setMaxMotorTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->maxMotorTorque = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->motorSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->motorSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getReferenceAngle(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->referenceAngle;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setReferenceAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->referenceAngle = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getUpperAngle(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jfloat) _self->upperAngle;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setUpperAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->upperAngle = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2RevoluteJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RevoluteJointDef* _self = (b2RevoluteJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_WeldJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1WeldJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_WeldJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1WeldJoint_00024Raw_createWeldJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_WeldJoint::createWeldJoint(worldId, (b2WeldJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WeldJoint_00024Raw_defaultWeldJointDef(JNIEnv*, jclass, jlong result) {
    B2_WeldJoint::defaultWeldJointDef(*((b2WeldJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1WeldJoint_00024Raw_setLinearHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_WeldJoint::setLinearHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WeldJoint_00024Raw_getLinearHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WeldJoint::getLinearHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WeldJoint_00024Raw_setLinearDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_WeldJoint::setLinearDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WeldJoint_00024Raw_getLinearDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WeldJoint::getLinearDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WeldJoint_00024Raw_setAngularHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_WeldJoint::setAngularHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WeldJoint_00024Raw_getAngularHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WeldJoint::getAngularHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WeldJoint_00024Raw_setAngularDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_WeldJoint::setAngularDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WeldJoint_00024Raw_getAngularDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WeldJoint::getAngularDampingRatio(jointId);
}

// b2WeldJointDef
JNIEXPORT jint JNICALL Java_box2d_b2WeldJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2WeldJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_b2WeldJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2WeldJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_b2WeldJointDef(JNIEnv*, jclass) {
    return (jlong) new b2WeldJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2WeldJointDef*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WeldJointDef_00024Raw_getAngularDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jfloat) _self->angularDampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setAngularDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->angularDampingRatio = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WeldJointDef_00024Raw_getAngularHertz(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jfloat) _self->angularHertz;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setAngularHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->angularHertz = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WeldJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2WeldJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WeldJointDef_00024Raw_getLinearDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jfloat) _self->linearDampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setLinearDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->linearDampingRatio = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WeldJointDef_00024Raw_getLinearHertz(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jfloat) _self->linearHertz;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setLinearHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->linearHertz = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jlong) &_self->localAnchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->localAnchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jlong) &_self->localAnchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->localAnchorB = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WeldJointDef_00024Raw_getReferenceAngle(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jfloat) _self->referenceAngle;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setReferenceAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->referenceAngle = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WeldJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2WeldJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WeldJointDef* _self = (b2WeldJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_WheelJoint
JNIEXPORT jint JNICALL Java_box2d_B2_1WheelJoint__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_WheelJoint);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1WheelJoint_00024Raw_createWheelJoint(JNIEnv*, jclass, jlong worldId, jlong def) {
    return (jlong) B2_WheelJoint::createWheelJoint(worldId, (b2WheelJointDef*) def);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_defaultWheelJointDef(JNIEnv*, jclass, jlong result) {
    B2_WheelJoint::defaultWheelJointDef(*((b2WheelJointDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_enableSpring(JNIEnv*, jclass, jlong jointId, jboolean enableSpring) {
    B2_WheelJoint::enableSpring(jointId, enableSpring);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1WheelJoint_00024Raw_isSpringEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_WheelJoint::isSpringEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_setSpringHertz(JNIEnv*, jclass, jlong jointId, jfloat hertz) {
    B2_WheelJoint::setSpringHertz(jointId, hertz);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getSpringHertz(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getSpringHertz(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_setSpringDampingRatio(JNIEnv*, jclass, jlong jointId, jfloat dampingRatio) {
    B2_WheelJoint::setSpringDampingRatio(jointId, dampingRatio);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getSpringDampingRatio(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getSpringDampingRatio(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_enableLimit(JNIEnv*, jclass, jlong jointId, jboolean enableLimit) {
    B2_WheelJoint::enableLimit(jointId, enableLimit);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1WheelJoint_00024Raw_isLimitEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_WheelJoint::isLimitEnabled(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getLowerLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getLowerLimit(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getUpperLimit(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getUpperLimit(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_setLimits(JNIEnv*, jclass, jlong jointId, jfloat lower, jfloat upper) {
    B2_WheelJoint::setLimits(jointId, lower, upper);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_enableMotor(JNIEnv*, jclass, jlong jointId, jboolean enableMotor) {
    B2_WheelJoint::enableMotor(jointId, enableMotor);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1WheelJoint_00024Raw_isMotorEnabled(JNIEnv*, jclass, jlong jointId) {
    return (jboolean) B2_WheelJoint::isMotorEnabled(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong jointId, jfloat motorSpeed) {
    B2_WheelJoint::setMotorSpeed(jointId, motorSpeed);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getMotorSpeed(jointId);
}
JNIEXPORT void JNICALL Java_box2d_B2_1WheelJoint_00024Raw_setMaxMotorTorque(JNIEnv*, jclass, jlong jointId, jfloat torque) {
    B2_WheelJoint::setMaxMotorTorque(jointId, torque);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getMaxMotorTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getMaxMotorTorque(jointId);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1WheelJoint_00024Raw_getMotorTorque(JNIEnv*, jclass, jlong jointId) {
    return (jfloat) B2_WheelJoint::getMotorTorque(jointId);
}

// b2WheelJointDef
JNIEXPORT jint JNICALL Java_box2d_b2WheelJointDef__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2WheelJointDef);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_b2WheelJointDef_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2WheelJointDef();
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_b2WheelJointDef(JNIEnv*, jclass) {
    return (jlong) new b2WheelJointDef();
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2WheelJointDef*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getBodyIdA(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) &_self->bodyIdA;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setBodyIdA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->bodyIdA = *((b2BodyId*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getBodyIdB(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) &_self->bodyIdB;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setBodyIdB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->bodyIdB = *((b2BodyId*) value);
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WheelJointDef_00024Raw_getCollideConnected(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jboolean) _self->collideConnected;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setCollideConnected(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->collideConnected = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getDampingRatio(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->dampingRatio;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setDampingRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->dampingRatio = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WheelJointDef_00024Raw_getEnableLimit(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jboolean) _self->enableLimit;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setEnableLimit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->enableLimit = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WheelJointDef_00024Raw_getEnableMotor(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jboolean) _self->enableMotor;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setEnableMotor(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->enableMotor = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2WheelJointDef_00024Raw_getEnableSpring(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jboolean) _self->enableSpring;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setEnableSpring(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->enableSpring = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getHertz(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->hertz;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setHertz(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->hertz = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2WheelJointDef_00024Raw_getInternalValue(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jint) _self->internalValue;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setInternalValue(JNIEnv*, jclass, jlong _address, jint value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->internalValue = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getLocalAnchorA(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) &_self->localAnchorA;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setLocalAnchorA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->localAnchorA = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getLocalAnchorB(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) &_self->localAnchorB;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setLocalAnchorB(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->localAnchorB = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getLocalAxisA(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) &_self->localAxisA;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setLocalAxisA(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->localAxisA = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getLowerTranslation(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->lowerTranslation;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setLowerTranslation(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->lowerTranslation = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getMaxMotorTorque(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->maxMotorTorque;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setMaxMotorTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->maxMotorTorque = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getMotorSpeed(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->motorSpeed;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setMotorSpeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->motorSpeed = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2WheelJointDef_00024Raw_getUpperTranslation(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jfloat) _self->upperTranslation;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setUpperTranslation(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->upperTranslation = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2WheelJointDef_00024Raw_getUserData(JNIEnv*, jclass, jlong _address) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_box2d_b2WheelJointDef_00024Raw_setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    b2WheelJointDef* _self = (b2WheelJointDef*) _address;
    _self->userData = (void*) value;
}

// B2_Geometry
JNIEXPORT jint JNICALL Java_box2d_B2_1Geometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Geometry);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Geometry_00024Raw_isValidRay(JNIEnv*, jclass, jlong input) {
    return (jboolean) B2_Geometry::isValidRay((b2RayCastInput*) input);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makePolygon(JNIEnv*, jclass, jlong hull, jfloat radius, jlong result) {
    B2_Geometry::makePolygon((b2Hull*) hull, radius, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeOffsetPolygon(JNIEnv*, jclass, jlong hull, jlong position, jlong rotation, jlong result) {
    B2_Geometry::makeOffsetPolygon((b2Hull*) hull, *((b2Vec2*) position), *((b2Rot*) rotation), *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeOffsetRoundedPolygon(JNIEnv*, jclass, jlong hull, jlong position, jlong rotation, jfloat radius, jlong result) {
    B2_Geometry::makeOffsetRoundedPolygon((b2Hull*) hull, *((b2Vec2*) position), *((b2Rot*) rotation), radius, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeSquare(JNIEnv*, jclass, jfloat halfWidth, jlong result) {
    B2_Geometry::makeSquare(halfWidth, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeBox(JNIEnv*, jclass, jfloat halfWidth, jfloat halfHeight, jlong result) {
    B2_Geometry::makeBox(halfWidth, halfHeight, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeRoundedBox(JNIEnv*, jclass, jfloat halfWidth, jfloat halfHeight, jfloat radius, jlong result) {
    B2_Geometry::makeRoundedBox(halfWidth, halfHeight, radius, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeOffsetBox(JNIEnv*, jclass, jfloat halfWidth, jfloat halfHeight, jlong center, jlong rotation, jlong result) {
    B2_Geometry::makeOffsetBox(halfWidth, halfHeight, *((b2Vec2*) center), *((b2Rot*) rotation), *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeOffsetRoundedBox(JNIEnv*, jclass, jfloat halfWidth, jfloat halfHeight, jlong center, jlong rotation, jfloat radius, jlong result) {
    B2_Geometry::makeOffsetRoundedBox(halfWidth, halfHeight, *((b2Vec2*) center), *((b2Rot*) rotation), radius, *((b2Polygon*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_transformPolygon(JNIEnv*, jclass, jlong transform, jlong polygon, jlong result) {
    B2_Geometry::transformPolygon(*((b2Transform*) transform), (b2Polygon*) polygon, *((b2Polygon*) result));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computeCircleMass(JNIEnv*, jclass, jlong shape, jfloat density) {
    static thread_local b2MassData _cache = B2_Geometry::computeCircleMass((b2Circle*) shape, density);
    _cache = B2_Geometry::computeCircleMass((b2Circle*) shape, density);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computeCapsuleMass(JNIEnv*, jclass, jlong shape, jfloat density) {
    static thread_local b2MassData _cache = B2_Geometry::computeCapsuleMass((b2Capsule*) shape, density);
    _cache = B2_Geometry::computeCapsuleMass((b2Capsule*) shape, density);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computePolygonMass(JNIEnv*, jclass, jlong shape, jfloat density) {
    static thread_local b2MassData _cache = B2_Geometry::computePolygonMass((b2Polygon*) shape, density);
    _cache = B2_Geometry::computePolygonMass((b2Polygon*) shape, density);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computeCircleAABB(JNIEnv*, jclass, jlong shape, jlong transform) {
    static thread_local b2AABB _cache = B2_Geometry::computeCircleAABB((b2Circle*) shape, *((b2Transform*) transform));
    _cache = B2_Geometry::computeCircleAABB((b2Circle*) shape, *((b2Transform*) transform));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computeCapsuleAABB(JNIEnv*, jclass, jlong shape, jlong transform) {
    static thread_local b2AABB _cache = B2_Geometry::computeCapsuleAABB((b2Capsule*) shape, *((b2Transform*) transform));
    _cache = B2_Geometry::computeCapsuleAABB((b2Capsule*) shape, *((b2Transform*) transform));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computePolygonAABB(JNIEnv*, jclass, jlong shape, jlong transform) {
    static thread_local b2AABB _cache = B2_Geometry::computePolygonAABB((b2Polygon*) shape, *((b2Transform*) transform));
    _cache = B2_Geometry::computePolygonAABB((b2Polygon*) shape, *((b2Transform*) transform));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_computeSegmentAABB(JNIEnv*, jclass, jlong shape, jlong transform) {
    static thread_local b2AABB _cache = B2_Geometry::computeSegmentAABB((b2Segment*) shape, *((b2Transform*) transform));
    _cache = B2_Geometry::computeSegmentAABB((b2Segment*) shape, *((b2Transform*) transform));
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Geometry_00024Raw_pointInCircle(JNIEnv*, jclass, jlong point, jlong shape) {
    return (jboolean) B2_Geometry::pointInCircle(*((b2Vec2*) point), (b2Circle*) shape);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Geometry_00024Raw_pointInCapsule(JNIEnv*, jclass, jlong point, jlong shape) {
    return (jboolean) B2_Geometry::pointInCapsule(*((b2Vec2*) point), (b2Capsule*) shape);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Geometry_00024Raw_pointInPolygon(JNIEnv*, jclass, jlong point, jlong shape) {
    return (jboolean) B2_Geometry::pointInPolygon(*((b2Vec2*) point), (b2Polygon*) shape);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_rayCastCircle(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::rayCastCircle((b2RayCastInput*) input, (b2Circle*) shape);
    _cache = B2_Geometry::rayCastCircle((b2RayCastInput*) input, (b2Circle*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_rayCastCapsule(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::rayCastCapsule((b2RayCastInput*) input, (b2Capsule*) shape);
    _cache = B2_Geometry::rayCastCapsule((b2RayCastInput*) input, (b2Capsule*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_rayCastSegment(JNIEnv*, jclass, jlong input, jlong shape, jboolean oneSided) {
    static thread_local b2CastOutput _cache = B2_Geometry::rayCastSegment((b2RayCastInput*) input, (b2Segment*) shape, oneSided);
    _cache = B2_Geometry::rayCastSegment((b2RayCastInput*) input, (b2Segment*) shape, oneSided);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_rayCastPolygon(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::rayCastPolygon((b2RayCastInput*) input, (b2Polygon*) shape);
    _cache = B2_Geometry::rayCastPolygon((b2RayCastInput*) input, (b2Polygon*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_shapeCastCircle(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::shapeCastCircle((b2ShapeCastInput*) input, (b2Circle*) shape);
    _cache = B2_Geometry::shapeCastCircle((b2ShapeCastInput*) input, (b2Circle*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_shapeCastCapsule(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::shapeCastCapsule((b2ShapeCastInput*) input, (b2Capsule*) shape);
    _cache = B2_Geometry::shapeCastCapsule((b2ShapeCastInput*) input, (b2Capsule*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_shapeCastSegment(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::shapeCastSegment((b2ShapeCastInput*) input, (b2Segment*) shape);
    _cache = B2_Geometry::shapeCastSegment((b2ShapeCastInput*) input, (b2Segment*) shape);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Geometry_00024Raw_shapeCastPolygon(JNIEnv*, jclass, jlong input, jlong shape) {
    static thread_local b2CastOutput _cache = B2_Geometry::shapeCastPolygon((b2ShapeCastInput*) input, (b2Polygon*) shape);
    _cache = B2_Geometry::shapeCastPolygon((b2ShapeCastInput*) input, (b2Polygon*) shape);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_computeHull(JNIEnv*, jclass, jlong points, jlong result) {
    B2_Geometry::computeHull((b2Vec2Array*) points, *((b2Hull*) result));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Geometry_00024Raw_validateHull(JNIEnv*, jclass, jlong hull) {
    return (jboolean) B2_Geometry::validateHull((b2Hull*) hull);
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Geometry_00024Raw_getMAX_1POLYGON_1VERTICES(JNIEnv*, jclass) {
    return (jint) B2_Geometry::MAX_POLYGON_VERTICES;
}

// b2MassData
JNIEXPORT jint JNICALL Java_box2d_b2MassData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2MassData);
}
JNIEXPORT jlong JNICALL Java_box2d_b2MassData_00024Raw_b2MassData_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2MassData();
}
JNIEXPORT jlong JNICALL Java_box2d_b2MassData_00024Raw_b2MassData(JNIEnv*, jclass) {
    return (jlong) new b2MassData();
}
JNIEXPORT void JNICALL Java_box2d_b2MassData_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2MassData*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2MassData_00024Raw_getCenter(JNIEnv*, jclass, jlong _address) {
    b2MassData* _self = (b2MassData*) _address;
    return (jlong) &_self->center;
}
JNIEXPORT void JNICALL Java_box2d_b2MassData_00024Raw_setCenter(JNIEnv*, jclass, jlong _address, jlong value) {
    b2MassData* _self = (b2MassData*) _address;
    _self->center = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MassData_00024Raw_getMass(JNIEnv*, jclass, jlong _address) {
    b2MassData* _self = (b2MassData*) _address;
    return (jfloat) _self->mass;
}
JNIEXPORT void JNICALL Java_box2d_b2MassData_00024Raw_setMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MassData* _self = (b2MassData*) _address;
    _self->mass = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2MassData_00024Raw_getRotationalInertia(JNIEnv*, jclass, jlong _address) {
    b2MassData* _self = (b2MassData*) _address;
    return (jfloat) _self->rotationalInertia;
}
JNIEXPORT void JNICALL Java_box2d_b2MassData_00024Raw_setRotationalInertia(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2MassData* _self = (b2MassData*) _address;
    _self->rotationalInertia = value;
}

// b2Circle
JNIEXPORT jint JNICALL Java_box2d_b2Circle__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Circle);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Circle_00024Raw_b2Circle_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Circle();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Circle_00024Raw_b2Circle(JNIEnv*, jclass) {
    return (jlong) new b2Circle();
}
JNIEXPORT void JNICALL Java_box2d_b2Circle_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Circle*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Circle_00024Raw_getCenter(JNIEnv*, jclass, jlong _address) {
    b2Circle* _self = (b2Circle*) _address;
    return (jlong) &_self->center;
}
JNIEXPORT void JNICALL Java_box2d_b2Circle_00024Raw_setCenter(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Circle* _self = (b2Circle*) _address;
    _self->center = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Circle_00024Raw_getRadius(JNIEnv*, jclass, jlong _address) {
    b2Circle* _self = (b2Circle*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_box2d_b2Circle_00024Raw_setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Circle* _self = (b2Circle*) _address;
    _self->radius = value;
}

// b2Capsule
JNIEXPORT jint JNICALL Java_box2d_b2Capsule__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Capsule);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Capsule_00024Raw_b2Capsule_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Capsule();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Capsule_00024Raw_b2Capsule(JNIEnv*, jclass) {
    return (jlong) new b2Capsule();
}
JNIEXPORT void JNICALL Java_box2d_b2Capsule_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Capsule*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Capsule_00024Raw_getCenter1(JNIEnv*, jclass, jlong _address) {
    b2Capsule* _self = (b2Capsule*) _address;
    return (jlong) &_self->center1;
}
JNIEXPORT void JNICALL Java_box2d_b2Capsule_00024Raw_setCenter1(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Capsule* _self = (b2Capsule*) _address;
    _self->center1 = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Capsule_00024Raw_getCenter2(JNIEnv*, jclass, jlong _address) {
    b2Capsule* _self = (b2Capsule*) _address;
    return (jlong) &_self->center2;
}
JNIEXPORT void JNICALL Java_box2d_b2Capsule_00024Raw_setCenter2(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Capsule* _self = (b2Capsule*) _address;
    _self->center2 = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Capsule_00024Raw_getRadius(JNIEnv*, jclass, jlong _address) {
    b2Capsule* _self = (b2Capsule*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_box2d_b2Capsule_00024Raw_setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Capsule* _self = (b2Capsule*) _address;
    _self->radius = value;
}

// b2Polygon
JNIEXPORT jint JNICALL Java_box2d_b2Polygon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Polygon);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Polygon_00024Raw_b2Polygon_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Polygon();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Polygon_00024Raw_b2Polygon(JNIEnv*, jclass) {
    return (jlong) new b2Polygon();
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Polygon*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Polygon_00024Raw_getVertices(JNIEnv*, jclass, jlong _address, jint _index) {
    b2Polygon* _self = (b2Polygon*) _address;
    return (jlong) &_self->vertices[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_setVertices(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    b2Polygon* _self = (b2Polygon*) _address;
    _self->vertices[_index] = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Polygon_00024Raw_getNormals(JNIEnv*, jclass, jlong _address, jint _index) {
    b2Polygon* _self = (b2Polygon*) _address;
    return (jlong) &_self->normals[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_setNormals(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    b2Polygon* _self = (b2Polygon*) _address;
    _self->normals[_index] = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Polygon_00024Raw_getCentroid(JNIEnv*, jclass, jlong _address) {
    b2Polygon* _self = (b2Polygon*) _address;
    return (jlong) &_self->centroid;
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_setCentroid(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Polygon* _self = (b2Polygon*) _address;
    _self->centroid = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2Polygon_00024Raw_getRadius(JNIEnv*, jclass, jlong _address) {
    b2Polygon* _self = (b2Polygon*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2Polygon* _self = (b2Polygon*) _address;
    _self->radius = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2Polygon_00024Raw_getCount(JNIEnv*, jclass, jlong _address) {
    b2Polygon* _self = (b2Polygon*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_box2d_b2Polygon_00024Raw_setCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Polygon* _self = (b2Polygon*) _address;
    _self->count = value;
}

// b2Segment
JNIEXPORT jint JNICALL Java_box2d_b2Segment__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Segment);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Segment_00024Raw_b2Segment_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Segment();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Segment_00024Raw_b2Segment(JNIEnv*, jclass) {
    return (jlong) new b2Segment();
}
JNIEXPORT void JNICALL Java_box2d_b2Segment_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Segment*) _address;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Segment_00024Raw_getPoint1(JNIEnv*, jclass, jlong _address) {
    b2Segment* _self = (b2Segment*) _address;
    return (jlong) &_self->point1;
}
JNIEXPORT void JNICALL Java_box2d_b2Segment_00024Raw_setPoint1(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Segment* _self = (b2Segment*) _address;
    _self->point1 = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Segment_00024Raw_getPoint2(JNIEnv*, jclass, jlong _address) {
    b2Segment* _self = (b2Segment*) _address;
    return (jlong) &_self->point2;
}
JNIEXPORT void JNICALL Java_box2d_b2Segment_00024Raw_setPoint2(JNIEnv*, jclass, jlong _address, jlong value) {
    b2Segment* _self = (b2Segment*) _address;
    _self->point2 = *((b2Vec2*) value);
}

// b2ChainSegment
JNIEXPORT jint JNICALL Java_box2d_b2ChainSegment__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ChainSegment);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainSegment_00024Raw_b2ChainSegment_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ChainSegment();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainSegment_00024Raw_b2ChainSegment(JNIEnv*, jclass) {
    return (jlong) new b2ChainSegment();
}
JNIEXPORT void JNICALL Java_box2d_b2ChainSegment_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ChainSegment*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2ChainSegment_00024Raw_getChainId(JNIEnv*, jclass, jlong _address) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    return (jint) _self->chainId;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainSegment_00024Raw_setChainId(JNIEnv*, jclass, jlong _address, jint value) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    _self->chainId = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainSegment_00024Raw_getGhost1(JNIEnv*, jclass, jlong _address) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    return (jlong) &_self->ghost1;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainSegment_00024Raw_setGhost1(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    _self->ghost1 = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainSegment_00024Raw_getGhost2(JNIEnv*, jclass, jlong _address) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    return (jlong) &_self->ghost2;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainSegment_00024Raw_setGhost2(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    _self->ghost2 = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ChainSegment_00024Raw_getSegment(JNIEnv*, jclass, jlong _address) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    return (jlong) &_self->segment;
}
JNIEXPORT void JNICALL Java_box2d_b2ChainSegment_00024Raw_setSegment(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ChainSegment* _self = (b2ChainSegment*) _address;
    _self->segment = *((b2Segment*) value);
}

// b2Hull
JNIEXPORT jint JNICALL Java_box2d_b2Hull__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2Hull);
}
JNIEXPORT jlong JNICALL Java_box2d_b2Hull_00024Raw_b2Hull_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2Hull();
}
JNIEXPORT jlong JNICALL Java_box2d_b2Hull_00024Raw_b2Hull(JNIEnv*, jclass) {
    return (jlong) new b2Hull();
}
JNIEXPORT void JNICALL Java_box2d_b2Hull_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2Hull*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2Hull_00024Raw_getCount(JNIEnv*, jclass, jlong _address) {
    b2Hull* _self = (b2Hull*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_box2d_b2Hull_00024Raw_setCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2Hull* _self = (b2Hull*) _address;
    _self->count = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2Hull_00024Raw_getPoints(JNIEnv*, jclass, jlong _address, jint _index) {
    b2Hull* _self = (b2Hull*) _address;
    return (jlong) &_self->points[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2Hull_00024Raw_setPoints(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    b2Hull* _self = (b2Hull*) _address;
    _self->points[_index] = *((b2Vec2*) value);
}

// b2ShapeProxy
JNIEXPORT jint JNICALL Java_box2d_b2ShapeProxy__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeProxy);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeProxy_00024Raw_b2ShapeProxy_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ShapeProxy();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeProxy_00024Raw_b2ShapeProxy(JNIEnv*, jclass) {
    return (jlong) new b2ShapeProxy();
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeProxy_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ShapeProxy*) _address;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeProxy_00024Raw_getCount(JNIEnv*, jclass, jlong _address) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeProxy_00024Raw_setCount(JNIEnv*, jclass, jlong _address, jint value) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    _self->count = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeProxy_00024Raw_getPoints(JNIEnv*, jclass, jlong _address, jint _index) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    return (jlong) &_self->points[_index];
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeProxy_00024Raw_setPoints(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    _self->points[_index] = *((b2Vec2*) value);
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ShapeProxy_00024Raw_getRadius(JNIEnv*, jclass, jlong _address) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeProxy_00024Raw_setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ShapeProxy* _self = (b2ShapeProxy*) _address;
    _self->radius = value;
}

// b2RayCastInput
JNIEXPORT jint JNICALL Java_box2d_b2RayCastInput__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2RayCastInput);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayCastInput_00024Raw_b2RayCastInput_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2RayCastInput();
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayCastInput_00024Raw_b2RayCastInput(JNIEnv*, jclass) {
    return (jlong) new b2RayCastInput();
}
JNIEXPORT void JNICALL Java_box2d_b2RayCastInput_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2RayCastInput*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2RayCastInput_00024Raw_getMaxFraction(JNIEnv*, jclass, jlong _address) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    return (jfloat) _self->maxFraction;
}
JNIEXPORT void JNICALL Java_box2d_b2RayCastInput_00024Raw_setMaxFraction(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    _self->maxFraction = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayCastInput_00024Raw_getOrigin(JNIEnv*, jclass, jlong _address) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    return (jlong) &_self->origin;
}
JNIEXPORT void JNICALL Java_box2d_b2RayCastInput_00024Raw_setOrigin(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    _self->origin = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2RayCastInput_00024Raw_getTranslation(JNIEnv*, jclass, jlong _address) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    return (jlong) &_self->translation;
}
JNIEXPORT void JNICALL Java_box2d_b2RayCastInput_00024Raw_setTranslation(JNIEnv*, jclass, jlong _address, jlong value) {
    b2RayCastInput* _self = (b2RayCastInput*) _address;
    _self->translation = *((b2Vec2*) value);
}

// b2ShapeCastInput
JNIEXPORT jint JNICALL Java_box2d_b2ShapeCastInput__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeCastInput);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeCastInput_00024Raw_b2ShapeCastInput_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2ShapeCastInput();
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeCastInput_00024Raw_b2ShapeCastInput(JNIEnv*, jclass) {
    return (jlong) new b2ShapeCastInput();
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeCastInput_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2ShapeCastInput*) _address;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2ShapeCastInput_00024Raw_getCanEncroach(JNIEnv*, jclass, jlong _address) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    return (jboolean) _self->canEncroach;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeCastInput_00024Raw_setCanEncroach(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    _self->canEncroach = value;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2ShapeCastInput_00024Raw_getMaxFraction(JNIEnv*, jclass, jlong _address) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    return (jfloat) _self->maxFraction;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeCastInput_00024Raw_setMaxFraction(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    _self->maxFraction = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeCastInput_00024Raw_getProxy(JNIEnv*, jclass, jlong _address) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    return (jlong) &_self->proxy;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeCastInput_00024Raw_setProxy(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    _self->proxy = *((b2ShapeProxy*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2ShapeCastInput_00024Raw_getTranslation(JNIEnv*, jclass, jlong _address) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    return (jlong) &_self->translation;
}
JNIEXPORT void JNICALL Java_box2d_b2ShapeCastInput_00024Raw_setTranslation(JNIEnv*, jclass, jlong _address, jlong value) {
    b2ShapeCastInput* _self = (b2ShapeCastInput*) _address;
    _self->translation = *((b2Vec2*) value);
}

// b2CastOutput
JNIEXPORT jint JNICALL Java_box2d_b2CastOutput__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2CastOutput);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CastOutput_00024Raw_b2CastOutput_1placed(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) b2CastOutput();
}
JNIEXPORT jlong JNICALL Java_box2d_b2CastOutput_00024Raw_b2CastOutput(JNIEnv*, jclass) {
    return (jlong) new b2CastOutput();
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_destroy(JNIEnv*, jclass, jlong _address) {
    delete (b2CastOutput*) _address;
}
JNIEXPORT jfloat JNICALL Java_box2d_b2CastOutput_00024Raw_getFraction(JNIEnv*, jclass, jlong _address) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    return (jfloat) _self->fraction;
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_setFraction(JNIEnv*, jclass, jlong _address, jfloat value) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    _self->fraction = value;
}
JNIEXPORT jboolean JNICALL Java_box2d_b2CastOutput_00024Raw_getHit(JNIEnv*, jclass, jlong _address) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    return (jboolean) _self->hit;
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_setHit(JNIEnv*, jclass, jlong _address, jboolean value) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    _self->hit = value;
}
JNIEXPORT jint JNICALL Java_box2d_b2CastOutput_00024Raw_getIterations(JNIEnv*, jclass, jlong _address) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    return (jint) _self->iterations;
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_setIterations(JNIEnv*, jclass, jlong _address, jint value) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    _self->iterations = value;
}
JNIEXPORT jlong JNICALL Java_box2d_b2CastOutput_00024Raw_getNormal(JNIEnv*, jclass, jlong _address) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    _self->normal = *((b2Vec2*) value);
}
JNIEXPORT jlong JNICALL Java_box2d_b2CastOutput_00024Raw_getPoint(JNIEnv*, jclass, jlong _address) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    return (jlong) &_self->point;
}
JNIEXPORT void JNICALL Java_box2d_b2CastOutput_00024Raw_setPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    b2CastOutput* _self = (b2CastOutput*) _address;
    _self->point = *((b2Vec2*) value);
}

// b2ShapeType
JNIEXPORT jint JNICALL Java_box2d_b2ShapeType__1getb2_1circleShape(JNIEnv*, jclass) {
    return b2_circleShape;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeType__1getb2_1capsuleShape(JNIEnv*, jclass) {
    return b2_capsuleShape;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeType__1getb2_1segmentShape(JNIEnv*, jclass) {
    return b2_segmentShape;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeType__1getb2_1polygonShape(JNIEnv*, jclass) {
    return b2_polygonShape;
}
JNIEXPORT jint JNICALL Java_box2d_b2ShapeType__1getb2_1chainSegmentShape(JNIEnv*, jclass) {
    return b2_chainSegmentShape;
}

// b2BodyType
JNIEXPORT jint JNICALL Java_box2d_b2BodyType__1getb2_1staticBody(JNIEnv*, jclass) {
    return b2_staticBody;
}
JNIEXPORT jint JNICALL Java_box2d_b2BodyType__1getb2_1kinematicBody(JNIEnv*, jclass) {
    return b2_kinematicBody;
}
JNIEXPORT jint JNICALL Java_box2d_b2BodyType__1getb2_1dynamicBody(JNIEnv*, jclass) {
    return b2_dynamicBody;
}

// b2JointType
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1distanceJoint(JNIEnv*, jclass) {
    return b2_distanceJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1filterJoint(JNIEnv*, jclass) {
    return b2_filterJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1motorJoint(JNIEnv*, jclass) {
    return b2_motorJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1mouseJoint(JNIEnv*, jclass) {
    return b2_mouseJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1prismaticJoint(JNIEnv*, jclass) {
    return b2_prismaticJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1revoluteJoint(JNIEnv*, jclass) {
    return b2_revoluteJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1weldJoint(JNIEnv*, jclass) {
    return b2_weldJoint;
}
JNIEXPORT jint JNICALL Java_box2d_b2JointType__1getb2_1wheelJoint(JNIEnv*, jclass) {
    return b2_wheelJoint;
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
