#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int numberOfOrders(vector<int>& orders, int& stock)
{
    if (stock <= 0 || orders.empty() || *orders.begin() > stock)
    {
        return 0;
    }
    else
    {
        int sum = 0;
        int cnt = 0;
        int temp = 0;
        sort(orders.begin(), orders.end(), less<int>());
        unordered_set<int> all_orders;
        for (auto i = orders.begin(); i != orders.end() - 1; i++)
        {
            if (*i <= stock)
            {
                cnt = 1;
            }
            else
            {
                break;
            }
            sum = *i;
            for (auto j = i + 1; j != orders.end(); j++)
            {
                temp = sum + *j;
                if (temp <= stock)
                {
                    sum = temp;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            all_orders.insert(cnt);
        }
        return *max_element(all_orders.begin(), all_orders.end());
    }
}

int main() {
    vector<int> orders = {2, 7, 3, 5, 9};
    int stock = 13;
    cout << numberOfOrders(orders, stock) << endl;
    return 0;
}