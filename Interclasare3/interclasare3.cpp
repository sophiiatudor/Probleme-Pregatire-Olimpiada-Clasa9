#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("interclasare3.in");
ofstream fout("interclasare3.out");

int a[100001], b[100001], c[200001];

int main()
{
    int n, m, k = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    sort(b + 1, b + m + 1);

    int i = 1, j = 1;
    while (i <= n && j <= m)
    {
        if (a[i] < b[j])
        {
            if (a[i] % 2 == 0)
            {
                k++;
                c[k] = a[i];
            }

            i++;
        }
        else if (a[i] > b[j])
        {
            if (b[j] % 2 == 0)
            {
                k++;
                c[k] = b[j];
            }

            j++;
        }
        else
        {
            if (a[i] % 2 == 0)
            {
                k += 2;
                c[k] = b[j];
                c[k - 1] = b[j];
            }
            j++;
            i++;
        }
    }

    while (i <= n)
    {
        if (a[i] % 2 == 0)
        {
            k++;
            c[k] = a[i];
        }

        i++;
    }
    while (j <= m)
    {
        if (b[j] % 2 == 0)
        {
            k++;
            c[k] = b[j];
        }

        j++;
    }

    for (int i = 1; i <= k; i++)
    {
        fout << c[i] << " ";
        if (i % 20 == 0)
            fout << "\n";
    }
    return 0;
}