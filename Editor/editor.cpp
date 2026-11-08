#include <fstream>
#include <string>
#include <stack>

using namespace std;

ifstream fin("editor.in");
ofstream fout("editor.out");

int main()
{
    int t;
    fin >> t;

    for (int test = 1; test <= t; test++)
    {
        string taste, ecran;
        fin >> taste;

        for (char c : taste)
        {
            if (c == 'E') break;

            if (c == '*')
            {
                if (!ecran.empty()) ecran.pop_back();
            }
            else
            {
                ecran.push_back(c);
            }
        }

        stack<char> stiva;
        bool corect = true;

        for (char c : ecran)
        {
            if (c == '(' || c == '[')
            {
                stiva.push(c);
            }
            else
            {
                char pereche;

                if (c == ')') pereche = '(';
                else pereche = '[';

                if (stiva.empty() || stiva.top() != pereche)
                {
                    corect = false;
                    break;
                }

                stiva.pop();
            }
        }

        if (corect && stiva.empty()) fout << ":)\n";
        else fout << ":(\n";
    }

    return 0;
}