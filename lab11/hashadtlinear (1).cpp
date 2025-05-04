#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Function to insert a key using linear probing
void insert(int key) {
    int index = key % TABLE_SIZE;
    int start = index;

    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        if (hashTable[index] == key) {
            printf("Key %d already exists in the table.\n", key);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d inserted successfully.\n", key);
}

// Function to search for a key
int search(int key) {
    int index = key % TABLE_SIZE;
    int start = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            break;
        }
    }
    return -1;
}

// Function to delete a key
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found. Cannot delete.\n", key);
    } else {
        hashTable[index] = DELETED;
        printf("Key %d deleted successfully.\n", key);
    }
}

// Function to display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else if (hashTable[i] == DELETED) {
            printf("Index %d: DELETED\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

// Main function with menu
int main() {
    int choice, key;
    initialize();

    do {
        printf("\n--- Hash ADT using Linear Probing ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
