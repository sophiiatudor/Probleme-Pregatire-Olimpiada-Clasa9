#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int main ()
{
    int t;
    cin >> t;

    for (int i = 1; i<=t; i++)
    {
        long long x, cx, n = 1, sum = 0, pasi = 0;
        cin >> x;
        int v[N];
        cx = x;

        while (cx >= 10)
        {
            v[n] = cx % 10;
            sum += cx % 10;
            cx = cx / 10;
            n++;
        }

        v[n] = cx - 1;
        sum += cx;

        sort (v + 1, v + n + 1);
        reverse(v + 1, v + n + 1);

        int p = 1;
        while (sum > 9 && p <= n)
        {
            sum -= v[p];
            pasi++;
            p++;
        }

        cout << pasi << "\n";

    }
    return 0;
}