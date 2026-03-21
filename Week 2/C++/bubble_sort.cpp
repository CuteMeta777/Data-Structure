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
    vector<int> array(5);

    for (int& e : array)
        cin >> e;

    // 1. array[0]에 있는 값이 e에 복사됨
    // 2. e에다가 cin으로 값을 넣음.
    // 3. array[1]에 있는 값이 e에 복사됨.

    // array[0]에 대한 레퍼런스가 e라서.

    printf("Inserted Values >>\n");
    for (int e : array)
        cout << e << " ";
}