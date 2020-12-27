#include <stdio.h>

#define ARR_SIZE 50

void shift_element(int *arr, int i);
void insertion_sort(int *arr, int len);

int main(int argc, char const *argv[])
{
    int arr[ARR_SIZE];
    //geting the numbers from the user
    printf("insert %d numbers for the arr: ", ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    //doing the function
    insertion_sort(arr, sizeof(arr) / sizeof(int));
    //printing
    if (sizeof(arr) / sizeof(int) > 0)
    {
        printf("%d", *arr);
    }
    for (int i = 1; i < (int)(sizeof(arr) / sizeof(int)); i++)
    {
        printf(",%d", *(arr + i));
    }

    return 0;
}

/**
 * @brief 
 * 
 * @param arr 
 * @param i 
 */
void shift_element(int *arr, int i)
{
    int next_num = 0;

    if (i != 0)
    {
        next_num = *(arr + 1);
        *(arr + 1) = *(arr);
        *arr = 0;
    }

    for (int j = 1; j < i; j++)
    {
        int temp = *(arr + j + 1);
        *(arr + j + 1) = next_num;
        next_num = temp;
    }
}

/**
 * @brief this function sort numbers in insertion sort
 * 
 * @param arr the pointer to array for sorting 
 * @param len length of the array to sort
 */
void insertion_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int pos = i;
        while (pos > 0 && *(arr + i) < *(arr + (pos - 1)))
        {
            pos--;
        }
        int temp = *(arr + i);
        shift_element(arr + pos, i - pos);
        *(arr + pos) = temp;
    }
}