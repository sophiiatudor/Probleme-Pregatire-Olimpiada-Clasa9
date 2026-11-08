#include <iostream>
#include <string>

using namespace std;

int main()
{
    int teste;
    cin >> teste;

    for (int t = 1; t <= teste; t++)
    {
        string s;
        cin >> s;

        int lungime = 0, deschideri = 0, perechi = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                lungime++;
                deschideri++;
            }
            else if (c == ')')
            {
                if (deschideri > perechi && lungime > 2 * perechi) perechi++;

                lungime++;
            }
            else
            {
                lungime -= c - '0';

                if (deschideri > lungime) deschideri = lungime;
                if (perechi > lungime / 2) perechi = lungime / 2;
            }
        }

        if (2 * perechi == lungime) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}