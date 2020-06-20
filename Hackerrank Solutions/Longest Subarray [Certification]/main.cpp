#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int subarrayLength(vector<int>& arr)
{
    int cnt = 0;
    unordered_set<int> res;
    if (arr.empty())
    {
        return 0;
    }
    else if (arr.size() == 1)
    {
        return 1;
    }
    else
    {
        for (auto i = arr.begin(); i < arr.end() - 1; i++)
        {
            cnt = 1;
            for (auto j = i + 1; j < arr.end(); j++)
            {
                if (abs(*j - *i) == 0 || abs(*j - *i) == 1)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            res.insert(cnt);
        }
    }
    return *max_element(res.begin(), res.end());
}

int main() {
    vector<int> arr = { 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543, 12543,
                        12547, 12543, 12543, 12543 };
    cout << subarrayLength(arr) << endl;
    return 0;
}