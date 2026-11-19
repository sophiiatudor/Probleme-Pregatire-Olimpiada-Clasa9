#include <iostream>

using namespace std;

int sp[1001][1001];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            int copac = (c == '*');
            sp[i][j] = copac + sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int nrCopaci = sp[y2][x2] - sp[y1 - 1][x2] - sp[y2][x1 - 1] + sp[y1 - 1][x1 - 1];
        cout << nrCopaci << '\n';
    }

    return 0;
}