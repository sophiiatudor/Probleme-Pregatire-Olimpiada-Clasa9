#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> v[200005];

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int a, b;
        cin >> a >> b;
        v[i] = {b, a};
    }

    sort(v + 1, v + n + 1);

    int cnt = 0, last = 0;

    for (int i = 1; i <= n; i++)
    {
        if (v[i].second >= last) 
        {
            cnt++;
            last = v[i].first;
        }
    }

    cout << cnt;
    return 0;
}