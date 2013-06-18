#ifndef __WRAP_H
#define __WRAP_H

#define WRAP(COMM, FUNC) \
   printf("/////begin "); \
   printf(COMM); \
   printf("\n"); \
   (*FUNC)();                                   \
   printf("/////end\n");

#endif
