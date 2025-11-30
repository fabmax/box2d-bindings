plugins {
    alias(libs.plugins.androidLibrary)
    alias(libs.plugins.webidl)
    alias(libs.plugins.mavenPublish)
}

android {
    namespace = "de.fabmax.box2djni"
    compileSdk = 36

    defaultConfig {
        minSdk = 24
    }

    sourceSets.getByName("main") {
        java.srcDir("src/main/generated")
    }

    externalNativeBuild {
        cmake {
            path = file("${rootDir}/../box2d-native/CMakeLists.txt")
            version = "3.22.1"
        }
    }
}

java {
    toolchain {
        languageVersion = JavaLanguageVersion.of(17)
    }
}

webidl {
    modelPath.set(file("${rootDir}/../box2d-native/src/webidl/"))
    modelName.set("Box2d")

    generateJni {
        javaClassesOutputDirectory.set(file("$projectDir/src/main/generated/box2dandroid"))
        nativeGlueCodeOutputFile.set(file("${rootDir}/../box2d-native/src/webidlbindings/jni/box2dGlue.h"))

        packagePrefix.set("box2dandroid")
        onClassLoadStatement.set("de.fabmax.box2dandroid.Loader.load();")
        nativeIncludeDirs.set(files(
            file("$rootDir/../box2d-native/build/_deps/box2d-src/include/box2d"),
            file("$rootDir/../box2d-native/src/webidlbindings"),
        ))
    }
}

tasks["clean"].doLast {
    delete("$projectDir/src/main/generated")
}

tasks["preBuild"].dependsOn("generateJniJavaBindings", "generateJniNativeBindings")

mavenPublishing {
    publishToMavenCentral()
    if (!version.toString().endsWith("-SNAPSHOT")) {
        signAllPublications()
    }

    coordinates(group.toString(), name, version.toString())

    pom {
        name.set("box2d-jni-android")
        description.set("JNI bindings for Box2D on Android.")
        inceptionYear.set("2025")
        url.set("https://github.com/fabmax/box2d-jni")
        licenses {
            license {
                name.set("MIT License")
                url.set("https://opensource.org/licenses/MIT")
                distribution.set("https://opensource.org/licenses/MIT")
            }
        }
        developers {
            developer {
                id.set("fabmax")
                name.set("Max Thiele")
                url.set("https://github.com/fabmax/")
            }
        }
        scm {
            url.set("https://github.com/fabmax/box2d-jni/")
            connection.set("scm:git:git://github.com/fabmax/box2d-jni.git")
            developerConnection.set("scm:git:ssh://git@github.com/fabmax/box2d-jni.git")
        }
    }
}
