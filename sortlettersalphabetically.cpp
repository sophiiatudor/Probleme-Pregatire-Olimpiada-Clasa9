#include <iostream>
#include <string>

using namespace std;

int f[26];

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) f[s[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        for (int j = 1; j <= f[i]; j++)
            cout << char(i + 'a');

    return 0;
}
