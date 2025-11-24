pluginManagement {
    repositories {
        mavenLocal()
        google()
        mavenCentral()
        gradlePluginPortal()
    }
}

@Suppress("UnstableApiUsage")
dependencyResolutionManagement {
    repositories {
        google()
        mavenCentral()
    }
}

rootProject.name = "box2d-jni"

include("box2d-jni")
include("box2d-jni-natives-linux")
include("box2d-jni-natives-macos")
include("box2d-jni-natives-windows")
include("box2d-jni-natives-windows-arm64")