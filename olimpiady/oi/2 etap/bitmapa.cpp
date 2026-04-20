#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    queue <pair<int , int> > q;
    vector <vector<int> > ans(207 , vector <int> (207 , -1));
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)
    {
        char c;
        cin >> c;
        if(c == '1')
        {
            q.push({i , j});
            ans[i][j] = 0;
        }
    }
    vector <int> uno = {1 , -1 , 0 , 0};
    vector <int> dos = {0 , 0 , 1 , -1};
    while(!q.empty())
    {
        int p1 = q.front().first , p2 = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int l1 = p1 + uno[i] , l2 = p2 + dos[i];
            if(l1 >= 0 && l1 < n && l2 >= 0 && l2 < m && ans[l1][l2] == -1)
            {
                ans[l1][l2] = ans[p1][p2] + 1;
                q.push({l1 , l2});
            }
        }
    }
    for(int i = 0; i < n; i++){for(int j = 0; j < m; j++)cout << ans[i][j] << ' ';cout << '\n';}
    return 0;
}