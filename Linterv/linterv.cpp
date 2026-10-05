#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("linterv.in");
ofstream fout("linterv.out");

pair<int, int> intervale[5005];

int main()
{
    int t;
    fin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        fin >> n;

        for (int j = 1; j <= n; j++)
        {
            fin >> intervale[j].first;
            fin >> intervale[j].second;
        }

        sort(intervale + 1, intervale + n + 1);

        int st = intervale[1].first;
        int dr = intervale[1].second;

        long long suma = 0;

        for (int j = 2; j <= n; j++)
        {
            int st_act = intervale[j].first;
            int dr_act = intervale[j].second;

            if (st_act <= dr)
            {
                if (dr_act > dr)
                {
                    dr = dr_act;
                }
            }
            else
            {
                suma = suma + dr - st;

                st = st_act;
                dr = dr_act;
            }
        }

        suma = suma + dr - st;

        fout << suma << '\n';
    }

    return 0;
}