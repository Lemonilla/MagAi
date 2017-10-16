// TODO: add evolution type to celled mags
//          (E type)


#include "../h/types.h"
#include "../h/const.h"
#include "../h/maglist.h"
#include "../h/magManagment.h"

HIDDEN int feedableItems[11] = {
    MONOMATE,
    DIMATE,
    TRIMATE,
    MONOFLUID,
    DIFLUID,
    TRIFLUID,
    ANTIDOTE,
    ANTIPARALYSIS,
    SOLATOMIZER,
    MOONATONIMZER,
    STARATOMIZER
};

// ( Startmag, EndMag, Check, HistoryCode, PhotonBlast, Tier )   
HIDDEN int EvolutionChart[112][5] = {
  //Tier 1  
    {MAG,       VARUNA,     0, HUgC      , FARLLA,    1},
    {MAG,       KALKI,      0, RAgC      , ESTLLA,    1},
    {MAG,       VRITRA,     0, FOgC      , LEILLA,    1},
  // Tier 2
    {VARUNA,    RUDRA,      1, Allg      , GOLLA,     2},
    {VARUNA,    MARUTAH,    2, Allg      , PILLA,     2},
    {VARUNA,    VAYU,       3, Allg      , TWINS,     2},
    {VARUNA,    RUDRA,      4, Allg      , GOLLA,     2},
    {KALKI,     SURYA,      1, Allg      , GOLLA,     2},
    {KALKI,     MITRA,      2, Allg      , PILLA,     2},
    {KALKI,     TAPAS,      3, Allg      , TWINS,     2},
    {KALKI,     MITRA,      4, Allg      , PILLA,     2},
    {VRITRA,    SUMBA,      1, Allg      , GOLLA,     2},
    {VRITRA,    ASHVINAU,   2, Allg      , PILLA,     2},
    {VRITRA,    NAMUCI,     3, Allg      , TWINS,     2},
    {VRITRA,    NAMUCI,     4, Allg      , TWINS,     2},
  // Tier 3
  // POW > DEX >= MIND
    {ANYMAG,    VARAHA,     5, HUgA,       GOLLA,     3},
    {ANYMAG,    VARAHA,    17, HUgA,       GOLLA,     3},
    {ANYMAG,    KAMA,       5, HUgB,       PILLA,     3},
    {ANYMAG,    KAMA,      17, HUgB,       PILLA,     3},
    {ANYMAG,    KAMA,       5, RAgA,       PILLA,     3},
    {ANYMAG,    KAMA,      17, RAgA,       PILLA,     3},
    {ANYMAG,    MADHU,      5, RAgB,       TWINS,     3},
    {ANYMAG,    MADHU,     17, RAgB,       TWINS,     3},
    {ANYMAG,    NARAKA,     5, FOgA,       GOLLA,     3},
    {ANYMAG,    MARICA,     5, FOgB,       PILLA,     3},
    {ANYMAG,    ANDHAKA,   17, FOgC,       ESTLLA,    3},
  // POW > MIND > DEX
    {ANYMAG,    BHIRAVA,    6, HUgA,       PILLA,     3},
    {ANYMAG,    BHIRAVA,   18, HUgA,       PILLA,     3},
    {ANYMAG,    APSARAS,    6, HUgB,       ESTLLA,    3},
    {ANYMAG,    APSARAS,   18, HUgB,       ESTLLA,    3},
    {ANYMAG,    BHIRAVA,    6, RAgA,       PILLA,     3},
    {ANYMAG,    BHIRAVA,   18, RAgA,       PILLA,     3},
    {ANYMAG,    KAITABHA,   6, RAgB,       TWINS,     3},
    {ANYMAG,    KAITABHA,  18, RAgB,       TWINS,     3},
    {ANYMAG,    RAVANA,     6, FOgA,       FARLLA,    3},
    {ANYMAG,    NAGA,       6, FOgB,       TWINS,     3},
    {ANYMAG,    ANDHAKA,   18, FOgC,       ESTLLA,    3},
  // DEX > POW > MIND
    {ANYMAG,    ILA,        7, HUgA,       TWINS,     3},
    {ANYMAG,    ILA,       19, HUgA,       TWINS,     3},
    {ANYMAG,    GARUDA,     7, HUgB,       PILLA,     3},
    {ANYMAG,    GARUDA,    19, HUgB,       PILLA,     3},
    {ANYMAG,    BHIRAVA,    7, RAgA,       PILLA,     3},
    {ANYMAG,    BHIRAVA,   19, RAgA,       PILLA,     3},
    {ANYMAG,    KAITABHA,   7, RAgB,       TWINS,     3},
    {ANYMAG,    KAITABHA,  19, RAgB,       TWINS,     3},
    {ANYMAG,    RIBHAVA,    7, FOgA,       FARLLA,    3},
    {ANYMAG,    GARUDA,     7, FOgB,       PILLA,     3},
    {ANYMAG,    BANA,      19, FOgC,       ESTLLA,    3},
  // DEX > MIND >= POW
    {ANYMAG,    NANDIN,     8, HUgA,       ESTLLA,    3},
    {ANYMAG,    NANDIN,    20, HUgA,       ESTLLA,    3},
    {ANYMAG,    YAKSA,      8, HUgB,       GOLLA,     3},
    {ANYMAG,    YAKSA,     20, HUgB,       GOLLA,     3},
    {ANYMAG,    KAMA,       8, RAgA,       PILLA,     3},
    {ANYMAG,    KAMA,      20, RAgA,       PILLA,     3},
    {ANYMAG,    VARAHA,     8, RAgB,       GOLLA,     3},
    {ANYMAG,    VARAHA,    20, RAgB,       GOLLA,     3},
    {ANYMAG,    SITA,       8, FOgA,       PILLA,     3},
    {ANYMAG,    BHIRAVA,    8, FOgB,       PILLA,     3},
    {ANYMAG,    BANA,      20, FOgC,       ESTLLA,    3},
  // MIND > POW >= DEX
    {ANYMAG,    KABANDA,    9, HUgA,       TWINS,     3},
    {ANYMAG,    KABANDA,   21, HUgA,       TWINS,     3},
    {ANYMAG,    BANA,       9, HUgB,       ESTLLA,    3},
    {ANYMAG,    BANA,      21, HUgB,       ESTLLA,    3},
    {ANYMAG,    VARAHA,     9, RAgA,       GOLLA,     3},
    {ANYMAG,    VARAHA,    21, RAgA,       GOLLA,     3},
    {ANYMAG,    KABANDA,    9, RAgB,       TWINS,     3},
    {ANYMAG,    KABANDA,   21, RAgB,       TWINS,     3},
    {ANYMAG,    NAGA,       9, FOgA,       TWINS,     3},
    {ANYMAG,    KUMARA,     9, FOgB,       GOLLA,     3},
    {ANYMAG,    BANA,      21, FOgC,       ESTLLA,    3},
  // MIND > DEX > POW
    {ANYMAG,    USHASU,     9, HUgA,       GOLLA,     3},
    {ANYMAG,    USHASU,    21, HUgA,       GOLLA,     3},
    {ANYMAG,    SOMA,       9, HUgB,       ESTLLA,    3},
    {ANYMAG,    SOMA,      21, HUgB,       ESTLLA,    3},
    {ANYMAG,    APSARAS,    9, RAgA,       ESTLLA,    3},
    {ANYMAG,    APSARAS,   21, RAgA,       ESTLLA,    3},
    {ANYMAG,    DURGA,      9, RAgB,       ESTLLA,    3},
    {ANYMAG,    DURGA,     21, RAgB,       ESTLLA,    3},
    {ANYMAG,    KABANDA,    9, FOgA,       TWINS,     3},
    {ANYMAG,    ILA,        9, FOgB,       TWINS,     3},
    {ANYMAG,    BANA,      21, FOgC,       ESTLLA,    3},
  // Other
    {ANYMAG,    VARAHA,    23, HUgA,       GOLLA,     3},
    {ANYMAG,    BHIRAVA,   34, HUgA,       PILLA,     3},
    {ANYMAG,    KAMA,      23, HUgB,       PILLA,     3},
    {ANYMAG,    APSARAS,   24, HUgB,       ESTLLA,    3},
    {ANYMAG,    BHIRAVA,   25, RAgA,       PILLA,     3},
    {ANYMAG,    KAMA,      26, RAgA,       PILLA,     3},
    {ANYMAG,    KAITABHA,  25, RAgB,       TWINS,     3},
    {ANYMAG,    VARAHA,    26, RAgB,       GOLLA,     3},
    {ANYMAG,    NAGA,      27, FOgA,       TWINS,     3},
    {ANYMAG,    KABANDA,   28, FOgA,       TWINS,     3},
    {ANYMAG,    KUMARA,    27, FOgB,       GOLLA,     3},
    {ANYMAG,    ILA,       28, FOgB,       TWINS,     3},
    {ANYMAG,    MANA,      29, FOgC,       ESTLLA,    3},
  // Tier 4
    {ANYMAG,    RATI,      30, HUgM&T4gA,  NOPHOTON,  4},
    {ANYMAG,    SAVITRI,   30, HUgF&T4gA,  NOPHOTON,  4},
    {ANYMAG,    PUSHAN,    30, RAgM&T4gA,  NOPHOTON,  4},
    {ANYMAG,    DIWARI,    30, RAgF&T4gA,  NOPHOTON,  4},
    {ANYMAG,    NIDRA,     30, FOgM&T4gA,  NOPHOTON,  4},
    {ANYMAG,    BHIMA,     30, FOgF&T4gA,  NOPHOTON,  4},
    {ANYMAG,    DEVA,      30, HUgM&T4gB,  NOPHOTON,  4},
    {ANYMAG,    SAVITRI,   30, HUgF&T4gB,  NOPHOTON,  4},
    {ANYMAG,    PUSHAN,    30, RAgM&T4gB,  NOPHOTON,  4},
    {ANYMAG,    RUKMIN,    30, RAgF&T4gB,  NOPHOTON,  4},
    {ANYMAG,    NIDRA,     30, FOgM&T4gB,  NOPHOTON,  4},
    {ANYMAG,    SATO,      30, FOgF&T4gB,  NOPHOTON,  4},
    {ANYMAG,    RATI,      30, HUgM&T4gC,  NOPHOTON,  4},
    {ANYMAG,    SAVITRI,   30, HUgF&T4gC,  NOPHOTON,  4},
    {ANYMAG,    PUSHAN,    30, RAgM&T4gC,  NOPHOTON,  4},
    {ANYMAG,    RUKMIN,    30, RAgF&T4gC,  NOPHOTON,  4},
    {ANYMAG,    NIDRA,     30, FOgM&T4gC,  NOPHOTON,  4},
    {ANYMAG,    BHIMA,     30, FOgF&T4gC,  NOPHOTON,  4}
}

