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
    workingDir = File("$rootDir/../box2d-native/build")
    commandLine = listOf("cmake", "-DCMAKE_BUILD_TYPE=Release", "..")

    doFirst {
        delete("$rootDir/../box2d-native/build")
        mkdir("$rootDir/../box2d-native/build")
    }
}

tasks.register<Exec>("buildNativeLibMacos") {
    dependsOn(":box2d-jni:generateJniNativeBindings")

    group = "native build"
    workingDir = File("$rootDir/../box2d-native/build")
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
            from("$rootDir/../box2d-native/build/lib")
            include("*.dylib")
            into(resourcesDir)
        }
        Sha1Helper.writeHashes(File(resourcesDir))
    }
}

dependencies {
    implementation(project(":box2d-jni"))
}
