#include <iostream>
#include <cstdio>

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

class ExpressionTree {
private:
    Node* nodes[100]; // Array-based stack
    int top;

public:
    ExpressionTree() {
        top = -1;
    }

    void push(Node* node) {
        nodes[++top] = node;
    }

    Node* pop() {
        return nodes[top--];
    }

    Node* constructExpressionTree(const char postfix[], int length) {
        for (int i = 0; i < length; i++) {
            char ch = postfix[i];

            Node* newNode = new Node(ch);

            if (ch >= '0' && ch <= '9') { 
                push(newNode);
            } else {
                newNode->right = pop();
                newNode->left = pop();
                push(newNode);
            }
        }
        return pop(); 
    }

    void preorder(Node* root) {
        if (root) {
            std::printf("%c ", root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            std::printf("%c ", root->data);
            inorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            std::printf("%c ", root->data);
        }
    }
};

int main() {
    ExpressionTree tree;
    char postfix[] = "53+62/*35*+";
    int length = sizeof(postfix) / sizeof(postfix[0]) - 1;

    Node* root = tree.constructExpressionTree(postfix, length);

    std::printf("Preorder: ");
    tree.preorder(root);
    std::printf("\n");

    std::printf("Inorder: ");
    tree.inorder(root);
    std::printf("\n");

    std::printf("Postorder: ");
    tree.postorder(root);
    std::printf("\n");

    return 0;
}
