#include <stdio.h>

#include "../h/types.h"
#include "../h/const.h"
#include "../h/feed.h"
#include "../h/maglist.h"
#include "../h/magManagment.h"


HIDDEN char buffer[BUFFERSIZE];

// returning 1 surpresses the repeat number
HIDDEN int itemCodeString(int code)
{
    // clear buffer
    for(int i = 0; i < BUFFERSIZE; i++)
        buffer[i] = "\0";

    // fill buffer
    switch(code)
    {
    // items
        case MONOMATE:
            buffer = "Monomate              x"; return 0;
        case DIMATE:
            buffer = "Dimate                x"; return 0;
        case TRIMATE:
            buffer = "Trimate               x"; return 0;
        case MONOFLUID:
            buffer = "Monofluid             x"; return 0;
        case DIFLUID:
            buffer = "Difluid               x"; return 0;
        case TRIFLUID:
            buffer = "Trifluid              x"; return 0;
        case ANTIDOTE:
            buffer = "Antidote              x"; return 0;
        case ANTIPARALYSIS:
            buffer = "Antiparalysis         x"; return 0;
        case SOLATOMIZER:
            buffer = "Sol Atomizer          x"; return 0;
        case MOONATOMIZER:
            buffer = "Moon Atomizer         x"; return 0;
        case STARATOMIZER:
            buffer = "Star Atomizer         x"; return 0;

    // cells
        case CELLOFMAG502:
            buffer = "Cell of Mag 502       x"; return 0;
        case CELLOFMAG213:
            buffer = "Cell of Mag 213       x"; return 0;
        case PARTSOFROBOCHAO:
            buffer = "Parts of RoboChao     x"; return 0;
        case HEARTOFOPAOPA:
            buffer = "Heart of OpaOpa       x"; return 0;
        case HEARTOFPIAN:
            buffer = "Heart of Pian         x"; return 0;
        case HEARTOFCHAO:
            buffer = "Heart of Chao         x"; return 0;
        case HEARTOFCHUCHU:
            buffer = "Heart of ChuChu       x"; return 0;
        case PARTSOFEGGBLASTER:
            buffer = "Parts of Egg Blaster  x"; return 0;
        case HEARTOFANGEL:
            buffer = "Heart of Angel        x"; return 0;
        case HEARTOFDEVIL:
            buffer = "Heart of Devil        x"; return 0;
        case KITOFHAMBURGER:
            buffer = "Kit of Hamburger      x"; return 0;
        case PANTHERSSPIRIT:
            buffer = "Panther's Spirit      x"; return 0;
        case KITOFMARK3:
            buffer = "Kit of MARK3          x"; return 0;
        case KITOFMASTERSYSTEM:
            buffer = "Kit of MASTER SYSTEM  x"; return 0;
        case KITOFGENESIS:
            buffer = "Kit of GENESIS        x"; return 0;
        case KITOFSEGASATURN:
            buffer = "Kit of SEGA SATURN    x"; return 0;
        case KITOFDREAMCAST:
            buffer = "Kit of DREAMCAST      x"; return 0;
        case HEARTOFKAPUKAPU:
            buffer = "Heart of KapuKapu     x"; return 0;
        case TABLET:
            buffer = "Tablet                x"; return 0;
        case DRAGONSCALE:
            buffer = "Dragon Scale          x"; return 0;
        case HEAVENSTRIKERCOAT:
            buffer = "Heaven Striker Coat   x"; return 0;
        case PIONEERPARTS:
            buffer = "Pioneer Parts         x"; return 0;
        case AMITIESMEMO:
            buffer = "Amitie's Memo         x"; return 0;
        case HEARTOFMOROLIAN:
            buffer = "Heart of Morolian     x"; return 0;
        case RAPPYSBEAK:
            buffer = "Rappy's Beak          x"; return 0;
        case ULTIMAENGINE:
            buffer = "Yahoo!'s' Engine      x"; return 0;
        case DPHOTONCORE:
            buffer = "Photon D-Core         x"; return 0;
        case LIBERTAKIT:
            buffer = "Libera Kit            x"; return 0;
        case CELLOFMAG0503:
            buffer = "Cell of Mag 503       x"; return 0;
        case CELLOFMAG0504:
            buffer = "Cell of Mag 504       x"; return 0;
        case CELLOFMAG0505:
            buffer = "Cell of Mag 505       x"; return 0;
        case CELLOFMAG0506:
            buffer = "Cell of Mag 506       x"; return 0;
        case CELLOFMAG0507:
            buffer = "Cell of Mag 507       x"; return 0;
        case ASHURAMAGCELL:
            buffer = "Heart of YN-1107      x"; return 0; // Subject to change?

    // codes
        case 0xE0000000:
            buffer = "0 Def Mag"; return 1;
        case default:
            // we're dealing with a wierd ood thing from documentation
            if (code&0xE0000000 == 0xE0000000) // E code
            {
                int type = code&0x0FFFFFFF; // get just the type out

                switch(type)
                {
                    case MAG:           buffer = "Evolve into MAG\n"; return 1;
                    case VARUNA:        buffer = "Evolve into VARUNA\n"; return 1;
                    case VRITA:         buffer = "Evolve into VRITA\n"; return 1;
                    case KALKI:         buffer = "Evolve into KALKI\n"; return 1;
                    case ASHVINAU:      buffer = "Evolve into ASHVINAU\n"; return 1;
                    case SUMBA:         buffer = "Evolve into SUMBA\n"; return 1;
                    case NAMUCI:        buffer = "Evolve into NAMUCI\n"; return 1;
                    case MARUTAH:       buffer = "Evolve into MARUTAH\n"; return 1;
                    case RUDRA:         buffer = "Evolve into RUDRA\n"; return 1;
                    case SURYA:         buffer = "Evolve into SURYA\n"; return 1;
                    case TAPAS:         buffer = "Evolve into TAPAS\n"; return 1;
                    case MITRA:         buffer = "Evolve into MITRA\n"; return 1;
                    case APSARAS:       buffer = "Evolve into APSARAS\n"; return 1;
                    case VAYU:          buffer = "Evolve into VAYU\n"; return 1;
                    case VARAHA:        buffer = "Evolve into VARAHA\n"; return 1;
                    case USHASU:        buffer = "Evolve into USHASU\n"; return 1;
                    case KAMA:          buffer = "Evolve into KAMA\n"; return 1;
                    case KAIDABHA:      buffer = "Evolve into KAIDABHA\n"; return 1;
                    case KUMARA:        buffer = "Evolve into KUMARA\n"; return 1;
                    case BHIRAVA:       buffer = "Evolve into BHIRAVA\n"; return 1;
                    case ILA:           buffer = "Evolve into ILA\n"; return 1;
                    case GARUDA:        buffer = "Evolve into GARUDA\n"; return 1;
                    case SITA:          buffer = "Evolve into SITA\n"; return 1;
                    case SOMA:          buffer = "Evolve into SOMA\n"; return 1;
                    case DURGA:         buffer = "Evolve into DURGA\n"; return 1;
                    case NANDIN:        buffer = "Evolve into NANDIN\n"; return 1;
                    case YAKSA:         buffer = "Evolve into YAKSA\n"; return 1;
                    case RIBHAVA:       buffer = "Evolve into RIBHAVA\n"; return 1;
                    case RATI:          buffer = "Evolve into RATI\n"; return 1;
                    case ANDHAKA:       buffer = "Evolve into ANDHAKA\n"; return 1;
                    case KABANDA:       buffer = "Evolve into KABANDA\n"; return 1;
                    case NAGA:          buffer = "Evolve into NAGA\n"; return 1;
                    case NARAKA:        buffer = "Evolve into NARAKA\n"; return 1;
                    case BANA:          buffer = "Evolve into BANA\n"; return 1;
                    case MARICA:        buffer = "Evolve into MARICA\n"; return 1;
                    case MADHU:         buffer = "Evolve into MADHU\n"; return 1;
                    case RAVANA:        buffer = "Evolve into RAVANA\n"; return 1;
                    case BHIMA:         buffer = "Evolve into BHIMA\n"; return 1;
                    case PUSHAN:        buffer = "Evolve into PUSHAN\n"; return 1;
                    case SAVITRI:       buffer = "Evolve into SAVITRI\n"; return 1;
                    case DIWARI:        buffer = "Evolve into DIWARI\n"; return 1;
                    case NIDRA:         buffer = "Evolve into NIDRA\n"; return 1;
                    case DEVA:          buffer = "Evolve into DEVA\n"; return 1;
                    case RUKMIN:        buffer = "Evolve into RUKMIN\n"; return 1;
                    case SATO:          buffer = "Evolve into SATO\n"; return 1;
                    case CHUREL:        buffer = "Evolve into CHUREL\n"; return 1;
                    case PRETRA:        buffer = "Evolve into PRETRA\n"; return 1;
                    case PITRI:         buffer = "Evolve into PITRI\n"; return 1;
                    case SONITI:        buffer = "Evolve into SONITI\n"; return 1;
                    case CHUCHU:        buffer = "Evolve into CHUCHU\n"; return 1;
                    case OPAOPA:        buffer = "Evolve into OPAOPA\n"; return 1;
                    case KAPUKAPU:      buffer = "Evolve into KAPUKAPU\n"; return 1;
                    case CHAO:          buffer = "Evolve into CHAO\n"; return 1;
                    case ROBOCHAO:      buffer = "Evolve into ROBOCHAO\n"; return 1;
                    case PIAN:          buffer = "Evolve into PIAN\n"; return 1;
                    case PANZERTAIL:    buffer = "Evolve into PANZER TAIL\n"; return 1;
                    case DEVILWINGS:    buffer = "Evolve into DEVIL WINGS\n"; return 1;
                    case DEVILTAIL:     buffer = "Evolve into DEVIL TAIL\n"; return 1;
                    case ANGELWINGS:    buffer = "Evolve into ANGEL WINGS\n"; return 1;
                    case HAMBURGER:     buffer = "Evolve into HAMBURGER\n"; return 1;
                    case MARK3:         buffer = "Evolve into MARK3\n"; return 1;
                    case MASTERSYSTEM:  buffer = "Evolve into MASTER SYSTEM\n"; return 1;
                    case GENESIS:       buffer = "Evolve into GENESIS\n"; return 1;
                    case SEGASATURN:    buffer = "Evolve into SEGA SATURN\n"; return 1;
                    case DREAMCAST:     buffer = "Evolve into DREAMCAST\n"; return 1;
                    
                    case default:
                        buffer = "ERROR READING CODE     "; 
                        return 0;
                }

            }

            if (code&0xF0000000 == 0xF0000000) // F code
            {
                printf("With IDs:\n");
                if (code&BLUEFULL)   printf(" - Bluefull\n");
                if (code&GREENILL)   printf(" - Greenill\n");
                if (code&ORAN)       printf(" - Oran\n");
                if (code&PINKAL)     printf(" - Pinkal\n");
                if (code&PURPLENUM)  printf(" - Purplenum\n");
                if (code&REDRIA)     printf(" - Redria\n");
                if (code&SKYLY)      printf(" - Skyly\n");
                if (code&VIRIDIA)    printf(" - Viridia\n");
                if (code&YELLOWBOZE) printf(" - Yellowboze\n");
                if (code&WHITILL)    printf(" - Whitill\n");

                printf("On Classes:")
                if (code&HUMAR)      printf(" - HUmar\n");
                if (code&HUNEWEARL)  printf(" - HUnewearl\n");
                if (code&HUCAST)     printf(" - HUcast\n");
                if (code&HUCASEAL)   printf(" - HUcaseal\n");
                if (code&RAMAR)      printf(" - RAmar\n");
                if (code&RAMARL)     printf(" - RAmarl\n");
                if (code&RACAST)     printf(" - RAcast\n");
                if (code&RACASEAL)   printf(" - RAcaseal\n");
                if (code&FOMAR)      printf(" - FOmar\n");
                if (code&FOMARL)     printf(" - FOmarl\n");
                if (code&FONEWM)     printf(" - FOnewm\n");
                if (code&FONEWEARL)  printf(" - FOnewearl\n");

                if (code&LEVELSEC)
                    printf("On a character of level %d", code&LEVELSEC);
                return 1;
            }

            buffer = "ERROR READING CODE     "; 
            return 0;
    }
}

