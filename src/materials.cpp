#include "materials.h"
#include "raylib.h"
#include "Rand.h"
#include <raymath.h>

Vector3 Diffused::scatter(Ray& ray, hit_info& hi) {
    return get_random_uv_hemisphere(hi.raycol.normal);
}

Vector3 Diffused::get_incoming_light(Vector3& incoming_light, Vector3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vector3 Diffused::get_ray_color(Vector3& ray_color) {
    return (ray_color * color);
}

Vector3 Diffused_Light::emit() {
    return color;
}

Vector3 Diffused_Light::scatter(Ray& ray, hit_info& hi) {
    return get_random_uv_hemisphere(hi.raycol.normal);
}

Vector3 Diffused_Light::get_incoming_light(Vector3& incoming_light, Vector3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vector3 Diffused_Light::get_ray_color(Vector3& ray_color) {
    return (ray_color * color);
}

Vector3 Lambertian::scatter(Ray& ray, hit_info& hi) {
    return get_random_uv_hemisphere(hi.raycol.normal + get_random_vec());
}

Vector3 Lambertian::get_incoming_light(Vector3& incoming_light, Vector3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vector3 Lambertian::get_ray_color(Vector3& ray_color) {
    return (ray_color * color);
}

Vector3 Metal::scatter(Ray& ray, hit_info& hi) {
    return Vector3Reflect(ray.direction, hi.raycol.normal);
}

Vector3 Metal::get_incoming_light(Vector3& incoming_light, Vector3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vector3 Metal::get_ray_color(Vector3& ray_color) {
    return (ray_color);
}

Vector3 Glass::scatter(Ray& ray, hit_info& hi) {
    double ri = hi.front_face ? (refr_index) : 1.0 / refr_index;

    double ran = get_random_double(0, 1);

    Vector3 dir = ray.direction;
    Vector3 udir = Vector3Normalize(dir);
    Vector3 normal = hi.raycol.normal;

    double cos_theta = Vector3DotProduct(-1 * udir, normal);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    double r0 = (1 - refr_index) / (1 + refr_index);
    r0 = r0*r0;
    r0 = r0 + (1-r0)*pow((1 - cos_theta),5);

    if (ri * sin_theta > 1.0) {
        return Vector3Reflect(udir, hi.raycol.normal);
    } else {
        if (r0 > ran) {
            return Vector3Reflect(udir, hi.raycol.normal);
        }

        return Vector3Refract(udir, normal, refr_index);
    }
}

Vector3 Glass::get_incoming_light(Vector3& incoming_light, Vector3& ray_color) {
    return incoming_light + emit() * ray_color;
}

Vector3 Glass::get_ray_color(Vector3& ray_color) {
    return (ray_color * color);
}
