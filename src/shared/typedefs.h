#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef signed long long int llong;
typedef unsigned long long int ullong;

// easy safe strings
#ifndef MAXSTRLEN
#define MAXSTRLEN 260
typedef char string[MAXSTRLEN];
#endif

#endif // TYPEDEFS_H
