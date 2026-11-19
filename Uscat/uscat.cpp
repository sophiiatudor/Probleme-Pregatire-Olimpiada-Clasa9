#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("uscat.in");
ofstream fout("uscat.out");

int n;
long long a[100001], x;

bool posibil(long long t) 
{
    long long minute = 0;

    for (int i = 1; i <= n; i++) 
    {
        if (a[i] > t) 
        {
            long long ramas = a[i] - t;
            minute += (ramas + x - 2) / (x - 1);

            if (minute > t) return false;
        }
    }
    return true;
}

int main() 
{
    fin >> n;

    long long maxim = 0;
    for (int i = 1; i <= n; i++) 
    {
        fin >> a[i];
        maxim = max(maxim, a[i]);
    }

    fin >> x;

    if (x == 1) 
    {
        fout << maxim << '\n';
        return 0;
    }

    long long st = 0, dr = maxim;

    while (st < dr) 
    {
        long long t = (st + dr) / 2;
        if (posibil(t)) dr = t;
        else st = t + 1;
    }

    fout << st << '\n';
    return 0;
}