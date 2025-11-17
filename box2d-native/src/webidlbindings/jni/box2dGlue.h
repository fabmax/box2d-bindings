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

// B2_Shape
JNIEXPORT jint JNICALL Java_box2d_B2_1Shape__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Shape);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_defaultShapeDef(JNIEnv*, jclass, jlong result) {
    B2_Shape::defaultShapeDef(*((b2ShapeDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Shape_00024Raw_createPolygonShape(JNIEnv*, jclass, jlong bodyId, jlong def, jlong polygon, jlong result) {
    B2_Shape::createPolygonShape(*((b2BodyId*) bodyId), (b2ShapeDef*) def, (b2Polygon*) polygon, *((b2ShapeId*) result));
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

// b2ShapeId
JNIEXPORT jint JNICALL Java_box2d_b2ShapeId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2ShapeId);
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

// B2_Vec2
JNIEXPORT jint JNICALL Java_box2d_B2_1Vec2__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Vec2);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Vec2_00024Raw_dot(JNIEnv*, jclass, jlong a, jlong b) {
    return (jfloat) B2_Vec2::dot(*((b2Vec2*) a), *((b2Vec2*) b));
}

// B2_Rot
JNIEXPORT jint JNICALL Java_box2d_B2_1Rot__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Rot);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Rot_00024Raw_getAngle(JNIEnv*, jclass, jlong q) {
    return (jfloat) B2_Rot::getAngle(*((b2Rot*) q));
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

// B2_World
JNIEXPORT jint JNICALL Java_box2d_B2_1World__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_World);
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_defaultWorldDef(JNIEnv*, jclass, jlong result) {
    B2_World::defaultWorldDef(*((b2WorldDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_createWorld(JNIEnv*, jclass, jlong def, jlong result) {
    B2_World::createWorld((b2WorldDef*) def, *((b2WorldId*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_destroyWorld(JNIEnv*, jclass, jlong result) {
    B2_World::destroyWorld(*((b2WorldId*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1World_00024Raw_step(JNIEnv*, jclass, jlong world, jfloat timeStep, jint subStepCount) {
    B2_World::step(*((b2WorldId*) world), timeStep, subStepCount);
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

// b2WorldId
JNIEXPORT jint JNICALL Java_box2d_b2WorldId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2WorldId);
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

// B2_Base
JNIEXPORT jint JNICALL Java_box2d_B2_1Base__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Base);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Base_00024Raw_getVersion(JNIEnv*, jclass) {
    static thread_local b2Version _cache = B2_Base::getVersion();
    _cache = B2_Base::getVersion();
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

// B2_Body
JNIEXPORT jint JNICALL Java_box2d_B2_1Body__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Body);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_defaultBodyDef(JNIEnv*, jclass, jlong result) {
    B2_Body::defaultBodyDef(*((b2BodyDef*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_createBody(JNIEnv*, jclass, jlong worldId, jlong def, jlong result) {
    B2_Body::createBody(*((b2WorldId*) worldId), (b2BodyDef*) def, *((b2BodyId*) result));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_destroyBody(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::destroyBody(*((b2BodyId*) bodyId));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isValid(JNIEnv*, jclass, jlong id) {
    return (jboolean) B2_Body::isValid(*((b2BodyId*) id));
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getType(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getType(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setType(JNIEnv*, jclass, jlong bodyId, jint type) {
    B2_Body::setType(*((b2BodyId*) bodyId), (b2BodyType) type);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setName(JNIEnv* _env, jclass, jlong bodyId, jstring name) {
    B2_Body::setName(*((b2BodyId*) bodyId), _env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_box2d_B2_1Body_00024Raw_getName(JNIEnv* _env, jclass, jlong bodyId) {
    return _env->NewStringUTF(B2_Body::getName(*((b2BodyId*) bodyId)));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setUserData(JNIEnv*, jclass, jlong bodyId, jlong userData) {
    B2_Body::setUserData(*((b2BodyId*) bodyId), (void*) userData);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getUserData(JNIEnv*, jclass, jlong bodyId) {
    return (jlong) B2_Body::getUserData(*((b2BodyId*) bodyId));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getPosition(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getPosition(*((b2BodyId*) bodyId));
    _cache = B2_Body::getPosition(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getRotation(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Rot _cache = B2_Body::getRotation(*((b2BodyId*) bodyId));
    _cache = B2_Body::getRotation(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getTransform(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Transform _cache = B2_Body::getTransform(*((b2BodyId*) bodyId));
    _cache = B2_Body::getTransform(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setTransform(JNIEnv*, jclass, jlong bodyId, jlong position, jlong rotation) {
    B2_Body::setTransform(*((b2BodyId*) bodyId), *((b2Vec2*) position), *((b2Rot*) rotation));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalPoint(JNIEnv*, jclass, jlong bodyId, jlong worldPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalPoint(*((b2BodyId*) bodyId), *((b2Vec2*) worldPoint));
    _cache = B2_Body::getLocalPoint(*((b2BodyId*) bodyId), *((b2Vec2*) worldPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldPoint(JNIEnv*, jclass, jlong bodyId, jlong localPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldPoint(*((b2BodyId*) bodyId), *((b2Vec2*) localPoint));
    _cache = B2_Body::getWorldPoint(*((b2BodyId*) bodyId), *((b2Vec2*) localPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalVector(JNIEnv*, jclass, jlong bodyId, jlong worldVector) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalVector(*((b2BodyId*) bodyId), *((b2Vec2*) worldVector));
    _cache = B2_Body::getLocalVector(*((b2BodyId*) bodyId), *((b2Vec2*) worldVector));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldVector(JNIEnv*, jclass, jlong bodyId, jlong localVector) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldVector(*((b2BodyId*) bodyId), *((b2Vec2*) localVector));
    _cache = B2_Body::getWorldVector(*((b2BodyId*) bodyId), *((b2Vec2*) localVector));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLinearVelocity(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getLinearVelocity(*((b2BodyId*) bodyId));
    _cache = B2_Body::getLinearVelocity(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getAngularVelocity(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getAngularVelocity(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setLinearVelocity(JNIEnv*, jclass, jlong bodyId, jlong linearVelocity) {
    B2_Body::setLinearVelocity(*((b2BodyId*) bodyId), *((b2Vec2*) linearVelocity));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAngularVelocity(JNIEnv*, jclass, jlong bodyId, jfloat angularVelocity) {
    B2_Body::setAngularVelocity(*((b2BodyId*) bodyId), angularVelocity);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setTargetTransform(JNIEnv*, jclass, jlong bodyId, jlong target, jfloat timeStep) {
    B2_Body::setTargetTransform(*((b2BodyId*) bodyId), *((b2Transform*) target), timeStep);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalPointVelocity(JNIEnv*, jclass, jlong bodyId, jlong localPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalPointVelocity(*((b2BodyId*) bodyId), *((b2Vec2*) localPoint));
    _cache = B2_Body::getLocalPointVelocity(*((b2BodyId*) bodyId), *((b2Vec2*) localPoint));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldPointVelocity(JNIEnv*, jclass, jlong bodyId, jlong worldPoint) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldPointVelocity(*((b2BodyId*) bodyId), *((b2Vec2*) worldPoint));
    _cache = B2_Body::getWorldPointVelocity(*((b2BodyId*) bodyId), *((b2Vec2*) worldPoint));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyForce(JNIEnv*, jclass, jlong bodyId, jlong force, jlong point, jboolean wake) {
    B2_Body::applyForce(*((b2BodyId*) bodyId), *((b2Vec2*) force), *((b2Vec2*) point), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyForceToCenter(JNIEnv*, jclass, jlong bodyId, jlong force, jboolean wake) {
    B2_Body::applyForceToCenter(*((b2BodyId*) bodyId), *((b2Vec2*) force), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyTorque(JNIEnv*, jclass, jlong bodyId, jfloat torque, jboolean wake) {
    B2_Body::applyTorque(*((b2BodyId*) bodyId), torque, wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyLinearImpulse(JNIEnv*, jclass, jlong bodyId, jlong impulse, jlong point, jboolean wake) {
    B2_Body::applyLinearImpulse(*((b2BodyId*) bodyId), *((b2Vec2*) impulse), *((b2Vec2*) point), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyLinearImpulseToCenter(JNIEnv*, jclass, jlong bodyId, jlong impulse, jboolean wake) {
    B2_Body::applyLinearImpulseToCenter(*((b2BodyId*) bodyId), *((b2Vec2*) impulse), wake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyAngularImpulse(JNIEnv*, jclass, jlong bodyId, jfloat impulse, jboolean wake) {
    B2_Body::applyAngularImpulse(*((b2BodyId*) bodyId), impulse, wake);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getMass(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getMass(*((b2BodyId*) bodyId));
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getRotationalInertia(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getRotationalInertia(*((b2BodyId*) bodyId));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getLocalCenterOfMass(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getLocalCenterOfMass(*((b2BodyId*) bodyId));
    _cache = B2_Body::getLocalCenterOfMass(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorldCenterOfMass(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2Vec2 _cache = B2_Body::getWorldCenterOfMass(*((b2BodyId*) bodyId));
    _cache = B2_Body::getWorldCenterOfMass(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setMassData(JNIEnv*, jclass, jlong bodyId, jlong massData) {
    B2_Body::setMassData(*((b2BodyId*) bodyId), *((b2MassData*) massData));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getMassData(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2MassData _cache = B2_Body::getMassData(*((b2BodyId*) bodyId));
    _cache = B2_Body::getMassData(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_applyMassFromShapes(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::applyMassFromShapes(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setLinearDamping(JNIEnv*, jclass, jlong bodyId, jfloat linearDamping) {
    B2_Body::setLinearDamping(*((b2BodyId*) bodyId), linearDamping);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getLinearDamping(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getLinearDamping(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAngularDamping(JNIEnv*, jclass, jlong bodyId, jfloat angularDamping) {
    B2_Body::setAngularDamping(*((b2BodyId*) bodyId), angularDamping);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getAngularDamping(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getAngularDamping(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setGravityScale(JNIEnv*, jclass, jlong bodyId, jfloat gravityScale) {
    B2_Body::setGravityScale(*((b2BodyId*) bodyId), gravityScale);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getGravityScale(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getGravityScale(*((b2BodyId*) bodyId));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isAwake(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isAwake(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setAwake(JNIEnv*, jclass, jlong bodyId, jboolean awake) {
    B2_Body::setAwake(*((b2BodyId*) bodyId), awake);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableSleep(JNIEnv*, jclass, jlong bodyId, jboolean enableSleep) {
    B2_Body::enableSleep(*((b2BodyId*) bodyId), enableSleep);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isSleepEnabled(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isSleepEnabled(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setSleepThreshold(JNIEnv*, jclass, jlong bodyId, jfloat sleepThreshold) {
    B2_Body::setSleepThreshold(*((b2BodyId*) bodyId), sleepThreshold);
}
JNIEXPORT jfloat JNICALL Java_box2d_B2_1Body_00024Raw_getSleepThreshold(JNIEnv*, jclass, jlong bodyId) {
    return (jfloat) B2_Body::getSleepThreshold(*((b2BodyId*) bodyId));
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isEnabled(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isEnabled(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_disable(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::disable(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enable(JNIEnv*, jclass, jlong bodyId) {
    B2_Body::enable(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setFixedRotation(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::setFixedRotation(*((b2BodyId*) bodyId), flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isFixedRotation(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isFixedRotation(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_setBullet(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::setBullet(*((b2BodyId*) bodyId), flag);
}
JNIEXPORT jboolean JNICALL Java_box2d_B2_1Body_00024Raw_isBullet(JNIEnv*, jclass, jlong bodyId) {
    return (jboolean) B2_Body::isBullet(*((b2BodyId*) bodyId));
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableContactEvents(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::enableContactEvents(*((b2BodyId*) bodyId), flag);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Body_00024Raw_enableHitEvents(JNIEnv*, jclass, jlong bodyId, jboolean flag) {
    B2_Body::enableHitEvents(*((b2BodyId*) bodyId), flag);
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_getWorld(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2WorldId _cache = B2_Body::getWorld(*((b2BodyId*) bodyId));
    _cache = B2_Body::getWorld(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getShapeCount(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getShapeCount(*((b2BodyId*) bodyId));
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getJointCount(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getJointCount(*((b2BodyId*) bodyId));
}
JNIEXPORT jint JNICALL Java_box2d_B2_1Body_00024Raw_getContactCapacity(JNIEnv*, jclass, jlong bodyId) {
    return (jint) B2_Body::getContactCapacity(*((b2BodyId*) bodyId));
}
JNIEXPORT jlong JNICALL Java_box2d_B2_1Body_00024Raw_computeAABB(JNIEnv*, jclass, jlong bodyId) {
    static thread_local b2AABB _cache = B2_Body::computeAABB(*((b2BodyId*) bodyId));
    _cache = B2_Body::computeAABB(*((b2BodyId*) bodyId));
    return (jlong) &_cache;
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

// b2BodyId
JNIEXPORT jint JNICALL Java_box2d_b2BodyId__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(b2BodyId);
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

// B2_Geometry
JNIEXPORT jint JNICALL Java_box2d_B2_1Geometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(B2_Geometry);
}
JNIEXPORT void JNICALL Java_box2d_B2_1Geometry_00024Raw_makeBox(JNIEnv*, jclass, jfloat halfWidth, jfloat halfHeight, jlong result) {
    B2_Geometry::makeBox(halfWidth, halfHeight, *((b2Polygon*) result));
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
