#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> stiva;
    int nr = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            nr++;
            stiva.push(nr);
        }
        else if (c == ')')
        {
            cout << stiva.top() << ' ';
            stiva.pop();
        }
    }

    cout << '\n';
    return 0;
}