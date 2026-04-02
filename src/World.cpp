#include "World.h"

World::World() {}

World::World(std::unique_ptr<Hittable> obj) {
    add(std::move(obj));
}

void World::add(std::unique_ptr<Hittable> obj) {
    world_objs.push_back(std::move(obj));
}

bool World::hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi) {
    hit_info temp;
    bool has_hit = false;
    double closest = ray_tmax;

    for (auto& obj: world_objs) {
        if (obj->hit(ray, ray_tmin, closest, temp)) {
            has_hit = true;
            closest = temp.raycol.distance;
            hi = temp;
        }
    }

    return has_hit;
}
