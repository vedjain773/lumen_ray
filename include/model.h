#ifndef MODEL_H
#define MODEL_H

#include "hittable.h"
#include "Triangle.h"

class model: public Hittable {
    public:
    std::vector<Triangle> tri_vec;

    model(std::vector<Triangle> triv);
    bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vec3 ecol);
    void set_material(material* matr);
};

#endif
