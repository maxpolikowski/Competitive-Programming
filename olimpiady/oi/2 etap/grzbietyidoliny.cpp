#include <bits/stdc++.h>
using namespace std;
int t[1002][1002];
bool odw[1002][1002];
bool czymniejsze = false;
bool czywieksze = false;
int n;
vector <int> A = {0 , -1 , 1} , B = {-1 , 1 , 0};
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int grzbiety = 0 , doliny = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)cin >> t[i][j];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(odw[i][j])continue;
            stack <pair<int , int> > s;
            s.push({i , j});
            while(!s.empty()){
                auto[ii , jj] = s.top();
                s.pop();
                odw[ii][jj] = true;
                for(int x : A)
                    for(int y : B)
                    {
                        int a = x + ii , b = y + jj;
                        if(a == 0 || a > n || b == 0 || b > n)continue;
                        if(t[a][b] == t[ii][jj] && !odw[a][b])s.push({a , b});
                        if(t[a][b] < t[ii][jj])czymniejsze = true;
                        if(t[a][b] > t[ii][jj])czywieksze = true;
                    }
            }
            if(!czymniejsze)doliny++;
            if(!czywieksze)grzbiety++;
            czywieksze = false;
            czymniejsze = false;
        }
    }
    cout << grzbiety << ' ' << doliny;
    return 0;
}