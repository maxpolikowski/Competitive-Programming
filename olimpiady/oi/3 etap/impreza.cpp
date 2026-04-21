#include <bits/stdc++.h>
using namespace std;
bool spoko[3001];
bool graf[3001][3001];
int n;
void wywal()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(!graf[i][j] && spoko[i] && spoko[j])
            {
                spoko[i] = false;
                spoko[j] = false;
                for(int e = j + 1; e <= n; e++)graf[j][e] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int  m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)spoko[i]  = true;
    while(m--)
    {
        int a , b;
        cin >> a >> b;
        if(b < a)swap(a , b);
        graf[a][b] = true;
    }
    wywal();
    int w = n / 3;
    for(int i = 1; i <= n; i++)
    {
        if(spoko[i])
        {
            cout << i << ' ';
            w--;
            if(w == 0)return 0;
        }
    }
}