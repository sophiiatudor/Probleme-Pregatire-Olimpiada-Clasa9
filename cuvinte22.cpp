#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, cuv = "";
    getline(cin, s);

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ')
            cuv += s[i];
        else if (cuv.size() > 0)
        {
            for (int j = 0; j < cuv.size(); j++)
                for (int k = j + 1; k < cuv.size(); k++)
                    if (cuv[j] < cuv[k])
                    {
                        char aux = cuv[j];
                        cuv[j] = cuv[k];
                        cuv[k] = aux;
                    }

            cout << cuv << '\n';
            cuv = "";
        }
    }

    return 0;
}
