#include <fstream>

using namespace std;

ifstream fin("carte.in");
ofstream fout("carte.out");

int main ()
{
    int x;
    fin >> x;
    int v[x];
    for (int i = 1; i<=x; i++)
    {
        fin >> v[i];
    }

    for
}