// Circular Queue -> We reuse the space of deleted element of queue
// Initially we set front & rear at position 0
// Using rear we'll insert and using front we'll delete
// Wherever front is pointing the position should be empty, if we move it
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q) {
    // Check if there is an empty space in queue
    if(q->front:)
}
