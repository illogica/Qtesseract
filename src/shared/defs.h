#ifndef DEFS_H
#define DEFS_H

#ifdef _DEBUG
#define ASSERT(c) assert(c)
#else
#define ASSERT(c) if(c) {}
#endif

#ifdef NULL
#undef NULL
#endif
#define NULL 0

extern uint randomMT();

#define rnd(x) ((int)(randomMT()&0x7FFFFFFF)%(x))
#define rndscale(x) (float((randomMT()&0x7FFFFFFF)*double(x)/double(0x7FFFFFFF)))
#define detrnd(s, x) ((int)(((((uint)(s))*1103515245+12345)>>16)%(x)))

#define DELETEP(p) if(p) { delete   p; p = 0; }
#define DELETEA(p) if(p) { delete[] p; p = 0; }

// server
#ifndef MAXCLIENTS
#define MAXCLIENTS 128                 // DO NOT set this any higher
#endif

#ifndef MAXTRANS
#define MAXTRANS 5000                  // max amount of data to swallow in 1 go
#endif

#define PI (3.14159265358979f)
#define SQRT2 (1.4142135623731f)
#define SQRT3 (1.73205080756888f)
#define SQRT5 (2.23606797749979f)
#define RAD (PI / 180.0f)

#endif // DEFS_H
