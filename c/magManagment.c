#include "../h/const.h"
#include "../h/types.h"
#include "../e/magManagment.e"

HIDDEN void* feedTables;

void magManagmentInit()
{
    // TABLE   0     
    static int table0Row1[6] = {5,40,5,0,0,0};         // MONOMATE
    static int table0Row2[6] = {10,45,5,0,0,0};        // DIMATE
    static int table0Row3[6] = {15,50,10,0,0,0};       // TRIMATE
    static int table0Row4[6] = {5,0,5,40,0,0};         // MONOFLUID
    static int table0Row5[6] = {10,0,5,45,0,0};        // DIFLUID
    static int table0Row6[6] = {15,0,10,50,0,0};       // TRIFLUID
    static int table0Row7[6] = {5,10,40,0,0,0};        // ANTIDOTE
    static int table0Row8[6] = {5,0,44,10,0,0};        // ANTIPARALYSIS
    static int table0Row9[6] = {15,30,15,25,0,0};      // SOLATOMIZER
    static int table0RowA[6] = {15,25,15,30,0,0};      // MOONATOMIZER
    static int table0RowB[6] = {25,25,25,25,0,0};      // STARATOMIZER
    // TABLE 1       
    static int table1Row1[6] = {5,10,0,-1,0,0};        // MONOMATE
    static int table1Row2[6] = {6,15,3,-3,0,0};        // DIMATE
    static int table1Row3[6] = {12,21,4,-7,0,0};       // TRIMATE
    static int table1Row4[6] = {5,0,0,8,0,0};          // MONOFLUID
    static int table1Row5[6] = {7,0,3,13,0,0};         // DIFLUID
    static int table1Row6[6] = {7,-7,6,19,0,0};        // TRIFLUID
    static int table1Row7[6] = {0,5,15,0,0,0};         // ANTIDOTE
    static int table1Row8[6] = {-1,0,14,5,0,0};        // ANTIPARALYSIS
    static int table1Row9[6] = {10,11,8,0,0,0};        // SOLATOMIZER
    static int table1RowA[6] = {9,0,9,11,0,0};         // MOONATOMIZER
    static int table1RowB[6] = {14,9,18,11,0,0};       // STARATOMIZER
    // TABLE 2       
    static int table2Row1[6] = {1,9,0,-5,0,0};         // MONOMATE
    static int table2Row2[6] = {1,13,0,-10,0,0};       // DIMATE
    static int table2Row3[6] = {8,16,2,-15,0,0};       // TRIMATE
    static int table2Row4[6] = {0,-5,0,9,0,0};         // MONOFLUID
    static int table2Row5[6] = {4,-10,0,13,0,0};       // DIFLUID
    static int table2Row6[6] = {6,-15,5,17,0,0};       // TRIFLUID
    static int table2Row7[6] = {-5,4,12,-5,0,0};       // ANTIDOTE
    static int table2Row8[6] = {-5,-6,11,4,0,0};       // ANTIPARALYSIS
    static int table2Row9[6] = {0,11,3,-5,0,0};        // SOLATOMIZER
    static int table2RowA[6] = {4,-5,0,11,0,0};        // MOONATOMIZER
    static int table2RowB[6] = {7,8,6,9,0,0};          // STARATOMIZER
    // TABLE 3       
    static int table3Row1[6] = {0,3,0,0,0,0};          // MONOMATE
    static int table3Row2[6] = {5,7,0,-5,0,0};         // DIMATE
    static int table3Row3[6] = {4,14,6,-10,0,0};       // TRIMATE
    static int table3Row4[6] = {0,0,0,4,0,0};          // MONOFLUID
    static int table3Row5[6] = {4,-5,0,8,0,0};         // DIFLUID
    static int table3Row6[6] = {4,-10,3,15,0,0};       // TRIFLUID
    static int table3Row7[6] = {0,0,7,0,0,0};          // ANTIDOTE
    static int table3Row8[6] = {-4,-5,20,-5,0,0};      // ANTIPARALYSIS
    static int table3Row9[6] = {-10,9,6,9,0,0};        // SOLATOMIZER
    static int table3RowA[6] = {8,5,-8,7,0,0};         // MOONATOMIZER
    static int table3RowB[6] = {7,7,7,7,0,0};          // STARATOMIZER
    // TABLE 4       
    static int table4Row1[6] = {-5,9,-5,0,0,0};        // MONOMATE
    static int table4Row2[6] = {0,11,0,-10,0,0};       // DIMATE
    static int table4Row3[6] = {4,14,0,-15,0,0};       // TRIMATE
    static int table4Row4[6] = {-5,0,-6,10,0,0};       // MONOFLUID
    static int table4Row5[6] = {0,-10,0,11,0,0};       // DIFLUID
    static int table4Row6[6] = {4,-15,0,15,0,0};       // TRIFLUID
    static int table4Row7[6] = {-5,-5,16,-5,0,0};      // ANTIDOTE
    static int table4Row8[6] = {7,-3,0,-3,0,0};        // ANTIPARALYSIS
    static int table4Row9[6] = {5,21,-5,-20,0,0};      // SOLATOMIZER
    static int table4RowA[6] = {-5,-20,5,21,0,0};      // MOONATOMIZER
    static int table4RowB[6] = {4,6,8,5,0,0};          // STARATOMIZER
    // TABLE 5       
    static int table5Row1[6] = {-4,13,-5,-5,0,0};      // MONOMATE
    static int table5Row2[6] = {0,16,0,-15,0,0};       // DIMATE
    static int table5Row3[6] = {3,19,-2,-18,0,0};      // TRIMATE
    static int table5Row4[6] = {-4,-5,-5,13,0,0};      // MONOFLUID
    static int table5Row5[6] = {0,-15,0,16,0,0};       // DIFLUID
    static int table5Row6[6] = {3,-20,0,19,0,0};       // TRIFLUID
    static int table5Row7[6] = {5,-6,6,-5,0,0};        // ANTIDOTE
    static int table5Row8[6] = {0,-4,14,-10,0,0};      // ANTIPARALYSIS
    static int table5Row9[6] = {4,17,-5,-15,0,0};      // SOLATOMIZER
    static int table5RowA[6] = {-10,-15,5,21,0,0};     // MOONATOMIZER
    static int table5RowB[6] = {2,8,3,6,0,0};          // STARATOMIZER
     // TABLE 6       
    static int table6Row1[6] = {-3,9,-3,-4,0,0};       // MONOMATE
    static int table6Row2[6] = {0,11,0,-10,0,0};       // DIMATE
    static int table6Row3[6] = {2,15,0,-16,0,0};       // TRIMATE
    static int table6Row4[6] = {-3,-4,-3,9,0,0};       // MONOFLUID
    static int table6Row5[6] = {0,-10,0,11,0,0};       // DIFLUID
    static int table6Row6[6] = {-2,-15,0,19,0,0};      // TRIFLUID
    static int table6Row7[6] = {0,6,9,-15,0,0};        // ANTIDOTE
    static int table6Row8[6] = {0,-15,9,6,0,0};        // ANTIPARALYSIS
    static int table6Row9[6] = {9,-20,-5,17,0,0};      // SOLATOMIZER
    static int table6RowA[6] = {-5,20,5,-20,0,0};      // MOONATOMIZER
    static int table6RowB[6] = {0,11,0,11,0,0};        // STARATOMIZER
     // TABLE 7       
    static int table7Row1[6] = {-4,21,-15,-5,0,0};     // MONOMATE
    static int table7Row2[6] = {-1,27,-10,-16,0,0};    // DIMATE
    static int table7Row3[6] = {5,29,-7,-25,0,0};      // TRIMATE
    static int table7Row4[6] = {-10,-5,-10,21,0,0};    // MONOFLUID
    static int table7Row5[6] = {-5,-16,-5,25,0,0};     // DIFLUID
    static int table7Row6[6] = {-7,-25,6,29,0,0};      // TRIFLUID
    static int table7Row7[6] = {-10,-10,28,-10,0,0};   // ANTIDOTE
    static int table7Row8[6] = {9,-18,24,-15,0,0};     // ANTIPARALYSIS
    static int table7Row9[6] = {19,18,-15,-20,0,0};    // SOLATOMIZER
    static int table7RowA[6] = {-15,-20,19,18,0,0};    // MOONATOMIZER
    static int table7RowB[6] = {3,7,3,3,0,0};          // STARATOMIZER

    static void* table0[11] = {
            &table0Row1, &table0Row2, &table0Row3, &table0Row4, 
            &table0Row5, &table0Row6, &table0Row7, &table0Row8, 
            &table0Row9, &table0RowA, &table0RowB
    };
    static void* table1[11] = {
            &table1Row1, &table1Row2, &table1Row3, &table1Row4, 
            &table1Row5, &table1Row6, &table1Row7, &table1Row8, 
            &table1Row9, &table1RowA, &table1RowB
    };
    static void* table2[11] = {
            &table2Row1, &table2Row2, &table2Row3, &table2Row4, 
            &table2Row5, &table2Row6, &table2Row7, &table2Row8, 
            &table2Row9, &table2RowA, &table2RowB
    };
    static void* table3[11] = {
            &table3Row1, &table3Row2, &table3Row3, &table3Row4, 
            &table3Row5, &table3Row6, &table3Row7, &table3Row8, 
            &table3Row9, &table3RowA, &table3RowB
    };
    static void* table4[11] = {
            &table4Row1, &table4Row2, &table4Row3, &table4Row4, 
            &table4Row5, &table4Row6, &table4Row7, &table4Row8, 
            &table4Row9, &table4RowA, &table4RowB
    };
    static void* table5[11] = {
            &table5Row1, &table5Row2, &table5Row3, &table5Row4, 
            &table5Row5, &table5Row6, &table5Row7, &table5Row8, 
            &table5Row9, &table5RowA, &table5RowB
    };
    static void* table6[11] = {
            &table6Row1, &table6Row2, &table6Row3, &table6Row4, 
            &table6Row5, &table6Row6, &table6Row7, &table6Row8, 
            &table6Row9, &table6RowA, &table6RowB
    };
    static void* table7[11] = {
            &table7Row1, &table7Row2, &table7Row3, &table7Row4, 
            &table7Row5, &table7Row6, &table7Row7, &table7Row8, 
            &table7Row9, &table7RowA, &table7RowB
    };
    static void* tables[8] = {
        &table0, &table1, &table2, &table3,
        &table4, &table5, &table6, &table7
    };
    feedTables = &tables;
}

