#include <bits/stdc++.h>
using namespace std;
#define pb push_back
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
    cin >> n;
    vector <pair <string , string> > v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].second;
        v[i].first = v[i].second;
        sort(v[i].first.begin() , v[i].first.end());
    }
    sort(v.begin() , v.end());
    vector <vector <string> > ans;
    vector <string> now = {v[0].second};
    for(int i = 1; i < n; i++)
    {
        if(v[i].first == v[i - 1].first)
        {
            if(v[i].second != v[i - 1].second)
                now.pb(v[i].second);
        }
        else 
        {
            ans.pb(now);
            now.clear();
            now.pb(v[i].second);
        }
    }
    ans.pb(now);
    sort(ans.begin() , ans.end());
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
}