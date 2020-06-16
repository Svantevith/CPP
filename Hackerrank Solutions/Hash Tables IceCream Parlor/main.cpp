#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
using namespace std;

void iceCream(int& money, vector<int>& prices)
{
    // Using Two Sum problem solution
    unordered_map<int, int> map;
    int complement = 0;
    for (auto i = 0; i < prices.size(); i++)
    {
        complement = money - prices[i];
        if (map.count(complement) > 0)
        {
            cout << map[complement] << " " << i + 1 << endl;
            break;
        }
        else
        {
            map[prices[i]] = i + 1;
        }
    }
}

int main()
{
    vector<int> prices = { 1, 5, 2, 4, 6 };
    int money = 5;
    iceCream(money, prices);

    system("pause");
}