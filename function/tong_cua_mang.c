// Fn to get an array
#include<stdio.h>

void get_array(int *arr, int size);
void print_array(int *arr, int size);
int get_sum(int *arr, int size);

int main()
{
    int size, sum_arr;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    get_array(arr, size);
    print_array(arr, size);
    get_sum(arr, size);

    return 0;
}

void get_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the value of element #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


void print_array(int *arr, int size)
{
    printf("Array: [");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d", arr[i]);    
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");
}


void get_sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    printf("Sum of array: %d", sum);
}