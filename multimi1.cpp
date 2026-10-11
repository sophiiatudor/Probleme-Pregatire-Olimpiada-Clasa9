#include <iostream>

using namespace std;

int a[100001], b[100001], c[200002], d[200001];

int main ()
{
    int n, m, k = 0, l = 0;
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i<=m; i++) cin >> b[i];

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
            l++;
            d[l] = b[j];
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
        cout << c[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i<=l; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}