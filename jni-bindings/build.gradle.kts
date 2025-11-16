subprojects {
    group = "de.fabmax"
    version = "1.0.0"

    if (name != "box2d-jni-android") {
        apply(plugin = "java-library")

//        tasks["jar"].apply {
//            this as Jar
//            from("$rootDir/LICENSE", "$rootDir/NOTICE.md")
//        }
    }
}
