#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int>& c)
{
    int jumps = 0;
    for (auto it = c.begin(); it != c.end() - 1; it++)
    {
        if (it < c.end() - 2)
        {
            if (*(it + 1) == 1 || (*(it + 1) == 0 && *(it + 2) == 0))
            {
                it++;
            }
        }
        jumps++;
    }
    return jumps;
}


int main() {
    vector<int> c = { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };
    cout << jumpingOnClouds(c) << endl;
    system("pause");
}