#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

vector* createVect() {
    vector* new = (vector*)malloc(sizeof(vector));
    new->head = NULL;
    new->tail = NULL;
    new->length = 0;
    return new;
}

node_v* createVectNode(int value) {
    node_v* result = (node_v*)malloc(sizeof(node_v));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

node_v* getElement(vector** vect, int index) {
    int len = (*vect)->length;
    if (index > len - 1 || index < 0) {
        return NULL;
    } else if (index > len / 2) {
        int indexFromTail = len - 1;
        node_v* tmp = (*vect)->tail;
        while(indexFromTail > index) {
            tmp = tmp->prev;
            indexFromTail--;
        }
        return tmp;
    } else {
        int indexFromHead = 0;
        node_v* tmp = (*vect)->head;
        while (indexFromHead < index) {
            tmp = tmp->next;
            indexFromHead++;
        }
        return tmp;
    }
}

void printVect(vector* vect) {
    node_v* tmp = vect->head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void printVectRev(vector* vect) {
    node_v* tmp = vect->tail;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->prev;
    }
    printf("\n");
}

void addEnd(vector** vect, int value) {
    node_v* tmp = (*vect)->tail;
    node_v* new_node = createVectNode(value);
    if (tmp == NULL) {
        (*vect)->tail = new_node;
        (*vect)->head = (*vect)->tail;
        (*vect)->length++;
    } else {
        new_node->next = NULL;
        new_node->prev = tmp;
        tmp->next = new_node;
        (*vect)->tail = new_node;
        (*vect)->length++;
    }
}

void addHead(vector** vect, int value) {
    node_v* tmp = (*vect)->head;
    node_v* new_node = createVectNode(value);
    if (tmp == NULL) {
        (*vect)->head = new_node;
        (*vect)->tail = (*vect)->head;
        (*vect)->length++;
    } else {
        new_node->next = tmp;
        new_node->prev = NULL;
        tmp->prev = new_node;
        (*vect)->head = new_node;
        (*vect)->length++;
    }
}

void removeElement(vector** vect, int index) {
    node_v* remove = getElement(vect, index);
    if (remove != NULL) {
        if (remove->prev == NULL) {
            (*vect)->head = remove->next;
            (*vect)->head->prev = NULL;
        } else if (remove->next == NULL) {
            (*vect)->tail = remove->prev;
            (*vect)->tail->next = NULL;
        } else {
            node_v* tmp_prev = remove->prev;
            node_v* tmp_next = remove->next;
            tmp_prev->next = remove->next;
            tmp_next->prev = remove->prev;
        }
        (*vect)->length--;
    }
    
    // The free may break things, have to be cautious
    free(remove);
    if (remove != NULL) 
        printf("FREE FAILED");
}

void pop(vector** vect) {
    removeElement(vect, (*vect)->length - 1);
}

void burst(vector** vect) {
    removeElement(vect, 0);
}

void hotSwap(vector** vect, int index) {
    if (index < (*vect)->length - 1) {
        node_v* self = getElement(vect, index);
        if (self != NULL) {
            int holder = self->value;
            self->value = self->next->value;
            self->next->value = holder;
        }
    }
}

void coldSwap(vector** vect, int index) {
    if (index > 0) {
        node_v* self = getElement(vect, index);
        if (self != NULL) {
            int holder = self->value;
            self->value = self->prev->value;
            self->prev->value = holder;
        }
    }
}

void vectSwap(vector** vect, int index_a, int index_b) {
    int len = (*vect)->length;
    if ((index_a < len) && (index_b < len) && (index_a >= 0) && (index_b >= 0)) {
        node_v* a = getElement(vect, index_a);
        node_v* b = getElement(vect, index_b);
        if (a != NULL && b != NULL) {
            int holder = a->value;
            a->value = b->value;
            b->value = holder;
        }
    }
}

void revalueElement(vector** vect, int index, int value) {
    getElement(vect, index)->value = value;
}