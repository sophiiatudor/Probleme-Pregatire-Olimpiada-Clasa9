#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("siruri4.in");
ofstream fout("siruri4.out");

long long a[100005];

struct Element 
{
    long long suma;
    int poz;
};

Element v[100005];

bool cmp(Element a, Element b) 
{
    if (a.suma == b.suma)
        return a.poz < b.poz;
    return a.suma < b.suma;
}

int main() 
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++) fin >> a[i];

    for (int i = 1; i <= n; i++) 
    {
        long long x;
        fin >> x;
        a[i] -= x;
    }

    long long s = 0;

    v[0] = {0, 0};

    for (int i = 1; i <= n; i++) 
    {
        s += a[i];
        v[i] = {s, i};
    }

    sort(v, v + n + 1, cmp);

    int maxim = 0;
    int i = 0;

    while (i <= n) 
    {
        int j = i;

        while (j <= n && v[j].suma == v[i].suma) j++;

        maxim = max(maxim, v[j - 1].poz - v[i].poz);

        i = j;
    }

    fout << maxim;

    return 0;
}