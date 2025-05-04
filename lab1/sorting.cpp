#include<cstdio>
void bubblesort(int arr[] , int n);
void selectionsort(int arr[] , int n);
void insertionsort(int arr[] , int n);
void display(int arr[] , int n);
int main(){
    int n ;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        printf("Enter the %d elements",i);
        scanf("%d",&arr[i]);
        while(1){
            printf("Enter 1 for bubblesort 2 for selection 3 for insertion and 4 to exit ");
            printf("\n");
            printf("Enter your choice ");
            int choice ;
            scanf("%d",&choice);
            switch (choice){
                case1:
                bubblesort(arr ,n);
                break;
                case2:
                selectionsort(arr , n);
                break;
                case3:
                insertionsort(arr ,n);
                break;
                case 4 : 
                return 0 ;
                break;
                default:
                printf("Enter valid choice ");
                printf("\n");

            }
            
        }
    }

    return 0;
}
void bubblesort(int arr[] , int n ){
    for(int i = 0 ; i < n -1 ; i++)
    {
        for(int j = 0 ; i < n-i-1 ; j++){
            if(arr[j+1]  < arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = arr[temp];
            }
        }
        printf("The array after %d pass is ",i);
        printf("\n");
        display(arr , n);
    }
}

void selectionsort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        int minindex = i ;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minindex]){
                minindex = j ;
            }
        }
        int temp1 = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp1;
        printf("The elements after %d passes are",i);
        display(arr ,n);
    }
}
void insertionsort(int arr [] , int n ){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;
        while(arr[j] > key && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printf("The elemnts after %d passes are", i);
        display(arr , n);
    }
}
void display(int arr[] , int n){
    for(int k = 0 ; k< n ; k++){
        printf("%d",arr[k]);
        printf("\n");
    }
}