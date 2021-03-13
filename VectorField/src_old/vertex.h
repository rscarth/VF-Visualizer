//All Vertex and associated error checking classes and functions

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

namespace VectorField {
    class vertex {
    private:
        float _pos[3] = {0.0f, 0.0f, 0.0f};
        float _pos_trans[3] = {0.0f, 0.0f, 0.0f};

    public:
        void pos(const float& x, const float& y, const float& z = 0.0) {
            _pos[0] = x; _pos[1] = y; _pos[2] = z;
        }

        float* getPos() {
            return &_pos[2];
        }

        float* getTransform() {
            return &_pos_trans[2];
        }

        void transform();
    };

    void vfGenerateMeshgrid(const int& dimensions, const float& density, const float* grid_x, const float* grid_y, const float* grid_z);
    
    int mmEval(const float* grid_vset, const int dim);
    int overflowCheck(const int& dimensions, const float& density, const float* grid_x, const float* grid_y, const float* grid_z);
}