package de.fabmax.box2djni;

import box2d.B2Math;
import box2d.b2Vec2;
import org.junit.jupiter.api.Test;
import org.lwjgl.system.MemoryStack;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MathTest {

    @Test
    public void b2Vec2Test() {
        try (var stack = MemoryStack.stackPush()) {
            var a = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            a.setX(2.0f);
            a.setY(3.0f);

            assertEquals(2.0f, a.getX());
            assertEquals(3.0f, a.getY());

            var b = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            b.setX(4.0f);
            b.setY(5.0f);

            assertEquals(2f * 4f + 3f * 5f, B2Math.dot(a, b));
        }
    }
}
