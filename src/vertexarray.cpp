#include "vertexarray.hpp"
#include <iostream>
using namespace agama;
VertexArray::VertexArray() : data()
{
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
}

VertexArray::~VertexArray()
{
    data.clear();
}

void
VertexArray::addVertex(Vertex vert){
    data.push_back(vert);
}

void
VertexArray::setData()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
}

void
VertexArray::bind()
{
   glBindVertexArray(vao);
}

void
VertexArray::unbind()
{
   glBindVertexArray(0);
}

unsigned int
VertexArray::count()
{
    return data.size();
}
