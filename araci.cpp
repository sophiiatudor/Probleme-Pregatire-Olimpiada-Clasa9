#include <iostream>

using namespace std;

long long d[100001];

int main()
{
    int n;
    long long a, maxim = 0;
    cin >> n >> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if (d[i] > maxim) maxim = d[i];
    }

    long long st = 1, dr = maxim, rezultat = 0;
    while (st <= dr)
    {
        long long mij = st + (dr - st) / 2;
        long long nr = 0;

        for (int i = 1; i <= n; i++)
        {
            nr += d[i] / mij;
            if (nr >= a) break;
        }

        if (nr >= a)
        {
            rezultat = mij;
            st = mij + 1;
        }
        
        else dr = mij - 1;
    }

    cout << rezultat;
    return 0;
}