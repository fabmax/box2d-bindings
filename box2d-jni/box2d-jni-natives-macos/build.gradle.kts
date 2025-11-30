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
    exclude("**/*.dylib")
    exclude("**/*.sha1")
}

tasks.register<Exec>("generateNativeProjectMacos") {
    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build-macos-x86_64")
    commandLine = listOf("cmake", "-DCMAKE_BUILD_TYPE=Release", "-DCMAKE_OSX_ARCHITECTURES=x86_64", "..")

    doFirst {
        delete("$rootDir/../box2d-native/build-macos-x86_64")
        mkdir("$rootDir/../box2d-native/build-macos-x86_64")
    }
}

tasks.register<Exec>("buildNativeLibMacos") {
    dependsOn(":box2d-jni:generateJniNativeBindings")

    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build-macos-x86_64")
    commandLine = listOf("cmake", "--build", ".")
    if (!workingDir.exists()) {
        dependsOn("generateNativeProjectMacos")
    }

    val resourcesDir = "${projectDir}/src/main/resources/de/fabmax/box2djni/macos/"
    doFirst {
        delete(resourcesDir)
    }
    doLast {
        copy {
            from("$rootDir/../box2d-native/build-macos-x86_64/lib/x86_64")
            include("*.dylib")
            into(resourcesDir)
        }
        Sha1Helper.writeHashes(File(resourcesDir))
    }
}

dependencies {
    implementation(project(":box2d-jni"))
}
