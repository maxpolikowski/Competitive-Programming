#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , p , q , x , y;
    cin >> n >> p >> q >> x >> y;
    string s;
    cin >> s;
    vector <int> min_pref(n + 1) , min_suf(n + 1) , pref(n + 1);
    int sum = 0;
    pref[0] = 0;
    min_pref[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i - 1] == '-')sum--;
        else sum++;
        pref[i] = sum;
        min_pref[i] = min(min_pref[i - 1] , sum);
    }
    min_suf[n] = pref[n];
    for(int i = n - 1; i >= 0; i--)
    {
        min_suf[i] = min(min_suf[i + 1] , pref[i]);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        int pom = max({-min_pref[i] + pref[i] - pref[n] - p , pref[i] - min_suf[i] - p , 0}); 
        if(pom % 2 == 1)pom++;
        if(q - p > pref[n] + pom)ans = min(ans , y * (n - i) + x * (q - p - pref[n]) / 2);
        else ans = min(ans , y * (n - i) + x * (pom + (pref[n] - q + p) / 2));
    }
    cout << ans;
    return 0;
}