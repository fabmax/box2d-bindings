plugins {
    alias(libs.plugins.webidl)
    //alias(libs.plugins.mavenPublish)
}

java {
    toolchain {
        languageVersion = JavaLanguageVersion.of(17)
    }
    withSourcesJar()

    sourceSets {
        main {
            java {
                srcDir("src/main/generated")
            }
        }
    }
}

webidl {
    modelPath.set(file("${rootDir}/../box2d-native/src/webidl/"))
    modelName.set("Box2d")

    generateJni {
        javaClassesOutputDirectory.set(file("$projectDir/src/main/generated/box2d"))
        nativeGlueCodeOutputFile.set(file("${rootDir}/../box2d-native/src/webidlbindings/jni/box2dGlue.h"))

        packagePrefix.set("box2d")
        onClassLoadStatement.set("de.fabmax.box2djni.Loader.load();")
        nativeIncludeDir.set(file("$rootDir/../box2d-native/build/_deps/box2d-src/include/box2d"))
    }
}

tasks.test {
    useJUnitPlatform()
    testLogging {
        showStandardStreams = true
    }
}

dependencies {
    testImplementation(platform(libs.junit.bom))
    testImplementation(libs.junit.jupiter)
    testRuntimeOnly("org.junit.platform:junit-platform-launcher")

//    testRuntimeOnly(project(":box2d-jni-natives-windows"))
//    testRuntimeOnly(project(":box2d-jni-natives-linux"))
//    testRuntimeOnly(project(":box2d-jni-natives-macos"))
    testRuntimeOnly(project(":box2d-jni-natives-macos-arm64"))

    testImplementation(libs.lwjgl.core)
    val os = org.gradle.internal.os.OperatingSystem.current()
    val arch = System.getProperty("os.arch", "unknown")
    val lwjglPlatform = when {
        os.isLinux -> "natives-linux"
        os.isMacOsX && arch == "aarch64" -> "natives-macos-arm64"
        os.isMacOsX && arch != "aarch64" -> "natives-macos"
        else -> "natives-windows"
    }
    testRuntimeOnly("${libs.lwjgl.core.get()}:$lwjglPlatform")
}