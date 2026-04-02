#ifndef WORLD_H
#define WORLD_H

#include "Hittable.h"
#include <vector>
#include <memory>

class World {
    public:
    std::vector<std::unique_ptr<Hittable>> world_objs;

    World();
    World(std::unique_ptr<Hittable> obj);

    void add(std::unique_ptr<Hittable> obj);
    bool hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi);
};

#endif
