#include "raylib.h"
#include "ray.h"
#include "vec3.h"
#include "cam.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Triangle.h"
#include "objloader.h"
#include "materials.h"
#include "model.h"
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main() {
    double ar = 16.0 / 9.0;
    cam cam_main(ar, 2.0, 1);

    cam_main.init(WINDOW_HEIGHT, WINDOW_WIDTH);

    World world;

    std::vector<Triangle> tri_vec = load_obj();

    for (Triangle& tri: tri_vec) {
        std::cout << tri.A << " " << tri.B << " " << tri.C << "\n";
    }

    Diffused mat_1;

    auto mod = std::make_unique<model>(tri_vec);
    mod->set_material(&mat_1);
    mod->set_emissive_props(Vec3(1, 0, 0));

    world.add(std::move(mod));
    // cam_main.draw(world);

    return 0;
}
