#include "CamUtils.h"
#include "VecUtils.h"
#include "raylib.h"
#include "materials.h"
#include "Sphere.h"
#include "Triangle.h"
#include "LoadModel.h"
#include "Mod.h"
#include "World.h"
#include <iostream>

int main() {
    CamParams cp;
    Camera3D cam;

    cam.position = new_vec(-3.0, 1.0, 7.0);
    cam.target = new_vec(0.0, 0.0, -1.0);
    cam.up = new_vec(0.0, 1.0, 0.0);
    cam.fovy = 90.0;
    cam.projection = CAMERA_PERSPECTIVE;

    cp.screen_width = 800;
    cp.screen_height = 450;
    cp.rays_per_pixel = 2;
    cp.cam3d = cam;

    std::vector<Triangle> tri_vec = get_triangles_from_model("obj/suzanne.obj");

    for (auto& tri: tri_vec) {
        std::cout << tri.A << "\n" << tri.B << "\n" << tri.C << "\n\n";
    }

    std::cout << tri_vec.size() << "\n";

    Diffused dif;
    auto model = std::make_unique<Mod>(tri_vec);
    model->set_material(&dif);
    model->set_emissive_props(new_vec(1, 0, 0));

    World world;

    // Lambertian mat_sm;
    // Lambertian mat_sm_2;
    // Diffused mat_gr;

    // auto tri = std::make_unique<Triangle>(new_vec(-1, -0.5, -1), new_vec(-1, 1, -1), new_vec(1, -0.5, -1));
    // tri->set_material(&mat_sm);
    // tri->set_emissive_props(new_vec(1.0, 0.0, 0.0));

    // auto sp_gr = std::make_unique<Sphere>(100, new_vec(0, -100.5, -1));
    // sp_gr->set_material(&mat_gr);
    // sp_gr->set_emissive_props(new_vec(0.0, 1.0, 0.0));

    // world.add(std::move(tri));
    // world.add(std::move(sp_sm_2));
    // world.add(std::move(sp_gr));

    world.add(std::move(model));
    draw(cp, world);
    return 0;
}
