#include <stdio.h>

// Divides array, sorts subarrays, and merges them.
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() 
{
    int arr[] = { 5, 3, 8, 6, 2 };
    int arr_size = 5;

    mergeSort(arr, 0, arr_size - 1);

    printf("Final Result: \n");
    for (int i = 0; i < arr_size; i++)
            printf("%d ", arr[i]);
    printf("\n\n");
    
    return 0;
}