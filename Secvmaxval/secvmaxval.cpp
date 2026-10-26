#include <fstream>
using namespace std;

ifstream fin("secvmaxval.in");
ofstream fout("secvmaxval.out");

int v[200001];

int main()
{
    int n;
    long long val, sum = 0;
    fin >> n >> val;

    for (int i = 1; i <= n; i++) fin >> v[i];

    int st = 1, lung = 0;
    for (int dr = 1; dr <= n; dr++)
    {
        sum += v[dr];
        while (st <= dr && sum > val)
        {
            sum -= v[st];
            st++;
        }
        if (dr - st + 1 > lung) lung = dr - st + 1;
    }

    fout << lung;
    return 0;
}