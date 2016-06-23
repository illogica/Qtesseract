#ifndef COMPARISON_H
#define COMPARISON_H

#ifdef tess_swap
#undef tess_swap
#endif
template<class T> static inline void tess_swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

template<class T> static inline T max(T a, T b)
{
    return a > b ? a : b;
}
template<class T> static inline T max(T a, T b, T c)
{
    return max(max(a, b), c);
}
template<class T> static inline T min(T a, T b)
{
    return a < b ? a : b;
}
template<class T> static inline T min(T a, T b, T c)
{
    return min(min(a, b), c);
}
template<class T, class U> static inline T clamp(T a, U b, U c)
{
    return max(T(b), min(a, T(c)));
}

//added to make ivec happy
template<class T> static inline T abs(T a)
{
    return a >= 0 ? a : -a;
}

#endif // COMPARISON_H
