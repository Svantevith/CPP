#include <iostream>
#include <vector>
#include <string>

using namespace std;

string twoStrings(string& s1, string& s2) {
    size_t found = 0;
    for (auto& c1 : s1)
    {
        found = s2.find(c1);
        if (found != std::string::npos)
        {
            return "YES";
        }
    }
    return "NO";
}


int main() {
    string s1 = "hello";
    string s2 = "wd";
    cout << twoStrings(s1, s2) << endl;
    system("pause");
}