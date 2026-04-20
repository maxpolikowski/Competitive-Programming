#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector <int> ans;
    set <int> bo;
    vector < vector <int> > v(n + 1);
    for(int i = 1; i <= m; i++)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        sort(v[i].begin() , v[i].end());
        bo.insert(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(bo.find(i) != bo.end())
        {
            queue <int> q;
            int l = 0;
            q.push(i);
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                auto it = bo.begin();
                while(it != bo.end())
                {
                    int po = *it;
                    if(!binary_search(v[t].begin() , v[t].end() , po))
                    {
                        q.push(po);
                        it = bo.erase(it);
                        l++;
                    }
                    else {
                        it++;
                    }
                }
            }
            ans.push_back(l);
        }
    }
    sort(ans.begin() , ans.end());
    cout << ans.size() << '\n';
    for(int i : ans)cout << i << ' ';
}