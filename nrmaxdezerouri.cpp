#include <iostream>

using namespace std;

int a[1000001];

int main()
{
    int n, k;
    cin >> n >> k;
    int st = 1, zerouri = 0, maxim = 0;

    for (int dr = 1; dr <= n; dr++)
    {
        cin >> a[dr];
        if (a[dr] == 0) zerouri++;

        while (zerouri > k)
        {
            if (a[st] == 0) zerouri--;
            st++;
        }

        if (dr - st + 1 > maxim) maxim = dr - st + 1;
    }

    cout << maxim;
    return 0;
}