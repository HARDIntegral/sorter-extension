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
    /*
    Im testing the vector file, this sort of works for the counting sort file

    node_t* head = NULL;
    
    for (int i = 0; i < 20; i++) {
        add(&head, rand() % 10);
    }

    print(head);
    counting_sort(&head);
    */

    vector* vect1 = createVect();

    addEnd(&vect1, 8);
    addHead(&vect1, 5);
    addHead(&vect1, 7);
    addHead(&vect1, 23);
    addEnd(&vect1, 6);

    printVect(vect1);
    printVectRev(vect1);

    revalueElement(&vect1, 3, 34);

    printVect(vect1);
    printVectRev(vect1);

    printf("vect1 length - %d\n",vect1->length);
}
