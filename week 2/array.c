#include <stdio.h>

void solution1(int arr[])
{
    int change_num = 10;
    arr[2] = change_num;
}

void solution2(int* arr)
{
    int change_num = 10;
    arr[2] = change_num;
}

void solution3(int* arr)
{
    int change_num = 10;
    *(arr + 2) = change_num;
}

int main(void)
{
    int arr_size = 5;
    int arr[] = { 1, 2, 3, 4, 5 };
    solution1(arr);
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    return 0;
}