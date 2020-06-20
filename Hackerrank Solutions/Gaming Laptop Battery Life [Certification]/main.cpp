#include <iostream>
#include <vector>

#define INITIAL_BATTERY 50
#define MIN_BATTERY 0
#define MAX_BATTERY 100
using namespace std;

int getBattery(vector<int>& time)
{
    int battery = INITIAL_BATTERY;
    int energy = 0;
    for (auto i = time.begin(); i != time.end(); i++)
    {
        energy = battery + *(i);
        if (energy < MIN_BATTERY)
        {
            battery = 0;
        }
        else if (energy > MAX_BATTERY)
        {
            battery = 100;
        }
        else
        {
            battery += *i;
        }
    }
    return battery;
}

int main() {
    vector<int> time = { 25, -30, 70, -10 };
    cout << getBattery(time) << endl;

    return 0;
}