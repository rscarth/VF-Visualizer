//All Vertex and associated error checking classes and functions

#include "vertex.h"
#include "equations.h"

namespace VectorField {
    //Declare equation to display from equations
    void vertex::transform() {
        int dimensions = 3;
        float* pos_trans = VectorField::Equations::ThreeD::rotationalVectorField(getPos());

        if (dimensions == 3) {
            _pos_trans[0] = pos_trans[0];
            _pos_trans[1] = pos_trans[1];
            _pos_trans[2] = pos_trans[2];
        }
        else if (dimensions == 2) {
            _pos_trans[0] = pos_trans[0];
            _pos_trans[1] = pos_trans[1];
        }
    }

    //std::vector<vf_ver*>
    void vfGenerateMeshgrid(const int& dimensions, const float& density, const float* grid_x, const float* grid_y, const float* grid_z) {
        std::vector<vertex*> meshgrid = {};
        //4,294,967,295 positions possible
        unsigned long int count = 0;

        if (dimensions == 3) {
            for (float z = grid_z[0]; z <= grid_z[1]; z += density) {
                for (float y = grid_y[0]; y <= grid_y[1]; y += density) {
                    for (float x = grid_x[0]; x <= grid_x[1]; x += density) {
                        meshgrid.push_back(new vertex());
                        meshgrid[count]->pos(x, y, z);
                        meshgrid[count]->transform();

                        float *temppos = meshgrid[count]->getPos();
                        float *temptrans = meshgrid[count]->getTransform();

                        std::cout << count << " | " << temppos[0] << ", " << temppos[1] << ", " << temppos[2] <<
                            " -> " << temptrans[0] << ", " << temptrans[1] << ", " << temptrans[2] << std::endl;

                        count += 1;
                    }
                }
            }
        }
        else if (dimensions == 2) {
            for (float y = grid_y[0]; y <= grid_y[1]; y += density) {
                for (float x = grid_x[0]; x <= grid_x[1]; x += density) {
                    meshgrid.push_back(new vertex());
                    meshgrid[count]->pos(x, y);
                    count += 1;
                }
            }
        }

    }

    //Evaluate sets of min/max vertecies
    //Dimension 3 with Vertex min 0.0 and Vertex max 0.0 equivilates to two dimensions
    //Dimension 1 or Dimension 2 and Vertex min is equal to Vertex max then throw error of equality
    //Dimension 1 or Dimension 2 and Vertex min and Vertex max are equal to zero then throw error of invalid size
    //Vertex min is greater than Vertex max then throw error of invalid dimension size
    //Dimension 3 with Vertex min and Vertex max not equal to 0.0 and Vertex min larger than Vertex max then throw error of invalid dimension size
    int mmEval(const float* grid_vset, const int dim) {
        switch (dim) {
        case 1:
            std::cout << "Dimensions X[0], X[1] || " << grid_vset[0] << ", " << grid_vset[1] << " : ";
            break;
        case 2:
            std::cout << "Dimensions Y[0], Y[1] || " << grid_vset[0] << ", " << grid_vset[1] << " : ";
            break;
        case 3:
            std::cout << "Dimensions Z[0], Z[1] || " << grid_vset[0] << ", " << grid_vset[1] << " : ";
            break;
        }

        try {
            if (dim == 1 || dim == 2) {
                grid_vset[0] == grid_vset[1] ? throw std::invalid_argument("Vertex Min = Vertex Max") : NULL;
                grid_vset[0] == 0.0 && grid_vset[1] == 0.0 ? throw std::invalid_argument("Vertex Min or/and Vertex Max must have a value") : NULL;
            }

            grid_vset[0] > grid_vset[1] ? throw std::invalid_argument("Vertex Min > Vertex Max") : NULL;
            dim == 3 && grid_vset[0] != 0.0 && grid_vset[1] != 0.0 && grid_vset[0] > grid_vset[1] ? throw std::invalid_argument("Vertex Min > Vertex Max") : NULL;
        }
        catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return -1;
        }

        std::cout << "Valid set" << std::endl;
        return 0;
    }

    //Check overflow error
    //Get range of each set of min/max and divide by density to determine points on axis
    //Multiply all points to determine if under max long int size (4294967295) otherwise throw excess range error
    int overflowCheck(const int& dimensions, const float& density, const float* grid_x, const float* grid_y, const float* grid_z) {
        unsigned int grid_x_size = (int)((grid_x[0] * -1) + grid_x[1]) / density;
        unsigned int grid_y_size = (int)((grid_y[0] * -1) + grid_y[1]) / density;
        unsigned int grid_z_size = (int)((grid_z[0] * -1) + grid_z[1]) / density;

        try {
            (grid_x_size * grid_y_size * grid_z_size) > 4294967295 ? throw std::invalid_argument("Given ranges and density are too large causing overflow error (Vertex Count >4294967295)\n"
                "Try reducing ranges or increasing density size") : NULL;
        }
        catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return -1;
        }

        return 0;
    }
}