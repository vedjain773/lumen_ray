#include "color.h"
#include "raylib.h"
#include <cstdint>

Color createColor(int r, int g, int b, int op) {
    Color col{(uint8_t)r, (uint8_t)g, (uint8_t)b, (uint8_t)op};
    return col;
}

Color createColor(Vec3 vec) {
    vec.comps[0] = gamma(std::clamp(vec.comps[0], 0.0, 0.999));
    vec.comps[1] = gamma(std::clamp(vec.comps[1], 0.0, 0.999));
    vec.comps[2] = gamma(std::clamp(vec.comps[2], 0.0, 0.999));

    Vec3 color_vec = getRGB(vec);

    Color col {
        (uint8_t) color_vec.x(),
        (uint8_t) color_vec.y(),
        (uint8_t) color_vec.z(),
        255
    };
    return col;
}
