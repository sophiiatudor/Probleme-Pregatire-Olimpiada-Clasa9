#include <iostream>
#include <algorithm>

using namespace std;

long long v[200005];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        long long ans = 0;

        for (int i = 1; i <= n; i++)
        {
            long long s = 0;
            for (int j = 1; j <= m; j++)
            {
                long long p;
                cin >> p;
                s += p;
                ans += s;
            }

            v[i] = s;
        }

        sort(v + 1, v + n + 1);
        reverse(v + 1, v + n + 1);

        long long s = 0;

        for (int i = 1; i <= n; i++)
        {
            ans += s * m;
            s += v[i];
        }

        cout << ans << '\n';
    }

    return 0;
}