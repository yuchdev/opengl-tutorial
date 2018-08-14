#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window = nullptr;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

// Include AntTweakBar
#include <AntTweakBar.h>

#include <iostream>


/*
            GLv1 = ["VERSION"
                , "SHADING_LANGUAGE_VERSION"
                , "VENDOR", "RENDERER"
                , "MAX_VERTEX_ATTRIBS"
                , "MAX_VERTEX_UNIFORM_VECTORS"
                , "MAX_VERTEX_TEXTURE_IMAGE_UNITS"
                , "MAX_VARYING_VECTORS"
                , "ALIASED_LINE_WIDTH_RANGE"
                , "ALIASED_POINT_SIZE_RANGE"
                , "MAX_FRAGMENT_UNIFORM_VECTORS"
                , "MAX_TEXTURE_IMAGE_UNITS"
                , ["RED_BITS", "GREEN_BITS", "BLUE_BITS", "ALPHA_BITS"]
                , ["DEPTH_BITS", "STENCIL_BITS"]
                , "MAX_RENDERBUFFER_SIZE"
                , "MAX_VIEWPORT_DIMS"
                , "MAX_TEXTURE_SIZE"
                , "MAX_CUBE_MAP_TEXTURE_SIZE"
                , "MAX_COMBINED_TEXTURE_IMAGE_UNITS"];

                GLv2 =  ["MAX_VERTEX_UNIFORM_COMPONENTS"
                    , "MAX_VERTEX_UNIFORM_BLOCKS"
                    , "MAX_VERTEX_OUTPUT_COMPONENTS"
                    , "MAX_VARYING_COMPONENTS"
                    , "MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS"
                    , "MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS"
                    , "MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS"
                    , "MAX_FRAGMENT_UNIFORM_COMPONENTS"
                    , "MAX_FRAGMENT_UNIFORM_BLOCKS"
                    , "MAX_FRAGMENT_INPUT_COMPONENTS"
                    , "MIN_PROGRAM_TEXEL_OFFSET"
                    , "MAX_PROGRAM_TEXEL_OFFSET"
                    , "MAX_DRAW_BUFFERS"
                    , "MAX_COLOR_ATTACHMENTS"
                    , "MAX_SAMPLES"
                    , "MAX_3D_TEXTURE_SIZE"
                    , "MAX_ARRAY_TEXTURE_LAYERS"
                    , "MAX_TEXTURE_LOD_BIAS"
                    , "MAX_UNIFORM_BUFFER_BINDINGS"
                    , "MAX_UNIFORM_BLOCK_SIZE"
                    , "UNIFORM_BUFFER_OFFSET_ALIGNMENT"
                    , "MAX_COMBINED_UNIFORM_BLOCKS"
                    , "MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS"
                    , "MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS"];
*/

template <typename T>
void print_param(const char* param_name, T val)
{
    std::cout << param_name << " = " << val << '\n';
}

int main()
{
    // Initialize GLFW
    if( !glfwInit() )
    {
        std::cerr << "Failed to initialize GLFW\n";
        return 0;
    }

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1024, 768, "GL Window", NULL, NULL);
    if( window == NULL )
    {
        std::cerr << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);

    std::cout << "GL_VENDOR = " << glGetString(GL_VENDOR) << '\n';
    std::cout << "GL_RENDERER = " << glGetString(GL_RENDERER) << '\n';
    std::cout << "GL_SHADING_LANGUAGE_VERSION = " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';

    // GL 1 Example
    GLint maxVertexAttribs = -1;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
    print_param("GL_MAX_VERTEX_ATTRIBS", maxVertexAttribs);

    // GL 2 Example
    GLint maxVertexUniformComponents = -1;
    glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &maxVertexUniformComponents);
    print_param("GL_MAX_VERTEX_UNIFORM_COMPONENTS", maxVertexUniformComponents);

    return 0;
}