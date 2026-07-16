#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Add element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Remove element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}