#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, cuv = "", rez = "";
    getline(cin, s);
    int ok = 0;

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ') cuv += s[i];
        else if (cuv.size() > 0)
        {
            int n = cuv.size();
            if (n % 2 == 0)
            {
                ok = 1;
                for (int j = 0; j < n / 2; j++)
                {
                    char aux = cuv[j];
                    cuv[j] = cuv[j + n / 2];
                    cuv[j + n / 2] = aux;
                }
            }

            if (rez.size() > 0) rez += ' ';
            rez += cuv;
            cuv = "";
        }
    }

    if (ok == 1) cout << rez;
    else cout << "nu exista";

    return 0;
}
