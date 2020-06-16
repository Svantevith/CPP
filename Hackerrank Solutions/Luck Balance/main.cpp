#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int luckBalance(int& k, vector<vector<int>>& contests)
{
    int luckBalance = 0;
    vector<vector<int>> important;
    vector<vector<int>> neglect;
    for (auto& i : contests)
    {
        if (i[1] == 1)
        {
            important.push_back(i);
        }
        else
        {
            neglect.push_back(i);
        }
    }
    sort(important.rbegin(), important.rend());
    for (size_t j = 0; j < important.size(); j++)
    {
        if (j < k)
        {
            luckBalance += important[j][0];
        }
        else
        {
            luckBalance -= important[j][0];
        }
    }
    for (auto& n : neglect)
    {
        luckBalance += n[0];
    }
    return luckBalance;
}


int main() {
    vector<vector<int>> arr = { {5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0} };
    int k = 3;
    cout << luckBalance(k, arr) << endl;
    system("pause");
}