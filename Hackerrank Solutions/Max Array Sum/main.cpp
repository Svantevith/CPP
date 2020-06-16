#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int& a, int& b)
{
    if (abs(a) < abs(b))
    {
        return 1;
    }
    return 0;
}

int maxSubsetSum(vector<int>& arr)
{
    //sort(arr.begin(), arr.end(), compare);
    if (arr.size() == 1)
    {
        return arr[0];
    }
    else if (arr.size() == 2)
    {
        return max(arr[0], arr[1]);
    }
    else
    {
        int i = 0;
        int j = 0;
        int n = (int)arr.size();
        int sum = 0;
        vector<int> sums;
        while (i < n)
        {
            j = i + 2;
            sum += arr[i];
            //cout << arr[i] << endl;
            while (j <= n - 1)
            {
                sum += arr[j];
                //cout << arr[j] << endl;
                if (j + 2 >= n)
                {
                    break;
                }
                else
                {
                    j += 2;
                }
            }
            sums.push_back(sum);
            sum = 0;
            i++;
        }
        return *max_element(sums.begin(), sums.end());
    }
    return 0;
}

int main() {
    vector<int> arr = { 3, 7, 4, 6, 5 };
    cout << maxSubsetSum(arr) << endl;
    return 0;
}