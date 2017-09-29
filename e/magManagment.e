#ifndef MAGMANAGMENT
#define MAGMANAGMENT

#include "../h/types.h"
#include "../h/const.h"

extern void magManagmentInit();
extern mag_t* copyMag(mag_t* m);
extern int getTableId(int magType);
extern int getItemBoost(int tableId, int itemCode, stat);

#endif
