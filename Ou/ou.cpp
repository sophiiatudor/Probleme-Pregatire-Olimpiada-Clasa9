#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("ou.in");
ofstream fout("ou.out");

int oua[100002];
long long dif[100002];

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) fin >> oua[i];
    for (int i = 1; i <= n; i++)
    {
        int r = min(i - 1, n - i);
        r = min(r, oua[i] / 2);
        if (r > 0)
        {
            int cantitate = oua[i] / (2 * r);

            dif[i - r] += cantitate;
            dif[i] -= cantitate;

            dif[i + 1] += cantitate;
            dif[i + r + 1] -= cantitate;

            oua[i] %= 2 * r;
        }
    }

    long long primite = 0;
    for (int i = 1; i <= n; i++)
    {
        primite += dif[i];
        fout << oua[i] + primite << ' ';
    }

    return 0;
}