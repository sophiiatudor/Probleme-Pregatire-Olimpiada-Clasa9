#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("perechi.in");
ofstream fout("perechi.out");

struct Element
{
    long long val;
    int poz;
};

Element a[2001];

bool compara(Element x, Element y)
{
    return x.val < y.val;
}

int main()
{
    int c, n;
    fin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i].val;
        a[i].poz = i;
    }

    sort(a + 1, a + n + 1, compara);

    if (c == 1)
    {
        int nr = 0;
        for (int i = 1; i <= n; i++) if (a[i].val < a[n].val) nr++;

        if (nr == 2 && a[1].val == a[2].val)
        {
            fout << a[1].poz << " " << a[2].poz << " " << a[n].val - a[1].val;
        }
        else fout << 0;
    }

    else
    {
        for (int i = 1; i < n; i += 2)
        {
            long long diferenta = a[i + 1].val - a[i].val;

            if (diferenta > 0)
            {
                fout << a[i].poz << " " << a[n].poz << " " << diferenta << "\n";
                a[i].val += diferenta;
                a[n].val += diferenta;
            }
        }

        for (int i = 1; i < n; i += 2)
        {
            long long diferenta = a[n].val - a[i].val;

            if (diferenta > 0)
            {
                fout << a[i].poz << " " << a[i + 1].poz << " " << diferenta << "\n";
            }
        }
    }

    return 0;
}