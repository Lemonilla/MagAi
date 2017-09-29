#include "../h/types.h"
#include "../h/const.h"
#include "../e/feed.e"
#include "../e/maglist.e"
#include "../e/magManagment.e"

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

#define HUgA        0xF0F80400
#define HUgB        0xFF040400
#define RAgA        0xF0F80200
#define RAgB        0xFF040200
#define FOgA        0xF0F80100
#define FOgB        0xFF040100
#define FOgC        0xFFFF0100


// ( Startmag, EndMag, Check, HistoryCode, PhotonBlast )   
HIDDEN int EvolutionChart[][5] = {
  //Tier 1  
    {MAG,       VARUNA,     0, 0xFFFFFC00, FARLLA},
    {MAG,       KALKI,      0, 0xFFFFFA00, ESTLLA},
    {MAG,       VRITRA,     0, 0xFFFFF900, LEILLA},
  // Tier 2
    {VARUNA,    RUDRA,      1, 0xF0000000, GOLLA },
    {VARUNA,    MARUTAH,    2, 0xF0000000, PILLA },
    {VARUNA,    VAYU,       3, 0xF0000000, TWINS },
    {VARUNA,    RUDRA,      4, 0xF0000000, GOLLA },
    {KALKI,     SURYA,      1, 0xF0000000, GOLLA },
    {KALKI,     MITRA,      2, 0xF0000000, PILLA },
    {KALKI,     TAPAS,      3, 0xF0000000, TWINS },
    {KALKI,     MITRA,      4, 0xF0000000, PILLA },
    {VRITRA,    SUMBA,      1, 0xF0000000, GOLLA },
    {VRITRA,    ASHVINAU,   2, 0xF0000000, PILLA },
    {VRITRA,    NAMUCI,     3, 0xF0000000, TWINS },
    {VRITRA,    NAMUCI,     4, 0xF0000000, TWINS },
  // Tier 3
  // POW > DEX >= MIND
    {ANYMAG,    VARAHA,     5, HUgA,       GOLLA },
    {ANYMAG,    VARAHA,    17, HUgA,       GOLLA },
    {ANYMAG,    KAMA,       5, HUgB,       PILLA },
    {ANYMAG,    KAMA,      17, HUgB,       PILLA },
    {ANYMAG,    KAMA,       5, RAgA,       PILLA },
    {ANYMAG,    KAMA,      17, RAgA,       PILLA },
    {ANYMAG,    MADHU,      5, RAgB,       TWINS },
    {ANYMAG,    MADHU,     17, RAgB,       TWINS },
    {ANYMAG,    NARAKA,     5, FOgA,       GOLLA },
    {ANYMAG,    MARICA,     5, FOgB,       PILLA },
    {ANYMAG,    ANDHAKA,   17, FOgC,       ESTLLA},
  // POW > MIND > DEX
    {ANYMAG,    BHIRAVA,    6, HUgA,       PILLA },
    {ANYMAG,    BHIRAVA,   18, HUgA,       PILLA },
    {ANYMAG,    APSARAS,    6, HUgB,       ESTLLA},
    {ANYMAG,    APSARAS,   18, HUgB,       ESTLLA},
    {ANYMAG,    BHIRAVA,    6, RAgA,       PILLA },
    {ANYMAG,    BHIRAVA,   18, RAgA,       PILLA },
    {ANYMAG,    KAITABHA,   6, RAgB,       TWINS },
    {ANYMAG,    KAITABHA,  18, RAgB,       TWINS },
    {ANYMAG,    RAVANA,     6, FOgA,       FARLLA},
    {ANYMAG,    NAGA,       6, FOgB,       TWINS },
    {ANYMAG,    ANDHAKA,   18, FOgC,       ESTLLA},
  // DEX > POW > MIND
    {ANYMAG,    ILA,        7, HUgA,       TWINS },
    {ANYMAG,    ILA,       19, HUgA,       TWINS },
    {ANYMAG,    GARUDA,     7, HUgB,       PILLA },
    {ANYMAG,    GARUDA,    19, HUgB,       PILLA },
    {ANYMAG,    BHIRAVA,    7, RAgA,       PILLA },
    {ANYMAG,    BHIRAVA,   19, RAgA,       PILLA },
    {ANYMAG,    KAITABHA,   7, RAgB,       TWINS },
    {ANYMAG,    KAITABHA,  19, RAgB,       TWINS },
    {ANYMAG,    RIBHAVA,    7, FOgA,       FARLLA},
    {ANYMAG,    GARUDA,     7, FOgB,       PILLA },
    {ANYMAG,    BANA,      19, FOgC,       ESTLLA},
  // DEX > MIND >= POW
    {ANYMAG,    NANDIN,     8, HUgA,       ESTLLA},
    {ANYMAG,    NANDIN,    20, HUgA,       ESTLLA},
    {ANYMAG,    YAKSA,      8, HUgB,       GOLLA },
    {ANYMAG,    YAKSA,     20, HUgB,       GOLLA },
    {ANYMAG,    KAMA,       8, RAgA,       PILLA },
    {ANYMAG,    KAMA,      20, RAgA,       PILLA },
    {ANYMAG,    VARAHA,     8, RAgB,       GOLLA },
    {ANYMAG,    VARAHA,    20, RAgB,       GOLLA },
    {ANYMAG,    SITA,       8, FOgA,       PILLA },
    {ANYMAG,    BHIRAVA,    8, FOgB,       PILLA },
    {ANYMAG,    BANA,      20, FOgC,       ESTLLA},
  // MIND > POW >= DEX
    {ANYMAG,    KABANDA,    9, HUgA,       TWINS },
    {ANYMAG,    KABANDA,   21, HUgA,       TWINS },
    {ANYMAG,    BANA,       9, HUgB,       ESTLLA},
    {ANYMAG,    BANA,      21, HUgB,       ESTLLA},
    {ANYMAG,    VARAHA,     9, RAgA,       GOLLA },
    {ANYMAG,    VARAHA,    21, RAgA,       GOLLA },
    {ANYMAG,    KABANDA,    9, RAgB,       TWINS },
    {ANYMAG,    KABANDA,   21, RAgB,       TWINS },
    {ANYMAG,    NAGA,       9, FOgA,       TWINS },
    {ANYMAG,    KUMARA,     9, FOgB,       GOLLA },
    {ANYMAG,    BANA,      21, FOgC,       ESTLLA},
  // MIND > DEX > POW
    {ANYMAG,    USHASU,     9, HUgA,       GOLLA },
    {ANYMAG,    USHASU,    21, HUgA,       GOLLA },
    {ANYMAG,    SOMA,       9, HUgB,       ESTLLA},
    {ANYMAG,    SOMA,      21, HUgB,       ESTLLA},
    {ANYMAG,    APSARAS,    9, RAgA,       ESTLLA},
    {ANYMAG,    APSARAS,   21, RAgA,       ESTLLA},
    {ANYMAG,    DURGA,      9, RAgB,       ESTLLA},
    {ANYMAG,    DURGA,     21, RAgB,       ESTLLA},
    {ANYMAG,    KABANDA,    9, FOgA,       TWINS },
    {ANYMAG,    ILA,        9, FOgB,       TWINS },
    {ANYMAG,    BANA,      21, FOgC,       ESTLLA},
  // Other
    


}

