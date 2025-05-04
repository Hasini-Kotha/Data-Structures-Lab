#include <cstdio>
#include <cstdlib>

// Creating a list and node 
class list {
    struct node {
        int data;
        struct node *next;
        struct node *prev;
    };
    struct node *head;
    struct node *tail;

public:
    // Constructor
    list() {
        head = NULL;
        tail = NULL;
    }

    // Function prototypes
    int insertBegin(int);
    int insertEnd(int);
    int insertPos(int, int);
    int deleteBegin();
    int deleteEnd();
    int deletePos(int);
    void display();
    int search(int);
};

int main() {
    int choice, value, pos, result, target;
    list list1;
    printf("\n");
    do {
        printf("MENU CARD\n");
        printf("Enter 1: To Insert the element at the Beginning of the List\n");
        printf("Enter 2: To Insert the element at the End of the List\n");
        printf("Enter 3: To Insert the element at a Specific Position of the List\n");
        printf("Enter 4: To Delete the element at the Beginning of the List\n");
        printf("Enter 5: To Delete the element at the End of the List\n");
        printf("Enter 6: To Delete the element at a Specific Position of the List\n");
        printf("Enter 7: To Search the element in the List\n");
        printf("Enter 8: To Display the elements of the List\n");
        printf("Enter 9: To Exit the Program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert in the List: ");
                scanf("%d", &value);
                list1.insertBegin(value);
                break;
            case 2:
                printf("Enter the element to insert in the List: ");
                scanf("%d", &value);
                list1.insertEnd(value);
                break;
            case 3:
                printf("Enter the element to insert in the List: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                list1.insertPos(pos, value);
                break;
            case 4:
                result = list1.deleteBegin();
                if (result != 0) {
                    printf("The value of the node deleted is: %d\n", result);
                }
                break;
            case 5:
                result = list1.deleteEnd();
                if (result != 0) {
                    printf("The value of the node deleted is: %d\n", result);
                }
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                result = list1.deletePos(pos);
                if (result != 0) {
                    printf("The value of the node deleted is: %d\n", result);
                }
                break;
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                result = list1.search(target);
                if (result != -1) {
                    printf("The element found in the list\n");
                    printf("The position of the element in the list is: %d\n", result);
                } else {
                    printf("Element not found in the list\n");
                }
                break;
            case 8:
                list1.display();
                break;
            case 9:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid choice\n");
                printf("Enter a choice between 1 to 9\n");
                break;
        }
    } while (choice != 9);
    return 0;
}

// Function to insert at the beginning
int list::insertBegin(int value) {
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return 1;
    }
    head->prev = newnode;
    head = newnode;
    return 1;
}

// Function to insert at the end
int list::insertEnd(int value) {
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
        return 1;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return 1;
}

// Function to insert at a specific position
int list::insertPos(int pos, int value) {
    if (pos < 1) {
        printf("Invalid position\n");
        return 0;
    }
    if (pos == 1) {
        return insertBegin(value);
    }
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position is not available in the list\n");
        printf("Enter a valid position number\n\n");
        free(newnode);
        return 0;
    }
    if (temp == tail) {
        return insertEnd(value);
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    temp = newnode->next;
    temp->prev = newnode;
    return 1;
}

// Function to delete from the beginning
int list::deleteBegin() {
    if (head == NULL) {
        printf("The list is empty\n");
        return 0;
    }
    if (head == tail) {
       struct node *temp = head;
        int result = head->data;
        head = NULL;
        tail = NULL;
        free(temp);
        printf("All elements in the list are deleted\n");
        return result;
    }
   struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    int result = temp->data;
    free(temp);
    return result;
}

// Function to delete from the end
int list::deleteEnd() {
    if (tail == NULL) {
        printf("The list is empty\n");
        return 0;
    } 
    if (tail == head) {
        return deleteBegin();
    }
    struct node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    int result = temp->data;
    free(temp);
    return result;
}

// Function to delete at a specific position
int list::deletePos(int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return 0;
    }
    if (pos == 1) {
        return deleteBegin();
    }
    struct node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp == tail) {
        printf("There is no such position in the list to delete\n");
        printf("Enter a valid position\n");
        return 0;
    }
    if (tail == temp->next) {
        return deleteEnd();
    }
    struct  node *del = temp->next;
    temp->next = del->next;
    int result = del->data;
    temp = del->next;
    temp->prev = del->prev;
    free(del);
    return result;
}

// Function to search for an element
int list::search(int target) {
    if (head == NULL) {
        printf("The list is empty\n");
        return 0;
    }
   struct node *temp = head;
    int count = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

// Function to display the list
void list::display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    struct node *temp1 = tail;

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Reverse: ");
    while (temp1 != NULL) {
        printf("%d\t", temp1->data);
        temp1 = temp1->prev;
    }
    printf("\n");
}
