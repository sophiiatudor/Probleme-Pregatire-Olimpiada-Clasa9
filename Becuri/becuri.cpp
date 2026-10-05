#include <fstream>

using namespace std;

ifstream fin("becuri.in");
ofstream fout("becuri.out");

int a[501][501];

int main()
{
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
        }
    }
}