#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX(a, b) (((x) >= (y)) ? (x) : (y))
#define MIN(a, b) (((x) <= (y)) ? (x) : (y))

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
 * FUNCTION: printVect
 * ------------------------------------------------
 * Iterates though the vector starting from the 
 * head of the vector. Prints vector in order.
 * 
 * head: the head of the vector
 * 
 * returns: void    
 */
void printVect(node_v* head) {
    node_v* tmp = head;
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
 * tail:    the tail of the vector
 * 
 * returns: void    
 */
void printVectRev(node_v* tail) {
    node_v* tmp = tail;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->prev;
    }
    printf("\n");
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
 * Function: len
 * ------------------------------------------------
 * Determines the length of a vector by iterating
 * through it starting from the head of the vector.
 * 
 * head:    the head of the vector
 * 
 * returns: int
 */
int len(node_v** head) {
    node_v* tmp = *head;
    int len = 0;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
}

/*
 * Function: addEnd
 * ------------------------------------------------
 * Adds an element to the end of the vector.
 * 
 * &head:   the address of the head of an existing
 *          vector
 * &tail:   the address of the tail of an existing
 *          vector
 * value:   the value the element is to contain
 * 
 * returns: void
 */
void addEnd(node_v** head, node_v** tail, int value) {
    node_v* tmp = *tail;
    node_v* new_node = createVectNode(value);
    if (tmp == NULL) {
        *tail = new_node;
        *head = *tail;
    } else {
        new_node->next = NULL;
        new_node->prev = tmp;
        tmp->next = new_node;
        *tail = new_node;
    }
}

/*
 * Function: addHead
 * ------------------------------------------------
 * Adds an element to the beginning of the vector.
 * 
 * &head:   the address of the head of an existing
 *          vector
 * &tail:   the address of the tail of an existing
 *          vector
 * value:   the value the element is to contain
 * 
 * returns: void
 */
void addHead(node_v** head, node_v** tail, int value) {
    node_v* tmp = *head;
    node_v* new_node = createVectNode(value);
    if (tmp == NULL) {
        *head = new_node;
        *tail = *head;
    } else {
        new_node->next = tmp;
        new_node->prev = NULL;
        tmp->prev = new_node;
        *head = new_node;
    }
}
