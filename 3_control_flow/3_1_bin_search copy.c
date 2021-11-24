#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int newbinsearch(int x, int v[], int n);
void test_binsearch(int binsearch(int x, int v[], int n), int x, int v[], int n);

int main(void)
{

    int arr[10] = {0, 1, 5, 8, 45, 69, 78, 99, 108, 7852};
    printf("%d\n", binsearch(9, arr, 10));
    printf("%d\n", binsearch(-9, arr, 10));
    printf("%d\n", binsearch(9999, arr, 10));
    printf("%d\n", binsearch(5, arr, 10));
    printf("%d\n", binsearch(99, arr, 10));

    printf("-------------\n");

    printf("%d\n", newbinsearch(9, arr, 10));
    printf("%d\n", newbinsearch(-9, arr, 10));
    printf("%d\n", newbinsearch(9999, arr, 10));
    printf("%d\n", newbinsearch(5, arr, 10));
    printf("%d\n", newbinsearch(99, arr, 10));

    printf("-------------\n");
    test_binsearch(binsearch, 9999, arr, 10);
    test_binsearch(newbinsearch, 9999, arr, 10);

}

int binsearch(int x, int v[], int n)
{

    int high = n - 1;
    int low = 0;
    int middle;
    while (low < high - 1)
    {
        middle = (low + high) / 2;

        if (x < v[middle])
        {
            high = middle;
        }
        else if (x > v[middle])
        {
            low = middle;
        }
        else
            return middle;
    }
    return -1;
}

int newbinsearch(int x, int v[], int n)
{
    int high = n - 1;
    int low = 0;
    int middle = (low + high) / 2;

    while (low < high - 1)
    {
        middle = (low + high) / 2;

        if (x < v[middle])
        {
            high = middle;
        }
        else
        {
            low = middle;
        }
    }
    if (x == v[low])
    {
        return low;
    }
    return -1;
}

void test_binsearch(int binsearch(int x, int v[], int n), int x, int v[], int n)
{
    static int test_nr = 0;
    long clocks = clock();

    int i;
    for (i = 0; i < 100000000; ++i)
    {
        binsearch(x, v, n);
        x++;
    }

    clocks = clock() - clocks;

    printf("test_%d: %lu clocks (%.4f seconds)\n", test_nr, clocks, (double)clocks / CLOCKS_PER_SEC);

    ++test_nr;
}