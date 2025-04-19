#ifndef ALM_HPP
#define ALM_HPP

#include <math.h>
#include <cstdio>
namespace alm
{
#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#define sq(v) ((v) * (v))
#define deg2rad(deg) ((deg)*(PI/180.0f))
#define rad2deg(rad) ((rad)*(180.0f/PI))

typedef struct {
    float x,y;
} vec2;

typedef struct {
    float x,y,z;
} vec3;

typedef struct {
    float x,y,z,w;
} vec4;

typedef struct {
    float
    a11, a12, a13, a14,
    a21, a22, a23, a24,
    a31, a32, a33, a34,
    a41, a42, a43, a44;
} mat4;

inline bool is_equal(float* a, float* b, float l, float k = 0)
{
    for(int i = 0; i < l; i++)
    {
        float diff = a[i] - b[i];
        if (diff < 0) diff *= -1;
        if (diff > k) return false;
    }
    return true;
}

//-----------------------------------------------------------------------//
//------------------------------ vec2 -----------------------------------//
inline void print(const char* label, vec2 v)
{printf("%s -> <%.2f,\t%.2f>\n", label, v.x, v.y);}

inline vec2 operator+(vec2 const& a, vec2 const& b)
{return {a.x + b.x, a.y + b.y};}

inline vec2 operator-(vec2 const& a, vec2 const& b)
{return {a.x - b.x, a.y - b.y};}

inline vec2 operator+(vec2 const& a, float const& b)
{return {a.x + b, a.y + b};}

inline vec2 operator-(vec2 const& a, float const& b)
{return {a.x - b, a.y - b};}

inline vec2 operator*(vec2 const& a, float const& b)
{return {a.x * b, a.y * b};}

inline vec2 operator/(vec2 const& a, float const& b)
{return {a.x / b, a.y / b};}

inline float len(vec2 v)
{return sqrtf(sq(v.x) + sq(v.y));}

inline vec2 norm(vec2 v)
{
    float l = len(v);
    if (l == 0) l = 1;
    return v / l;
}

inline float dot(vec2 a, vec2 b)
{return a.x * b.x + a.y * b.y;}

inline float dist(vec2 a, vec2 b)
{return sqrtf(sq(a.x - b.x) + sq(a.y - b.y));}

//-----------------------------------------------------------------------//
//------------------------------ vec3 -----------------------------------//
inline void print(const char* label, vec3 v)
{printf("%s -> <%.2f,\t%.2f,\t%.2f>\n", label, v.x, v.y, v.z);}

inline vec3 operator+(vec3 const& a, vec3 const& b)
{return {a.x + b.x, a.y + b.y, a.z + b.z};}

inline vec3 operator-(vec3 const& a, vec3 const& b)
{return {a.x - b.x, a.y - b.y, a.z - b.z};}

inline vec3 operator+(vec3 const& a, float const& b)
{return {a.x + b, a.y + b, a.z + b};}

inline vec3 operator-(vec3 const& a, float const& b)
{return {a.x - b, a.y - b, a.z - b};}

inline vec3 operator*(vec3 const& a, float const& b)
{return {a.x * b, a.y * b, a.z * b};}

inline vec3 operator/(vec3 const& a, float const& b)
{return {a.x / b, a.y / b, a.z / b};}

inline float len(vec3 v)
{return sqrtf(sq(v.x) + sq(v.y) + sq(v.z));}

inline vec3 norm(vec3 v)
{
    float l = len(v);
    if (l != 0) return v / l;
    return v;
}

inline vec3 cross(vec3 a, vec3 b)
{
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x,
    };
}

inline float dot(vec3 a, vec3 b)
{return a.x * b.x + a.y * b.y + a.z * b.z;}

//-----------------------------------------------------------------------//
//------------------------------ vec4 -----------------------------------//
inline void print(const char* label, vec4 v)
{printf("%s -> <%.2f,\t%.2f,\t%.2f,\t%.2f>\n", label, v.x, v.y, v.z, v.w);}

inline vec4 operator+(vec4 const& a, vec4 const& b)
{return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};}

