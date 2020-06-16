#include <iostream>
#include<vector>
#include<map>
#include<sstream>
#include<iterator>


using namespace std;

int socks(vector<string>& tokens)
{
    int pairs = 0;

    if (tokens.size() <= 5)
    {
        map<string, int> map;
        for (auto& i : tokens)
        {
            map[i] += 1;
        }
        for (auto& m : map)
        {
            cout << m.first << " " << m.second << endl;
            if (m.second >= 2)
            {
                pairs += (int)m.second / 2;
            }
        }
    }
    return pairs;
}

vector<string> splitStringBySpace(string& str)
{
    istringstream buf(str);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
    return tokens;
}

int main() {
    int n = 0;
    cin >> n;
    cin.ignore();

    string str = "";
    getline(cin, str);
    vector<string> numbers = splitStringBySpace(str);
    if (numbers.size() <= n)
    {
        cout << socks(numbers) << endl;
    }
    else
    {
        cout << "Input array size exceeds number of arguments." << endl;
    }
    system("pause");
}