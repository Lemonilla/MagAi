#include "../h/const.h"
#include "../h/types.h"
#include "../e/maglist.e"


/****************** PRIVATE ******************/


// puts mag at end of list
HIDDEN void enqueMag(mag_t* m, mag_t** tp)
{
    // case 0
    if ((*tp) == NULL)
    {
        (*tp) = m;
        m->next = m;
        return;
    }

    // case 1+
    m->next = (*tp)->next;
    (*tp)->next = m;
    (*tp) = m;
}

// puts mag at front of list
HIDDEN void pushMag(mag_t* m, mag_t** tp)
{
    // case 0
    if ((*tp) == NULL)
    {
        (*tp) = m;
        m->next = m;
        return;
    }
    // case 1+ 
    m->next = (*tp)->next;
    (*tp)->next = m;
}

/****************** PUBLIC ******************/

// abstraction to easily change between a queue and stack
void addMag(mag_t* m, mag_t** tp)
{
    // change this when we decide on stack vs queue
    enqueMag(m,tp);
}

// remove top of list
mag_t* removeMag(mag_t** tp)
{
    // case 0
    if ((*tp) == NULL)
    {
        return NULL;
    }

    mag_t* m = (*tp)->next;
    // case 1
    if ((*tp)->next == (*tp))
    {
        m->next = NULL;
        (*tp) = NULL;
        return m;
    }

    // case 2+
    (*tp)->next = (*tp)->next->next;
    m->next = NULL;
    return m
}
