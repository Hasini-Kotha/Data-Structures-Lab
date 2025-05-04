#include <cstdio>
#include <cstdlib>

class tree {
    struct node {
        char data;
        struct node *left, *right;
    };
    struct node *root;
public:
    tree() {
        root = NULL;
    }
    void insert(char);
    void preorder();
    void inorder();
    void postorder();
    void search(char);
private:
    struct node* insert_node(struct node*, char);
    void preorder_traversal(struct node*);
    void inorder_traversal(struct node*);
    void postorder_traversal(struct node*);
    int search_node(struct node*, char);
};

int main() {
    tree t;
    int choice;
    char value;
    do {
        printf("\n===Tree Menu===\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter the choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the character to insert: ");
                scanf(" %c", &value);
                t.insert(value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                t.preorder();
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                t.inorder();
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                t.postorder();
                printf("\n");
                break;
            case 5:
                printf("Enter the character to search: ");
                scanf(" %c", &value);
                t.search(value);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    return 0;
}

void tree::insert(char value) {
    root = insert_node(root, value);
}

struct tree::node* tree::insert_node(struct node* temp, char value) {
    if (temp == NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        printf("Inserted '%c' in the tree.\n", value);
        return temp;
    }
    char dir;
    printf("Insert '%c' to left or right of '%c'? (L/R): ", value, temp->data);
    scanf(" %c", &dir);
    if (dir == 'L' || dir == 'l') {
        temp->left = insert_node(temp->left, value);
    } else {
        temp->right = insert_node(temp->right, value);
    }
    return temp;
}

void tree::preorder() {
    preorder_traversal(root);
}

void tree::inorder() {
    inorder_traversal(root);
}

void tree::postorder() {
    postorder_traversal(root);
}

void tree::preorder_traversal(struct node* temp) {
    if (temp != NULL) {
        printf("%c ", temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}

void tree::inorder_traversal(struct node* temp) {
    if (temp != NULL) {
        inorder_traversal(temp->left);
        printf("%c ", temp->data);
        inorder_traversal(temp->right);
    }
}

void tree::postorder_traversal(struct node* temp) {
    if (temp != NULL) {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%c ", temp->data);
    }
}

void tree::search(char value) {
    if (search_node(root, value)) {
        printf("'%c' is found in the tree.\n", value);
    } else {
        printf("'%c' is not found in the tree.\n", value);
    }
}

int tree::search_node(struct node* temp, char value) {
    if (temp == NULL) {
        return 0;
    }
    if (temp->data == value) {
        return 1;
    }
    return search_node(temp->left, value) || search_node(temp->right, value);
}
