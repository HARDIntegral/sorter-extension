#ifndef LIST_H
#define LIST_H

struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

void print(node_t* head);
void printNode(node_t* node);
node_t* getNode(node_t** head, int index);
void add(node_t** head, int value);
void insert(node_t** head, int value, int index);
int length(node_t** head);
void removeNode(node_t** head, int index);
void insertNode(node_t** head, int value, int index);
void swap(node_t** head, int index_a, int index_b);
void revalue(node_t** head, int index, int value);

#endif //list_h