inline vec4 operator-(vec4 const& a, vec4 const& b)
{return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};}

inline vec4 operator+(vec4 const& a, float const& b)
{return {a.x + b, a.y + b, a.z + b, a.w + b};}

inline vec4 operator-(vec4 const& a, float const& b)
{return {a.x - b, a.y - b, a.z - b, a.w - b};}

inline vec4 operator*(vec4 const& a, float const& b)
{return {a.x * b, a.y * b, a.z * b, a.w * b};}

inline vec4 operator/(vec4 const& a, float const& b)
{return {a.x / b, a.y / b, a.z / b, a.w / b};}

inline float len(vec4 v)
{return sqrtf(sq(v.x) + sq(v.y) + sq(v.z) + sq(v.w));}

inline vec4 norm(vec4 v)
{
    float l = len(v);
    if (l == 0) l = 1;
    return v / l;
}

inline float dot(vec4 a, vec4 b)
{return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;}

inline float dist(vec4 a, vec4 b)
{return sqrtf(sq(a.x - b.x) + sq(a.y - b.y)+ sq(a.z - b.z)+ sq(a.w - b.w));}

//-----------------------------------------------------------------------//
//------------------------------ mat4 -----------------------------------//
inline void print(const char* label, mat4 m)
{
    float* p = &m.a11;
    printf("%s ->\n\t", label);
    for(int i = 0; i < 16; i++)
    {
        printf("%.2f,\t", p[i]);
        if ((i + 1) % 4 == 0)
        {printf("\n\t");}
    }
    printf("\n");
}

inline mat4 operator*(mat4 const& m1, mat4 const& m2)
{
    return {
        m1.a11 * m2.a11 + m1.a12 * m2.a21 + m1.a13 * m2.a31 + m1.a14 * m2.a41,
        m1.a11 * m2.a12 + m1.a12 * m2.a22 + m1.a13 * m2.a32 + m1.a14 * m2.a42,
        m1.a11 * m2.a13 + m1.a12 * m2.a23 + m1.a13 * m2.a33 + m1.a14 * m2.a43,
        m1.a11 * m2.a14 + m1.a12 * m2.a24 + m1.a13 * m2.a34 + m1.a14 * m2.a44,

        m1.a21 * m2.a11 + m1.a22 * m2.a21 + m1.a23 * m2.a31 + m1.a24 * m2.a41,
        m1.a21 * m2.a12 + m1.a22 * m2.a22 + m1.a23 * m2.a32 + m1.a24 * m2.a42,
        m1.a21 * m2.a13 + m1.a22 * m2.a23 + m1.a23 * m2.a33 + m1.a24 * m2.a43,
        m1.a21 * m2.a14 + m1.a22 * m2.a24 + m1.a23 * m2.a34 + m1.a24 * m2.a44,

        m1.a31 * m2.a11 + m1.a32 * m2.a21 + m1.a33 * m2.a31 + m1.a34 * m2.a41,
        m1.a31 * m2.a12 + m1.a32 * m2.a22 + m1.a33 * m2.a32 + m1.a34 * m2.a42,
        m1.a31 * m2.a13 + m1.a32 * m2.a23 + m1.a33 * m2.a33 + m1.a34 * m2.a43,
        m1.a31 * m2.a14 + m1.a32 * m2.a24 + m1.a33 * m2.a34 + m1.a34 * m2.a44,

        m1.a41 * m2.a11 + m1.a42 * m2.a21 + m1.a43 * m2.a31 + m1.a44 * m2.a41,
        m1.a41 * m2.a12 + m1.a42 * m2.a22 + m1.a43 * m2.a32 + m1.a44 * m2.a42,
        m1.a41 * m2.a13 + m1.a42 * m2.a23 + m1.a43 * m2.a33 + m1.a44 * m2.a43,
        m1.a41 * m2.a14 + m1.a42 * m2.a24 + m1.a43 * m2.a34 + m1.a44 * m2.a44,
    };
}

