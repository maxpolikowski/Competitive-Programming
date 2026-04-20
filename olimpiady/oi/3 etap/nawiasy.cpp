#include <bits/stdc++.h>
using namespace std;
//jakis dp nie wiem czemu dziala i jak dziala
#define mp make_pair
#define int long long
int dp[5007];
const int mod = 1000000000;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n <= 5)
    {
        cout << 0;
        return 0;
    }
    vector <char> v(n + 1);
    for(int i = 1; i < n; i++)dp[i] = 1;
    for(int i = 1; i < n; i++)cin >> v[i];
    for(int i = 2; i < n; i++)
    {
        if(v[i] == '+' && v[i + 1] == '-')
        {
            for(int j = i + 1; j < n; j++)
            {
                dp[j] = dp[j] + dp[j - 1];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[n - 1] << '\n';
}