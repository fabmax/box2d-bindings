package de.fabmax.box2djni;

import box2d.B2_Base;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Box2dVersionTest {
    @Test
    public void box2dVersion() {
        var version = B2_Base.getVersion();
        System.out.println("Box2d version: " + version.getMajor() + "." + version.getMinor() + "." + version.getRevision());
        assertEquals(3, version.getMajor());
        assertEquals(1, version.getMinor());
        assertEquals(1, version.getRevision());
    }
}