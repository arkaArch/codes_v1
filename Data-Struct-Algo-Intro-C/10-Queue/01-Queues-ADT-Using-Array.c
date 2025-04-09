// Queue -> [F]irst [I]n [F]irst [O]ut
#include <stdio.h>
#include <stdlib.h>
 
struct Queue {
    int size;
    int front;
    int rear;
    // If we use one pointer(only rear) dequeue will take O(N);
    int *Q;
};

// The drawbacks of Queue using Array are:
// The space can't be re-use. 
// That is when we delete an element we can't use the space for insert again. 
// Even if queue is empty (front == rear), for the condition (front == size - 1) 
// we can't insert any element. Though this can be setteled by resettling the pointers
// --> see "dequeue()" method but that works(reuse the spaces) iff the queue is empty.

// Insert an element in Queue
void enqueue(struct Queue *q) {
    // Check if there is an empty position for enqueue
    if(q->front >= q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    int element;
    printf("Enter the element to be added: ");
    scanf("%d", &element);
    // Forward "front" by 1 and assign the element
    q->Q[++ q->front] = element;
}

// Delete an element
void dequeue(struct Queue *q) {
    // Check if the queue is empty
    if(q->front == q->rear) {
        // Re-settle the pointer for use the queue again
        q->front = q->rear = -1;
        printf("Queue is empty.\n");
        return;
    }
    // Forward "rear" by 1 and remove the element
    printf("Removed %d.\n", q->Q[++ q->rear]);
}

void display(struct Queue *q) {
    printf("( ");
    for(int i = q->rear + 1; i <= q->front; i ++)
        printf("%d ", q->Q[i]);
    printf(")\n");
}

int main() {
    struct Queue queue;
    printf("Enter the size of the queue: ");
    scanf("%d", &queue.size);
    queue.Q = (int *)malloc(sizeof(int) * queue.size);

    // First assign both front and rear to -1;
    queue.front = queue.rear = -1;

    int choice;
    while(1) {
        printf("1. Enter an element in queue\n");
        printf("2. Delete an element from queue\n");
        printf("3. Display queue\n");
        printf("4. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(&queue);
                break;
            case 2: dequeue(&queue);
                break;
            case 3: display(&queue);
                break;
            case 4: exit(1);
            default: printf("Wrong input.\n");
        }
    }
    return 0;
}
