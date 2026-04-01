#ifndef COLUTILS_H
#define COLUTILS_H

#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <cstdint>

Color create_color(Vector3& vec);

inline double gamma(double lin) {
    if (lin > 0.0)
        return sqrt(lin);

    return 0.0;
}

inline void get_rgb(Vector3& vec) {
    vec.x = 255.0 * Clamp(vec.x, 0.0, 0.999);
    vec.y = 255.0 * Clamp(vec.y, 0.0, 0.999);
    vec.z = 255.0 * Clamp(vec.z, 0.0, 0.999);
}

#endif
