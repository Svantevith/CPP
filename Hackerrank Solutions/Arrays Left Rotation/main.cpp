#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> rotLeft(int& d, vector<int>& v)
{
    vector<int> res = v;

    int diff = 0;
    auto val = v.begin();

    if (d > (int)v.size())
    {
        d = d % v.size();
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        val = v.begin() + i;
        diff = (int)i - d;

        if (diff >= 0)
        {
            *(res.begin() + diff) = *val;
        }
        else if (diff < 0)
        {
            *(res.end() + diff) = *val;
        }
    }

    return res;
}

int main() {
    int d = 5;
    vector<int> v = { 1, 2, 3, 4, 5 };
    vector<int> res = rotLeft(d, v);
    for (auto& i : res)
    {
        cout << i << endl;
    }
    return 0;
}