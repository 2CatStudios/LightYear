#ifndef GLOBAL_H
#define GLOBAL_H


#if defined (WIN32) || defined (_WIN32)
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

#define YES 1
#define NO 0

static const char VERSION[7] = {"0.0.4d"};


#endif /* end of include guard: GLOBAL_H */
