#include <stdio.h>

/* https://www.interviewbit.com/tutorial/insertion-sort-algorithm/  */
void insertion_sort(int arr[], int n);

int main(void)
{

    int arr[10] = {10, 8, 1, 3, 0, 7, 8, 2, 1, 4};
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("--Initial array--\n");
    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
    printf("\n");

    printf("--All the steps--\n");
    insertion_sort(arr, 10);
    printf("--Final array--\n");

    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);

    return 0;
}

void insertion_sort(int arr[], int n)
{

    int j;
    int i;
    int temp;

    for (j = 1; j < n; j++)
    {

        temp = arr[j];

        i = j;

        while (i > 0 && arr[i-1] > temp)
        {

            i--;
            arr[i + 1] = arr[i];
        }
        arr[i] = temp;

        for (int k = 0; k < 10; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

/*
Space complexity:
Storage of array : O(n)
Auxiliary storage : only one temp var : O(1)

Time complexity:
Best case : already sorted : O(n) : does not go through while loop but still need
to do the wholde for loop

Worst case : goes all the way through while loop at each iteration:
nb op per iteration on for loop : 1+2+3+..+n : O(n**2)
 */