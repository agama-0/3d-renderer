#ifndef VertexArray_HPP
#define VertexArray_HPP
#include <glad/glad.h>
#include <vector>
namespace Agama {

struct Vertex {
    float position[3];
    float color[3];
};
class VertexArray {
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

} // namespace Agama
#endif // VertexArray_HPP
