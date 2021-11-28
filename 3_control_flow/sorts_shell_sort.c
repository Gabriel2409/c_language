#include <stdio.h>

/* https://www.interviewbit.com/tutorial/insertion-sort-algorithm/  */
void shell_sort(int arr[], int n);

int main(void)
{

    int arr[10] = {10, 8, 1, 3, 0, 7, 8, 2, 1, 4};
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("--Initial array--\n");
    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
    printf("\n");

    printf("--All the steps--\n");
    shell_sort(arr, 10);
    printf("--Final array--\n");

    for (int k = 0; k < 10; k++)
        printf("%d ", arr[k]);

    return 0;
}

void shell_sort(int arr[], int n)
{

    int gap;
    int j;
    int i;
    int temp;

    // {10, 8, 1, 3, 0, 7, 8, 2, 1, 4}
    // {10, 8, 2, 1, 4, 7, 8, 1, 3, 0}

    for (gap = n/2; gap > 0; gap /=2){
        for(i=gap; i < n; i++){
            for (j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap){
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
        }
    }
}

/*
Space complexity:
Storage of array : O(n)
Auxiliary storage : only one temp var : O(1)

Time complexity:
Best case : already sorted : 
never enter the j loop
number of elements in the i loop < n per loop
number of gap loop : n + n/2 + ... n/n => O(log(n)) (see quick sort)
=> time complexity is O(nlogn)

Worst case hard to calculate


Worst case : goes all the way through while loop at each iteration:
nb op per iteration on for loop : 1+2+3+..+n : O(n**2)
 */