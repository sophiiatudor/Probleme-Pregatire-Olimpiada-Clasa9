#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("ambuscada.in");
ofstream fout("ambuscada.out");

struct Eveniment
{
    int poz, modificare;
};

Eveniment e[200002];

bool compara(Eveniment a, Eveniment b)
{
    return a.poz < b.poz;
}

int main()
{
    int n, m, vieti;
    fin >> n >> m >> vieti;
    int nr = 0;

    for (int i = 1; i <= m; i++)
    {
        int s, d, x;
        fin >> s >> d >> x;
        nr++;
        e[nr].poz = s;
        e[nr].modificare = x;
        nr++;
        e[nr].poz = d + 1;
        e[nr].modificare = -x;
    }

    sort(e + 1, e + nr + 1, compara);

    long long pierdere = 0, ramasi = 0;
    int anterior = 1, i = 1;

    while (i <= nr)
    {
        int poz = e[i].poz;
        if (pierdere < vieti) ramasi += poz - anterior;
        while (i <= nr && e[i].poz == poz)
        {
            pierdere += e[i].modificare;
            i++;
        }
        anterior = poz;
    }

    if (pierdere < vieti) ramasi += n - anterior + 1;

    fout << ramasi;
    return 0;
}