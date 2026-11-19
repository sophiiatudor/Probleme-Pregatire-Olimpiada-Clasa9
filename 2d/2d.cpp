#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("2d.in");
ofstream fout("2d.out");

int n, k;
long long x[200001];

bool posibil(long long lungime)
{
    int segmente = 1;
    long long capat = x[1] + lungime;
    for (int i = 2; i <= n; i++)
    {
        if (x[i] > capat)
        {
            segmente++;
            if (segmente > k) return false;
            capat = x[i] + lungime;
        }
    }

    return true;
}

int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        double abscisa, ordonata;
        fin >> abscisa >> ordonata; 
        double miimi = abscisa * 1000;

        if (miimi >= 0) x[i] = (long long)(miimi + 0.5);
        else x[i] = (long long)(miimi - 0.5);
    }

    sort(x + 1, x + n + 1);
    long long st = 1000;
    long long dr = max(1000LL, x[n] - x[1]);

    while (st < dr)
    {
        long long mij = st + (dr - st) / 2;

        if (posibil(mij)) dr = mij;
        else st = mij + 1;
    }

    fout << st / 1000 << '.';

    int zecimale = st % 1000;
    if (zecimale < 100) fout << '0';
    if (zecimale < 10) fout << '0';

    fout << zecimale << '\n';

    return 0;
}