#include <stdio.h>

// Finds the smallest element and swaps it with the first element
void selectionSort(int arr[], int n) 
{
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Print array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main(void)
{
    int arr[5] = { 5, 3, 8, 6, 2 };
    selectionSort(arr, 5);

    return 0;
}