#include <fstream>

using namespace std;

ifstream fin ("stdin");
ofstream fout ("stdout");

int v[100001];

int main ()
{
    int n;
    fin >> n;
    for (int i = 1; i<=n; i++)
    {
        fin >> v[i];
    }
    long long maxim = v[1], sum = 0;
    int st = 1, dr = 1, last = 0;

    for (int i = 1; i<=n; i++)
    {
        sum = sum + v[i];

        if (sum > maxim)
        {
            maxim = sum;
            dr = i;
            st = last + 1;
        }
        if (sum <= 0)
        {
            sum = 0;
            last = i;
        }
    }

    fout << st << " " << dr;
    return 0;
}