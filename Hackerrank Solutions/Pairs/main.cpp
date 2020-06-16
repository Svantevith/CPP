#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int pairs(int& target, vector<int>& arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int result = 0;
    int difference = 0;
    auto i = arr.begin();
    auto j = i + 1;
    while (j < arr.end())
    {
        difference = *i - *j;
        if (difference == target)
        {
            result++;
            i++;
            j++;
        }
        else if (difference > target)
        {
            i++;
        }
        else if (difference < target)
        {
            j++;
        }
    }
    return result;
}

int main()
{
    int target = 2;
    vector<int> arr = { 1, 3, 5, 8, 6, 4, 2 };
    cout << pairs(target, arr) << endl;

    return 0;
}

//Previous solution( too long execution time )

/*int pairs(int &target, vector<int> &arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    //auto it = find(arr.begin(), arr.end(), target);
    int result = 0;
    for (auto it = arr.begin(); it != arr.end() - 1; it++)
    {
        if (*it > target)
        {
            for (auto it2 = arr.begin() + 1; it2 != arr.end(); it2++)
            {
                if (*it - *it2 == target)
                {
                    result++;
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    return result;

}*/