// checks a mag for cell usage and adds the cells to the table
HIDDEN void checkCells(mag_t* checkedMag, mag_t** toAddList)
{
    mag_t* m = NULL;
    int magLevel = checkedMag->levels[0] + 
                   checkedMag->levels[1] + 
                   checkedMag->levels[2] +
                   checkedMag->levels[3];

    // mark 3
    if (magLevel >= 5 && magLevel < 10)
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFMARK3);
        addHistory(m,0xFFFFFF41); // char level 65+
        m->type = MARK3;
        addMag(m,toAddList);
    }


    // level 50+
    if(magLevel >= 50)
    {
        // Kapu Kapu
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFKAPUKAPU);
        m->type = KAPUKAPU;
        addMag(m,toAddList);

        //Chu Chu
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFCHUCHU);
        m->type = CHUCHU;
        addMag(m,toAddList);

        // Panzer Tail
        if (checkedMag->type == NAGA)
        {
            m = copyMag(checkedMag);
            addHistory(m,PANTHERSSPIRIT);
            m->type = PANZERTAIL;
            addMag(m,toAddList);
        }

        // Hamburger
        if (checkedMag->type == KAIDABHA)
        {
            m = copyMag(checkedMag);
            addHistory(m,KITOFHAMBURGER);
            m->type = HAMBURGER;
            addMag(m,toAddList);
        }

        // Master System
        if (checkedMag->type == MARK3)
        {
            m = copyMag(checkedMag);
            addHistory(m,KITOFMASTERSYSTEM);
            addHistory(m,0xFFFFFF46); // char level 70+
            m->type = MASTERSYSTEM;
            addMag(m,toAddList);
        }
    }

    // Genesis
    if (magLevel >= 70 &&
        checkedMag->type == MASTERSYSTEM)
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFGENESIS);
        addHistory(m,0xFFFFFF50); // char level 80+
        m->type = GENESIS;
        addMag(m,toAddList);
    }

    // Sega Saturn
    if (magLevel >= 90 &&
        checkedMag->type == GENESIS)
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFSEGASATURN);
        addHistory(m,0xFFFFFF5A); // char level 90+
        m->type = SEGASATURN;
        addMag(m,toAddList);
    }

    // Dreamcast
    if (magLevel == 101 &&
        checkedMag->type == SEGASATURN)
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFDREAMCAST);
        addHistory(m,0xFFFFFF64); // char level 100+
        m->type = DREAMCAST;
        addMag(m,toAddList);
    }

    // level 100+
    if (magLevel >= 100)
    {
        // Churel
        m = copyMag(checkedMag);
        addHistory(m,CELLOFMAG213);
        addHistory(m,0xF0F8FF00); // Viridia, Skyly, Purplenum, Redria, Yellowboze, All Classes
        m->type = CHUREL;
        addMag(m,toAddList);

        // Soniti
        m = copyMag(checkedMag);
        addHistory(m,CELLOFMAG502);
        addHistory(m,0xF0F8FF00); // Viridia, Skyly, Purplenum, Redria, Yellowboze, All Classes
        m->type = SONITI;
        addMag(m,toAddList);

        // Pretra
        m = copyMag(checkedMag);
        addHistory(m,CELLOFMAG213);
        addHistory(m,0xFF04FF00); // Greenil, Bluefull, Pinkal,Whitil, Oran, All Classes
        m->type = PRETRA;
        addMag(m,toAddList);

        // Pitri
        m = copyMag(checkedMag);
        addHistory(m,CELLOFMAG502);
        addHistory(m,0xFF04FF00); // Greenil, Bluefull, Pinkal,Whitil, Oran, All Classes
        m->type = PITRI;
        addMag(m,toAddList);

        // Opa Opa
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFOPAOPA);
        m->type = OPAOPA;
        addMag(m,toAddList);

        // Devil Wings
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFDEVIL);
        addHistory(m,0xFFFFDF00); // no cast
        m->type = DEVILWINGS;
        addMag(m,toAddList);

        // Devil Tail
        if (checkedMag->type == DEVILTAIL)
        {
            m = copyMag(checkedMag);
            addHistory(m,HEARTOFDEVIL);
            m->type = DEVILTAIL;
            addMag(m,toAddList);
        }

        // Angel Wings
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFANGEL);
        addHistory(m,0xFFFFDF00); // no cast
        m->type = ANGELWINGS;
        addMag(m,toAddList);
    }

    // Pian
    if (magLevel >= 120)
    {
        if (checkedMag->iq == 180 && checkedMag->sync == 120)
        {
            m = copyMag(checkedMag);
            addHistory(m,HEARTOFPIAN);
            m->type = PIAN;
            addMag(m,toAddList);
        }
    }

    // Chao
    if (checkedMag->levels[0] > 35 &&
        checkedMag->levels[1] > 35 &&
        checkedMag->levels[2] > 35 &&
        checkedMag->levels[3] > 35 )
    {
        m = copyMag(checkedMag);
        addHistory(m,HEARTOFCHAO);
        m->type = CHAO;
        addMag(m,toAddList);
    }

    // RoboChao
    if ((checkedMag->levels[0] > 70 && checkedMag->levels[1] > 70) ||
        (checkedMag->levels[0] > 70 && checkedMag->levels[2] > 70) ||
        (checkedMag->levels[0] > 70 && checkedMag->levels[3] > 70) ||
        (checkedMag->levels[1] > 70 && checkedMag->levels[2] > 70) ||
        (checkedMag->levels[1] > 70 && checkedMag->levels[3] > 70) ||
        (checkedMag->levels[2] > 70 && checkedMag->levels[3] > 70))
    {
        m = copyMag(checkedMag);
        addHistory(m,PARTSOFROBOCHAO);
        m->type = ROBOCHAO;
        addMag(m,toAddList);
    }
}

