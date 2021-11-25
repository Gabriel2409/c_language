#include <stdio.h>

/* https://www.interviewbit.com/tutorial/bubble-sort/  */
void bubble_sort(int arr[], int n);

int main(void)
{

    int arr[10] = {10, 8, 1, 3, 0, 7, 8, 2, 1, 4};
    // int arr[10] = {1,5,7,2,3,4,7,8,9,10};
    printf("--Initial array--\n");
    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
    printf("\n");

    printf("--All the steps--\n");
    bubble_sort(arr, 10);
    printf("--Final array--\n");

    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
}

void bubble_sort(int arr[], int n)
{

    int j;
    int i = 0;
    int temp;

    int lastswap;
    int total_operations = 0;
    while (lastswap != -1)
    {
        lastswap = -1;
        for (j = 0; j < n - 1 - i; j++)
        {
            total_operations++;

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                lastswap = j;
            }
        }
        // i++; // standard solution
        i = n -1 - lastswap; // same number of steps as standard solution but can decrease nb of operations

        for (int k = 0; k < 10; k++)
            printf("%d ", arr[k]);
        printf("\t%d", lastswap);
        printf("\n");
    }
    printf("--Total operations: %d--\n", total_operations);
}


/*
Space complexity:
Storage of array : O(n)
Auxiliary storage : only one temp var : O(1)

Time complexity:
Best case : already sorted : O(n) (go through the array, dont swap)

Worst case : move only one element at a time : n + n-1 + n-2... = O(n**2)
 */