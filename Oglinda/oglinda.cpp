#include <fstream>

using namespace std;

ifstream fin("oglinda.in");
ofstream fout("oglinda.out");

int main() 
{

    int n, m;
    fin >> n >> m;
    int stanga[2000], dreapta[2000];
    int nr = 0;

    for (int i = 0; i < m; ++i) 
    {
        int tip, poz;
        fin >> tip >> poz;

        if (tip == 1) 
        {
            stanga[nr] = poz;
            fin >> dreapta[nr];
            nr++;
        } 
        else 
        {
            for (int j = nr - 1; j >= 0; j--) 
            {
                if (stanga[j] <= poz && poz <= dreapta[j]) 
                {
                    poz = stanga[j] + dreapta[j] - poz;
                }
            }

            fout << poz << '\n';
        }
    }

    return 0;
}