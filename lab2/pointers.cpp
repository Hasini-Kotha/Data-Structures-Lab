#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Palindrome(int *num);
void Armstrong(int *num);
void Perfect(int *num);
int main(){
int *choice = (int*)malloc(sizeof(int));
int *number = (int *)malloc(sizeof(int));
do{
   printf("Menu card\n");
   printf("Enter 1 : To check palindrome number\n");
   printf("Enter 2 : To check Armstrong number \n");
   printf("Enter 3 : To check Perfect number\n");
   printf("Enter 4 : To exit\n\n");
   printf("Enter a number ");
   scanf("%d",choice);
   switch(*choice){
     case 1:
         printf("Enter a number : \n");
         scanf("%d",number);
         if(*number < 0){
             printf("Invalid number ! Enter positive number");
         }
         else{
            Palindrome(number);
         }
        break;
    case 2:
         printf("Enter a number");
         scanf("%d",number);
          if(*number < 0){
             printf("Invalid number ! Enter positive number");
         }
         else{
            Armstrong(number);
         }
         break;
    case 3:
         printf("Enter a number");
         scanf("%d",number);
         if(*number < 0){
            printf("Invalid number ! Enter positive number");
         }
         else{
            Perfect(number);
         }
         break;
     case 4:
           printf("Program ended!\n");
           break;    
     default:
               printf("The number youve entered is not valid\n");
               printf("Enter valid number");
         
   }
   
}while(*choice != 4);
  free(choice);
   free(number);
}
void Palindrome(int *num){
    int *temp = (int *)malloc(sizeof(int));
    int *num2 = (int*)malloc(sizeof(int));
    int *rem  = (int *)malloc(sizeof(int));
    *temp = *num;
    *rem = 0;
    *num2 = 0;
    while(*temp != 0){
        (*rem) = (*temp) % 10;
        (*num2) = (*num2)*10 + (*rem);
        (*temp) = (*temp)/10;
    }
    if(*num2 == *num){
        printf("Its a palindrome number\n");
    }
    else{
        printf("Its not a palidrome number\n");
    }
    free(temp);
    free(num2);
    free(rem);
}

void Armstrong(int *num){
    int *temp = (int *)malloc(sizeof(int));
    int *rem = (int*)malloc(sizeof(int));
    int *num2 = (int*)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    int *sum= (int *)malloc(sizeof(int));
    *temp = *num;
    *rem = 0;
    *sum = 0;
    *num2 = 0;
    *count = 0;
    while(*temp != 0){
        (*count)++;
         (*temp) = (*temp)/10;
    }
    while(*temp != 0){
        (*rem) = (*temp)%10;
        (*num2) = (*num2) + pow(*rem ,*count);
        (*temp) = (*temp)/10;
    }
    if(*num2 == *num){
        printf("Its an armstrong number\n");
    }
    else{
        printf("Its not an armstrong number\n");
    }
   free(temp);
   free(rem);
   free(num2);
   free(count);
   free(sum);
}
void Perfect(int *num){
    int *i = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    int *rem = (int *)malloc(sizeof(int));
    *sum =0;
    *i = 1;
    while(*i< (*num)){
      if(*num % (*i) == 0){
        *(sum)+= (*i);
      }
      (*i)++;
    }
      if(*sum == *num){
        printf("Its a perfect number");
      }
      else{
        printf("Its not a perfect number");
      }
    
    free(i);
    free(sum);
}
