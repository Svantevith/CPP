#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <math.h>
#include<numeric>

#define MAX_CHARS 26

using namespace std;

bool compare(int& a, int& b)
{
    return a > b;
}

int greedyFlorist(int& people, vector<int>& prices)
{
    int money = 0;
    sort(prices.begin(), prices.end(), greater<int>()); // or instead of greater<>() provided by STL ( by default less<>() ), use compare
    // using greater<>() it will work for any type
    if (people == prices.size())
    {
        money = accumulate(prices.begin(), prices.end(), money); // first val, last val, add to this initial value.
    }
    else
    {
        vector<int> bought(people, 0);
        auto it_b = bought.begin();
        auto it_p = prices.begin();
        while (it_p < prices.end())
        {
            money += *it_p * (1 + *it_b);
            *it_b += 1; //if the flower was purchased once, it's bought counter increases by 1

            if (it_b == bought.end() - 1)
            {
                it_b = bought.begin(); // if each person has bought equal amount of flowers, new cycle must start
            }
            else
            {
                it_b++; // if not every person has bought equal amount of flowers, then next person will buy now
            }
            it_p++; // we are constantly moving on with next price
        }
    }

    return money;
}

int main() {
    int people = 3;
    vector<int> prices = { 1, 2, 3, 4 };
    cout << greedyFlorist(people, prices) << endl;
    system("pause");
}