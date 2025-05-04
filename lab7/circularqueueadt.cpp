#include <cstdio>
#include <cstdlib>

class circularQueue {
    int arr[5];
    int front, rear, count;
public:
    circularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    int enqueue(int);
    int dequeue();
    int peek();
    int is_empty();
    int is_full();
    void display();
};

int main() {
    circularQueue obj;
    int choice, value;
    do {
        printf("\n===Circular Queue Menu===\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                obj.enqueue(value);
                break;
            case 2:
                value = obj.dequeue();
                if (value != -1) {
                    printf("The element dequeued is %d\n", value);
                }
                break;
            case 3:
                value = obj.peek();
                if (value != -1) {
                    printf("The element at front is %d\n", value);
                }
                break;
            case 4:
                obj.display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

int circularQueue::is_empty() {
    return count == 0;
}

int circularQueue::is_full() {
    return count == 5;
}

int circularQueue::enqueue(int value) {
    if (is_full()) {
        printf("Queue Overflow!\n");
        return 0;
    }
    rear = (rear + 1) % 5;
    arr[rear] = value;
    count++;
    printf("%d is enqueued at position %d\n", value, rear);
    return 1;
}

int circularQueue::dequeue() {
    if (is_empty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % 5;
    count--;
    return value;
}

int circularQueue::peek() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    return arr[front];
}

void circularQueue::display() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[(front + i) % 5]);
    }
    printf("\n");
}
