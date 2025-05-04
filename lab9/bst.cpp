#include<cstdio>
#include<cstdlib>


class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};


class BST {
private:
    Node* root;
    
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        
        return node;
    }
    
    

int main() {
    BST tree;
    int choice, value;
    
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                tree.insert(value);
                break;
                
            case 2:
                printf("Preorder Traversal: ");
                tree.preorder();
                break;
                
            case 3:
                printf("Inorder Traversal: ");
                tree.inorder();
                break;
                
            case 4:
                printf("Postorder Traversal: ");
                tree.postorder();
                break;
                
            case 5:
                printf("Enter value to search: ");
                scanf("%d",&value);
                
                if (tree.search(value)) {
                    printf("Value found in the BST.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
                
            case 6:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    
    return 0;
}


void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        printf("%d",node->data);
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node) {
        printf("%d",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d",node->data);
    }
}

bool search(Node* node, int key) {
    if (node == NULL) {
        return false;
    }
    
    if (node->data == key) {
        return true;
    }
    
    if (key < node->data) {
        return search(node->left, key);
    }
    
    return search(node->right, key);
}

public:
BST() {
    root = NULL;
}

void insert(int value) {
    root = insert(root, value);
}

void inorder() {
    inorder(root);
    
}

void preorder() {
    preorder(root);
    
}

void postorder() {
    postorder(root);
    
}

bool search(int key) {
    return search(root, key);
}
};
