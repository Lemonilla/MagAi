#ifndef MAGMANAGMENT
#define MAGMANAGMENT

#include "../h/types.h"
#include "../h/const.h"

void magManagmentInit();
mag_t* copyMag(mag_t* m);
int getTableId(int magType);
int getItemBoost(int tableId, int itemCode, stat);
void addPhoton(mag_t* m, int pb);
int compareMag(mag_t* a, mag_t* b);
mag_t* newMag(int ppp);
void deleteMag(mag_t* m);

#endif
