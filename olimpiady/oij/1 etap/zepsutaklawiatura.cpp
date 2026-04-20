#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    priority_queue <pair<int , int> > q;
    vector <bool> v(n + 1 , true);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'd')
        {
            if(!q.empty())
            {
                v[q.top().second] = false;
                q.pop();
            }
            v[i] = false;
        }
        else q.push({s[i] - 'a' , i});
    }
    for(int i = 0; i < n; i++)if(v[i])cout << s[i];
    return 0;
}