#include <iostream>

using namespace std;

int n, m, maxi = 0;
int v[1001];

long long verif(long long x)
{
    long long S = 0;
    for (int i = 1; i <= n; i++)
    {
        S = S + x / v[i];
    }
    return S;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (maxi < v[i])
            maxi = v[i];
    }
    long long st = 0, dr = m * maxi;
    while (st < dr)
    {
        long long mij = (st + dr) / 2;
        if (verif(mij) < m)
        {
            st = mij + 1;
        }
        else
            dr = mij;
    }
    int ans = st;
    cout << ans;
}