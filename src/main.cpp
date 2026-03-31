#include "raylib.h"
#include "ray.h"
#include "vec3.h"
#include "cam.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "materials.h"
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main() {
    double ar = 16.0 / 9.0;
    cam cam_main(ar, 2.0, 10);

    cam_main.init(WINDOW_HEIGHT, WINDOW_WIDTH);

    World world;

    Diffused mat1;
        Diffused mat2;
        Diffused mat3;
        Diffused mat4;
        Diffused mat5;
        Diffused mat6;
        Diffused_Light mat7;
        Glass mat8;
        Metal mat_cuboid;

        auto rect_1 = std::make_unique<Quad>(Vec3(-1, 1, -1), Vec3(-1, -1, -1), Vec3(-1, -1, -3), Vec3(-1, 1, -3));
        rect_1->set_material(&mat1);
        rect_1->set_emissive_props(Vec3(1, 0, 0));

        auto rect_2 = std::make_unique<Quad>(Vec3(-1, 1, -3), Vec3(-1, -1, -3), Vec3(1, -1, -3), Vec3(1, 1, -3));
        rect_2->set_material(&mat2);
        rect_2->set_emissive_props(Vec3(1, 1, 1));

        auto rect_3 = std::make_unique<Quad>(Vec3(1, 1, -3), Vec3(1, -1, -3), Vec3(1, -1, -1), Vec3(1, 1, -1));
        rect_3->set_material(&mat3);
        rect_3->set_emissive_props(Vec3(0, 1, 0));

        auto rect_4 = std::make_unique<Quad>(Vec3(-1, -1, -1), Vec3( 1, -1, -1), Vec3( 1, -1, -3), Vec3(-1, -1, -3));
        rect_4->set_material(&mat4);
        rect_4->set_emissive_props(Vec3(1, 1, 1));

        auto rect_5 = std::make_unique<Quad>(Vec3(-1, 1, -1), Vec3(-1, 1, -3), Vec3(1, 1, -3), Vec3(1, 1, -1));
        rect_5->set_material(&mat5);
        rect_5->set_emissive_props(Vec3(1, 1, 1));

        auto rect_6 = std::make_unique<Quad>(Vec3(-1, 1, -1), Vec3(-1, -1, -1), Vec3(1, -1, -1), Vec3(1, 1, -1));
        rect_6->set_material(&mat6);
        rect_6->set_emissive_props(Vec3(1, 1, 1));

        auto rect_7 = std::make_unique<Quad>(Vec3(-0.5, 1, -2.5), Vec3(0.5, 1, -2.5), Vec3(0.5, 1, -1.5), Vec3(-0.5, 1, -1.5));
        rect_7->set_material(&mat7);
        rect_7->set_emissive_props(Vec3(1, 1, 1));

        auto sp_md = std::make_unique<Sphere>(0.5, Vec3(0.5, -0.5, -1.5));
        sp_md->set_material(&mat8);
        sp_md->set_emissive_props(Vec3(1, 1, 1));

        auto cuboid = std::make_unique<Cuboid>(Vec3(-0.75, -1, -2.75), 1.0, 1.0, 1.0);
        cuboid->rot_y(5.0);
        cuboid->set_material(&mat_cuboid);
        cuboid->set_emissive_props(Vec3(1, 1, 1));

        world.add(std::move(rect_1));
        world.add(std::move(rect_2));
        world.add(std::move(rect_3));
        world.add(std::move(rect_4));
        world.add(std::move(rect_5));
        // world.add(std::move(rect_6));
        world.add(std::move(rect_7));
        world.add(std::move(sp_md));
        world.add(std::move(cuboid));

    cam_main.draw(world);

    return 0;
}
