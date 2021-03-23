#ifndef VECT_H
#define VECT_H

struct element {
    int value;
    struct element* next;
    struct element* prev;
};
typedef struct element node_v;

struct vector {
    struct element* head;
    struct element *tail;
    int length;
};
typedef struct vector vector;

vector* createVect();
node_v* getElement(vector** vect, int index);
void printVect(vector* vect);
void printVectRev(vector* vect);
void addEnd(vector** vect, int value);
void addHead(vector** vect, int value);
void removeElement(vector** vect, int index);
void pop(vector** vect);
void burst(vector** vect);
void hotSwap(vector** vect, int index);
void coldSwap(vector** vect, int index);
void vectSwap(vector** vect, int index_a, int index_b);
void revalueElement(vector** vect, int index, int value);

#endif //vect_h