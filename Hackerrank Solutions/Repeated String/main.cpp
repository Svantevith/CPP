#include <iostream>
#include <vector>

using namespace std;

long long repeatedString(string& str, long long& n)
{
    auto single_ctr = 0;
    for (char& c : str)
    {
        if (c == 'a')
        {
            single_ctr++;
        }
    }
    long long a_ctr = 0;
    a_ctr += (n / str.size()) * single_ctr;
    for (auto i = 0; i < n % str.size(); i++)
    {
        if (str[i] == 'a')
        {
            a_ctr++;
        }
    }
    return a_ctr;

}


int main() {
    long long n = 10000000000;
    string str = "aba";
    cout << repeatedString(str, n) << endl;
    system("pause");
}