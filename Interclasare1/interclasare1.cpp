#include <fstream>

using namespace std;

ifstream fin ("interclasare1.in");
ofstream fout ("interclasare1.out");

int a[100001], b[100001], c[200002];

int main ()
{
    int n, m, k = 0;
    fin >> n;
    for (int i = 1; i<=n; i++) fin >> a[i];
    fin >> m;
    for (int i = 1; i<=m; i++) fin >> b[i];

    int i = 1, j = 1;
    while (i<=n && j<=m)
    {
        if (a[i] < b[j])
        {
            k++;
            c[k] = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            k++;
            c[k] = b[j];
            j++;
        }
        else
        {
            k++;
            c[k] = b[j];
            j++;
            i++;
        }
    }

    while (i<=n)
    {
        k++;
        c[k] = a[i];
        i++;
    }
    while (j<=m)
    {
        k++;
        c[k] = b[j];
        j++;
    }

    for (int i = 1; i<=k; i++)
    {
        fout << c[i] << " ";
        if (i%10==0) fout << "\n";
    }
    return 0;
}