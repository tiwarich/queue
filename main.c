#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
bool isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = item;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // You can choose a different value for underflow
    } else {
        int item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // If there is only one element in the queue
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

// Function to peek at the front element of the queue without removing it
int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // You can choose a different value for an empty queue
    } else {
        return queue->items[queue->front];
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element after dequeue: %d\n", peek(&queue));

    return 0;
}
