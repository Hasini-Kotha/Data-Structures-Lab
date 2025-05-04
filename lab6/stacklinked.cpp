#include<cstdio>
#include<cstdlib>
class list{
   
    struct node {
        int data;
       struct node *next ;
    };
    struct node *top;

public: 
list(){
    top = NULL;
}
int peek();
int pop();
int push(int);
void display();
int is_empty();
};
int main(){
    list obj;
    int choice,val;
    do{
        printf("\n===Stack Menu===\n1.push\n2.pop\n3.peek\n4.display\n5.Exit\n\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
        obj.push(val);
        break;
        case 2:
        val = obj.pop();
        if(val!=0){
            printf("The element poped is %d",val);
        }
        break;
        case 3:
        val = obj.peek();
        if(val!=0){
            printf("The element poped is %d",val);
        }

        break;
        case 4:
        obj.display();
        break;
        case 5:
        break;

}
}while(choice!=5);
return 0;
}
int list:: is_empty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int list :: push(int val){
   
   struct node *newnode =(struct node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("The stack is overflow.\n");
        return 0;
    }
    newnode -> data  = val;
    newnode-> next = top;
    top = newnode;
    printf("%d is inserted at the beginning.\n");
 return 0;
}

int list :: pop(){
    if(is_empty()){
        printf("Stack underflow") ;
        return -1;
    }
    node *temp = top;
    int val = top->data;
    top = top->next;
    free(temp);
    return val;
}
int list :: peek (){
    if(is_empty()){
        printf("Stack underflow") ;
        return -1;
    }
    return top->data;

}
void list ::display(){
    if(is_empty()){
        printf("Stack underflow") ;
        return ;}
    node *temp = top;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }


}



















