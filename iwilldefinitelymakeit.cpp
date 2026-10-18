#include <iostream>

using namespace std;

int v[100005];

int main() 
{
    int t;
    cin >> t;

    while (t > 0) 
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> v[i];

        int h = v[k];

        sort(v + 1, v + n + 1);

        int poz = 1;

        while (v[poz] < h) poz++;

        bool ok = true;

        for (int i = poz + 1; i <= n; i++) 
        {
            if (v[i] - v[i - 1] > h - 1) 
            {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";

        t--;
    }

    return 0;
}