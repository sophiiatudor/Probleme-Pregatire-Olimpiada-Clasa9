#include <fstream>

using namespace std;

ifstream fin("carte.in");
ofstream fout("carte.out");

int main()
{
    int n;
    fin >> n;
    int v[n+1];
    for (int i = 1; i <= n; i++)
    {
        int x;
        fin >> x;
        v[x] = i;
    }

    int zile = 1, maxi = 0, save = 0, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i + 1])
        {
            zile++;
            if (cnt > maxi)
                maxi = cnt, save = zile - 1;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }

    if (cnt > maxi)
    {
        maxi = cnt;
        save = zile;
    }
    fout << zile << " " << save << " " << maxi;
}