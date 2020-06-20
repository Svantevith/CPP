#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define VOWELS {'a', 'e', 'i', 'o', 'u'}

using namespace std;

string getVowels(string& str, int &n)
{
    int char_cnt = 0;
    int occ = 0;
    unordered_set<int> vowels;
    map<int, string> map;
    string temp = "";
    if (str.size() >= n)
    {
        for (auto i = str.begin(); i != str.end() - (n - 1); i++)
        {
            temp = string(i, i + n);
            for (auto& ch : VOWELS)
            {
                char_cnt = count(temp.begin(), temp.end(), ch);
                if (char_cnt > 0)
                {
                    occ += char_cnt;
                }
            }
            map.insert(pair<int, string>(occ, temp));
            occ = 0;
        }
        return prev(map.end())->second;
    }
    else
    {
        return str;
    }
}


int main() {
    string input = "caberqiitefg";
    int n = 5;
    cout << getVowels(input, n) << endl;
    return 0;
}