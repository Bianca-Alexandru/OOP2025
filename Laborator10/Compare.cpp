#include "Compare.h"

int Compare::CompareElements(void* e1, void* e2)
{
    int* elem1 = static_cast<int*>(e1);
    int* elem2 = static_cast<int*>(e2);

    if (*elem1 < *elem2) {
        return -1;
    }
    else if (*elem1 > *elem2) {
        return 1;
    }
    else {
        return 0;
    }
};
