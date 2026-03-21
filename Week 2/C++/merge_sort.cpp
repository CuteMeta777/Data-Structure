#include <iostream>
#include <vector>

using namespace std;

// Divides array, sorts subarrays, and merges them.
void mergeSort(vector<int>& array)
{
    
}

int main(void)
{
    vector<int> array = { 5, 3, 8, 6, 2 };

    mergeSort(array);

    cout << "\nFinal Result:\n";
    for (int e : array)
        cout << e << " ";
    cout << "\n\n";
}