#include <iostream>
using namespace std;

int a[1000001], f[1000001];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int st = 1, distincte = 0;
    long long nr = 0;

    if (k == 0)
    {
        long long total = n;
        total = total * (n + 1) / 2;
        cout << total;
        return 0;
    }

    for (int dr = 1; dr <= n; dr++)
    {
        f[a[dr]]++;
        if (f[a[dr]] == 1)
            distincte++;

        while (distincte >= k)
        {
            nr += n - dr + 1;
            f[a[st]]--;
            if (f[a[st]] == 0)
                distincte--;
            st++;
        }
    }

    cout << nr;
    return 0;
}