#include"circular.h"

int main(){
    time obj;
    int choice,time,timeslice;
    printf("Enter the time slice for execution: ");
    scanf("%d",&timeslice);
    do{
        printf("\n MENU CARD\n");
        printf("Enter 1: To insert the Process\n");
        printf("Enter 2: To Execute the Process\n");
        printf("Enter 3: To Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the process Execution time: ");
            scanf("%d",&time);
            obj.insertprocess(time);
            obj.display();
            break;
            case 2:
            obj.execute(timeslice);
            break;
            case 3:
            printf("Program Ended");
            break;
            default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 3\n");

        } 
     }while(choice!=3);
}

// Function to insert the process in the queue
int time :: insertprocess(int time){
    process *newprocess = (process*)malloc(sizeof(process));
    newprocess->time = time;
    if(head==NULL){
        newprocess->next = newprocess;
        head = newprocess;
        tail = newprocess;
        return 0;}
        newprocess ->next = head;
    process *temp = head;
    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = newprocess;
    head = newprocess;
    return 0;
}
// program to execute the process
int time :: execute(int timeslice){
    if(head==NULL){
        printf("No process in the queue to execute\n");
        return 0;
    }
    while(head!=NULL){
        printf("Executing process with time: %d\n", head->time);
        head->time -= timeslice;
        if(head->time <= 0){
            printf("process completed and removed\n");
            if(tail==head){
                free(head);
                head = tail = NULL;
                return 0 ;
            }
            else{
            process *del = head ;
            head = head->next;
            tail->next = head;
            free(del);}

        }
        else{
        tail = head;
        head = head->next;}
    }
    return 0;

    }

// Program to display the process times
void time :: display(){
    if(head==NULL){
        printf("The queue is empty\n");
        return;
    }
    process *temp = head;
    printf("Current process queue: ");
    while(temp->next!=head){
        printf("%d  ",temp->time);
        temp = temp->next;
    }
    printf("%d",temp->time);
    printf("\n");
    printf("back to the front\n");
}
