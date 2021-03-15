#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../includes/list.h"

void bubble_sort(node_t** head) {
    int len = length(head);
    int i = 0;
    while (i < len - 1) {
        int j = 0;
        while (j < len - i - 1) {
            node_t* node_a = getNode(head, j);
            node_t* node_b = getNode(head, j + 1);
            if (node_a->value > node_b->value) {
                swap(head, j, j + 1);
            }
            j++;
        }
        i++;
    }
}