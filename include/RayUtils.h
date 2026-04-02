#ifndef RAYUTILS_H
#define RAYUTILS_H

#include "raylib.h"
#include "Hittable.h"
#include "World.h"

Vector3 trace(Ray& ray, World& world);

#endif
