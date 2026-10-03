#include <iostream> 

using namespace std;

int v[100001];
int sp[100001];

int main ()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> v[i];
        if (v[i]==1) cnt++;
        sp[i] = sp[i-1];
        if (v[i]==0) sp[i]++;
    }
    int mini = cnt, swaps = 0;
    
    for (int st = 1; st + cnt - 1<=n; st++)
    {
        int dr = st + cnt - 1;

        int zerouri = sp[dr] - sp[st - 1];

        if (zerouri < mini) mini = zerouri;
    }

    cout << mini;
}