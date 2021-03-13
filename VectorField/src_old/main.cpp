#include <iostream>
#include <vector>
#include <stdexcept>
#include <GLFW/glfw3.h>

#include "vertex.h"

int main(void)
{
    //To change dimensions constraints from 3d to 2d change grid_z to 0.0, 0.0
    const float grid_x[2] = { -5.0f, 5.0f };
    const float grid_y[2] = { -5.0f, 5.0f };
    const float grid_z[2] = { -5.0f, 5.0f };
    const float density = 1.0;
    int dimensions = (((int)grid_z[0] == 0 && (int)grid_z[1] == 0)) ? 2 : 3;

    //Error Checking for variables
    if (VectorField::mmEval(grid_x, 1) == -1) return -1;
    if (VectorField::mmEval(grid_y, 2) == -1) return -1;
    if (VectorField::mmEval(grid_z, 3) == -1) return -1;
    if (density <= 0.0) {
        std::cerr << "Density must be greater than 0";
        return -1;
    }
    if (VectorField::overflowCheck(dimensions, density, grid_x, grid_y, grid_z) == -1) return -1;

    std::vector<VectorField::vertex*> v;

    VectorField::vfGenerateMeshgrid(dimensions, density, grid_x, grid_y, grid_z);

    v.clear();


    ////       v.push_back(vf_ver::pos(1.0, -1.0));


        //GLFWwindow* window;

        ///* Initialize the library */
        //if (!glfwInit())
        //    return -1;

        ///* Create a windowed mode window and its OpenGL context */
        //window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        //if (!window)
        //{
        //    glfwTerminate();
        //    return -1;
        //}

        ///* Make the window's context current */
        //glfwMakeContextCurrent(window);

        ///* Loop until the user closes the window */
        //while (!glfwWindowShouldClose(window))
        //{
        //    /* Render here */
        //    glClear(GL_COLOR_BUFFER_BIT);

        //    /* Swap front and back buffers */
        //    glfwSwapBuffers(window);

        //    /* Poll for and process events */
        //    glfwPollEvents();
        //}

        //glfwTerminate();
        //return 0;
    return 0;
}