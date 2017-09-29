// mags = [Type, [LEVELS], [PERCENTS], [PHOTON], "HISTORY"]

struct history_t
{
    history_t* next;
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
    mag_t* next;
    history_t* history;
} mag_t;