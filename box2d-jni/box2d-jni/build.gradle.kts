plugins {
    alias(libs.plugins.webidl)
    alias(libs.plugins.mavenPublish)
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
        nativeIncludeDirs.set(files(
            file("$rootDir/../box2d-native/build/_deps/box2d-src/include/box2d"),
            file("$rootDir/../box2d-native/src/webidlbindings"),
        ))
    }
    generateCompactWebIdl {
        outputFile.set(file("${rootDir}/../box2d-native/src/webidlbindings/wasm/box2d.idl"))
    }
}

tasks.javadoc {
    val opts = options as StandardJavadocDocletOptions
    opts.addStringOption("Xdoclint:none", "-quiet")
}

tasks["clean"].doLast {
    delete("$projectDir/src/main/generated")
}

tasks.compileJava {
    dependsOn("generateJniJavaBindings")
    //dependsOn("updateVersionNames")
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

    testRuntimeOnly(project(":box2d-jni-natives-windows"))
    testRuntimeOnly(project(":box2d-jni-natives-windows-arm64"))
    testRuntimeOnly(project(":box2d-jni-natives-linux"))
    testRuntimeOnly(project(":box2d-jni-natives-linux-arm64"))
    testRuntimeOnly(project(":box2d-jni-natives-macos"))
    testRuntimeOnly(project(":box2d-jni-natives-macos-arm64"))

    testImplementation(libs.lwjgl.core)
    val os = org.gradle.internal.os.OperatingSystem.current()
    val arch = System.getProperty("os.arch", "unknown")
    val lwjglPlatform = when {
        os.isLinux && arch == "aarch64" -> "natives-linux-arm64"
        os.isLinux && arch != "aarch64" -> "natives-linux"
        os.isMacOsX && arch == "aarch64" -> "natives-macos-arm64"
        os.isMacOsX && arch != "aarch64" -> "natives-macos"
        else -> "natives-windows"
    }
    testRuntimeOnly("${libs.lwjgl.core.get()}:$lwjglPlatform")
}

mavenPublishing {
    publishToMavenCentral()
    if (!version.toString().endsWith("-SNAPSHOT")) {
        signAllPublications()
    }

    coordinates(group.toString(), name, version.toString())

    pom {
        name.set("box2d-jni")
        description.set("JNI bindings for Box2D.")
        inceptionYear.set("2025")
        url.set("https://github.com/fabmax/box2d-bindings")
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
            url.set("https://github.com/fabmax/box2d-bindings/")
            connection.set("scm:git:git://github.com/fabmax/box2d-bindings.git")
            developerConnection.set("scm:git:ssh://git@github.com/fabmax/box2d-bindings.git")
        }
    }
}

afterEvaluate {
    tasks["generateMetadataFileForMavenPublication"].dependsOn("plainJavadocJar")

    publishing.publications["maven"].apply {
        this as MavenPublication

        artifact(project(":box2d-jni-natives-windows").tasks["jar"]).apply {
            classifier = "natives-windows"
        }
        artifact(project(":box2d-jni-natives-windows-arm64").tasks["jar"]).apply {
            classifier = "natives-windows-arm64"
        }
        artifact(project(":box2d-jni-natives-linux").tasks["jar"]).apply {
            classifier = "natives-linux"
        }
        artifact(project(":box2d-jni-natives-linux-arm64").tasks["jar"]).apply {
            classifier = "natives-linux-arm64"
        }
        artifact(project(":box2d-jni-natives-macos").tasks["jar"]).apply {
            classifier = "natives-macos"
        }
        artifact(project(":box2d-jni-natives-macos-arm64").tasks["jar"]).apply {
            classifier = "natives-macos-arm64"
        }
    }
}
