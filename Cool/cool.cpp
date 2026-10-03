#include <fstream>

using namespace std;

ifstream fin("cool.in");
ofstream fout("cool.out");

int main()
{
    int p, n, k;
    fin >> p >> n >> k;

    int v[5001];

    for (int i = 1; i <= n; i++)
        fin >> v[i];

    if (p == 1)
    {
        int maxi = v[1], mini = v[1];
        bool distincte = true;
        int nr = 0;

        for (int i = 1; i <= k; i++)
        {
            if (v[i] > maxi)
                maxi = v[i];
            if (v[i] < mini)
                mini = v[i];
        }

        for (int i = 1; i <= k; i++)
        {
            int cnt = 0;

            for (int j = 1; j <= k; j++)
            {
                if (v[i] == v[j])
                    cnt++;
            }

            if (cnt == 1)
                nr++;
            else
                distincte = false;
        }

        if (maxi - mini == k - 1 && distincte)
            fout << maxi;
        else
            fout << nr;
    }

    else
    {
        int lung_max = 0;
        int nr_secvente = 0;

        for (int i = 1; i <= n; i++)
        {
            int mini = v[i];
            int maxi = v[i];

            int ap[5001] = {};

            for (int j = i; j <= n; j++)
            {
                if (ap[v[j]] == 1) break;
                ap[v[j]] = 1;
                if (v[j] < mini) mini = v[j];
                if (v[j] > maxi) maxi = v[j];

                int lung = j - i + 1;

                if (maxi - mini == lung - 1)
                {
                    if (lung > lung_max)
                    {
                        lung_max = lung;
                        nr_secvente = 1;
                    }
                    else if (lung == lung_max)
                    {
                        nr_secvente++;
                    }
                }
            }
        }

        fout << lung_max << endl << nr_secvente;
    }

    return 0;
}