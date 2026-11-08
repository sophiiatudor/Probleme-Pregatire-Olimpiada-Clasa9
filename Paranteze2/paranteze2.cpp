#include <fstream>
#include <string>

using namespace std;

ifstream fin("paranteze2.in");
ofstream fout("paranteze2.out");

int main()
{
    string s;
    getline(fin, s);
    int deschise = 0, adancime = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            deschise++;
            if (deschise > adancime) adancime = deschise;
        }
        else if (c == ')')
        {
            deschise--;
        }
    }

    fout << adancime << '\n';
    return 0;
}