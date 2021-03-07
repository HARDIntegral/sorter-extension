#ifndef LIST_H
#define LIST_H

struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

void print(node_t* head);
void printNode(node_t* node);
void add(node_t** head, int value);
int length(node_t** head);
node_t* getNode(node_t** head, int index);

#endif //list_h