#include <fstream>
using namespace std;

ifstream fin("easyquery.in");
ofstream fout("easyquery.out");

long long v[100002], dif[100002];

int main()
{
    int n, t, tip, x, y;
    long long p;

    fin >> n;
    for (int i = 1; i <= n; i++) fin >> v[i];
    fin >> t;

    while (t--)
    {
        fin >> tip >> x >> y >> p;
        if (tip == 2) p = -p;
        dif[x] += p;
        dif[y + 1] -= p;
    }

    for (int i = 1; i <= n; i++)
    {
        dif[i] += dif[i - 1];
        fout << v[i] + dif[i] << ' ';
    }
    return 0;
}