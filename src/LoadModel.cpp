#include "LoadModel.h"
#include "raylib.h"
#include "Triangle.h"
#include <iostream>

std::vector<Triangle> get_triangles_from_model(const char *filename) {
    std::vector<Triangle> result;
    Model model = LoadModel(filename);

    int mesh_count = model.meshCount;
    Mesh* mesh = model.meshes;

    for (int i = 0; i < mesh_count; i++) {
        int tri_count = mesh->triangleCount;

        int vertex_count = mesh->vertexCount;
        float* vertices = mesh->vertices;

        if (mesh->indices != nullptr) {
            unsigned short* indices = mesh->indices;

            for (int j = 0; j < tri_count; j += 1) {
                short index = *indices;

                double x_1 = *(vertices + 3 * index);
                double y_1 = *(vertices + 3 * index + 1);
                double z_1 = *(vertices + 3 * index + 2);

                indices++;
                index = *indices;

                double x_2 = *(vertices + 3 * index);
                double y_2 = *(vertices + 3 * index + 1);
                double z_2 = *(vertices + 3 * index + 2);

                indices++;
                index = *indices;

                double x_3 = *(vertices + 3 * index);
                double y_3 = *(vertices + 3 * index + 1);
                double z_3 = *(vertices + 3 * index + 2);

                indices++;

                Triangle tri(
                    new_vec(x_1, y_1, z_1),
                    new_vec(x_2, y_2, z_2),
                    new_vec(x_3, y_3, z_3)
                );

                result.push_back(tri);
            }
        } else {
            for (int j = 0; j < vertex_count * 3; j += 9) {
                double x_1 = *(vertices + j);
                double y_1 = *(vertices + j + 1);
                double z_1 = *(vertices + j + 2);

                double x_2 = *(vertices + j + 3);
                double y_2 = *(vertices + j + 4);
                double z_2 = *(vertices + j + 5);

                double x_3 = *(vertices + j + 6);
                double y_3 = *(vertices + j + 7);
                double z_3 = *(vertices + j + 8);

                Triangle tri(
                    new_vec(x_1, y_1, z_1),
                    new_vec(x_2, y_2, z_2),
                    new_vec(x_3, y_3, z_3)
                );

                result.push_back(tri);
            }
        }

        mesh++;
    }

    return result;
}
