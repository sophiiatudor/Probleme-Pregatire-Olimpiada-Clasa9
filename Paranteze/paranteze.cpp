#include <fstream>
#include <string>
#include <stack>

using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

int main()
{
    int n;
    string s;
    fin >> n >> s;

    stack<int> stiva;
    int ultimaGresita = -1;
    int maxim = 0;

    for (int i = 1; i <= n; i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
        {
            stiva.push(i);
            continue;
        }

        char pereche;
        if (c == ')') pereche = '(';
        else if (c == ']') pereche = '[';
        else pereche = '{';

        if (stiva.empty() || s[stiva.top()] != pereche)
        {
            while (!stiva.empty()) stiva.pop();
            ultimaGresita = i;
        }
        else
        {
            stiva.pop();

            int limita = ultimaGresita;
            if (!stiva.empty()) limita = stiva.top();

            int lungime = i - limita;
            if (lungime > maxim) maxim = lungime;
        }
    }

    fout << maxim << '\n';
    return 0;
}