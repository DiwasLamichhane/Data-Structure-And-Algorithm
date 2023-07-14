// WAP to implement a circular queue by enqueuing any 5 elements.
#include <stdio.h>
#define MAX_SIZE 5

// Structure to represent a circular queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to check if the queue is full
int isFull(CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->front == queue->rear;
}

// Function to enqueue an element
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element %d\n", value);
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("Enqueued element: %d\n", value);
}

// Function to print the queue
void display(CircularQueue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = queue->front + 1; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    queue.front = MAX_SIZE - 1;
    queue.rear = MAX_SIZE - 1;

    // Enqueue 5 elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Display the queue
    display(&queue);

    return 0;
}
