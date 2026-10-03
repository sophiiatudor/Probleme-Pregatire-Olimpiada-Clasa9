#include <fstream>
using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int sp[6000005];

int main() 
{
    int n;
    fin >> n;
    sp[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        int x;
        fin >> x;
        sp[i] = sp[i - 1] + x;
    }

    int maxim = sp[1], st = 1, dr = 1, sp_min = 0, poz_sp_min = 0;

    for (int i = 1; i <= n; i++) 
    {
        int suma_curenta = sp[i] - sp_min;
        if (suma_curenta > maxim) 
        {
            maxim = suma_curenta;
            st = poz_sp_min + 1;
            dr = i;
        }
        if (sp[i] < sp_min) 
        {
            sp_min = sp[i];
            poz_sp_min = i;
        }
    }

    fout << maxim << " " << st << " " << dr << endl;
}