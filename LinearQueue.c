// WAP to implement linear queue enqueuing any 5 elements
#include <stdio.h>
#define MAX_SIZE 5

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue any more elements.\n");
    } else {
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Enqueued element: %d\n", item);
    }
}

void display(struct Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    return 0;
}
