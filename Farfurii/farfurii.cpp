#include <fstream>
using namespace std;

ifstream fin("farfurii.in");
ofstream fout("farfurii.out");

int main()
{
    int n, x = 1;
    long long k;
    fin >> n >> k;

    while (1LL * x * (x - 1) / 2 < k) x++;

    for (int i = 1; i <= n - x; i++) fout << i << " ";

    long long r = k - 1LL * (x - 1) * (x - 2) / 2;
    int a = n - x + 1;

    fout << a + r << " ";

    for (int i = n; i >= a; i--)
    {
        if (i != a + r) fout << i << " ";
    }

    return 0;
}