HIDDEN void printHistory(mag_t* m)
{
    history_t* reverse = NULL;
    history_t* current = NULL;
    while(m->history != NULL)
    {
        current = m->history;
        m->history = current->next;
        current->next = reverse;
        reverse = current;
    }

    int itemcode = NULL;
    int lastItemCode = NULL;
    int repeated = 0;
    int surpressed = 0;
    history_t* tmp = NULL;
    while(reverse != NULL)
    {
        itemcode = reverse->itemcode;
        if (itemcode == lastItemCode || lastItemCode == NULL)
        {
            // we're repeating an item
            repeated = repeated + 1;
        } else {
            // we're to a new itemcode
            surpressed = itemCodeString(lastItemCode);
            printf("%s",buffer);
            if (surpressed == 0) printf("%d", repeated);
            printf("\n");
            repeated = 1;
        }
        lastItemCode = itemcode;

        // move reverse and delete old one
        tmp = reverse;
        reverse = reverse->next;
        free(tmp);
    }
    free(m);
}

int main()
{    

    // define final (this will later go in as param)
    mag_t* final = malloc(sizeof(mag_t));
    final->type = SATO;
    final->levels[0] = 5;
    final->levels[1] = 150;
    final->levels[2] = 45;
    final->levels[3] = 0;
    final->photon[0] = NOPHOTON;
    final->photon[1] = NOPHOTON;
    final->photon[2] = NOPHOTON;

    mag_t** toCheck = NULL;
    addMag(newMag(FALSE), toCheck); // add normal mag
    addMag(newMag(TRUE), toCheck);  // add 0 def mag

    mag_t* working = NULL;
    do
    {
        if (working) // this will only trigger if we failed compare check at end
            free(working); 

        working = removeMag(m, toCheck);

        // this triggers feed, evolve, and checkCells
        // and appends them all to toCheck
        feed(m, toCheck);
            //evolve (done in feed())
            //checkCells (done in feed())
        deleteMag(working);
    } 
    while (!compareMag(working,final) && working != NULL);

    if (compareMag(working, final))
    {
        // found
        printHistory(working);
        deleteMag(working);
        return TRUE;
    }

    // not found
    printf("No Feed Plan Found.");
    return FALSE;
}