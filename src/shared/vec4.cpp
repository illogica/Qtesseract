#include "vec4.h"
#include "vec.h"
#include "vec2.h"

vec4::vec4() {}
vec4::vec4(const vec &p, float w) : x(p.x), y(p.y), z(p.z), w(w) {}
vec4::vec4(const vec2 &p, float z, float w) : x(p.x), y(p.y), z(z), w(w) {}
vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
vec4::vec4(const float *v) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) {}

float &vec4::operator[](int i)       { return v[i]; }
float  vec4::operator[](int i) const { return v[i]; }

bool vec4::operator==(const vec4 &o) const { return x == o.x && y == o.y && z == o.z && w == o.w; }
bool vec4::operator!=(const vec4 &o) const { return x != o.x || y != o.y || z != o.z || w != o.w; }

float vec4::dot3(const vec4 &o) const { return x*o.x + y*o.y + z*o.z; }
float vec4::dot3(const vec &o) const { return x*o.x + y*o.y + z*o.z; }
float vec4::dot(const vec4 &o) const { return dot3(o) + w*o.w; }
float vec4::dot(const vec &o) const  { return x*o.x + y*o.y + z*o.z + w; }
float vec4::squaredlen() const { return dot(*this); }
float vec4::magnitude() const  { return sqrtf(squaredlen()); }
float vec4::magnitude3() const { return sqrtf(dot3(*this)); }
vec4 &vec4::normalize() { mul(1/magnitude()); return *this; }

vec4 &vec4::lerp(const vec4 &b, float t)
{
    x += (b.x-x)*t;
    y += (b.y-y)*t;
    z += (b.z-z)*t;
    w += (b.w-w)*t;
    return *this;
}
vec4 &vec4::lerp(const vec4 &a, const vec4 &b, float t)
{
    x = a.x+(b.x-a.x)*t;
    y = a.y+(b.y-a.y)*t;
    z = a.z+(b.z-a.z)*t;
    w = a.w+(b.w-a.w)*t;
    return *this;
}
vec4 &vec4::avg(const vec4 &b) { add(b); mul(0.5f); return *this; }

vec4 &vec4::mul3(float f)      { x *= f; y *= f; z *= f; return *this; }
vec4 &vec4::mul(float f)       { mul3(f); w *= f; return *this; }
vec4 &vec4::mul(const vec4 &o) { x *= o.x; y *= o.y; z *= o.z; w *= o.w; return *this; }
vec4 &vec4::mul(const vec &o)  { x *= o.x; y *= o.y; z *= o.z; return *this; }
vec4 &vec4::square()           { mul(*this); return *this; }
vec4 &vec4::div3(float f)      { x /= f; y /= f; z /= f; return *this; }
vec4 &vec4::div(float f)       { div3(f); w /= f; return *this; }
vec4 &vec4::div(const vec4 &o) { x /= o.x; y /= o.y; z /= o.z; w /= o.w; return *this; }
vec4 &vec4::div(const vec &o)  { x /= o.x; y /= o.y; z /= o.z; return *this; }
vec4 &vec4::recip()            { x = 1/x; y = 1/y; z = 1/z; w = 1/w; return *this; }
vec4 &vec4::add(const vec4 &o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
vec4 &vec4::add(const vec &o)  { x += o.x; y += o.y; z += o.z; return *this; }
vec4 &vec4::add3(float f)      { x += f; y += f; z += f; return *this; }
vec4 &vec4::add(float f)       { add3(f); w += f; return *this; }
vec4 &vec4::addw(float f)      { w += f; return *this; }
vec4 &vec4::sub(const vec4 &o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; return *this; }
vec4 &vec4::sub(const vec &o)  { x -= o.x; y -= o.y; z -= o.z; return *this; }
vec4 &vec4::sub3(float f)      { x -= f; y -= f; z -= f; return *this; }
vec4 &vec4::sub(float f)       { sub3(f); w -= f; return *this; }
vec4 &vec4::subw(float f)      { w -= f; return *this; }
vec4 &vec4::neg3()             { x = -x; y = -y; z = -z; return *this; }
vec4 &vec4::neg()              { neg3(); w = -w; return *this; }
vec4 &vec4::clamp(float l, float h) { x = ::clamp(x, l, h); y = ::clamp(y, l, h); z = ::clamp(z, l, h); w = ::clamp(w, l, h); return *this; }

vec4 &vec4::cross(const vec &o, const vec &a, const vec &b) { return cross(vec(a).sub(o), vec(b).sub(o)); }

void vec4::setxyz(const vec &v) { x = v.x; y = v.y; z = v.z; }

vec4 &vec4::rotate_around_z(float c, float s) { float rx = x, ry = y; x = c*rx-s*ry; y = c*ry+s*rx; return *this; }
vec4 &vec4::rotate_around_x(float c, float s) { float ry = y, rz = z; y = c*ry-s*rz; z = c*rz+s*ry; return *this; }
vec4 &vec4::rotate_around_y(float c, float s) { float rx = x, rz = z; x = c*rx-s*rz; z = c*rz+s*rx; return *this; }

vec4 &vec4::rotate_around_z(float angle) { return rotate_around_z(cosf(angle), sinf(angle)); }
vec4 &vec4::rotate_around_x(float angle) { return rotate_around_x(cosf(angle), sinf(angle)); }
vec4 &vec4::rotate_around_y(float angle) { return rotate_around_y(cosf(angle), sinf(angle)); }

vec4 &vec4::rotate_around_z(const vec2 &sc) { return rotate_around_z(sc.x, sc.y); }
vec4 &vec4::rotate_around_x(const vec2 &sc) { return rotate_around_x(sc.x, sc.y); }
vec4 &vec4::rotate_around_y(const vec2 &sc) { return rotate_around_y(sc.x, sc.y); }

