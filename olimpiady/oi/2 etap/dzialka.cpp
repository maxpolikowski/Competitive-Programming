#include <bits/stdc++.h>
using namespace std;
int gora[2001];
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        stack <pair <int , int> > s;
        for(int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                gora[j] = 0;
            }
            else {
                gora[j]++;
            }
            int x = j;
            while(!s.empty() && s.top().first > gora[j])
            {
                ans = max((j - s.top().second) * s.top().first , ans);
                x = s.top().second;
                s.pop();
            }
            if(gora[j] > 0)s.push({gora[j] , x});
        }
        while(!s.empty())
        {
            ans = max(ans , s.top().first * (n + 1 - s.top().second));
            s.pop();
        }
    }
    cout << ans;
}