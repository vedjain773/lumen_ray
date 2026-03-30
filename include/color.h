#ifndef COLOR_H
#define COLOR_H

#include "color.h"
#include "raylib.h"
#include "vec3.h"
#include <cmath>

Color createColor(int r, int g, int b, int op);
Color createColor(Vec3 vec);

inline double gamma(double lin) {
    if (lin > 0)
        return sqrt(lin);

    return 0;
}

#endif
