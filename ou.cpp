#include <fstream>

using namespace std;

ifstream cin("ou.in");
ofstream cout("ou.out");

const int VMAX = 1e5;

int v[VMAX+1];
long long smen[VMAX+2];


int main()
{
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        int ceva = min(i - 1, n - i);
        ceva = min(ceva, v[i] / 2);
        int oua_date = v[i] / (2 * ceva);
        if (ceva != 0)
        {
            smen[i-ceva] += oua_date;
            smen[i] -= oua_date;
            smen[i+1] += oua_date;
            smen[i+ceva+1] -= oua_date;
            v[i] %= (2 * ceva);
        }
    }
    for (int i = 1; i<=n;i++){
        s += smen[i];
        cout << v[i] + s << ' ';
    }
    return 0;
}
