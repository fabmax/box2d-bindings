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
    modelPath.set(file("${rootDir}/../src/webidl/"))
    modelName.set("Box2d")

    generateJni {
        javaClassesOutputDirectory.set(file("$projectDir/src/main/generated/box2d"))
        nativeGlueCodeOutputFile.set(file("${rootDir}/../src/webidlbindings/jni/box2dGlue.h"))

        packagePrefix.set("box2d")
        onClassLoadStatement.set("de.fabmax.box2djni.Loader.load();")
        nativeIncludeDir.set(file("$rootDir/../build/_deps/box2d-src/include/box2d"))
    }

//    generateCompactWebIdl {
//        outputFile.set(file("${rootDir}/PhysX/physx/source/webidlbindings/src/wasm/PhysXWasm.idl"))
//    }
}

//tasks {
//    withType<Test>().configureEach {
//        useJUnitPlatform()
//        testLogging {
//            showStandardStreams = true
//            //exceptionFormat = org.gradle.api.tasks.testing.logging.TestExceptionFormat.FULL
//        }
//    }
//}

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
}