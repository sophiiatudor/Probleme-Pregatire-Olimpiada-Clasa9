#include <fstream>
using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int v[6000005];

int main() 
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) 
    {
        fin >> v[i];
    }

    int maxim = v[1], st = 1, dr = 1, sum = 0, last = 0;

    for (int i = 1; i <= n; i++) 
    {
        
        sum += v[i];
        if (sum > maxim) 
        {
            maxim = sum;
            st = last + 1;
            dr = i;
        }

        if (sum < 0) 
        {
            sum = 0;
            last = i;
        }
    }

    fout << maxim << " " << st << " " << dr;
}