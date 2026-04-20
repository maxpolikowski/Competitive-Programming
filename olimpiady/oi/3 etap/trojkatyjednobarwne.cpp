#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector <int> v(1005);
    for(int i = 0; i < m; i++)
    {
        int x , y;
        cin >> x >> y;
        v[x]++;
        v[y]++;
    }
    int s = 0;
    for(int i = 1; i <= n; i++)
    {
        int d = v[i];
        int D = n - 1 - d;
        s += d * D;
    }
    s /= 2;
    int ans = n * (n - 1) * (n - 2);
    ans /= 6;
    ans -= s;
    cout << ans;
}