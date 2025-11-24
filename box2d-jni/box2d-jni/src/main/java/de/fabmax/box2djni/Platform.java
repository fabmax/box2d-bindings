package de.fabmax.box2djni;

public enum Platform {

    LINUX("de.fabmax.box2djni.linux.NativeLibLinux"),
    WINDOWS("de.fabmax.box2djni.windows.NativeLibWindows"),
    WINDOWS_ARM64("de.fabmax.box2djni.windows.arm64.NativeLibWindowsArm64"),
    MACOS("de.fabmax.box2djni.macos.NativeLibMacos");

    private final String metaClassName;

    Platform(String metaClassName) {
        this.metaClassName = metaClassName;
    }

    public NativeLib getLib() throws ReflectiveOperationException {
        Class<?> libImpl =  Loader.class.getClassLoader().loadClass(metaClassName);
        return (NativeLib) libImpl.getConstructor().newInstance();
    }

    public static Platform getPlatform() {
        String vendor = System.getProperty("java.vendor", "unknown").toLowerCase();
        String osName = System.getProperty("os.name", "unknown").toLowerCase();
        String arch = System.getProperty("os.arch", "unknown").toLowerCase();

        if (vendor.contains("android")) {   // on Android java.vendor should be "The Android Project"
            throw new IllegalStateException("Android environment detected. Use 'box2d-jni-android' library instead of regular 'box2d-jni'");
        } else if (osName.contains("windows")) {
            if (arch.contains("aarch64") || arch.contains("arm64")) {
                return WINDOWS_ARM64;
            } else {
                return WINDOWS;
            }
        } else if (osName.contains("linux")) {
            return LINUX;
        } else if (osName.contains("mac os x") || osName.contains("darwin") || osName.contains("osx")) {
            return MACOS;
        } else {
            throw new IllegalStateException("Unsupported OS: " + osName);
        }
    }
}
