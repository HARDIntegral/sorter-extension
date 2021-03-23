#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>

#include "../includes/vector.h"

int power10(int highest_value) {
    int i = 1;
    while(!(i >= highest_value))
        i *= 10;
    return i;
}

int highestValue(vector** vect) {
    node_v* tmp = (*vect)->head;
    int i = INT_MIN;
    while(tmp != NULL) {
        if(tmp->value > i)
            i = tmp->value;
        tmp = tmp->next;
    }
    return i;
}

void countingSort(vector** vect) {
    // Initialize a vector to contain counted elements to all values being 0
    vector* frequency = createVect();
    for(int i = 0; i < power10(highestValue(vect)); i++)
        addHead(&frequency, 0);
    
    // Counts the occurance of values in the original vector
    // Stores the frequency of values in the previously created vector
    node_v* tmp = (*vect)->head;
    while(tmp != NULL){
        revalueElement(
            &frequency, 
            tmp->value, 
            getElement(&frequency, tmp->value)->value + 1
        );
        tmp = tmp->next;
    }

    // Adds values of all preious elements to the current element of the frequency vector
    tmp = frequency->head;
    int indexCounter = 0;
    while(tmp != NULL){
        node_v* currentElement = getElement(&frequency, indexCounter);
        if (currentElement->prev != NULL)
            revalueElement(
                &frequency, 
                indexCounter, 
                currentElement->value + currentElement->prev->value
            );
        indexCounter++;
        tmp = tmp->next;
    }

    // Creates a new vector to store the sorted values
    vector* copy = createVect();
    for (int i = 0; i < (*vect)->length; i++)
        addHead(&copy, 0);

    // Sorting
    tmp = (*vect)->head;
    while(tmp != NULL) {
        node_v* currentCount = getElement(&frequency, tmp->value);
        revalueElement(&copy, currentCount->value-- - 1, tmp->value);
        tmp = tmp->next;
    }

    // Copies the values from the sorted vector to the original vector
    node_v* original = (*vect)->head;
    node_v* sorted = copy->head;
    indexCounter = 0;
    while (original != NULL) {
        revalueElement(vect, indexCounter, sorted->value);
        indexCounter++;
        original = original->next;
        sorted = sorted->next;
    }
}