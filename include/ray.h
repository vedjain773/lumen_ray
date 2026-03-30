#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class World;

class LRay {
    public:
    Vec3 src;
    Vec3 dir;

    LRay(Vec3 source, Vec3 direction);

    Vec3 getSrc() const;
    Vec3 getDir() const;

    Vec3 at(double t);
};

Vec3 trace(LRay& lr, World& world);

#endif
