#include <iostream>
#include <string>
using namespace std;

int f[11];

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++)
        f[a[i - 1] - '0' + 1]++;

    for (int i = 1; i <= b.size(); i++)
        f[b[i - 1] - '0' + 1]++;

    for (int i = 10; i >= 1; i--)
        for (int j = 1; j <= f[i]; j++)
            cout << i - 1;

    return 0;
}
