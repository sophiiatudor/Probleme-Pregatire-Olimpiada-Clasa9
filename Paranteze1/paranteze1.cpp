#include <fstream>
#include <string>

using namespace std;

ifstream fin("paranteze1.in");
ofstream fout("paranteze1.out");

int main() 
{
    int n;
    string s;

    fin >> n;
    fin.ignore(10000, '\n');

    for (int k = 0; k < n; ++k) 
    {
        getline(fin, s);
        int deschise = 0;

        for (char c : s) 
        {
            if (c == '(') deschise++;
            else if (c == ')') deschise--;

            if (deschise < 0) break;
        }

        fout << (deschise == 0) << '\n';
    }

    return 0;
}