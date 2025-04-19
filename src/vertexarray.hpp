#ifndef VertexArray_HPP
#define VertexArray_HPP
#include <glad/glad.h>
#include <vector>
#include "alm.hpp"
namespace agama {
struct Vertex {
    alm::vec3 position;
    alm::vec3 color;
    alm::vec2 uv;
};
class VertexArray
{
    private:
        std::vector<Vertex> data;
        GLuint vao,vbo;
    public:
    VertexArray();
    ~VertexArray();
    void bind();
    void unbind();
    void addVertex(Vertex vert);
    void setData();
    unsigned int count();
};

} // namespace agama
#endif // VertexArray_HPP
