#include <bits/stdc++.h>
using namespace std;
vector <int> v[260];
bool odw[2][260][260];
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    int auno , ados;
    cin >> auno >> ados;
    int ans = 0;
    while(m--)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    queue <pair<int , pair<int , int> > > q;
    q.push({0 , {auno , ados}});
    odw[0][auno][ados] = true;
    while(!q.empty())
    {
        int ro = q.size();
        ans++;
        while(ro--)
        {
            auto[l , pom] = q.front();
            auto[a , b] = pom;
            q.pop();
            if(l == 0)
            {
                for(int i : v[a])
                {
                    if(!odw[1][i][b])
                    {
                        odw[1][i][b] = true;
                        q.push({1 , {i , b}});
                    }
                }
            }
            else {
                for(int i : v[b])
                {
                    if(!odw[0][a][i])
                    {
                        odw[0][a][i] = true;
                        q.push({0 , {a , i}});
                        if(a == i)
                        {
                            cout << ans / 2;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NIE";
}