#include <fstream>

using namespace std;
int v[102], n, k;
bool ok = 0;
ifstream fin("sumainsecv.in");
ofstream fout("sumainsecv.out");

int main()
{
    int j = 1, s = 0, i;
    fin >> n >> k;
    for (i = 1; i <= n; i++)
        fin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        s += v[i];
        while (s > k)
            s = s - v[j++];
        if (s == k)
        {
            fout << j << " " << i;
            ok = 1;
            return 0;
        }
    }
    if (ok == 0)
        fout << "0 0";
}