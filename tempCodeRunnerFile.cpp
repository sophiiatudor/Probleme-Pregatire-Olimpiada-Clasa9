#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int nr;
    cin >> nr;
    cin.ignore(1000, '\n');

    for (int i = 1; i <= nr; i++)
    {
        string linie, prop1, prop2;
        getline(cin, linie);

        for (char c : linie)
        {
            if (c >= 'a' && c <= 'z')
            {
                prop1 += c;
            }
        }

        prop2 = prop1;
        reverse(prop2.begin(), prop2.end());

        if (prop1 == prop2)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}