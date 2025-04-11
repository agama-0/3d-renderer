#ifndef ALM_HPP
#define ALM_HPP

typedef struct {
    float x,y;
} vec2;

inline vec2 new_vec2(float x, float y);
inline vec2 operator+(vec2 const& a, vec2 const& b);
inline vec2 operator-(vec2 const& a, vec2 const& b);
inline vec2 operator+(vec2 const& a, float const& b); // TODO
inline vec2 operator-(vec2 const& a, float const& b); // TODO
inline vec2 operator*(vec2 const& a, float const& b); // TODO
inline vec2 operator/(vec2 const& a, float const& b); // TODO
inline vec2 operator*(vec2 const& a, float const& b);
inline vec2 operator/(vec2 const& a, float const& b);
inline float dot(vec2 const& a, vec2 const& b);
inline vec2 copy(vec2 const& a);
inline vec2 norm(vec2 const& a);
inline float len_sq(vec2 const& a);
inline float len(vec2 const& a);
inline vec2 cross(vec2 const& a, vec2 const& b); // TODO
inline vec2 reflect(vec2 const& a, vec2 const& b); // TODO

typedef struct {
    float x,y,z;
} vec3;

inline vec3 new_vec3(float x, float y, float z);
inline vec3 operator+(vec3 const& a, vec3 const& b);
inline vec3 operator-(vec3 const& a, vec3 const& b);
inline vec3 operator+(vec3 const& a, float const& b); // TODO
inline vec3 operator-(vec3 const& a, float const& b); // TODO
inline vec3 operator*(vec3 const& a, float const& b); // TODO
inline vec3 operator/(vec3 const& a, float const& b); // TODO
inline vec3 operator*(vec3 const& a, float const& b);
inline vec3 operator/(vec3 const& a, float const& b);
inline float dot(vec3 const& a, vec3 const& b);
inline vec3 copy(vec3 const& a);
inline vec3 norm(vec3 const& a);
inline float len(vec3 const& a);
inline float len_sq(vec3 const& a);;
inline vec3 cross(vec3 const& a, vec3 const& b);
inline vec3 reflect(vec3 const& a, vec3 const& b); // TODO

// REFLECT
// r=d−2(d⋅n)n

typedef struct {
    float x,y,z,w;
} vec4;

inline vec4 new_vec4(float x, float y, float z, float w);
inline vec4 operator+(vec4 const& a, vec4 const& b);
inline vec4 operator-(vec4 const& a, vec4 const& b);
inline vec4 operator+(vec4 const& a, float const& b); // TODO
inline vec4 operator-(vec4 const& a, float const& b); // TODO
inline vec4 operator*(vec4 const& a, float const& b); // TODO
inline vec4 operator/(vec4 const& a, float const& b); // TODO
inline vec4 operator*(vec4 const& a, float const& b);
inline vec4 operator/(vec4 const& a, float const& b);
inline float dot(vec4 const& a, vec4 const& b);
inline vec4 copy(vec4 const& a);
inline vec4 norm(vec4 const& a);
inline float len_sq(vec4 const& a);
inline float len(vec4 const& a);
inline vec4 cross(vec4 const& a, vec4 const& b); // TODO
inline vec4 reflect(vec4 const& a, vec4 const& b); // TODO

typedef struct {
    float
    m11, m12, m13, m14,
    m21, m22, m23, m24,
    m31, m32, m33, m34,
    m41, m42, m43, m44;
} mat4;

inline mat4 new_mat4_from_rows(vec4 r1, vec4 r2, vec4 r3, vec4 r4);
inline mat4 new_mat4_from_cols(vec4 c1, vec4 c2, vec4 c3, vec4 c4);
inline mat4 zero_mat4();
inline mat4 ident_mat4();
inline mat4 copy(mat4 const& a);
inline mat4 transpose(mat4 const& a);
inline mat4 operator+(mat4 const& a, mat4 const& b);
inline mat4 operator-(mat4 const& a, mat4 const& b);
inline mat4 operator+(mat4 const& a, float b); // TODO
inline mat4 operator-(mat4 const& a, float b); // TODO
inline mat4 operator*(mat4 const& a, float b);
inline mat4 operator/(mat4 const& a, float b);
inline mat4 operator*(mat4 const& a, mat4 const& b);
inline mat4 operator*(mat4 const& a, vec4 const& b);
inline mat4 scale_aniso(mat4 const& a, float x, float y, float z);
inline mat4 scale_aniso(mat4 const& a, vec3 v);
inline mat4 translate(mat4 const& a, float x, float y, float z);
inline mat4 translate(mat4 const& a, vec3 v);
inline mat4 translate_ident(float x, float y, float z);
inline mat4 translate_ident(vec3 v);
inline mat4 mul_outer(vec3 const a, vec3 const b);
inline mat4 rotate(mat4 const& a, float x, float y, float z, float angle);
inline mat4 rotate(mat4 const& a, vec3 axis, float angle);
inline mat4 rotate_x(mat4 const& a, float angle);
inline mat4 rotate_y(mat4 const& a, float angle);
inline mat4 rotate_z(mat4 const& a, float angle);
inline mat4 ortho_normalize(mat4 const& a); // TODO
inline mat4 frustum(float l, float r, float b, float t, float n, float f);
inline mat4 ortho(float l, float r, float b, float t, float n, float f);
inline mat4 perspective(float fov, float aspect, float n, float f);
inline mat4 look_at(mat4 m, vec3 const eye, vec3 const center, vec3 const up);

