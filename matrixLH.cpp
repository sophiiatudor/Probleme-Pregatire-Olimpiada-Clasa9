#include <iostream>

using namespace std;

int sp[501][501];

int main()
{
    int n, k, L, H;
    cin >> n >> k >> L >> H;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            sp[i][j] = x + sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
        }
    }

    int cnt = 0;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            int suma = sp[i][j] - sp[i - k][j] - sp[i][j - k] + sp[i - k][j - k];
            if (L <= suma && suma <= H) cnt++;
        }
    }

    cout << cnt;
    return 0;
}