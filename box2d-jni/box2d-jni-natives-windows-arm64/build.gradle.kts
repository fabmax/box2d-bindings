plugins {
    `java-library`
}

java {
    toolchain {
        languageVersion = JavaLanguageVersion.of(17)
    }
    withSourcesJar()
}

tasks["sourcesJar"].apply {
    this as Jar
    exclude("**/*.dll")
    exclude("**/*.sha1")
}

tasks.register<Exec>("generateNativeProjectWindowsArm64") {
    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build-windows-arm64")
    commandLine = listOf("cmake", "-DBOX2D_AVX2=Off", "-DCMAKE_TOOLCHAIN_FILE=../cmake/WindowsArm64.cmake", "-A", "ARM64", "..")

    doFirst {
        delete("$rootDir/../box2d-native/build-windows-arm64")
        mkdir("$rootDir/../box2d-native/build-windows-arm64")
    }
}

tasks.register<Exec>("buildNativeLibWindowsArm64") {
    dependsOn(":box2d-jni:generateJniNativeBindings")

    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build-windows-arm64")
    commandLine = listOf("cmake", "--build", ".", "--config", "Release")
    if (!workingDir.exists()) {
        dependsOn("generateNativeProjectWindowsArm64")
    }

    val resourcesDir = "${projectDir}/src/main/resources/de/fabmax/box2djni/windowsarm64/"
    doFirst {
        delete(resourcesDir)
    }
    doLast {
        copy {
            from("$rootDir/../box2d-native/build-windows-arm64/bin/arm64/Release")
            include("*.dll")
            into(resourcesDir)
        }
        Sha1Helper.writeHashes(File(resourcesDir))
    }
}

dependencies {
    implementation(project(":box2d-jni"))
}