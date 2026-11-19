#include <fstream>
#include <string>

using namespace std;

ifstream fin("harddp.in");
ofstream fout("harddp.out");

int main()
{
    int T;
    fin >> T;
    while (T--)
    {
        int n;
        string a;
        fin >> n >> a;
        int nr0 = 0;
        for (int i = 0; i < n; i++) if (a[i] == '0') nr0++;

        int nr1 = n - nr0;
        char cifra;
        if (nr0 <= nr1) cifra = '0';
        else cifra = '1';

        for (int i = 0; i < n; i++) fout << cifra;
        fout << '\n';
    }
    return 0;
}