#include <fstream>

using namespace std;

ifstream fin ("transport.in");
ofstream fout ("transport.out"); 

int n, k, maxi = 0, suma = 0;
int v[16001];

int verif (long long x)
{
    int S = 0, nr = 1;
    for (int i = 1; i<=n; i++)
    {
        if (S + v[i] <=x) S += v[i];
        else nr++, S = v[i];
    }
    return nr;
}

int main ()
{
    fin >> n >> k;
    for (int i = 1; i<=n; i++)
    {
        fin >> v[i];
        suma += v[i];
        if (maxi<v[i]) maxi = v[i];
    }
    int st = maxi, dr = suma;
    while (st < dr)
    {
        int mij = st + (dr - st)/2;
        if (verif(mij)<=k)
        {
            dr = mij;
        }
        else st = mij + 1;
    }
    int ans = st;
    fout << ans;
}