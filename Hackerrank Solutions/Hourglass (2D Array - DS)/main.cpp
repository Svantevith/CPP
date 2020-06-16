#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int hourglass(array<array<int, 6>, 6>& arr)
{
    int sum = 0;
    vector<int> sums;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            //cout << sum << endl;
            sums.push_back(sum);
        }
    }
    int max_sum = *max_element(sums.begin(), sums.end());
    //cout << max_sum << endl;
    return max_sum;
}

int main() {

    array<array<int, 6>, 6> ar = {
            {
                    {1, 0, 1, 0, 0, 0},
                    {0, 1, 0, 0, 5, 0},
                    {1, 1, 1, 1, 0, 0},
                    {1, 0, 0, 0, 6, 0},
                    {1, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0}
            }
    };

    cout << hourglass(ar) << endl;

    return 0;
}