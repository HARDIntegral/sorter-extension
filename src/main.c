#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "includes/list.h"

#include "sorters/bubble.h"
#include "sorters/counting.h"
#include "sorters/heap.h"
#include "sorters/insertion.h"
#include "sorters/merge.h"
#include "sorters/quick.h"
#include "sorters/selection.h"

int main() {
    node_t* head = NULL;
    
    for (int i = 0; i < 20; i++) {
        add(&head, rand() % 10);
    }

    print(head);
    counting_sort(&head);
}
