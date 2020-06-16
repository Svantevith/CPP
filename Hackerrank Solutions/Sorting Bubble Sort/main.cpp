#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int>& a)
{
    int ctr = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a.size() - 1; j++)
        {
            //Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ctr++;
            }
        }
    }
    return ctr;
}

int main() {
    vector<int> a = { 5, 2, 3, 8, 1, 9 };
    int ctr = bubbleSort(a);
    cout << "Array is sorted in " << ctr << " swaps." << endl;
    cout << "First Element: " << *a.begin() << endl;
    cout << "Last Element: " << *prev(a.end());
    return 0;
}