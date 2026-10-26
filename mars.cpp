#include <iostream>

using namespace std;

int v[200001];

int main()
{
    int n, m, s, d, x;
    cin >> n >> m;

    while (m--)
    {
        cin >> s >> d >> x;
        v[s] += x;
        v[d + 1] -= x;
    }
    cout << v[1] << " ";
    for (int i = 2; i <= n; i++)
    {
        v[i] += v[i - 1];
        cout << v[i] << " ";
    }
    return 0;
}