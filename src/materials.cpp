#include "materials.h"
#include <cmath>

Vec3 Diffused::scatter(LRay& lr, hit_info& hi) {
    return get_random_uv_hemisphere(hi.normal);
}

Vec3 Diffused::get_incoming_light(Vec3& incoming_light, Vec3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vec3 Diffused::get_ray_color(Vec3& ray_color) {
    return (ray_color * color);
}

Vec3 Diffused_Light::scatter(LRay& lr, hit_info& hi) {
    return lr.getDir();
}

Vec3 Diffused_Light::get_incoming_light(Vec3& incoming_light, Vec3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vec3 Diffused_Light::get_ray_color(Vec3& ray_color) {
    return (ray_color * color);
}

Vec3 Diffused_Light::emit() {
    return color;
}

Vec3 Lambertian::scatter(LRay& lr, hit_info& hi) {
    return get_random_uv_hemisphere(hi.normal + get_random_vec());
}

Vec3 Lambertian::get_incoming_light(Vec3& incoming_light, Vec3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vec3 Lambertian::get_ray_color(Vec3& ray_color) {
    return (ray_color * color);
}

Vec3 Metal::scatter(LRay& lr, hit_info& hi) {
    Vec3 dir = lr.getDir();
    return (dir - 2 * dot(dir, hi.normal) * hi.normal);
}

Vec3 Metal::get_incoming_light(Vec3& incoming_light, Vec3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vec3 Metal::get_ray_color(Vec3& ray_color) {
    return ray_color * color;
}

Vec3 Glass::scatter(LRay& lr, hit_info& hi) {
    double ri = hi.front_face ? (refr_index) : 1.0 / refr_index;

    double ran = get_random_double(0, 1);

    Vec3 dir = lr.getDir();
    Vec3 udir = unit_vec(dir);
    Vec3 normal = hi.normal;

    double cos_theta = dot(-1 * udir, normal);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    double r0 = (1 - refr_index) / (1 + refr_index);
    r0 = r0*r0;
    r0 = r0 + (1-r0)*pow((1 - cos_theta),5);

    if (ri * sin_theta > 1.0) {
        return (udir - 2 * dot(udir, hi.normal) * hi.normal);
    } else {
        if (r0 > ran) {
            return (udir - 2 * dot(udir, hi.normal) * hi.normal);
        }

        Vec3 r_out_perp =  ri * (udir + dot(-1 * udir, normal) * normal);
        Vec3 r_out_parallel = -sqrt((1.0 - r_out_perp.length_sq())) * normal;
        return r_out_perp + r_out_parallel;
    }
}

Vec3 Glass::get_incoming_light(Vec3& incoming_light, Vec3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vec3 Glass::get_ray_color(Vec3& ray_color) {
    return ray_color * color;
}
