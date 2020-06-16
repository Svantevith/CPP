#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> getAllSubstrings(string& s)
{
    vector<string> substrings;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size() + 1; j++)
        {
            //cout << string(s.begin() + i, s.begin() + j) << endl;
            substrings.push_back(string(s.begin() + i, s.begin() + j));
        }
    }
    return substrings;
}

bool compareAlphabetically(string& s1, string& s2)
{
    return s1 < s2;
}

bool compareByLength(string& s1, string& s2)
{
    return s1.size() < s2.size();
}

vector<string> sortVector(vector<string>& v)
{
    // sorts each string alphabetically
    for (auto& s : v)
    {
        sort(s.begin(), s.end());
    }
    return v;
}

int sherlockAndAnagrams(string& s)
{
    vector<string> v = getAllSubstrings(s);
    int anagrams = 0;
    sortVector(v);
    sort(v.begin(), v.end(), compareAlphabetically);
    sort(v.begin(), v.end(), compareByLength);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                anagrams++;
            }
        }
    }
    return anagrams;
}

int main()
{
    string s = "ifailuhkqq";
    cout << sherlockAndAnagrams(s) << endl;
    system("pause");
}