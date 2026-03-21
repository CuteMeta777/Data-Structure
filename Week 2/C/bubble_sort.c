#include <stdio.h>

// Repeatedly swaps adjacent elements if they are in the wrong order.
void bubbleSort(int arr[], int n) 
{
    int temp, swapped;
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Print array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
        if (!swapped) break; // If no swaps, break early
    }
}

int main(void)
{
    int arr[5] = { 5, 3, 8, 6, 2 };
    bubbleSort(arr, 5);

    printf("\nFinal Result:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    return 0;
}