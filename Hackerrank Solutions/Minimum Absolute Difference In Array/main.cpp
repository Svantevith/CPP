#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumAbsoluteDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int difference = 0;
    vector<int> differences;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        if (it < arr.end() - 1)
        {
            difference = abs(*it - *(it + 1));
            differences.push_back(difference);
            if (difference == 0)
            {
                break;
            }
        }
    }
    return *min_element(differences.begin(), differences.end());
}

int main() {
    vector<int> arr = { -59, -36, -13, 1, -53, -92, -2, -96, -54, 75 };
    cout << minimumAbsoluteDifference(arr) << endl;

    system("pause");
}