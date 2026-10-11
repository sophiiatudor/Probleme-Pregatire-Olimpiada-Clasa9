#include <fstream>

using namespace std;

ifstream fin("3secv.in");
ofstream fout("3secv.out");

long long sp[1000001];
long long cnt[3];

int main()
{
    int n, r;
    long long nr = 0;
    fin >> n >> r;
    cnt[0] = 1;
    fin >> sp[1];
    for (int i = 2; i<=n; i++)
    {
        int x;
        fin >> x;
        sp[i] = sp[i-1] + x;
    }

    for (int i = 1; i <= n; i++)
    {   
        int rest = sp[i] % 3;
        int m = (rest - r + 3)%3;
        nr += cnt[m];
        cnt[rest]++;
    }
    fout << nr;
    return 0;

}