#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minMax(int& n, vector<int>& v)
{
    sort(v.begin(), v.end());
    vector<int> arr;
    vector<int> results;
    for (auto it = v.begin(); it != v.end() - (n - 1); it++)
    {
        for (int i = 0; i < n; i++)
        {
            arr.push_back(*(it + i));
        }
        results.push_back(*(arr.end() - 1) - *arr.begin());
        arr.erase(arr.begin(), arr.end());
    }

    return *min_element(results.begin(), results.end());
}

int main() {
    vector<int> v = { 7, 300, 200, 300, 350, 400, 401, 402 };
    int n = 3;
    cout << minMax(n, v) << endl;
    system("pause");
}