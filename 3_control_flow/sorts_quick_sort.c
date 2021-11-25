#include <stdio.h>

/* https://www.interviewbit.com/tutorial/quicksort-algorithm/  */
void quick_sort(int arr[], int low, int high);
int quick_sort_part(int arr[], int low, int high);

int main(void)
{

    int arr[10] = {10, 8, 1, 3, 0, 7, 8, 2, 1, 4};
    // int arr[10] = {1,5,7,2,3,4,7,8,9,10};
    printf("--Initial array--\n");
    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
    printf("\n");

    printf("--All the steps--\n");
    quick_sort(arr, 0, 9);
    printf("--Final array--\n");

    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);

    return 0;
}

void quick_sort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pivot_pos = quick_sort_part(arr, low, high);
        printf("%d\n", pivot_pos);
        quick_sort(arr, low, pivot_pos - 1);
        quick_sort(arr, pivot_pos + 1, high);
    }
}

int quick_sort_part(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i, j;
    int temp;
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (arr[j] <= arr[high])
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // could be done in the loop as condition arr[j] <= arr[high] is true for j == high
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

/*
Time complexity:
Best case : pivot all the time in center of array
first n element
then n/2 element on each side
then n/4 element on each side, etc...

define p such as n <= 2**p ( log(n) == plog(2))

nb of op <= 2**p + 1/2 * 2 * 2**p + 1/4 * 4 * 2**p +... 1/2**p *2**p * 2**p
== 2**p * p == n *log(n) / log(2)
=> Best case is O(nlogn)

As there are log(n) function calls =>
space complexity is:
    Storing array : O(n)
    recursion stack : O(logn)


Worst case : pivot is always the largest element.
first n element
then  n-1
then n-2
then n-3
=> Time complexity is O(n**2)

As there are n function calls =>
space complexity is:
    Storing array : O(n)
    recursion stack : O(n)

 */