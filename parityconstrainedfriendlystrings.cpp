#include <iostream>
#include <string>

using namespace std;

int f[2][26];

int main()
{
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size())
    {
        cout << "NOT FRIENDS";
        return 0;
    }

    int n = a.size();

    for (int i = 0; i <= n - 1; i++)
    {
        f[i % 2][a[i] - 'a']++;
        f[i % 2][b[i] - 'a']--;
    }

    for (int p = 0; p <= 1; p++)
        for (int litera = 0; litera <= 25; litera++)
            if (f[p][litera] != 0)
            {
                cout << "NOT FRIENDS";
                return 0;
            }

    cout << "FRIENDS";
    return 0;
}