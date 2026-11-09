#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string v[256];

int numaraVocale(const string& cuvant)
{
    int nr = 0;

    for (char c : cuvant)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            nr++;

    return nr;
}

bool ordine(const string& a, const string& b)
{
    int vocaleA = numaraVocale(a);
    int vocaleB = numaraVocale(b);

    if (vocaleA != vocaleB) return vocaleA > vocaleB;

    if (a.size() != b.size())  return a.size() > b.size();

    return a < b;
}

int main()
{
    int n = 0;
    string cuvant;

    while (cin >> cuvant)
    {
        n++;
        v[n] = cuvant;
    }

    sort(v + 1, v + n + 1, ordine);

    for (int i = 1; i <= n; i++) cout << v[i] << '\n';

    return 0;
}