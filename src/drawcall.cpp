#include "drawcall.hpp"
using namespace agama;

void
agama::draw(struct DrawCall drawcall)
{
    if (drawcall.variant == DRAW_ARRAYS_TRIANGLE)
    {
        drawcall.va->bind();
        drawcall.program->bind();
        glDrawArrays(GL_TRIANGLES, 0, drawcall.va->count());
        drawcall.va->unbind();
        drawcall.program->unbind();
    }
}
