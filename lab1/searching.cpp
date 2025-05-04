#include <cstdio>
#include "header.h"
void linearsearch(int arr[],int size,int target);
void binarysearch(int arr[],int size,int target);
int main(){
int size;
int target;
printf("Enter the no of elements in the array");
scanf("%d",&size);
int arr[size];
for(int i=0;i<size;i++){
printf("Enter the %d element",i);
scanf("%d",&arr[i]);
}
while(1){
printf("Enter 1 for linearsearch 2 for binarysearch 3 to exit");
printf("\n");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter the target");
scanf("%d",&target);
linearsearch(arr,size,target);
break;
case 2:
printf("Enter the target");
scanf("%d",&target);
insertionsort(arr,size);
binarysearch(arr,size,target);
break;
case 3:
return 0;
default:
printf("Enter valid number");
printf("\n");
}
}

}

// function to perform linear search
void linearsearch(int arr[],int size,int target){
int found =0;
for(int i=0;i<size;i++){
if (arr[i] == target){
printf("The element is found at %d",i);
printf("\n");
found=1;
break;
}
}
if (found==0){
printf("The element is not present in the array");
printf("\n");
}
}
// function for perform binary search
void binarysearch(int arr[],int size,int target){
int left = 0;
int right = size-1;
int found=0;
while(left<=right){
int middle = (left + right)/2;
if (arr[middle] == target){
printf("The element is found at %d",middle);
printf("\n");
found=1;
break;
}
else if (arr[middle]>target){
right=middle-1;
}
else{
left=middle+1;
}
}
if (found==0){
printf("The element is not present in the array");
printf("\n");
}

}



