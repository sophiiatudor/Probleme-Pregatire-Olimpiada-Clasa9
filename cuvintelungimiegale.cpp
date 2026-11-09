#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = 0, cnt = 0;

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ') cnt++;
        else if (cnt > 0)
        {
            if (n == 0) n = cnt;
            else if (cnt != n)
            {
                cout << "NU";
                return 0;
            }

            cnt = 0;
        }
    }

    cout << "DA " << n;
    return 0;
}
