#ifndef VEC2_H
#define VEC2_H

class vec;
class vec4;

class vec2
{
public:

    union
    {
        struct { float x, y; };
        float v[2];
    };

    vec2();
    vec2(float x, float y);
    explicit vec2(const vec &v);
    explicit vec2(const vec4 &v);

    float &operator[](int i);
    float  operator[](int i) const;

    bool operator==(const vec2 &o) const;
    bool operator!=(const vec2 &o) const;

    bool iszero() const;
    float dot(const vec2 &o) const;
    float squaredlen() const;
    float magnitude() const;
    vec2 &normalize();
    float cross(const vec2 &o) const;
    float squaredist(const vec2 &e) const;
    float dist(const vec2 &e) const;

    vec2 &mul(float f);
    vec2 &mul(const vec2 &o);
    vec2 &square();
    vec2 &div(float f);
    vec2 &div(const vec2 &o);
    vec2 &recip();
    vec2 &add(float f);
    vec2 &add(const vec2 &o);
    vec2 &sub(float f);
    vec2 &sub(const vec2 &o);
    vec2 &neg();
    vec2 &min(const vec2 &o);
    vec2 &max(const vec2 &o);
    vec2 &min(float f);
    vec2 &max(float f);
    vec2 &abs();
    vec2 &clamp(float l, float h);
    vec2 &reflect(const vec2 &n);
    vec2 &lerp(const vec2 &b, float t);
    vec2 &lerp(const vec2 &a, const vec2 &b, float t);
    vec2 &avg(const vec2 &b);

    template<class B> vec2 &madd(const vec2 &a, const B &b)
    {
        return add(vec2(a).mul(b));
    }
    template<class B> vec2 &msub(const vec2 &a, const B &b)
    {
        return sub(vec2(a).mul(b));
    }

    vec2 &rotate_around_z(float c, float s);
    vec2 &rotate_around_z(float angle);
    vec2 &rotate_around_z(const vec2 &sc);

};

#endif // VEC2_H
