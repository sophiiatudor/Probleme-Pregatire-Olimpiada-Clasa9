#include <fstream>

using namespace std;

ifstream fin("mcub.in");
ofstream fout("mcub.out");

int main()
{
    int n;
    long long h, anterior = 0, suma = 0;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> h;
        if (h > anterior)
        {
            suma += h - anterior;
        }
        anterior = h;
    }

    fout << suma;
    return 0;
}