inline mat4 copy(mat4 const& m)
{
    return {
        m.a11, m.a12, m.a13, m.a14,
        m.a21, m.a22, m.a23, m.a24,
        m.a31, m.a32, m.a33, m.a34,
        m.a41, m.a42, m.a43, m.a44,
    };
}

inline mat4 translate(vec3 t)
{
    return {
        1, 0, 0, t.x,
        0, 1, 0, t.y,
        0, 0, 1, t.z,
        0, 0, 0, 1
    };
}

// reference: https://en.wikipedia.org/wiki/Rotation_matrix
inline mat4 rotate(float theta, vec3 axis)
{
    mat4 r;
    vec3 u = norm(axis);
    float c = cosf(theta),
    s = sinf(theta);

    r.a11 = sq(u.x) * (1 - c) + c;
    r.a12 = u.x * u.y * (1 - c) - u.z * s;
    r.a13 = u.x * u.z * (1 - c) + u.y * s;
    r.a14 = 0;

    r.a21 = u.x * u.y * (1 - c) + u.z * s;
    r.a22 = sq(u.y) * (1 - c) + c;
    r.a23 = u.y * u.z * (1 - c) - u.x * s;
    r.a24 = 0;

    r.a31 = u.x * u.z * (1 - c) - u.y * s;
    r.a32 = u.y * u.z * (1 - c) + u.x * s;
    r.a33 = sq(u.z) * (1 - c) + c;
    r.a34 = 0;

    r.a41 = 0;
    r.a42 = 0;
    r.a43 = 0;
    r.a44 = 1;

    return r;
}
inline mat4 rotate_x(float theta)
{
    float c = cosf(theta),
    s = sinf(theta);
    return {
        1, 0,  0, 0,
        0, c, -s, 0,
        0, s,  c, 0,
        0, 0,  0, 1,
    };
}

inline mat4 rotate_y(float theta)
{
    float c = cosf(theta),
    s = sinf(theta);
    return {
         c, 0, s, 0,
         0, 1, 0, 0,
        -s, 0, c, 0,
         0, 0, 0, 1,
    };
}

inline mat4 rotate_z(float theta)
{
    float c = cosf(theta),
    s = sinf(theta);
    return {
        c, -s, 0, 0,
        s,  c, 0, 0,
        0,  0, 1, 0,
        0,  0, 0, 1,
    };
}

inline mat4 scale(vec3 s)
{
    return {
        s.x,   0,   0,   0,
        0,   s.y,   0,   0,
        0,     0,  s.z,  0,
        0,     0,   0,   1,
    };
}
// reference: https://graphicscompendium.com/opengl/18-lookat-matrix
inline mat4 look_at(vec3 eye, vec3 center, vec3 up)
{
    vec3 w = norm(eye - center); // CAMERA Z
    vec3 u = norm(cross(norm(up),w)); // CAMERA X
    vec3 v = cross(w,u); // CAMERA Y
    float pv = dot(v, eye);
    float pu = dot(u, eye);
    float pw = dot(w, eye);
    return {
        u.x, u.y, u.z, -pu,
        v.x, v.y, v.z, -pv,
        w.x, w.y, w.z, -pw,
        0.f, 0.f, 0.f, 1.f,
    };
}

// reference: https://docs.gl/gl3/glFrustum
// reference: https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/opengl-perspective-projection-matrix.html
inline mat4 perspective(float fov, float aspect, float near, float far)
{

    float top = near * tan(fov * 0.5);
    float bottom = -top;
    float right = top * aspect;
    float left = -right;

    // TODO: Implement frustum function so the below operation can be refactored as
    // frustum(left, right, bottom, top, near, far)

    float a,b,c,d,e,f,g;
    a = (near * 2.0f) / (right - left);
    b = (near * 2.0f) / (top - bottom);
    c = (right + left) / (right - left);
    d = (top + bottom) / (top - bottom);
    e = -(far + near) / (far - near);
    f = -1.0f;
    g = -(far * near * 2.0f) / (far - near);
    return {
        a, 0, c, 0,
        0, b, d, 0,
        0, 0, e, g,
        0, 0, f, 0,
    };
}

} // namespace alm
#endif // ALM_HPP
