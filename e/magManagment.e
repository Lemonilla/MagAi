#ifndef MAGMANAGMENT
#define MAGMANAGMENT

#include "../h/types.h"
#include "../h/const.h"

extern void magManagmentInit();
extern mag_t* copyMag(mag_t* m);
extern int getTableId(int magType);
extern int getItemBoost(int tableId, int itemCode, stat);
extern void addPhoton(mag_t* m, int pb);
extern int compareMag(mag_t* a, mag_t* b);
extern mag_t* newMag(int ppp);
extern void deleteMag(mag_t* m);

#endif
