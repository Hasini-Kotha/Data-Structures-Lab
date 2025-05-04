#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200005

int a[MAX_N];
int last_occurrence[MAX_N];

int main() 
{
    int t;
    printf("Enter the number of test cases (t): ");
    scanf("%d", &t);

    while (t--) 
    {
        int n;
        printf("\nEnter the length of the sequence (n): ");
        scanf("%d", &n);

        printf("Enter the sequence elements (space-separated): ");
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
        }

        // Replacing memset with a loop
        for (int i = 0; i < MAX_N; i++) 
        {
            last_occurrence[i] = -1;
        }

        int left = 0;

        for (int i = 0; i < n; i++) 
        {
            if (last_occurrence[a[i]] >= left) 
            {
                left = last_occurrence[a[i]] + 1;
            }
            last_occurrence[a[i]] = i;
        }
        

        printf("Minimum number of elements to remove from the start: %d\n", left);
    }

     return 0;
}