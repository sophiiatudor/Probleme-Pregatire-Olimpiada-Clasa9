#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, cuv = "";
    getline(cin, s);

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ') cuv += s[i];
        else if (cuv.size() > 0)
        {
            int ok = 1;

            for (int j = 0; j < cuv.size(); j++)
                if (cuv[j] != 'a' && cuv[j] != 'e' && cuv[j] != 'i' && cuv[j] != 'o' && cuv[j] != 'u') ok = 0;

            if (ok == 1) cout << cuv << '\n';
            cuv = "";
        }
    }

    return 0;
}
