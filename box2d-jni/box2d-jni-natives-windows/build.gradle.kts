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

tasks.register<Exec>("generateNativeProjectWindows") {
    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build")
    commandLine = listOf("cmake", "-DBOX2D_AVX2=On", "..")

    doFirst {
        delete("$rootDir/../box2d-native/build")
        mkdir("$rootDir/../box2d-native/build")
    }
}

tasks.register<Exec>("buildNativeLibWindows") {
    dependsOn(":box2d-jni:generateJniNativeBindings")

    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build")
    commandLine = listOf("cmake", "--build", ".", "--config", "Release")
    if (!workingDir.exists()) {
        dependsOn("generateNativeProjectWindows")
    }

    val resourcesDir = "${projectDir}/src/main/resources/de/fabmax/box2djni/windows/"
    doFirst {
        delete(resourcesDir)
    }
    doLast {
        copy {
            from("$rootDir/../box2d-native/build/bin/x64/Release")
            include("*.dll")
            into(resourcesDir)
        }
        Sha1Helper.writeHashes(File(resourcesDir))
    }
}

dependencies {
    implementation(project(":box2d-jni"))
}
