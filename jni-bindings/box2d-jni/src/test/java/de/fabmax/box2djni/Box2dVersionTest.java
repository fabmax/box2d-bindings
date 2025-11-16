package de.fabmax.box2djni;

import box2d.B2Base;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class Box2dVersionTest {
    @Test
    public void box2dVersion() {
        var version = B2Base.getVersion();
        System.out.println("Box2d version: " + version.getMajor() + "." + version.getMinor() + "." + version.getRevision());
        Assertions.assertEquals(3, version.getMajor());
        Assertions.assertEquals(1, version.getMinor());
        Assertions.assertEquals(1, version.getRevision());
    }
}