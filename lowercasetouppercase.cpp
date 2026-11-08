#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;
    int distanta = c - 'a';
    char literaMare = 'A' + distanta;
    cout << literaMare << '\n';
    return 0;
}