#include <fstream>
#include <string>
#include <stack>

using namespace std;

ifstream fin("paranteze3.in");
ofstream fout("paranteze3.out");

int main()
{
    int n;
    string s;
    fin >> n;
    fin.ignore(10000, '\n');

    for (int k = 1; k <= n; k++)
    {
        getline(fin, s);
        stack<char> stiva;
        bool corect = true;

        for (char c : s)
        {
            if (c == '(' || c == '[')
            {
                stiva.push(c);
            }
            else if (c == ')' || c == ']')
            {
                char pereche;

                if (c == ')')
                {
                    pereche = '(';
                }
                else
                {
                    pereche = '[';
                }

                if (stiva.empty() || stiva.top() != pereche)
                {
                    corect = false;
                    break;
                }

                stiva.pop();
            }
        }

        fout << (corect && stiva.empty()) << '\n';
    }

    return 0;
}