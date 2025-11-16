#
# Build JNI Bindings
#

set(JAVA_AWT_LIBRARY NotNeeded)
set(JAVA_JVM_LIBRARY NotNeeded)
find_package(JNI REQUIRED)

add_library(Box2dJniBindings SHARED src/webidlbindings/jni/box2d.cpp)

target_link_libraries(Box2dJniBindings)