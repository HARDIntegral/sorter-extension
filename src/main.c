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

   node_v* head = NULL;
   node_v* tail = NULL;

   addEnd(&head, &tail, 8);
   addHead(&head, &tail, 5);
   addHead(&head, &tail, 7);
   addHead(&head, &tail, 23);

   printVect(head);
   printVectRev(tail);

   printf("Vector Length - %d\n", len(&head));
}
