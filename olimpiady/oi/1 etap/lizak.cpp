#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , q;
    cin >> n >> q;
    string s;
    cin >> s;
    int sum = 0;
    for(char c : s)
    {
        if(c == 'T')sum += 2;
        else sum++;
    }
    vector <pair<int , int> > ans(sum + 7 , {-1 , -1});
    ans[sum] = {1 , n};
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'W')
        {
            ans[sum - i - i - 1] = {i + 2 , n};
            break;
        }
        if(s[n - i - 1] == 'W')
        {
            ans[sum - i - i - 1] = {1 , n - i - 1};
            break;
        }
    }
    for(int i = sum; i > 2; i--)
    {
        if(ans[i] != pair(-1,-1))
        {
            if(s[ans[i].first - 1] == 'T')ans[i - 2] = {ans[i].first + 1 , ans[i].second};
            else if(s[ans[i].second - 1] == 'T')ans[i - 2] = {ans[i].first , ans[i].second - 1};
            else ans[i - 2] = {ans[i].first + 1 , ans[i].second - 1};
        }
    }
    while(q--)
    {
        int k;
        cin >> k;
        if(k <= sum && ans[k] != pair(-1,-1))cout << ans[k].first << ' ' << ans[k].second << '\n';
        else cout << "NIE\n";
    }
    return 0;
}