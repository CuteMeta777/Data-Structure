#include <iostream>
#include <vector>

using namespace std;

// Repeatedly swaps adjacent elements if they are in the wrong order.
void bubbleSort(vector<int>& array)
{
    bool isSwapped;
    int arraySize = array.size();
    for (int i = 0; i < arraySize - 1; i++)
    {
        isSwapped = false;
        for (int j = 0; j < arraySize - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                isSwapped = true;
                swap(array[j], array[j + 1]);
            }
        }

        cout << "Pass " << i + 1 << ": ";
        for (int e : array)
            cout << e << " ";
        cout << "\n";

        if (!isSwapped)
            return;
    }
}

int main(void)
{
    vector<int> array = { 5, 3, 8, 6, 2 };

    bubbleSort(array);

    cout << "\nFinal Result:\n";
    for (int e : array)
        cout << e << " ";
    cout << "\n\n";
}