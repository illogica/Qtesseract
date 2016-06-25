#include "vec.h"
#include "vec2.h"
#include "vec4.h"

vec::vec(){}

vec::vec(int a) : x(a), y(a), z(a) {}
vec::vec(float a) : x(a), y(a), z(a) {}
vec::vec(float a, float b, float c) : x(a), y(b), z(c) {}
vec::vec(int v[3]) : x(v[0]), y(v[1]), z(v[2]) {}
vec::vec(const float *v) : x(v[0]), y(v[1]), z(v[2]) {}
vec::vec(const vec2 &v, float z) : x(v.x), y(v.y), z(z) {}
vec::vec(const vec4 &v) : x(v.x), y(v.y), z(v.z) {}

vec::vec(float yaw, float pitch) : x(-sinf(yaw)*cosf(pitch)), y(cosf(yaw)*cosf(pitch)), z(sinf(pitch)) {}

float& vec::operator[](int i)       { return v[i]; }
float  vec::operator[](int i) const { return v[i]; }

vec &vec::set(int i, float f) { v[i] = f; return *this; }

bool vec::operator==(const vec &o) const { return x == o.x && y == o.y && z == o.z; }
bool vec::operator!=(const vec &o) const { return x != o.x || y != o.y || z != o.z; }

bool vec::iszero() const { return x==0 && y==0 && z==0; }
float vec::squaredlen() const { return x*x + y*y + z*z; }
float vec::dot2(const vec2 &o) const { return x*o.x + y*o.y; }
float vec::dot2(const vec &o) const { return x*o.x + y*o.y; }
float vec::dot(const vec &o) const { return x*o.x + y*o.y + z*o.z; }
float vec::squaredot(const vec &o) const { float k = dot(o); return k*k; }
float vec::absdot(const vec &o) const { return fabs(x*o.x) + fabs(y*o.y) + fabs(z*o.z); }
float vec::zdot(const vec &o) const { return z*o.z; }
vec &vec::mul(const vec &o)   { x *= o.x; y *= o.y; z *= o.z; return *this; }
vec &vec::mul(float f)        { x *= f; y *= f; z *= f; return *this; }
vec &vec::mul2(float f)       { x *= f; y *= f; return *this; }
vec &vec::square()            { mul(*this); return *this; }
vec &vec::div(const vec &o)   { x /= o.x; y /= o.y; z /= o.z; return *this; }
vec &vec::div(float f)        { x /= f; y /= f; z /= f; return *this; }
vec &vec::div2(float f)       { x /= f; y /= f; return *this; }
vec &vec::recip()             { x = 1/x; y = 1/y; z = 1/z; return *this; }
vec &vec::add(const vec &o)   { x += o.x; y += o.y; z += o.z; return *this; }
vec &vec::add(float f)        { x += f; y += f; z += f; return *this; }
vec &vec::add2(float f)       { x += f; y += f; return *this; }
vec &vec::addz(float f)       { z += f; return *this; }
vec &vec::sub(const vec &o)   { x -= o.x; y -= o.y; z -= o.z; return *this; }
vec &vec::sub(float f)        { x -= f; y -= f; z -= f; return *this; }
vec &vec::sub2(float f)       { x -= f; y -= f; return *this; }
vec &vec::subz(float f)       { z -= f; return *this; }
vec &vec::neg2()              { x = -x; y = -y; return *this; }
vec &vec::neg()               { x = -x; y = -y; z = -z; return *this; }
vec &vec::min(const vec &o)   { x = ::min(x, o.x); y = ::min(y, o.y); z = ::min(z, o.z); return *this; }
vec &vec::max(const vec &o)   { x = ::max(x, o.x); y = ::max(y, o.y); z = ::max(z, o.z); return *this; }
vec &vec::min(float f)        { x = ::min(x, f); y = ::min(y, f); z = ::min(z, f); return *this; }
vec &vec::max(float f)        { x = ::max(x, f); y = ::max(y, f); z = ::max(z, f); return *this; }
vec &vec::abs() { x = fabs(x); y = fabs(y); z = fabs(z); return *this; }
vec &vec::clamp(float l, float h) { x = ::clamp(x, l, h); y = ::clamp(y, l, h); z = ::clamp(z, l, h); return *this; }
float vec::magnitude2() const { return sqrtf(dot2(*this)); }
float vec::magnitude() const  { return sqrtf(squaredlen()); }
vec &vec::normalize()         { div(magnitude()); return *this; }
bool vec::isnormalized() const { float m = squaredlen(); return (m>0.99f && m<1.01f); }
float vec::squaredist(const vec &e) const { return vec(*this).sub(e).squaredlen(); }
float vec::dist(const vec &e) const { return sqrtf(squaredist(e)); }
float vec::dist(const vec &e, vec &t) const { t = *this; t.sub(e); return t.magnitude(); }
float vec::dist2(const vec &o) const { float dx = x-o.x, dy = y-o.y; return sqrtf(dx*dx + dy*dy); }

