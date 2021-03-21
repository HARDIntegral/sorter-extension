#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX(a, b) (((x) >= (y)) ? (x) : (y))
#define MIN(a, b) (((x) <= (y)) ? (x) : (y))

/*
 * Structure: node
 * ------------------------------------------------
 * Groups the value of an node of a list along
 * with the pointer to the next node of the same 
 * list.
 */
struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

/*
 * FUNCTION: print
 * ------------------------------------------------
 * Iterates though the list starting from the 
 * head of the list. Prints list in order.
 * 
 * head:    the head of the list
 * 
 * returns: void    
 */
void print(node_t* head) {
    node_t* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

/*
 * Function: print
 * ------------------------------------------------
 * Prints the value of an individual node.
 * 
 * node:    the node of which contains the value to 
 *          print
 * 
 * returns: void
 */
void printNode(node_t* node) {
    printf("%d\n", node->value);
}

/*
 * Function: createListNode
 * ------------------------------------------------
 * Creates and initializes a new node of a list. To 
 * be used to be inserted as an node of a list.
 * 
 * value:   the value the node in the list should 
 *          contain.
 * 
 * returns: type node
 */
node_t* createListNode(int value) {
    node_t* result = (node_t*)malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

/*
 * Function: add
 * ------------------------------------------------
 * Adds a node to the end of the list.
 * 
 * head:    the address of the head of an existing
 *          list
 * value:   the value the node is to contain
 * 
 * returns: void
 */
void add(node_t** head, int value) {
    node_t* tmp = *head;
    node_t* new = createListNode(value);
    if (tmp == NULL) {
        *head = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

/*
 * Function: length
 * ------------------------------------------------
 * Determines the length of a list by iterating
 * through it starting from the head of the list.
 * 
 * head:    the address of the head of an existing 
 *          list
 * 
 * returns: int
 */
int length(node_t** head) {
    node_t* tmp = *head;
    int len = 0;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
}


/*
 * Function: getNode
 * ------------------------------------------------
 * Returns a node of a list at a specific index.
 * 
 * head:    the address of the head of an existing 
 *          list
 * index:   the index of the node that is requested
 * 
 * returns: type node
 */
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

/*
 * Function: removeNode
 * ------------------------------------------------
 * Removes a node of a list at a specific index.
 * 
 * head:    the address of the head of an existing 
 *          list
 * index:   the index of the node that is to be 
 *          removed
 * 
 * returns: void
 */
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

/*
 * Function: insertNode
 * ------------------------------------------------
 * Inserts a node into a list so that the new 
 * element of the list has a specific index.
 * 
 * head:    the address of the head of an existing 
 *          list
 * value:   the value the node
 * index:   the index of the node that is to be 
 *          inserted
 * 
 * returns: void
 */
void insertNode(node_t** head, int value, int index) {
    node_t* prev_node = getNode(head, index - 1);
    if (index < 0 || index > length(head)) {
        return;
    } else if (index == length(head) + 1) {
        add(head, value);
    } else {
        node_t* new_node = createListNode(value);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

/*
 * Function: swap
 * ------------------------------------------------
 * Swaps the values of two nodes of goven indicies.
 * 
 * head:    the address of the head of an existing 
 *          list
 * index_a: one of the indicies that would have its
 *          value swaped
 * index_b: the other index that would have its
 *          value swaped
 * 
 * returns: void
 */
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

/*
 * Function: revalue
 * ------------------------------------------------
 * Will revalue a node of a list at a given index.
 * 
 * head:    the address of the head of an existing 
 *          list
 * index:   the index of the node that is to be 
 *          revalued
 * value:   the new value the node
 * 
 * returns: void
 */
void revalue(node_t** head, int index, int value) {
    if (index < 0 || index > length(head)) {
        return;
    }
    node_t* element = getNode(head, index);
    element->value = value;
}
