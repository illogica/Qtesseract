#ifndef VEC_H
#define VEC_H

#include <QObject>
#include "cmath"
#include "loops.h"
#include "comparison.h"

class vec2;
class vec4;
struct ivec;
struct usvec;
struct svec;

class vec
{
public:

    union
    {
        struct { float x, y, z; };
        struct { float r, g, b; };
        float v[3];
    };

    vec();
    explicit vec(int a);
    explicit vec(float a);
    vec(float a, float b, float c);
    explicit vec(int v[3]);
    explicit vec(const float *v);
    explicit vec(const vec2 &v, float z = 0);
    explicit vec(const vec4 &v);
    explicit vec(const ivec &v);
    explicit vec(const usvec &v);
    explicit vec(const svec &v);
    vec(float yaw, float pitch);
    float &operator[](int i);
    float  operator[](int i) const;
    vec &set(int i, float f);
    bool operator==(const vec &o) const;
    bool operator!=(const vec &o) const;
    bool iszero() const;
    float squaredlen() const;
    float dot2(const vec2 &o) const;
    float dot2(const vec &o) const;
    float dot(const vec &o) const;
    float squaredot(const vec &o) const;
    float absdot(const vec &o) const;
    float zdot(const vec &o) const;
    vec &mul(const vec &o);
    vec &mul(float f);
    vec &mul2(float f);
    vec &square();
    vec &div(const vec &o);
    vec &div(float f);
    vec &div2(float f);
    vec &recip();
    vec &add(const vec &o);
    vec &add(float f);
    vec &add2(float f);
    vec &addz(float f);
    vec &sub(const vec &o);
    vec &sub(float f);
    vec &sub2(float f);
    vec &subz(float f);
    vec &neg2();
    vec &neg();
    vec &min(const vec &o);
    vec &max(const vec &o);
    vec &min(float f);
    vec &max(float f);
    vec &abs();
    vec &clamp(float l, float h);
    float magnitude2() const;
    float magnitude() const;
    vec &normalize();
    bool isnormalized() const;
    float squaredist(const vec &e) const;
    float dist(const vec &e) const;
    float dist(const vec &e, vec &t) const;
    float dist2(const vec &o) const;

    template<class T> bool reject(const T &o, float r)
    {
        return x>o.x+r || x<o.x-r || y>o.y+r || y<o.y-r;
    }

    template<class A, class B> vec &cross(const A &a, const B &b)
    {
        x = a.y*b.z-a.z*b.y; y = a.z*b.x-a.x*b.z; z = a.x*b.y-a.y*b.x;
        return *this;
    }

    vec &cross(const vec &o, const vec &a, const vec &b);
    float scalartriple(const vec &a, const vec &b) const;
    float zscalartriple(const vec &a, const vec &b) const;
    vec &reflectz(float rz);
    vec &reflect(const vec &n);
    vec &project(const vec &n);
    vec &projectxydir(const vec &n);
    vec &projectxy(const vec &n);
    vec &projectxy(const vec &n, float threshold);
    vec &lerp(const vec &b, float t);
    vec &lerp(const vec &a, const vec &b, float t);
    vec &avg(const vec &b);
    template<class B> vec &madd(const vec &a, const B &b) { return add(vec(a).mul(b)); }
    template<class B> vec &msub(const vec &a, const B &b) { return sub(vec(a).mul(b)); }

    vec &rescale(float k);

    vec &rotate_around_z(float c, float s);
    vec &rotate_around_x(float c, float s);
    vec &rotate_around_y(float c, float s);

    vec &rotate_around_z(float angle);
    vec &rotate_around_x(float angle);
    vec &rotate_around_y(float angle);

    vec &rotate_around_z(const vec2 &sc);
    vec &rotate_around_x(const vec2 &sc);
    vec &rotate_around_y(const vec2 &sc);

    vec &rotate(float c, float s, const vec &d);
    vec &rotate(float angle, const vec &d);
    vec &rotate(const vec2 &sc, const vec &d);

    void orthogonal(const vec &d);

    void orthonormalize(vec &s, vec &t) const;

    template<class T> bool insidebb(const T &bbmin, const T &bbmax) const
    {
        return x >= bbmin.x && x <= bbmax.x && y >= bbmin.y && y <= bbmax.y && z >= bbmin.z && z <= bbmax.z;
    }

    template<class T, class U> bool insidebb(const T &bbmin, const T &bbmax, U margin) const
    {
        return x >= bbmin.x-margin && x <= bbmax.x+margin && y >= bbmin.y-margin && y <= bbmax.y+margin && z >= bbmin.z-margin && z <= bbmax.z+margin;
    }

    template<class T, class U> bool insidebb(const T &o, U size) const
    {
        return x >= o.x && x <= o.x + size && y >= o.y && y <= o.y + size && z >= o.z && z <= o.z + size;
    }

    template<class T, class U> bool insidebb(const T &o, U size, U margin) const
    {
        size += margin;
        return x >= o.x-margin && x <= o.x + size && y >= o.y-margin && y <= o.y + size && z >= o.z-margin && z <= o.z + size;
    }

    template<class T> float dist_to_bb(const T &min, const T &max) const
    {
        float sqrdist = 0;
        loopi(3)
        {
            if     (v[i] < min[i]) { float delta = v[i]-min[i]; sqrdist += delta*delta; }
            else if(v[i] > max[i]) { float delta = max[i]-v[i]; sqrdist += delta*delta; }
        }
        return sqrt(sqrdist);
    }

    template<class T, class S> float dist_to_bb(const T &o, S size) const
    {
        return dist_to_bb(o, T(o).add(size));
    }

    template<class T> float project_bb(const T &min, const T &max) const
    {
        return x*(x < 0 ? max.x : min.x) + y*(y < 0 ? max.y : min.y) + z*(z < 0 ? max.z : min.z);
    }

    static vec hexcolor(int color)
    {
        return vec(((color>>16)&0xFF)*(1.0f/255.0f), ((color>>8)&0xFF)*(1.0f/255.0f), (color&0xFF)*(1.0f/255.0f));
    }

    int tohexcolor() const;

};

#endif // VEC_H

