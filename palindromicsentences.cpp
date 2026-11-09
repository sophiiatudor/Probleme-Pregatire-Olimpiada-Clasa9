#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) 
    {
        string s, t = "";
        getline(cin, s);

        for (char c : s) 
        {
            if (c != ' ')
                t += c;
        }

        string copie = t;
        reverse(copie.begin(), copie.end());

        if (t == copie)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
