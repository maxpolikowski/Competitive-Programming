#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack <int> s;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a >> a;
        while(!s.empty() && s.top() > a)
            s.pop();
        if(s.empty() || s.top() < a)
            ans++;
        s.push(a);
    }
    cout << ans;
}