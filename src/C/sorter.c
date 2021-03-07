#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "includes/list.h"

int main() {
    node_t* head = NULL;
    
    for (int i = 0; i < 100; i++) {
        add(&head, i);
    }

    print(head);

    node_t* node = getNode(&head, 101);
    if (node != NULL) {
        printNode(node);
    } else {
        printf("NODE IS NULL\n");
    }    
}