HIDDEN void addHistory(mag_t* mag, int item)
{
    history_t* newHistory = malloc(sizeof(history_t));
    newHistory->itemcode = item;
    newHistory->next = mag->history;
    mag->history = newHistory;
}

HIDDEN evolve(mag_t* m, mag_t** toAddList)
{
    for ( int i = 0; i < ; i++ ) 
    {
        if (statCheck(EvolutionChart[2]) && m->type == EvolutionChart[0]) 
        {
            mag_t* n = copyMag(m);
            addHistory(n,EvolutionChart[3]);
            n->type = EvolutionChart[1];
            addPhoton(n,EvolutionChart[4]);
            addMag(n,toAddList);
        }
    }
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
void feed(mag_t* m, mag_t** toAddList)
{
    for(int i=0; i < 11; i++)
        feedItem(m, toAddList, feedableItems[i]);
}

// checks a mag for cell usage and adds the cells to the table
void checkCells(mag_t* checkedMag, mag_t** toAddList)
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
        m->type = DEVILWINGS;
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
        (checkedMag->type == MARK3 || checkedMag->type == MASTERSYSTEM))
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFGENESIS);
        addHistory(m,0xFFFFFF50); // char level 80+
        m->type = GENESIS;
        addMag(m,toAddList);
    }

    // Sega Saturn
    if (magLevel >= 90 &&
        (checkedMag->type == MARK3 ||
         checkedMag->type == MASTERSYSTEM ||
         checkedMag->type == GENESIS))
    {
        m = copyMag(checkedMag);
        addHistory(m,KITOFSEGASATURN);
        addHistory(m,0xFFFFFF5A); // char level 90+
        m->type = SEGASATURN;
        addMag(m,toAddList);
    }

    // Dreamcast
    if (magLevel == 101 &&
        (checkedMag->type == MARK3 ||
         checkedMag->type == MASTERSYSTEM ||
         checkedMag->type == GENESIS ||
         checkedMag->type == SEGASATURN))
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
