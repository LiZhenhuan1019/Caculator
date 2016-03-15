#ifndef CACULATORHEADER
#define CACULATORHEADER

#define DEBUG

#ifdef DEBUG
#define GRAPHICSTESTMODE

#ifdef GRAPHICSTESTMODE
#define GRAPHICSDEBUG(x) (x)
#else
#define GRAPHICSDEBUG(x)
#endif
#endif

#endif // CACULATORHEADER

