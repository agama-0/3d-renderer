#ifndef DrawCall_HPP
#define DrawCall_HPP
#include <glad/glad.h>
#include <vector>
#include "shader.hpp"
#include "vertexarray.hpp"
namespace Agama {

enum DrawCallVariant {
    DRAW_ARRAYS_TRIANGLE
};

struct DrawCall {
  enum DrawCallVariant variant;
  VertexArray* va;
  ShaderProgram* program;
};

void draw(struct DrawCall drawcall);

} // namespace Agama
#endif // DrawCall_HPP
