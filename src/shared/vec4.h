#ifndef VEC4_H
#define VEC4_H

class vec2;
class vec;

class vec4
{
public:
    union
    {
        struct { float x, y, z, w; };
        struct { float r, g, b, a; };
        float v[4];
    };

    vec4();
    explicit vec4(const vec &p, float w = 0);
    explicit vec4(const vec2 &p, float z = 0, float w = 0);
    vec4(float x, float y, float z, float w);
    explicit vec4(const float *v);

    float &operator[](int i);
    float  operator[](int i) const;

    bool operator==(const vec4 &o) const;
    bool operator!=(const vec4 &o) const;

    float dot3(const vec4 &o) const;
    float dot3(const vec &o) const;
    float dot(const vec4 &o) const;
    float dot(const vec &o) const;
    float squaredlen() const;
    float magnitude() const;
    float magnitude3() const;
    vec4 &normalize();

    vec4 &lerp(const vec4 &b, float t);
    vec4 &lerp(const vec4 &a, const vec4 &b, float t);
    vec4 &avg(const vec4 &b);
    template<class B> vec4 &madd(const vec4 &a, const B &b) { return add(vec4(a).mul(b)); }
    template<class B> vec4 &msub(const vec4 &a, const B &b) { return sub(vec4(a).mul(b)); }

    vec4 &mul3(float f);
    vec4 &mul(float f);
    vec4 &mul(const vec4 &o);
    vec4 &mul(const vec &o);
    vec4 &square();
    vec4 &div3(float f);
    vec4 &div(float f);
    vec4 &div(const vec4 &o);
    vec4 &div(const vec &o);
    vec4 &recip();
    vec4 &add(const vec4 &o);
    vec4 &add(const vec &o);
    vec4 &add3(float f);
    vec4 &add(float f);
    vec4 &addw(float f);
    vec4 &sub(const vec4 &o);
    vec4 &sub(const vec &o);
    vec4 &sub3(float f);
    vec4 &sub(float f);
    vec4 &subw(float f);
    vec4 &neg3();
    vec4 &neg();
    vec4 &clamp(float l, float h);

    template<class A, class B>  vec4 &cross(const A &a, const B &b)
    {
        x = a.y*b.z-a.z*b.y; y = a.z*b.x-a.x*b.z; z = a.x*b.y-a.y*b.x;
        return *this;
    }

    vec4 &cross(const vec &o, const vec &a, const vec &b);

    void setxyz(const vec &v);

    vec4 &rotate_around_z(float c, float s);
    vec4 &rotate_around_x(float c, float s);
    vec4 &rotate_around_y(float c, float s);

    vec4 &rotate_around_z(float angle);
    vec4 &rotate_around_x(float angle);
    vec4 &rotate_around_y(float angle);

    vec4 &rotate_around_z(const vec2 &sc);
    vec4 &rotate_around_x(const vec2 &sc);
    vec4 &rotate_around_y(const vec2 &sc);
};

#endif // VEC4_H
