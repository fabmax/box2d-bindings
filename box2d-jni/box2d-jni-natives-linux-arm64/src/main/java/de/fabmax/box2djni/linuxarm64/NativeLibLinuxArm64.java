package de.fabmax.box2djni.linuxarm64;

import de.fabmax.box2djni.NativeLib;

import java.util.ArrayList;
import java.util.List;

public class NativeLibLinuxArm64 extends NativeLib {

    private static final String version = "1.0.0";

    private static final List<String> libraries = new ArrayList<>() {{
        add("libBox2dJniBindings.so");
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