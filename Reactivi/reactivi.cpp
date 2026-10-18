#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("reactivi.in");
ofstream fout("reactivi.out");

pair<int, int> v[8005];

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++) 
    {
        int a, b;
        fin >> a >> b;
        v[i] = {b, a};
    }

    sort(v + 1, v + n + 1);

    int cnt = 0, t = -101;

    for (int i = 1; i <= n; i++) 
    {
        if (v[i].second > t) 
        {
            cnt++;
            t = v[i].first;
        }
    }

    fout << cnt;

    return 0;
}