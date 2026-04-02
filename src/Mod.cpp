#include "Mod.h"

Mod::Mod(std::vector<Triangle> triv) {
    tri_vec = triv;
}

bool Mod::hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi) {
    for (Triangle& tri: tri_vec) {
        tri.set_material(mat);
        tri.set_emissive_props(mat->color);
    }

    hit_info temp;
    bool has_hit = false;
    double closest = ray_tmax;

    for (auto& tri: tri_vec) {
        if (tri.hit(ray, ray_tmin, closest, temp)) {
            has_hit = true;
            closest = temp.raycol.distance;
            hi = temp;
        }
    }

    return has_hit;
}

void Mod::set_emissive_props(Vector3 ecol) {
    mat->color = ecol;
}

 void Mod::set_material(material* matr) {
     mat = matr;
 }
