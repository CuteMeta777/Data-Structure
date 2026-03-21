#include <iostream>
#include <vector>

using namespace std;

// Finds the smallest element and swaps it with the first element
void selectionSort(vector<int>& array)
{
    int min_idx, temp;
    int arraySize = array.size();
    for (int i = 0; i < arraySize - 1; i++) 
    {
        min_idx = i;
        for (int j = i + 1; j < arraySize; j++) 
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        swap(array[i], array[min_idx]);
    }
}

int main(void)
{
    vector<int> array = { 5, 3, 8, 6, 2 };

    selectionSort(array);

    cout << "\nFinal Result:\n";
    for (int e : array)
        cout << e << " ";
    cout << "\n\n";
}