vec &vec::cross(const vec &o, const vec &a, const vec &b) { return cross(vec(a).sub(o), vec(b).sub(o)); }
float vec::scalartriple(const vec &a, const vec &b) const { return x*(a.y*b.z-a.z*b.y) + y*(a.z*b.x-a.x*b.z) + z*(a.x*b.y-a.y*b.x); }
float vec::zscalartriple(const vec &a, const vec &b) const { return z*(a.x*b.y-a.y*b.x); }
vec &vec::reflectz(float rz) { z = 2*rz - z; return *this; }
vec &vec::reflect(const vec &n) { float k = 2*dot(n); x -= k*n.x; y -= k*n.y; z -= k*n.z; return *this; }
vec &vec::project(const vec &n) { float k = dot(n); x -= k*n.x; y -= k*n.y; z -= k*n.z; return *this; }
vec &vec::projectxydir(const vec &n) { if(n.z) z = -(x*n.x/n.z + y*n.y/n.z); return *this; }
vec &vec::projectxy(const vec &n)
{
    float m = squaredlen(), k = dot(n);
    projectxydir(n);
    rescale(sqrtf(::max(m - k*k, 0.0f)));
    return *this;
}
vec &vec::projectxy(const vec &n, float threshold)
{
    float m = squaredlen(), k = ::min(dot(n), threshold);
    projectxydir(n);
    rescale(sqrtf(::max(m - k*k, 0.0f)));
    return *this;
}
vec &vec::lerp(const vec &b, float t) { x += (b.x-x)*t; y += (b.y-y)*t; z += (b.z-z)*t; return *this; }
vec &vec::lerp(const vec &a, const vec &b, float t) { x = a.x + (b.x-a.x)*t; y = a.y + (b.y-a.y)*t; z = a.z + (b.z-a.z)*t; return *this; }
vec &vec::avg(const vec &b) { add(b); mul(0.5f); return *this; }

vec &vec::rescale(float k)
{
    float mag = magnitude();
    if(mag > 1e-6f) mul(k / mag);
    return *this;
}

vec &vec::rotate_around_z(float c, float s) { float rx = x, ry = y; x = c*rx-s*ry; y = c*ry+s*rx; return *this; }
vec &vec::rotate_around_x(float c, float s) { float ry = y, rz = z; y = c*ry-s*rz; z = c*rz+s*ry; return *this; }
vec &vec::rotate_around_y(float c, float s) { float rx = x, rz = z; x = c*rx+s*rz; z = c*rz-s*rx; return *this; }

vec &vec::rotate_around_z(float angle) { return rotate_around_z(cosf(angle), sinf(angle)); }
vec &vec::rotate_around_x(float angle) { return rotate_around_x(cosf(angle), sinf(angle)); }
vec &vec::rotate_around_y(float angle) { return rotate_around_y(cosf(angle), sinf(angle)); }

vec &vec::rotate_around_z(const vec2 &sc) { return rotate_around_z(sc.x, sc.y); }
vec &vec::rotate_around_x(const vec2 &sc) { return rotate_around_x(sc.x, sc.y); }
vec &vec::rotate_around_y(const vec2 &sc) { return rotate_around_y(sc.x, sc.y); }

vec &vec::rotate(float c, float s, const vec &d)
{
    *this = vec(x*(d.x*d.x*(1-c)+c) + y*(d.x*d.y*(1-c)-d.z*s) + z*(d.x*d.z*(1-c)+d.y*s),
                x*(d.y*d.x*(1-c)+d.z*s) + y*(d.y*d.y*(1-c)+c) + z*(d.y*d.z*(1-c)-d.x*s),
                x*(d.x*d.z*(1-c)-d.y*s) + y*(d.y*d.z*(1-c)+d.x*s) + z*(d.z*d.z*(1-c)+c));
    return *this;
}
vec &vec::rotate(float angle, const vec &d) { return rotate(cosf(angle), sinf(angle), d); }
vec &vec::rotate(const vec2 &sc, const vec &d) { return rotate(sc.x, sc.y, d); }

void vec::orthogonal(const vec &d)
{
    *this = fabs(d.x) > fabs(d.z) ? vec(-d.y, d.x, 0) : vec(0, -d.z, d.y);
}

void vec::orthonormalize(vec &s, vec &t) const
{
    s.project(*this);
    t.project(*this).project(s);
}

int vec::tohexcolor() const { return (int(::clamp(r, 0.0f, 1.0f)*255)<<16)|(int(::clamp(g, 0.0f, 1.0f)*255)<<8)|int(::clamp(b, 0.0f, 1.0f)*255); }

