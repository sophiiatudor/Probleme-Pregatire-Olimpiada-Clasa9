#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string linie, cuvant;
    bool primul = true;
    getline(cin, linie);
    linie += ' ';

    for (char c : linie)
    {
        if (c == ' ')
        {
            if (!primul) cout << " ";
            cout << cuvant << " ";
            reverse (cuvant.begin(), cuvant.end());
            cout << cuvant;
            cuvant.clear();
            primul = false;
        }
        else
        {
            cuvant += c;
        }
    }
    return 0;
}