#define ALM_HPP_DEFINE_MAT4_ROW(i) \
inline vec4 row_##i(mat4 const& a);

ALM_HPP_DEFINE_MAT4_ROW(1)
ALM_HPP_DEFINE_MAT4_ROW(2)
ALM_HPP_DEFINE_MAT4_ROW(3)
ALM_HPP_DEFINE_MAT4_ROW(4)

#define ALM_HPP_FUNC_MAT4_ROW(i) \
inline vec4 row_##i(mat4 const& a) \
{ \
    return {a.m##i##1,a.m##i##2,a.m##i##3,a.m##i##4}; \
} \

#define ALM_HPP_DEFINE_MAT4_COL(i) \
inline vec4 col_##i(mat4 const& a);

ALM_HPP_DEFINE_MAT4_COL(1)
ALM_HPP_DEFINE_MAT4_COL(2)
ALM_HPP_DEFINE_MAT4_COL(3)
ALM_HPP_DEFINE_MAT4_COL(4)

#define ALM_HPP_FUNC_MAT4_COL(i) \
inline vec4 col_##i(mat4 const& a) \
{ \
    return {a.m1##i, a.m2##i, a.m3##i, a.m4##i }; \
}

#define ALM_IMPLEMENTATION
#ifdef ALM_IMPLEMENTATION
#include <math.h>

// vec2
inline vec2 new_vec2(float x, float y)
{return {x,y};}

inline vec2 operator+(vec2 const& a, vec2 const& b)
{return {a.x+b.x,a.y+b.y};}

inline vec2 operator-(vec2 const& a, vec2 const& b)
{return {a.x-b.x,a.y-b.y};}

inline vec2 operator*(vec2 const& a, float const& b)
{return {a.x*b,a.y*b};}

inline vec2 operator/(vec2 const& a, float const& b)
{return {a.x/b,a.y/b};}

inline float dot(vec2 const& a, vec2 const& b)
{return a.x*b.x+a.y*b.y;}

inline float len_sq(vec2 const& a)
{return (a.x*a.x)+(a.y*a.y);}

inline float len(vec2 const& a)
{return sqrtf(len(a));}

inline vec2 copy(vec2 const& a)
{return {a.x,a.y};}

inline vec2 norm(vec2 const& a)
{return {a / len(a)};}

// vec3
inline vec3 new_vec3(float x, float y, float z)
{return {x,y,z};}

inline vec3 operator+(vec3 const& a, vec3 const& b)
{return {a.x+b.x,a.y+b.y,a.z+b.z};}

inline vec3 operator-(vec3 const& a, vec3 const& b)
{return {a.x-b.x,a.y-b.y,a.z-b.z};}

inline vec3 operator*(vec3 const& a, float const& b)
{return {a.x*b,a.y*b,a.z*b};}

inline vec3 operator/(vec3 const& a, float const& b)
{return {a.x/b,a.y/b,a.z/b};}

inline float dot(vec3 const& a, vec3 const& b)
{return a.x*b.x+a.y*b.y+a.z*b.z;}

inline float len_sq(vec3 const& a)
{return (a.x*a.x)+(a.y*a.y)+(a.z*a.z);}

inline float len(vec3 const& a)
{return sqrtf(len(a));}

inline vec3 copy(vec3 const& a)
{return {a.x,a.y,a.z};}

inline vec3 norm(vec3 const& a)
{return {a / len(a)};}

inline vec3 cross(vec3 const& a, vec3 const& b)
{
    return {
        a.y*b.z-b.y*a.z,
        a.z*b.x-b.z*a.x,
        a.x*b.y-b.x*a.y,
    };
}

// vec4
inline vec4 new_vec4(float x, float y, float z, float w)
{return {x,y,z,w};}

inline vec4 operator+(vec4 const& a, vec4 const& b)
{return {a.x+b.x,a.y+b.y,a.z+b.z,a.w+b.w};}

inline vec4 operator-(vec4 const& a, vec4 const& b)
{return {a.x-b.x,a.y-b.y,a.z-b.z,a.w-b.w};}

inline vec4 operator*(vec4 const& a, float const& b)
{return {a.x*b,a.y*b,a.z*b,a.w*b};}

inline vec4 operator/(vec4 const& a, float const& b)
{return {a.x/b,a.y/b,a.z/b,a.w/b};}

inline float dot(vec4 const& a, vec4 const& b)
{return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;}

inline float len_sq(vec4 const& a)
{return (a.x*a.x)+(a.y*a.y)+(a.z*a.z)+(a.w*a.w);}

inline float len(vec4 const& a)
{return sqrtf(len(a));}

inline vec4 copy(vec4 const& a)
{return {a.x,a.y,a.z,a.w};}

inline vec4 norm(vec4 const& a)
{return {a / len(a)};}

// mat4
ALM_HPP_FUNC_MAT4_ROW(1)
ALM_HPP_FUNC_MAT4_ROW(2)
ALM_HPP_FUNC_MAT4_ROW(3)
ALM_HPP_FUNC_MAT4_ROW(4)

ALM_HPP_FUNC_MAT4_COL(1)
ALM_HPP_FUNC_MAT4_COL(2)
ALM_HPP_FUNC_MAT4_COL(3)
ALM_HPP_FUNC_MAT4_COL(4)

inline mat4 new_mat4_from_rows(vec4 r1, vec4 r2, vec4 r3, vec4 r4)
{
    return {
        r1.x,r1.y,r1.z,r1.w,
        r2.x,r2.y,r2.z,r2.w,
        r3.x,r3.y,r3.z,r3.w,
        r4.x,r4.y,r4.z,r4.w,
    };
}

inline mat4 new_mat4_from_cols(vec4 c1, vec4 c2, vec4 c3, vec4 c4)
{
    return {
      c1.x,c2.x,c3.x,c4.x,
      c1.y,c2.y,c3.y,c4.y,
      c1.z,c2.z,c3.z,c4.z,
      c1.w,c2.w,c3.w,c4.w,
    };
}

inline mat4 zero_mat4()
{
    return {
        0,0,0,
        0,0,0,
        0,0,0,
    };
}

inline mat4 ident_mat4()
{
    return {
        1,0,0,
        0,1,0,
        0,0,1,
    };
}

inline mat4 copy(mat4 const& a)
{
    return {
        a.m11,a.m12,a.m13,a.m14,
        a.m21,a.m22,a.m23,a.m24,
        a.m31,a.m32,a.m33,a.m34,
        a.m41,a.m42,a.m43,a.m44,
    };
}

inline mat4 transpose(mat4 const& a)
{
    mat4 r = copy(a);
    r.m12 = a.m21; r.m13 = a.m31; r.m14 = a.m41;
    r.m21 = a.m12; r.m23 = a.m32; r.m24 = a.m42;
    r.m31 = a.m13; r.m32 = a.m23; r.m34 = a.m43;
    r.m41 = a.m14; r.m42 = a.m24; r.m34 = a.m43;
    return r;
}

inline mat4 operator+(mat4 const& a, mat4 const& b)
{
    return {
        a.m11+b.m11,a.m12+b.m12,a.m13+b.m13,a.m14+b.m14,
        a.m21+b.m21,a.m22+b.m22,a.m23+b.m23,a.m24+b.m24,
        a.m31+b.m31,a.m32+b.m32,a.m33+b.m33,a.m34+b.m34,
        a.m41+b.m41,a.m42+b.m42,a.m43+b.m43,a.m44+b.m44,
    };
}

inline mat4 operator-(mat4 const& a, mat4 const& b)
{
    return {
        a.m11-b.m11,a.m12-b.m12,a.m13-b.m13,a.m14-b.m14,
        a.m21-b.m21,a.m22-b.m22,a.m23-b.m23,a.m24-b.m24,
        a.m31-b.m31,a.m32-b.m32,a.m33-b.m33,a.m34-b.m34,
        a.m41-b.m41,a.m42-b.m42,a.m43-b.m43,a.m44-b.m44,
    };
}
inline mat4 operator*(mat4 const& a, float b)
{
    return {
        a.m11*b,a.m12*b,a.m13*b,a.m14*b,
        a.m21*b,a.m22*b,a.m23*b,a.m24*b,
        a.m31*b,a.m32*b,a.m33*b,a.m34*b,
        a.m41*b,a.m42*b,a.m43*b,a.m44*b,
    };
}
inline mat4 operator/(mat4 const& a, float b)
{
    return {
        a.m11/b,a.m12/b,a.m13/b,a.m14/b,
        a.m21/b,a.m22/b,a.m23/b,a.m24/b,
        a.m31/b,a.m32/b,a.m33/b,a.m34/b,
        a.m41/b,a.m42/b,a.m43/b,a.m44/b,
    };
}

inline mat4 operator*(mat4 const& a, mat4 const& b)
{
    return {
        .m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31 + a.m14 * b.m41,
        .m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32 + a.m14 * b.m42,
        .m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33 + a.m14 * b.m43,
        .m14 = a.m11 * b.m14 + a.m12 * b.m24 + a.m13 * b.m34 + a.m14 * b.m44,
        .m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31 + a.m24 * b.m41,
        .m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32 + a.m24 * b.m42,
        .m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33 + a.m24 * b.m43,
        .m24 = a.m21 * b.m14 + a.m22 * b.m24 + a.m23 * b.m34 + a.m24 * b.m44,
        .m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31 + a.m34 * b.m41,
        .m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32 + a.m34 * b.m42,
        .m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 + a.m34 * b.m43,
        .m34 = a.m31 * b.m14 + a.m32 * b.m24 + a.m33 * b.m34 + a.m34 * b.m44,
        .m41 = a.m41 * b.m11 + a.m42 * b.m21 + a.m43 * b.m31 + a.m43 * b.m41,
        .m42 = a.m41 * b.m12 + a.m42 * b.m22 + a.m43 * b.m32 + a.m43 * b.m42,
        .m43 = a.m41 * b.m13 + a.m42 * b.m23 + a.m43 * b.m33 + a.m43 * b.m43,
        .m44 = a.m41 * b.m14 + a.m42 * b.m24 + a.m43 * b.m34 + a.m43 * b.m44,
    };
}
inline mat4 operator*(mat4 const& a, vec4 const& b)
{
    return {
        .m11 = a.m11 * b.x + a.m12 * b.y + a.m13 * b.z + a.m14 * b.w,
        .m12 = a.m11 * b.x + a.m12 * b.y + a.m13 * b.z + a.m14 * b.w,
        .m13 = a.m11 * b.x + a.m12 * b.y + a.m13 * b.z + a.m14 * b.w,
        .m14 = a.m11 * b.x + a.m12 * b.y + a.m13 * b.z + a.m14 * b.w,
        .m21 = a.m21 * b.x + a.m22 * b.y + a.m23 * b.z + a.m24 * b.w,
        .m22 = a.m21 * b.x + a.m22 * b.y + a.m23 * b.z + a.m24 * b.w,
        .m23 = a.m21 * b.x + a.m22 * b.y + a.m23 * b.z + a.m24 * b.w,
        .m24 = a.m21 * b.x + a.m22 * b.y + a.m23 * b.z + a.m24 * b.w,
        .m31 = a.m31 * b.x + a.m32 * b.y + a.m33 * b.z + a.m34 * b.w,
        .m32 = a.m31 * b.x + a.m32 * b.y + a.m33 * b.z + a.m34 * b.w,
        .m33 = a.m31 * b.x + a.m32 * b.y + a.m33 * b.z + a.m34 * b.w,
        .m34 = a.m31 * b.x + a.m32 * b.y + a.m33 * b.z + a.m34 * b.w,
        .m41 = a.m41 * b.x + a.m42 * b.y + a.m43 * b.z + a.m43 * b.w,
        .m42 = a.m41 * b.x + a.m42 * b.y + a.m43 * b.z + a.m43 * b.w,
        .m43 = a.m41 * b.x + a.m42 * b.y + a.m43 * b.z + a.m43 * b.w,
        .m44 = a.m41 * b.x + a.m42 * b.y + a.m43 * b.z + a.m43 * b.w,
    };
}

inline mat4 scale_aniso(mat4 const& a, float x, float y, float z)
{
    return {
        a.m11*x,a.m12*x,a.m13*x,a.m14*x,
        a.m21*y,a.m22*y,a.m23*y,a.m24*y,
        a.m31*z,a.m32*z,a.m33*z,a.m34*z,
        a.m41*1,a.m42*1,a.m43*1,a.m44*1,
    };
}

inline mat4 scale_aniso(mat4 const& a, vec3 v)
{return scale_aniso(a,v.x,v.y,v.z);}

inline mat4 translate(mat4 const& a, float x, float y, float z)
{
    mat4 r = copy(a);
    r.m11 += x;
    r.m22 += x;
    r.m33 += x;
    return r;
}

inline mat4 translate(mat4 const& a, vec3 v)
{return translate(a,v.x,v.y,v.z);}

inline mat4 translate_ident(float x, float y, float z)
{
    mat4 r = ident_mat4();
    r.m11 = x;
    r.m22 = y;
    r.m33 = z;
    return r;
}

inline mat4 translate_ident(vec3 v)
{return translate_ident(v.x,v.y,v.z);}

inline mat4 mul_outer(vec3 const a, vec3 const b)
{
    return {
        a.x*b.x,a.x*b.y,a.x*b.z,
        a.y*b.x,a.y*b.y,a.y*b.z,
        a.z*b.x,a.z*b.y,a.z*b.z,
        0      ,0      ,0,    0,
    };
}
inline mat4 rotate(mat4 const& a, float x, float y, float z, float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);
    mat4 r = {
        x*x*(1-c)+c,   x*y*(1-c)-z*s, x*z*(1-c)+y*s, 0,
        y*x*(1-c)+z*s, y*y*(1-c)+c,   y*z*(1-c)-x*s, 0,
        x*z*(1-c)-y*s, y*z*(1-c)+x*s, z*z*(1-c)+c  , 0,
        0,             0,             0,             1,
    };
    return r * a;
}
inline mat4 rotate(mat4 const& a, vec3 axis, float angle)
{return rotate(a,axis.x,axis.y,axis.z,angle);}

inline mat4 rotate_x(mat4 const& a, float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);
    mat4 rx = {
        1, 0, 0,
        0, c,-s,
        0, s, c,
    };
    return rx * a;
}
inline mat4 rotate_y(mat4 const& a, float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);
    mat4 ry = {
        +c, 0, s,
        +0, 1, 0,
        -s,0, c,
    };
    return ry * a;
}
inline mat4 rotate_z(mat4 const& a, float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);
    mat4 rz = {
        c,-s, 0,
        s, c, 0,
        0, 0, 1,
    };
    return rz * a;
}
inline mat4 frustum(float left, float right, float bottom, float top, float near, float far)
{
    float a,b,c,d,e,f,g = -1;
    a = (2 * near) / (right - left);
    b = (right + left) / (right - left);
    c = (top + bottom) / (top - bottom);
    d = (2 * near) / (top - bottom);
    e = -(far + near) / (far - near);
    f = -(2 * far * near) / (far - near);
    return {
        a,0,b,0,
        0,c,d,0,
        0,0,e,f,
        0,0,g,0,
    };
}
inline mat4 ortho(float left, float right, float bottom, float top, float near, float far)
{
    float a,b,c,d,e,f;
    a = 2 / (right - left);
    b = 2 / (top - bottom);
    c = -2 / (far - near);
    d = (right + left) / (right - left);
    e = (top + bottom) / (top - bottom);
    f = -(2 * far * near) / (far - near);
    return {
        a,0,0,d,
        0,b,0,e,
        0,0,c,f,
        0,0,0,1,
    };
}
inline mat4 perspective(float fov, float aspect, float near, float far)
{
    float a,b,c,d,e;
    a = 1.f / tanf(fov / 2.f);
    b = a / aspect;
    c = -(far + near) / (far - near);
    d = -1;
    e = -(2.f * far * near) / (far - near);
    return {
        b,0,0,0,
        0,a,0,0,
        0,0,c,d,
        0,0,e,0
    };
}
inline mat4 look_at(mat4 m, vec3 const eye, vec3 const center, vec3 const up)
{
    vec3 f = norm(center - eye);
    vec3 s = norm(cross(f,up));
    vec3 t = cross(s,f);
    return translate({
        s.x,t.x,f.x,0,
        s.y,t.y,f.y,0,
        s.z,t.z,f.z,0,
        0.f,0.f,0.f,1,
    }, eye);
}

#endif // ALM_IMPLEMENTATION
#endif // ALM_HPP
