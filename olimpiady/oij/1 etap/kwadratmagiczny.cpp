#include <bits/stdc++.h>
using namespace std;
char t[7][7];
bool check()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(t[i][j] != t[j][i])return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 5; i++)for(int j = 0; j < 5; j++)cin >> t[i][j];
    for(int i = 0; i < 5; i++)
    {
        for(int j = i; j < 5; j++)
        {
            if(t[i][j] == '?' && t[j][i] == '?')
            {
                t[i][j] = 'A';
                t[j][i] = 'A';
            }
            else if(t[i][j] == '?')
            {
                t[i][j] = t[j][i];
            }
            else if(t[j][i] == '?')
            {
                t[j][i] = t[i][j];
            }
        }
    }
    if(check())
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)cout << t[i][j];
            cout << '\n';
        }
    }
    else cout << "NIE\n";
    return 0;
}