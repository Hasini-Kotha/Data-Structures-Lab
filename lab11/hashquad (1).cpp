#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Insert key using Quadratic Probing
void insert(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Key %d inserted at index %d.\n", key, newIndex);
            return;
        } else if (hashTable[newIndex] == key) {
            printf("Key %d already exists in the table.\n", key);
            return;
        }
        i++;
    }

    printf("Hash table is full. Cannot insert key %d.\n", key);
}

// Search key
int search(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == EMPTY) {
            return -1; // Key not found
        }

        if (hashTable[newIndex] == key) {
            return newIndex; // Key found
        }

        i++;
    }

    return -1; // Key not found after full probe
}

// Delete key
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found. Cannot delete.\n", key);
    } else {
        hashTable[index] = DELETED;
        printf("Key %d deleted from index %d.\n", key, index);
    }
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
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
        printf("\n--- Hash ADT using Quadratic Probing ---\n");
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
