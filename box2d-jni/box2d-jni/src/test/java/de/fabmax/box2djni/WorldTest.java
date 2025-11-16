package de.fabmax.box2djni;

import box2d.*;
import org.junit.jupiter.api.Test;
import org.lwjgl.system.MemoryStack;

import static org.junit.jupiter.api.Assertions.*;

public class WorldTest {
    @Test
    public void simpleWorldTest() {
        try (var stack = MemoryStack.stackPush()) {
            var worldDef = b2WorldDef.createAt(stack, MemoryStack::nmalloc);
            B2_World.defaultWorldDef(worldDef);
            var grav = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            grav.setX(0.0f);
            grav.setY(-10.0f);
            worldDef.setGravity(grav);
            var worldId = new b2WorldId();
            B2_World.createWorld(worldDef, worldId);

            var groundBodyDef = b2BodyDef.createAt(stack, MemoryStack::nmalloc);
            B2_Body.defaultBodyDef(groundBodyDef);
            var groundPos = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            groundPos.setX(0.0f);
            groundPos.setY(-10.0f);
            groundBodyDef.setPosition(groundPos);
            var groundId = new b2BodyId();
            B2_Body.createBody(worldId, groundBodyDef, groundId);

            var groundBox = b2Polygon.createAt(stack, MemoryStack::nmalloc);
            B2_Geometry.makeBox(50.0f, 10.0f, groundBox);
            var groundShapeDef = b2ShapeDef.createAt(stack, MemoryStack::nmalloc);
            B2_Shape.defaultShapeDef(groundShapeDef);
            var groundShapeId = new b2ShapeId();
            B2_Shape.createPolygonShape(groundId, groundShapeDef, groundBox, groundShapeId);


            var bodyDef = b2BodyDef.createAt(stack, MemoryStack::nmalloc);
            B2_Body.defaultBodyDef(bodyDef);
            bodyDef.setType(b2BodyType.b2_dynamicBody);
            var bodyPos = b2Vec2.createAt(stack, MemoryStack::nmalloc);
            bodyPos.setX(0.0f);
            bodyPos.setY(10.0f);
            bodyDef.setPosition(bodyPos);
            var bodyId = new b2BodyId();
            B2_Body.createBody(worldId, bodyDef, bodyId);

            var dynamicBox = b2Polygon.createAt(stack, MemoryStack::nmalloc);
            B2_Geometry.makeBox(1f, 1f, dynamicBox);
            var shapeDef = b2ShapeDef.createAt(stack, MemoryStack::nmalloc);
            B2_Shape.defaultShapeDef(shapeDef);
            shapeDef.setDensity(1.0f);
            var material = shapeDef.getMaterial();
            material.setFriction(0.3f);
            shapeDef.setMaterial(material);
            var bodyShapeId = new b2ShapeId();
            B2_Shape.createPolygonShape(bodyId, shapeDef, dynamicBox, bodyShapeId);

            float timeStep = 1f / 60f;
            int subStepCount = 4;
            for (int i = 0; i < 100; i++) {
                B2_World.step(worldId, timeStep, subStepCount);
                var pos = B2_Body.getPosition(bodyId);
                var rot = B2_Body.getRotation(bodyId);
                var angle = B2_Rot.getAngle(rot);
                System.out.printf("%4.2f %4.2f %4.2f\n", pos.getX(), pos.getY(), angle);
            }

            var pos = B2_Body.getPosition(bodyId);
            assertEquals(0.0f, pos.getX(), 0.1f);
            assertEquals(1.0f, pos.getY(), 0.01f);
            assertEquals(0.0f, B2_Rot.getAngle(B2_Body.getRotation(bodyId)), 0.01f);

            B2_World.destroyWorld(worldId);

            groundId.destroy();
            groundShapeId.destroy();
            bodyId.destroy();
            bodyShapeId.destroy();
            worldId.destroy();
        }
    }
}
