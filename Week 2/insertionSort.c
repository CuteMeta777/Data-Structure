#include <stdio.h>

// Inserts each element into its correct position.
void insertionSort(int arr[], int n) 
{
    int key, j;
    for (int i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Print array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main(void)
{
    int arr[5] = { 5, 3, 8, 6, 2 };
    insertionSort(arr, 5);

    return 0;
}