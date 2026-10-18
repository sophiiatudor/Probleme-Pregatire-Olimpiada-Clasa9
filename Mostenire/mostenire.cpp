#include <fstream>

using namespace std;

const int N = 1000005;
int n, k;
long long a[N], total, sumaGrupa[105];
int nrSaci[105], fiuGrupa[105], folosit[105];

ifstream fin("mostenire.in");
ofstream fout("mostenire.out");

bool verificare(long long x)
{
    long long suma = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        suma += a[i];

        if (suma >= x)
        {
            cnt++;
            suma = 0;
        }
    }

    return cnt >= k;
}

int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
        total += a[i];
    }

    long long st = 0, dr = total / k, ans = 0;

    while (st <= dr)
    {
        long long mij = st + (dr - st) / 2;

        if (verificare(mij))
        {
            ans = mij;
            st = mij + 1;
        }
        else
        {
            dr = mij - 1;
        }
    }

    int grupa = 1;
    int nr = 0;
    long long suma = 0;

    for (int i = 1; i <= n; i++)
    {
        suma += a[i];
        nr++;

        if (grupa < k && suma >= ans)
        {
            sumaGrupa[grupa] = suma;
            nrSaci[grupa] = nr;
            grupa++;
            suma = 0;
            nr = 0;
        }
    }
    sumaGrupa[k] = suma;
    nrSaci[k] = nr;

    for (int fiu = 1; fiu <= k; fiu++)
    {
        long long maxim = -1;
        int poz = 0;

        for (int i = 1; i <= k; i++)
        {
            if (folosit[i] == 0 && sumaGrupa[i] > maxim)
            {
                maxim = sumaGrupa[i];
                poz = i;
            }
        }

        folosit[poz] = 1;
        fiuGrupa[poz] = fiu;
    }

    fout << ans << '\n';

    for (int i = 1; i <= k; i++)
    {
        fout << fiuGrupa[i] << ' ' << nrSaci[i] << '\n';
    }

    return 0;
}