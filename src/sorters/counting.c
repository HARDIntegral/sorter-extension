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
    // To make a linked list that will store the frequency of values
    node_t* count_head = NULL;
    for(int i = 0; i < power_10(highest_value(head)); i++) {
        add(&count_head, 0);
    }
    node_t* tmp_a = *head;
    node_t* current_node;
    // Populate the frequency list with the actual frequency of the values in the input list
    while(tmp_a != NULL) {
        for (int i = 0; i < length(&count_head); i++) {
            if (tmp_a->value == i) {
                current_node = getNode(&count_head, i);
                current_node->value = current_node->value + 1;
            }
        }
        tmp_a = tmp_a->next;
    }
    // Modify the frequency list to represent a cumulative frequency
    for (int i = 1; i <= length(&count_head) - 1; i++) {
        node_t* self = getNode(&count_head, i);
        node_t* before = getNode(&count_head, i - 1);
        self->value = self->value + before->value;
    }

    // Initialize a linked list and set all values to 0 as a default
    node_t* sorted_head = NULL;
    for (int i = 0; i < length(head); i++) {
        add(&sorted_head, 0);
    }

    // Swap values into the sorted list
    node_t* tmp_b = *head;
    while (tmp_b != NULL) {
        // TODO: Make the swapper
    }

    print(sorted_head);
}
