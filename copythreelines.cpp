#include <iostream>
#include <string>

using namespace std;

int main()
{
    string linie;
    for (int i = 1; i <= 3; i++)
    {
        getline(cin, linie);
        cout << linie << '\n';
    }

    return 0;
}