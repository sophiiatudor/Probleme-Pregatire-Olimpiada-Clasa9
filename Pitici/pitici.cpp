#include <fstream>

using namespace std;

ifstream fin("pitici.in");
ofstream fout("pitici.out");

long long suma[200002];
int dif[200002];

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        fin >> x;
        suma[i] = suma[i - 1] + x;
    }

    for (int i = 1; i <= n; i++)
    {
        long long b;
        fin >> b;
        int st = i, dr = n, poz = n;

        while (st <= dr)
        {
            int mij = st + (dr - st) / 2;
            if (suma[mij] - suma[i - 1] >= b)
            {
                poz = mij;
                dr = mij - 1;
            }
            else st = mij + 1;
        }
        dif[i]++;
        dif[poz + 1]--;
    }

    int vizite = 0, maxim = 0, nr = 0;
    for (int i = 1; i <= n; i++)
    {
        vizite += dif[i];
        if (vizite > maxim)
        {
            maxim = vizite;
            nr = 1;
        }
        else if (vizite == maxim) nr++;
    }

    fout << maxim << " "<< nr;
    return 0;
}