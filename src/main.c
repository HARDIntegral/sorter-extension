#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "includes/list.h"
#include "includes/vector.h"

#include "sorters/bubble.h"
#include "sorters/counting.h"
#include "sorters/heap.h"
#include "sorters/insertion.h"
#include "sorters/merge.h"
#include "sorters/quick.h"
#include "sorters/selection.h"

int main() {
    printf("\n");

    node_t* head = NULL;
    vector* vect1 = createVect();
    
    for (int i = 0; i < 20; i++) {
        add(&head, rand() % 10);
        addHead(&vect1, rand() % 100);
    }

    printVect(vect1);
    countingSort(&vect1);
    printVect(vect1);    
}
