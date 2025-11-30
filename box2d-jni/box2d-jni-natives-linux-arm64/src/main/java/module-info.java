module de.fabmax.box2djni.linuxarm {
    requires de.fabmax.box2djni;

    exports de.fabmax.box2djni.linuxarm64;

    opens de.fabmax.box2djni.linuxarm64 to de.fabmax.box2djni;
}