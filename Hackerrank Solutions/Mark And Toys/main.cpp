#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int markAndToys(vector<int>& prices, int k)
{
    int ctr = 0;
    sort(prices.begin(), prices.end());
    for (auto& i : prices)
    {
        if (k - i >= 0)
        {
            k -= i;
            ctr++;
        }
        else
        {
            break;
        }
    }
    return ctr;
}

int main() {
    int k = 50;
    vector<int> prices = { 1,12,5,111,200,1000,10 };
    cout << markAndToys(prices, k) << endl;
    return 0;
}