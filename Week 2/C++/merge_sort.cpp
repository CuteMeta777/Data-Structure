#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int i = 0; i < n2; i++) R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }
    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}

void mergeSort(vector<int>& array, int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(void)
{
    vector<int> array = { 5, 3, 8, 6, 2 };

    mergeSort(array, 0, array.size() - 1);

    cout << "\nFinal Result:\n";
    for (int e : array)
        cout << e << " ";
    cout << "\n\n";
}