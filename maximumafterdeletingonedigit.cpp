#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long maxim = 0;

    for (int i = 0; i < s.size(); i++)
    {
        long long nr = 0;
        for (int j = 0; j < s.size(); j++)
            if (i != j) nr = nr * 10 + s[j] - '0';

        if (nr > maxim) maxim = nr;
    }

    cout << maxim;
    return 0;
}
