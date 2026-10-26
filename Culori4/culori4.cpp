#include <fstream>

using namespace std;

ifstream fin("culori.in");
ofstream fout("culori.out");

int v[10002];
long long dif[10002];

int main()
{
    int cerinta, c, n, m;
    fin >> cerinta;
    fin >> c >> n >> m;

    for (int i = 1; i <= n; i++) fin >> v[i];

    if (cerinta == 1)
    {
        int lung = 1, maxim = 1;
        for (int i = 2; i <= n; i++)
        {
            if (v[i] == v[i - 1]) lung++;
            else lung = 1;

            if (lung > maxim) maxim = lung;
        }
        fout << maxim;
    }

    else
    {
        int a, b;
        long long x;
        for (int i = 1; i <= m; i++)
        {
            fin >> a >> b >> x;
            dif[a] += x;
            dif[b + 1] -= x;
        }

        for (int i = 1; i <= n; i++)
        {
            dif[i] += dif[i - 1];
            fout << v[i] + dif[i] << ' ';
        }
    }

    return 0;
}