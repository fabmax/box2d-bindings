module de.fabmax.box2djni.windowsarm {
    requires de.fabmax.box2djni;

    exports de.fabmax.box2djni.windowsarm64;

    opens de.fabmax.box2djni.windowsarm64 to de.fabmax.box2djni;
}