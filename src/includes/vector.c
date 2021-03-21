#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
 * Structure: element
 * ------------------------------------------------
 * Groups the value of an element of a vector along
 * with the pointers to the next and previous 
 * elements of the same vector.
 */
struct element {
    int value;
    struct element* next;
    struct element* prev;
};
typedef struct element node_v;

/*
 * Structure: vector
 * ------------------------------------------------
 * Groups together the pointers to the head and 
 * tail of the vector along with its length.
 */
struct vector {
    struct element* head;
    struct element *tail;
    int length;
};
typedef struct vector vector;

/*
 * Function: createVect
 * ------------------------------------------------
 * Creates a vector and initializes its values
 * 
 * returns: type vector
 */
vector* createVect() {
    vector* new = (vector*)malloc(sizeof(vector));
    new->head = NULL;
    new->tail = NULL;
    new->length = 0;
    return new;
}

/*
 * Function: createVectNode
 * ------------------------------------------------
 * Creates and initializes a new node of a vector.
 * To be used to be inserted as an element of a
 * vector.
 * 
 * value:   the value the element in the vector 
 *          should contain.
 * 
 * returns: type element
 */
node_v* createVectNode(int value) {
    node_v* result = (node_v*)malloc(sizeof(node_v));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

/*
 * Function: getElement
 * ------------------------------------------------
 * Returns an element from a vector froma a given 
 * index. Iterates through the vector from the most
 * efficient end.
 * 
 * vect:    the address of an existing vector
 * index:   the index of the vector requested
 * 
 * returs:  type element
 */
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

/*
 * FUNCTION: printVect
 * ------------------------------------------------
 * Iterates though the vector starting from the 
 * head of the vector. Prints vector in order.
 * 
 * vect: the vector
 * 
 * returns: void    
 */
void printVect(vector* vect) {
    node_v* tmp = vect->head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

/*
 * FUNCTION: printVectRev
 * ------------------------------------------------
 * Iterates though the vector starting from the 
 * tail of the vector. Prints vector in reverse
 * order.
 * 
 * vect:    the vector
 * 
 * returns: void    
 */
void printVectRev(vector* vect) {
    node_v* tmp = vect->tail;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->prev;
    }
    printf("\n");
}

/*
 * Function: addEnd
 * ------------------------------------------------
 * Adds an element to the end of the vector.
 * 
 * vect:    the address of an existing vector
 * value:   the value the element is to contain
 * 
 * returns: void
 */
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

/*
 * Function: addHead
 * ------------------------------------------------
 * Adds an element to the beginning of the vector.
 * 
 * vect:    the address of an existing vector
 * value:   the value the element is to contain
 * 
 * returns: void
 */
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

/*
 * Function: removeElement
 * ------------------------------------------------
 * Removes an element from a vector at a specific 
 * index.
 * 
 * vect:    the address of an existing vector
 * index:   the index of the element to remove
 */
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
}

/*
 * Function: pop
 * ------------------------------------------------
 * Removes the last element in a vector.
 * 
 * vect:    the address of an existing vector
 * 
 * returns: void 
 */
void pop(vector** vect) {
    (*vect)->tail = (*vect)->tail->prev;
}

/*
 * Function: burst
 * ------------------------------------------------
 * Removes the first element in a vector.
 * 
 * vect:    the address of an existing vector
 * 
 * returns: void 
 */
void burst(vector** vect) {
    (*vect)->head = (*vect)->head->next;
}

/*
 * Function: hotSwap
 * ------------------------------------------------
 * Swaps the values of an element in vector at a 
 * given index with the value of an element at the 
 * next index.
 * 
 * vect:    the address of an existing vector
 * index:   the index of the vector to hot swap
 * 
 * returns: void 
 */
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

/*
 * Function: coldSwap
 * ------------------------------------------------
 * Swaps the values of an element in vector at a 
 * given index with the value of an element at the 
 * next index.
 * 
 * vect:    the address of an existing vector
 * index:   the index of the vector to cold swap
 * 
 * returns: void 
 */
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

/*
 * Function: swap
 * ------------------------------------------------
 * Swaps the values of an element in a vector at a 
 * given index with another element in the same 
 * vector in another index. 
 * 
 * vect:    the address of an existing vector
 * index_a: one of the indicies for value swapping
 * index_b: the other index for value swapping
 * 
 * returns: void
 */
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

/*
 * Function: revalueElement
 * ------------------------------------------------
 * Revalues an element in a vector at a given index
 * with a provided value.
 * 
 * vect:    the address of an existing vector
 * index:   the index of the vector to revalue
 * value:   the new value the element
 * 
 * returns: void
 */
void revalueElement(vector** vect, int index, int value) {
    getElement(vect, index)->value = value;
}