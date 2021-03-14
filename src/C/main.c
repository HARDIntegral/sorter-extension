#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "includes/list.h"

int main() {
    node_t* head = NULL;
    
    for (int i = 0; i < 10; i++) {
        add(&head, i);
    }
    printf("length - %d\n", length(&head));
    print(head);

    node_t* node = getNode(&head, 11);
    if (node != NULL) {
        printNode(node);
    } else {
        printf("NODE IS NULL\n");
    }    

    removeNode(&head, 5);
    print(head);

    insertNode(&head, 5, 8);
    print(head);
}
