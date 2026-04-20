#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector <vector <int> > v(n + 7);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector <char> t(n + 8 , 'c');
    for(int i = 1; i <= n; i++)
    {
        if(v[i].empty())
        {
            cout << "NIE";
            return 0;
        }
        if(t[i] == 'c')
        {
            t[i] = 'K';
            for(int j = 0; j < v[i].size(); j++)if(t[v[i][j]] == 'c')t[v[i][j]] = 'S';
        }
    }
    cout << "TAK\n";
    for(int i = 1; i <= n; i++)cout << t[i] << '\n';
    return 0;
}