#include <iostream>
#include <vector>

using namespace std;

// Inserts each element into its correct position.
void insertionSort(vector<int>& array)
{
    int key, j;
    int arraySize = array.size();
    for (int i = 1; i < arraySize; i++) 
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) 
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main(void)
{
    vector<int> array = { 5, 3, 8, 6, 2 };

    insertionSort(array);

    cout << "\nFinal Result:\n";
    for (int e : array)
        cout << e << " ";
    cout << "\n\n";
}