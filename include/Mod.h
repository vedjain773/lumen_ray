#ifndef MOD_H
#define MOD_H

#include "Hittable.h"
#include "Triangle.h"
#include <vector>

class Mod: public Hittable {
    public:
    std::vector<Triangle> tri_vec;

    Mod(std::vector<Triangle> triv);

    bool hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_material(material* mat);
    void set_emissive_props(Vector3 color);
};

#endif
