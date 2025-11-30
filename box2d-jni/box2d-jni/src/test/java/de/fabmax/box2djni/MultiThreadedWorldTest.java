package de.fabmax.box2djni;

import box2d.*;
import org.junit.jupiter.api.Test;
import org.lwjgl.system.MemoryStack;

public class MultiThreadedWorldTest {
    @Test
    public void simpleWorldTest() {
        TaskManager taskManager;
        long worldId;
        long bodyId = 0L;

        var t = System.nanoTime();
        var dynBoxCnt = 0;

        try (var stack = MemoryStack.stackPush()) {
            var worldDef = b2WorldDef.createAt(stack, MemoryStack::nmalloc);
            B2_World.defaultWorldDef(worldDef);
            taskManager = new DefaultTaskManager(worldDef, 8);

            var grav = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            grav.setX(0.0f);
            grav.setY(-10.0f);
            worldDef.setGravity(grav);
            worldId = B2_World.createWorld(worldDef);

            var groundBodyDef = b2BodyDef.createAt(stack, MemoryStack::nmalloc);
            B2_Body.defaultBodyDef(groundBodyDef);
            var groundPos = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            groundPos.setX(0.0f);
            groundPos.setY(-10.0f);
            groundBodyDef.setPosition(groundPos);
            var groundId = B2_Body.createBody(worldId, groundBodyDef);

            var groundBox = b2Polygon.createAt(stack, MemoryStack::nmalloc);
            B2_Geometry.makeBox(50.0f, 10.0f, groundBox);
            var groundShapeDef = b2ShapeDef.createAt(stack, MemoryStack::nmalloc);
            B2_Shape.defaultShapeDef(groundShapeDef);
            B2_Shape.createPolygonShape(groundId, groundShapeDef, groundBox);

            var bodyDef = b2BodyDef.createAt(stack, MemoryStack::nmalloc);
            B2_Body.defaultBodyDef(bodyDef);
            bodyDef.setType(b2BodyType.b2_dynamicBody);
            var shapeDef = b2ShapeDef.createAt(stack, MemoryStack::nmalloc);
            B2_Shape.defaultShapeDef(shapeDef);
            shapeDef.setDensity(1.0f);
            var material = shapeDef.getMaterial();
            material.setFriction(0.3f);
            shapeDef.setMaterial(material);

            var dynamicBox = b2Polygon.createAt(stack, MemoryStack::nmalloc);
            B2_Geometry.makeBox(1f, 1f, dynamicBox);

            var bodyPos = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            for (int x = -40; x < 40; x += 2) {
                for (int i = 0; i < 100; i++) {
                    bodyPos.setX(x);
                    bodyPos.setY(10.0f + i * 3f);
                    bodyDef.setPosition(bodyPos);
                    bodyId = B2_Body.createBody(worldId, bodyDef);
                    B2_Shape.createPolygonShape(bodyId, shapeDef, dynamicBox);
                    dynBoxCnt++;
                }
            }
        }

        float timeStep = 1f / 60f;
        int subStepCount = 4;
        for (int i = 0; i < 500; i++) {
            B2_World.step(worldId, timeStep, subStepCount);

            var pos = B2_Body.getPosition(bodyId);
            var rot = B2_Body.getRotation(bodyId);
            var angle = B2_Rot.getAngle(rot);
            if (i % 10 == 0) {
                System.out.printf("%d dynamic boxes, %4.2f %4.2f %4.2f\n", dynBoxCnt, pos.getX(), pos.getY(), angle);
            }
        }

        var now = System.nanoTime();
        System.out.println("time: " + (now - t) / 1e9f);

        B2_World.destroyWorld(worldId);
        taskManager.destroy();
    }
}
