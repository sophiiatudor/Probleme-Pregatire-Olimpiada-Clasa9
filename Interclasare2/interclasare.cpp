#include <fstream>

using namespace std;

ifstream fin ("interclasare2.in");
ofstream fout ("interclasare2.out");

int a[100001], b[100001], d[200001];

int main ()
{
    int n, m, l = 0;
    fin >> n;
    for (int i = 1; i<=n; i++) fin >> a[i];
    fin >> m;
    for (int i = 1; i<=m; i++) fin >> b[i];

    int i = 1, j = 1;
    while (i<=n && j<=m)
    {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else
        {
            l++;
            d[l] = b[j];
            j++;
            i++;
        }
    }

    for (int i = 1; i<=l; i++)
    {
        fout << d[i] << " ";
        if (i%10 == 0) fout << "\n";
    }
    return 0;
}