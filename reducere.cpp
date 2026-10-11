#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int t;
    cin >> t;

    for (int p = 1; p<=t; p++)
    {
        int n, m;
        cin >> n;
        int a[n+1];
        for (int i = 1; i<=n; i++) cin >> a[i];
        cin >> m;
        int b[m+1];
        for (int i = 1; i<=m; i++) cin >> b[i];

        bool ok = true;
        int indice = 1, x = 0;
        for (int i = 1; i<=n; i++)
        {
            x += a[i];
            if (indice > m)
            {
                ok = false;
                break;
            }
            else if (x==b[indice])
            {
                indice++;
                x = 0;
            }
            else if (x>b[indice])
            {
                ok = false;
                break;
            }
        }

        if (indice != m + 1 || x != 0) ok = false;

        if (ok==true) cout << 1 << endl;
        else cout << 0 << endl; 
    }
    return 0;
}