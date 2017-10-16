#ifndef MAGLIST
#define MAGLIST

#include "../h/types.h"
#include "../h/const.h"
#include "../h/magManagment.h"

// abstraction to easily change between a queue and stack
void addMag(mag_t* m, mag_t** tp);

// removes from top of list
mag_t* removeMag(mag_t** tp);


#endif
