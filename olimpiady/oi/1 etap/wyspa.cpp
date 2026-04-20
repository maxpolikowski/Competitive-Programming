#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,sum_all = 0;
    cin >> n;
    vector <ll> t(n + n);
    for(ll i = 0; i < n; i++){
        cin >> t[i];
        sum_all += t[i];
        t[n + i] = t[i];
    }
    ll l_m = 0 , l = 0 , j = 0;
    for(ll i = 0; i < n; i++)
    {
        while(l <= sum_all - l)
        {
            l+=t[j];
            j++;
            l_m = max(l_m , min(l , sum_all - l));
        }
        l -= t[i];
    }
    cout << l_m;
    return 0;
}