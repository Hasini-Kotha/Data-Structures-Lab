#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

// Initialize the hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key
void insert(int key) {
    int index = hashFunction(key);
    struct Node* current = hashTable[index];

    // Check if key already exists
    while (current != NULL) {
        if (current->data == key) {
            printf("Key %d already exists in the hash table.\n", key);
            return;
        }
        current = current->next;
    }

    // Insert at beginning
    struct Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Key %d inserted at index %d.\n", key, index);
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    struct Node* current = hashTable[index];

    while (current != NULL) {
        if (current->data == key) {
            return index;
        }
        current = current->next;
    }

    return -1;
}

// Delete a key
void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* current = hashTable[index];
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                hashTable[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Key %d deleted from index %d.\n", key, index);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Display the hash table
void display() {
    printf("\nHash Table (Separate Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* current = hashTable[i];
        if (!current) {
            printf("EMPTY");
        }
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function with menu
int main() {
    int choice, key;
    initialize();

    do {
        printf("\n--- Hash ADT using Separate Chaining ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index;
                index = search(key);
                if (index == -1) {
                    printf("Key %d not found in the hash table.\n", key);
                } else {
                    printf("Key %d found at index %d.\n", key, index);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
