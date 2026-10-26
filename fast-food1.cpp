#include <iostream>
using namespace std;

int v[200002];

int main()
{
    int n, x, y, maxim = 0, limita = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        v[x]++;
        v[y + 1]--;
        if (y > limita) limita = y;
    }

    int suma = 0;
    for (int i = 0; i <= limita; i++)
    {
        suma += v[i];
        if (suma > maxim) maxim = suma;
    }

    cout << maxim;
    return 0;
}