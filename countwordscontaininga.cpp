#include <iostream>
#include <string>

using namespace std;

int main()
{
    string linie, cuvant;
    int nr = 0;
    getline(cin, linie);
    linie += ' ';

    for (char c : linie)
    {
        if (c == ' ')
        {
            if (cuvant.find('a') != string::npos) nr++;
            cuvant.clear();
        }
        else
        {
            cuvant += c;
        }
    }

    cout << nr << '\n';
    return 0;
}