int getTableId(int magType)
{
    switch(magType)
    {
        case MAG:
            return 0;
        case VARUNA:
        case VRITA:
        case KALKI:
            return 1;
        case ASHVINAU:
        case SUMBA:
        case NAMUCI:
        case MARUTAH:
        case RUDRA: 
            return 2;
        case SURYA:
        case TAPAS:
        case MITRA:
            return 3;
        case APSARAS:
        case VAYU:
        case VARAHA:
        case USHASU:
        case KAMA:
        case KAITABHA:
        case KUMARA:
        case BHIRAVA:
            return 4;
        case ILA:
        case GARUDA:
        case SITA:
        case SOMA:
        case DURGA:
        case NANDIN:
        case YAKSA:
        case RIBHAVA:
        case DEVA:
        case RUKMIN:
        case SATO:
            return 5;
        case RATI:
        case ANDHAKA:
        case KABANDA:
        case NAGA:
        case NARAKA:
        case BANA:
        case MARICA:
        case MADHU:
        case RAVANA:
        case BHIMA:
        case PUSHAN:
            return 6;
        case SAVITRI:
        case DIWARI:
        case NIDRA:
        case CHUREL:
        case PRETRA:
        case PITRI:
        case SONITI:
        case CHUCHU:
        case OPAOPA:
        case KAPUKAPU:
        case CHAO:
        case ROBOCHAO:
        case PIAN:
        case PANZERTAIL:
        case DEVILWINGS:
        case DEVILTAIL:
        case ANGELWINGS:
        case HAMBURGER:
        case MARK:
        case MASTERSYSTEM:
        case GENESIS:
        case SEGASATURN:
        case DREAMCAST:
            return 7;
        case default:
            return NULL;
    }
}

int getItemBoost(int tableId, int itemIndex, int stat)
{
    return (*((*((*feedTables)[tableId]))[itemIndex]))[stat];
}

mag_t* copyMag(mag_t* m)
{
    mag_t* copy = malloc(sizeof(mag_t));
    copy->type = m->type;
    copy->iq = m->iq;
    copy->sync = m->sync;
    copy->levels[0] = m->levels[0];
    copy->levels[1] = m->levels[1];
    copy->levels[2] = m->levels[2];
    copy->levels[3] = m->levels[3];
    copy->percents[0] = m->percents[0];
    copy->percents[1] = m->percents[1];
    copy->percents[2] = m->percents[2];
    copy->percents[3] = m->percents[3];
    copy->photon[0] = m->photon[0];
    copy->photon[1] = m->photon[1];
    copy->photon[2] = m->photon[2];
    copy->next = NULL;

    history_t* h = m->history;
    while (h != NULL)
    {
        addHistory(copy,h->itemcode);
        h = h->next;
    }
    return copy;
}

