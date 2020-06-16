#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long tripleSum(vector<int>& a, vector<int>& b, vector<int>& c)
{
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int a_index = 0;
    int b_index = 0;
    int c_index = 0;

    long result = 0;
    long result_for_each_cycle = 0;
    // Result for each cycle can be MAX = a.size() * 1 ( always 1 because B array is the medium one ) * c.size().
    // That's why the final result will be calculated as the sum of result_for_each_cycle


    // We have always 3 arrays. The B array is the medium one, which will be always used to obtain the result.
    // The checking for each triplets will always start from B array, which is the medium in the whole algorithm.
    // The result of B array will make the result either 0, or result * 1.
    // The result will be dependent from the B array. This is the heart of the whole algorithm.
    while (b_index < (int)b.size())
    {
        while (a_index < (int)a.size() && a[a_index] <= b[b_index])
        {
            ++a_index; // If there is the possibility to connect a[a_index] with b[i_index], we don't want to retake the same operation on the same element a[a_index]. That's why we move to the next a_index++;
            // We must move to the next a_index++, because of the while on B array.
            // If we add a_index++ each time there is the connection between A and B elements, the algorithm will know that there is already a solution to that element and will no longer try to retake the comparison.
        }
        while (c_index < (int)c.size() && c[c_index] <= b[b_index])
        {
            ++c_index;
        }

        result_for_each_cycle = (long)a_index * (long)c_index;

        ++b_index; // We want to repeat comparison with a and c elements for each element of b. B is constantly the "heart" of the algorithm.
        result += result_for_each_cycle;

        result_for_each_cycle = 0;
    }
    return result;
}

int main()
{
    vector<int> a = { 3, 3, 3 };
    vector<int> b = { 1, 4, 5 };
    vector<int> c = { 2, 3, 3 };

    cout << tripleSum(a, b, c) << endl;
    system("pause");
}