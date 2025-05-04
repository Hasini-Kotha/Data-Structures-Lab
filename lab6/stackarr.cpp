#include<cstdio>
#include<cstdlib>
#define max 5
class stack{
    int stackarr[max];
    int top;
    public:
    stack(){
        top =-1;}
   
    int push(int);  
    int peek();
    int pop();
    int is_Full();
    int is_Empty();
    void display();
};

int main(){
    stack obj;
    int choice,val;
    do{
        printf("\n===Stack Menu===\n1.push\n2.pop\n3.peek\n4.display\n5.Exit\n\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value: ");
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
        val =obj.peek();
        if(val!=0){
            printf("The element at the last  is %d",val);
        }
        break;
        case 4:
        obj.display();
        break;
        case 5:
        printf("Program ended");
        break;
    }}
    while(choice !=5);
}
int stack :: is_Full(){
    if(top == max-1){
        return 1;
    }
    else {
        return 0;
    }
}

int stack :: is_Empty(){
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}


int  stack :: push (int val){
    if(is_Full()){
        printf ("Error: stack overflow !cant push %d ", val);
        return 0;
    }
    else{
        top ++;
        stackarr[top] = val;
        printf("%d is pushed into the stack\n",val);
    }
    return 0;
}

int stack :: pop(){
    if(is_Empty()){
        printf("Error! stack underflow! cannot pop.\n");
        return 0;
    }
    int value ;
    value = stackarr[top];
    top --;
    return value;
}

int stack :: peek(){
    if (is_Empty()){
        printf("Error:Stack underflow! no top element\n");
        return 0;
    }
    return stackarr[top];
}
void  stack :: display(){
    if(is_Empty()){
        printf("the stack is empty.\n");
        return;
    }
    printf("The elements in the stack are: ");
    for(int i=top;i>=0;i--){
        printf("%d  ",stackarr[i]);

   }
}