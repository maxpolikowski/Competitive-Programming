#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector < vector <char> > v(n + 2 , vector <char> (m + 2 , '.'));
    for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)cin >> v[i][j];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int a = 0 , b = 0;
            for(int k = -1; k < 2; k++)
            {
                for(int c = -1; c < 2; c++)
                {
                    if(v[i + k][c + j] == '#')a++;
                    else if(v[i + k][c + j] == '*')b++;
                }
            }
            if(a > b)cout << '#';
            else if(b > a)cout << '*';
            else if(a == b)cout << '.';
        }
        cout << '\n';
    }
    return 0;
}