#include <bits/stdc++.h>
using namespace std;
int v[200007][2];
int z[400007][2];
int parent[200007];
int ans[200007];
int find(int a)
{
    if(parent[a] == a)return a;
    int ojciec = find(parent[a]);
    if(ans[a] == -2)ans[a] = ans[parent[a]];
    return parent[a] = ojciec;
}
void unio(int a , int b)
{
    parent[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        ans[i] = -2;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        if(v[i][0] > 0)v[i][0]--;
        if(v[i][1] > 0)v[i][1]--;
        
    }
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        z[i][0] = v[a][b];
        z[i][1] = a;
        v[a][b] = -1;
    }
    for(int i = 0; i < n; i++)
    {
        if(v[i][0] != -1)unio(find(i) , find(v[i][0]));
        if(v[i][1] != -1)unio(find(i) , find(v[i][1]));
    }
    ans[find(0)] = -1;
    for(int i = m - 1; i >= 0; i--)
    {
        int a = find(z[i][0]) , b = find(z[i][1]);
        if(a == find(0) && a != b)ans[b] = i;
        else if(b == find(0) && a != b)ans[a] = i;
        unio(a , b);
    }
    for(int i = 0; i < n; i++)
    {
        find(i);
        cout << ans[i] << '\n';
    }
}