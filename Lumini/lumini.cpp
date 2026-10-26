#include <fstream>
using namespace std;

ifstream fin("lumini.in");
ofstream fout("lumini.out");

long long v[200002];

int main()
{
    int c, n, m, s, d;
    long long x;
    fin >> c >> n >> m;

    while (m--)
    {
        fin >> s >> d >> x;
        v[s] += x;
        v[d + 1] -= x;
    }

    for (int i = 1; i <= n; i++) v[i] += v[i - 1];

    if (c == 1)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++) sum += v[i];
        fout << sum;
    }

    else
    {
        long long maxi = v[1];
        for (int i = 2; i <= n; i++) if (v[i] > maxi) maxi = v[i];
        fout << maxi;
    }

    return 0;
}