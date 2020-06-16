#include <iostream>
#include <string>
using namespace std;

int alternatingCharacters(string& s)
{
    string new_str = s;
    int del = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1] && i < s.size() - 1)
        {
            new_str.erase(new_str.begin() + 1);
            del++;
        }
    }
    cout << new_str << endl;
    cout << del << endl;
    return del;
}

int main() {
    string s = "AAABBB";
    cout << alternatingCharacters(s) << endl;
    return 0;
}