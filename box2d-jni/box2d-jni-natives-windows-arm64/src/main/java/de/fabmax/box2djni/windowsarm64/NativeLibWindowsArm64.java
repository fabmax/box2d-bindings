package de.fabmax.box2djni.windowsarm64;

import de.fabmax.box2djni.NativeLib;

import java.util.ArrayList;
import java.util.List;

public class NativeLibWindowsArm64 extends NativeLib {

    private static final String version = "1.0.0-SNAPSHOT";

    private static final List<String> libraries = new ArrayList<>() {{
        add("Box2dJniBindings.dll");
    }};

    @Override
    public String getVersion() {
        return version;
    }

    @Override
    protected List<String> getLibResourceNames() {
        return libraries;
    }
}
