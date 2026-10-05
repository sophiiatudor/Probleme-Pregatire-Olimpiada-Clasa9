#include <iostream>

using namespace std;

int ordine[1001];
bool acceptat[1001];

int main()
{
    int n;
    int lungime = 1;

    cin >> n;

    ordine[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            acceptat[j] = false;
        }

        for (int poz = 0; poz < i; poz++)
        {
            int x;
            cin >> x;

            if (poz < (i + 1) / 2)
            {
                acceptat[x] = true;
            }
        }

        int loc = -1;

        if (acceptat[ordine[0]] == true)
        {
            loc = 0;
        }
        else if (acceptat[ordine[lungime - 1]] == true)
        {
            loc = lungime;
        }
        else
        {
            for (int j = 0; j < lungime - 1; j++)
            {
                if (acceptat[ordine[j]] == true &&
                    acceptat[ordine[j + 1]] == true)
                {
                    loc = j + 1;
                    break;
                }
            }
        }

        for (int j = lungime; j > loc; j--)
        {
            ordine[j] = ordine[j - 1];
        }

        ordine[loc] = i;
        lungime++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ordine[i] << ' ';
    }

    cout << '\n';

    return 0;
}