#ifndef MAGLIST
#define MAGLIST

#include "../h/types.h"
#include "../h/const.h"
#include "../e/magManagment.e"

// abstraction to easily change between a queue and stack
extern void addMag(mag_t* m, mag_t** tp);

// removes from top of list
extern mag_t* removeMag(mag_t** tp);


#endif
