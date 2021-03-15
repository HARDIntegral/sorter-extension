#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../includes/list.h"

int highest_value(node_t** head) {
    node_t* tmp = *head;
    int i = 0;
    while(tmp != NULL) {
        if (tmp->value > i) {
            i = tmp->value;
        }
        tmp = tmp->next;
    }
    return i;
}

int power_10(int highest_value) {
    int i = 1;
    while(!(i >= highest_value)) {
        i *= 10;
    }
    return i;
}

void counting_sort(node_t** head) {
    node_t* count_head = NULL;
    for(int i = 0; i < power_10(highest_value(head)); i++) {
        add(&count_head, 0);
    }
    node_t* tmp = *head;
    node_t* current_node;
    while(tmp != NULL) {
        for (int i = 0; i < length(&count_head); i++) {
            if (tmp->value % (i + 1) == 0) {
                current_node = getNode(&count_head, i);
                current_node->value = current_node->value + 1;
            }
        }
        tmp = tmp->next;
    }
    print(count_head);
}
