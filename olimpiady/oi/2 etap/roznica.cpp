#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <vector <int> > v(30);
    for(int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a'].pb(i);
    }
    for(int i = 0; i < 26; i++)v[i].pb(n + 7);
    int ans = 0;
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(i == j)continue;
            int sum = 0;
            int sum_b = INT_MIN;
            int pos1 = 0 , pos2 = 0;
            while(v[i][pos1] < n || v[j][pos2] < n)
            {
                if(v[i][pos1] < v[j][pos2])
                {
                    sum++;
                    sum_b++;
                    pos1++;
                }
                else
                {
                    sum--;
                    sum_b = sum;
                    pos2++;
                }
                if(sum < 0)
                {
                    if(sum_b > n)
                    sum_b = -1;
                    sum = 0;
                }
                ans = max(ans , sum_b);
            }
        }
    }
    cout << ans;
}