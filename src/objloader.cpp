#define TINYOBJLOADER_IMPLEMENTATION
#include "./tiny_obj_loader.h"
#include "objloader.h"
#include <iostream>

std::vector<Triangle> load_obj() {
    std::vector<Triangle> tri_vec;
    std::string inputfile = "./obj/suzanne.obj";
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err,
                                inputfile.c_str(), "./obj/", true);

    if (!err.empty()) {
    std::cerr << err << std::endl;
    }

    for (size_t s = 0; s < shapes.size(); s++) {
        for (size_t i = 0; i < shapes[s].mesh.indices.size(); i += 3) {
            tinyobj::index_t idx_1 = shapes[s].mesh.indices[i + 0];
            tinyobj::index_t idx_2 = shapes[s].mesh.indices[i + 1];
            tinyobj::index_t idx_3 = shapes[s].mesh.indices[i + 2];

            int i1 = idx_1.vertex_index;
            int i2 = idx_2.vertex_index;
            int i3 = idx_3.vertex_index;

            Vec3 v1(attrib.vertices[3 * i1 + 0], attrib.vertices[3 * i1 + 1], attrib.vertices[3 * i1 + 2]);
            Vec3 v2(attrib.vertices[3 * i2 + 0], attrib.vertices[3 * i2 + 1], attrib.vertices[3 * i2 + 2]);
            Vec3 v3(attrib.vertices[3 * i3 + 0], attrib.vertices[3 * i3 + 1], attrib.vertices[3 * i3 + 2]);

            Triangle tri(v1, v2, v3);

            tri_vec.push_back(tri);
        }
    }

    return tri_vec;
}
