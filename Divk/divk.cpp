#include <fstream>

using namespace std;

ifstream fin ("divk.in");
ofstream fout ("divk.out");

int sp[500001];
int frecventa[100001];

int main ()
{
    int n, k, a, b, x, y;
    fin >> n >> k >> a >> b;
    sp[0] = 0;
    for (int i = 1; i<=n; i++)
    {
        fin >> x;
        sp[i] = (sp[i-1] + x)%k;
    }
    long long cnt = 0;
    for (int i = 1; i<=n; i++)
    {
        x = i - a;
        if (x >= 0) frecventa[sp[x]]++;
        
        y = i - b - 1;
        if (y >= 0) frecventa[sp[y]]--;

        cnt += frecventa[sp[i]];
    }

    fout << cnt;
}