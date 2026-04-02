#include "ColUtils.h"

Color create_color(Vector3 vec) {
    vec.x = gamma(Clamp(vec.x, 0.0, 0.999));
    vec.y = gamma(Clamp(vec.y, 0.0, 0.999));
    vec.z = gamma(Clamp(vec.z, 0.0, 0.999));

    get_rgb(vec);

    Color color;
    color.r = (uint8_t) vec.x;
    color.g = (uint8_t) vec.y;
    color.b = (uint8_t) vec.z;
    color.a = 255;

    return color;
}
