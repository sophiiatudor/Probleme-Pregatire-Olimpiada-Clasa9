#include <fstream>

using namespace std;

ifstream fin("defrag.in");
ofstream fout("defrag.out");

int m[101][361];

int main()
{
    int v, p, s, c, x, y;
    fin >> v >> p >> s >> c;
    for (int i = 1; i <= c; i++)
    {
        fin >> x >> y;
        m[x][y] = 1;
    }

    if (v == 1)
    {
        int cnt = 0;

        for (int i = 1; i <= p; i++)
        {
            int ocupate = 0;

            for (int j = 1; j <= s; j++)
            {
                if (m[i][j] == 1) ocupate++;
            }

            if (ocupate == 0) cnt++;
        }

        fout << cnt;
    }

    else
    {
        for (int i = 1; i <= p; i++)
        {
            int k = 0;
            for (int j = 1; j <= s; j++) k += m[i][j];

            int suma = 0;

            for (int j = 1; j <= k; j++) suma += m[i][j];

            int maxi = suma;

            for (int st = 2; st <= s; st++)
            {
                suma -= m[i][st - 1];
                int dr = st + k - 1;

                if (dr > s) dr -= s;
                
                suma += m[i][dr];
                maxi = max(maxi, suma);
            }
            fout << k - maxi << " ";
        }
    }
}