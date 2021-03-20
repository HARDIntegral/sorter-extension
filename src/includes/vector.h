#ifndef VECT_H
#define VECT_H

struct element {
    int value;
    struct element* next;
    struct element* prev;
};
typedef struct element node_v;

void printVect(node_v* head);
void printVectRev(node_v* tail);
int len(node_v** head);
void addEnd(node_v** head, node_v** tail, int value);
void addHead(node_v** head, node_v** tail, int value);

#endif //vect_h