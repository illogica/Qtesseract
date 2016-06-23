#ifndef LOOPS_H
#define LOOPS_H

#ifndef loop(v,m)
#define loop(v,m) for(int v = 0; v < int(m); ++v)
#endif

#ifndef loopi(m)
#define loopi(m) loop(i,m)
#endif

#ifndef loopj(m)
#define loopj(m) loop(j,m)
#endif

#ifndef loopk(m)
#define loopk(m) loop(k,m)
#endif

#ifndef loopl(m)
#define loopl(m) loop(l,m)
#endif

#ifndef looprev(v,m)
#define looprev(v,m) for(int v = int(m); --v >= 0;)
#endif

#ifndef loopirev(m)
#define loopirev(m) looprev(i,m)
#endif

#ifndef loopjrev(m)
#define loopjrev(m) looprev(j,m)
#endif

#ifndef loopkrev(m)
#define loopkrev(m) looprev(k,m)
#endif

#ifndef looplrev(m)
#define looplrev(m) looprev(l,m)
#endif

#ifndef loopv(v)
#define loopv(v)    for(int i = 0; i<(v).length(); i++)
#endif

#ifndef loopvj(v)
#define loopvj(v)   for(int j = 0; j<(v).length(); j++)
#endif

#ifndef loopvk(v)
#define loopvk(v)   for(int k = 0; k<(v).length(); k++)
#endif

#ifndef loopvrev(v)
#define loopvrev(v) for(int i = (v).length()-1; i>=0; i--)
#endif

#endif // LOOPS_H
