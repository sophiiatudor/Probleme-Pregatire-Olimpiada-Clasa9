#include <fstream>

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

int v[250002];

int main()
{
    int n, k, m, d, l;
    fin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        fin >> d >> l;
        v[d]++;
        v[d + l]--;
    }

    int straturi = 0, suprafata = 0;
    for (int i = 0; i < n; i++)
    {
        straturi += v[i];
        if (straturi < k) suprafata++;
    }

    fout << suprafata;
    return 0;
}