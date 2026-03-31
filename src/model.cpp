#include "model.h"

model::model(std::vector<Triangle> triv) {
    tri_vec = triv;
}

bool model::hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) {
    for (auto& tri: tri_vec) {
        tri.set_material(mat);
        tri.set_emissive_props(mat->color);
    }

    hit_info temp;
    bool has_hit = false;
    double closest = ray_tmax;

    for (auto& tri: tri_vec) {
        if (tri.hit(lr, ray_tmin, closest, temp)) {
            has_hit = true;
            closest = temp.t;
            hi = temp;
        }
    }

    return has_hit;
}

void model::set_emissive_props(Vec3 ecol) {
    mat->color = ecol;
}

void model::set_material(material* matr) {
    mat = matr;
}
