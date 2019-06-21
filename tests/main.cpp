#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <u3d.hpp>
#include <iostream>
#include <cmath>

#define FINE 1e-6f
#define COARSE 0.1f

bool close_to(float val, float target, float err)
{
    return fabsf(val - target) < err;
}

TEST_CASE("object3d children move with parent", "[Object3D]")
{
    Object3D a;
    Object3D b;

    b.position.x = 2;

    a.addChild(b);

    a.position.x = 2;
    a.position.y = 2;
    a.position.z = 2;

    a.update();

    REQUIRE(a.position == glm::vec3(2, 2, 2));
    REQUIRE(b.position == glm::vec3(2, 0, 0));
    REQUIRE(b.world_position == glm::vec3(4, 2, 2));
}

TEST_CASE("object3d children rotate with parent", "[Object3D]")
{
    Object3D a;
    Object3D b;

    b.position.x = 1;
    a.addChild(b);
    a.update();

    REQUIRE(b.world_position == glm::vec3(1, 0, 0));

    a.rotation.y = 90;
    a.update();

    REQUIRE(close_to(b.rotation.y, 0, COARSE));

    REQUIRE(close_to(b.world_rotation.y, 90, COARSE));

    REQUIRE(close_to(b.world_position.x, 0, FINE));
    REQUIRE(close_to(b.world_position.y, 0, FINE));
    REQUIRE(close_to(b.world_position.z, -1, FINE));    
}