HIDDEN int statCheck(int id, mag_t* mag)
{
    int d = mag->levels[0];
    int p = mag->levels[1];
    int x = mag->levels[2];
    int m = mag->levels[3];
    int lvl = d + p + x + m;

    switch(id)
    {
        case 0 : return (lvl >= 10);
        case 1 : return (p > x && p > m && lvl >= 35);
        case 2 : return (x > p && x > m && lvl >= 35);
        case 3 : return (m > p && m > x && lvl >= 35);
        case 4 : return ((m == x && m > p) || (m == p && m > x) || (p >= x && p > m) && lvl >= 35);
        case 5 : return (p > x && x >= m && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 6 : return (p > m && m > x && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 7 : return (x > p && p > m && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 8 : return (x > m && m >= p && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 9 : return (m > p && p >= x && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 10: return (m > x && x > p && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 11: return ((p == x || p == m || m == x) && x >= m && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 12: return ((p == x || p == m || m == x) && m > x && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 13: return ((p == x || p == m || m == x) && p > m && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 14: return ((p == x || p == m || m == x) && m >= p && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 15: return ((p == x || p == m || m == x) && p >= x && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 16: return ((p == x || p == m || m == x) && x > p && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 17: return (p > x && x >= m && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 18: return (p > m && m > x && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 19: return (x > p && p > m && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 20: return (x > m && m >= p && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 21: return (m > p && p >= x && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 22: return (m > x && x > p && d >= 45  && lvl >= 50 && lvl%5 == 0);
        case 23: return ((p == x || p == m || m == x) && x >= m && lvl >= 50 && lvl%5 == 0);
        case 24: return ((p == x || p == m || m == x) && m > x && lvl >= 50 && lvl%5 == 0);
        case 25: return ((p == x || p == m || m == x) && p > m && lvl >= 50 && lvl%5 == 0);
        case 26: return ((p == x || p == m || m == x) && m >= p && lvl >= 50 && lvl%5 == 0);
        case 27: return ((p == x || p == m || m == x) && x > p && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 28: return ((p == x || p == m || m == x) && p >= x && d < 45 && lvl >= 50 && lvl%5 == 0);
        case 29: return ((p == x || p == m || m == x) && d >= 45 && lvl >= 50 && lvl%5 == 0);
        case 30: return ((d + p) == (x + m) && lvl >= 100 && lvl%5 == 0);
        case 31: return ((d + x) == (p + m) && lvl >= 100 && lvl%5 == 0);
        case 32: return ((d + m) == (p + x) && lvl >= 100 && lvl%5 == 0);
        case default: return FALSE;
    }
    return FALSE;
}

HIDDEN void addHistory(mag_t* mag, int item)
{
    history_t* newHistory = malloc(sizeof(history_t));
    newHistory->itemcode = item;
    newHistory->next = mag->history;
    mag->history = newHistory;
}

HIDDEN void evolve(mag_t* m, mag_t** toAddList)
{
    
    int currentT = NULL;
    for ( int i = 112; i > 0; i-- ) // Go backwards so we do t4 first
    {
        if (statCheck(EvolutionChart[2], m) && m->type == EvolutionChart[0]) 
        {
            if (EvolutionChart[5] != currentT) return;
            currentT = EvolutionChart[5];

            mag_t* n = copyMag(m);
            addHistory(n,0xE0000000&n->type);
            addHistory(n,EvolutionChart[3]);
            n->type = EvolutionChart[1];
            addPhoton(n,EvolutionChart[4]);
            addMag(n,toAddList);
        }
    }
    checkCells(m, toAddList);
    return;
}

// feeds a specific item
HIDDEN void feedItem(mag_t* m, mag_t** toAddList, int item)
{
    int tableId = getTableId(m->type);

    m->percents[DEF] += getItemBoost(tableId, item, DEF);
    m->percents[POWER] += getItemBoost(tableId, item, POWER);
    m->percents[DEX] += getItemBoost(tableId, item, DEX);
    m->percents[MIND] += getItemBoost(tableId, item, MIND);
    m->iq += getItemBoost(tableId, item, IQ);
    m->sync += getItemBoost(tableId, item, SYNC);

    evolve(m, toAddList);
}

// feeds a given mag all items it can be fed
// and evolves that mag if applicable
void feed(mag_t* m, mag_t** toAddList)
{
    for(int i=0; i < 11; i++)
        feedItem(m, toAddList, feedableItems[i]);
}
