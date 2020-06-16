#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <math.h>

#define MAX_CHARS 26

using namespace std;

int makingAnagrams(string& a, string& b)
{
    int count = 0;
    array<int, MAX_CHARS> arr = { (26, 0) };
    for (const char& ca : a)
    {
        arr[ca - 'a']++; // in ASCII format 'a' = 97. If ca = 'a', then arr[0] + 1.
        // char - char gives ASCII integer. For example 'b' - 'a' = 98 - 97 = 1.
        // so If ca = 'b', then arr['b' - 'a'] => arr[98 - 97] => arr[1]++ ( at arr[0] there is counter for 'a', arr[1] for 'b', arr[2] for 'c' etc. )
    }
    for (const char& cb : b)
    {
        arr[cb - 'a']--; // then if cb = 'a' , it means that it is an anagram, so arr[0] - 1.
    }
    for (const int& i : arr)
    {
        count += abs(i);
    }
    return count;
}

int main() {
    string a = "fcrxzwscanmligyxyvym";
    string b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";
    cout << makingAnagrams(a, b) << endl;

    system("pause");
}