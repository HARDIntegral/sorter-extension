#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
    if (index > length(head)) {
        return NULL;
    }
    while (i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}
