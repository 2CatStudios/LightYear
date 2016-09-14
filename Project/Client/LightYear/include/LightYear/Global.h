#ifndef GLOBAL_H
#define GLOBAL_H


#if defined (WIN32) || defined (_WIN32)
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

#define YES 1
#define NO 0

enum {GUI_WINDOW, GUI_LABEL, GUI_BUTTON};


#endif /* end of include guard: GLOBAL_H */