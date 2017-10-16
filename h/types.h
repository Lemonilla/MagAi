#ifndef TYPES
#define TYPES
// mags = [Type, [LEVELS], [PERCENTS], [PHOTON], "HISTORY"]

struct history_t
{
    struct history_t* next;
    int itemcode;
} history_t;


struct mag_t 
{
    int type,
        iq,
        sync,
        levels[4],
        percents[4],
        photon[3];
    struct mag_t* next;
    struct history_t* history;
} mag_t;

#endif