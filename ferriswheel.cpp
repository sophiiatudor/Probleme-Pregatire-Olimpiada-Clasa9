#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int n, x, gondole = 0;
    cin >> n >> x;
    int v[n+1];
    for (int i = 1; i<=n; i++)
    {
        cin >> v[i];
    }

    sort (v + 1, v + n + 1);
    int st = 1, dr = n;

    while (st<dr)
    {
        if (v[st]+v[dr]<=x)
        {
            gondole++;
            st++;
            dr--;
        }
        else
        {
            gondole++;
            dr--;
        }
    }

    if (st==dr) cout << gondole + 1;
    else cout << gondole;
    return 0;
}