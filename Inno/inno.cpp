#include <fstream>
using namespace std;

const int N = 200005;

int a[N], pref[N], suf[N];

ifstream fin("inno.in");
ofstream fout("inno.out");

int main()
{
    int n, k;
    fin >> n >> k;

    for (int i = 1; i <= n; i++) fin >> a[i];

    int mask = (1U << 31) - 1;
    pref[0] = mask;

    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] & a[i];

    suf[n + 1] = mask;

    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] & a[i];

    long long ans = 0;
    int j = 1;

    for (int i = 1; i <= n; i++)
    {
        if (j < i) j = i;

        while (j <= n && __builtin_popcount(pref[i - 1] & suf[j + 1]) < k) j++;

        if (j <= n)
        {
            ans += n - j + 1;

            if (i == 1) ans--;
        }
    }

    if (__builtin_popcount(pref[n]) >= k) ans++;

    fout << ans;

    return 0;
}