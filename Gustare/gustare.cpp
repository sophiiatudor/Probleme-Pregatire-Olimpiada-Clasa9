#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("gustare.in");
ofstream fout("gustare.out");

int mere[500001], coceni[500001];

int main()
{
    int n, m, t;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> coceni[i];

    fin >> m;
    for (int i = 1; i <= m; i++)
        fin >> mere[i];

    fin >> t;

    sort(coceni + 1, coceni + n + 1);
    sort(mere + 1, mere + m + 1);

    while (t--)
    {
        long long x;
        fin >> x;

        int i = 1, j = m;
        bool gasit = false;

        while (i <= n && j >= 1)
        {
            long long suma = coceni[i] + mere[j];

            if (suma == x)
            {
                gasit = true;
                break;
            }

            if (suma < x)
                i++;
            else
                j--;
        }

        if (gasit==true) fout << "DA\n";
        else fout << "NU\n";
    }

    return 0;
}