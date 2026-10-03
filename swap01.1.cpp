#include <iostream> 

using namespace std;

int v[100001];

int main ()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> v[i];
        if (v[i]==1) cnt++;
    }
    int st = 1, dr = cnt, mini, swaps = 0;
    for (int i = st; i<=dr; i++)
    {
        if (v[i]==0) swaps++;
    }

    mini = swaps;

    while (dr<n)
    {
        if (v[st]==0) swaps--;
        st++;
        dr++;
        if (v[dr]==0) swaps++;
        if (swaps < mini) mini = swaps;
    }

    cout << mini;
}