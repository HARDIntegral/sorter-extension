#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX(a, b) (((x) >= (y)) ? (x) : (y))
#define MIN(a, b) (((x) <= (y)) ? (x) : (y))

struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

void print(node_t* head) {
    node_t* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void printNode(node_t* node) {
    printf("%d\n", node->value);
}

node_t* createNode(int value) {
    node_t* result = (node_t*)malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void add(node_t** head, int value) {
    node_t* tmp = *head;
    node_t* new = createNode(value);
    if (tmp == NULL) {
        *head = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int length(node_t** head) {
    node_t* tmp = *head;
    int len = 0;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
}

node_t* getNode(node_t** head, int index) {
    node_t* tmp = *head;
    int i = 0;
    if (index < 0 || index > length(head)) {
        return NULL;
    }
    while (i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

void removeNode(node_t** head, int index) {
    node_t* prev_node = getNode(head, index - 1);
    if (index < 0 || index > length(head)) {
        return;
    } else if (index == length(head)) {
        prev_node->next = NULL;
    } else {
        node_t* current_node = getNode(head, index);
        prev_node->next = current_node->next; 
        free(current_node);
        current_node = NULL;
    }
}

void insertNode(node_t** head, int value, int index) {
    node_t* prev_node = getNode(head, index - 1);
    if (index < 0 || index > length(head)) {
        return;
    } else if (index == length(head) + 1) {
        add(head, value);
    } else {
        node_t* new_node = createNode(value);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

void swap(node_t** head, int index_a, int index_b) {
    if (index_a < 0 || index_a > length(head) || index_b < 0 || index_b > length(head)) {
        return;
    } else {
        node_t* node_a = getNode(head, index_a);
        node_t* node_b = getNode(head, index_b);
        int tmp = node_a->value;
        node_a->value = node_b->value;
        node_b->value = tmp; 
    }
}

void revalue(node_t** head, int index, int value) {
    if (index < 0 || index > length(head)) {
        return;
    }
    node_t* element = getNode(head, index);
    element->value = value;
}
