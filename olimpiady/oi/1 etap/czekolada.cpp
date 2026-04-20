#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
//da sie prosciej sortujoc
//jest omowienie na oi.edu.pl
//https://oi.edu.pl/l/10oi_ksiazeczka/
using namespace std;
const int pot = 10;
pair <int , int> tree_x[(1 << pot) * 2 + 7];
pair <int , int> tree_y[(1 << pot) * 2 + 7];
void uptade_x(int a , int value)
{
    a += (1 << pot);
    tree_x[a] = mp(value , a - (1 << pot));
    a /= 2;
    while(a > 0)
    {
        if(tree_x[a * 2].first > tree_x[a * 2 + 1].first)
            tree_x[a] = tree_x[a * 2];
        else 
            tree_x[a] = tree_x[a * 2 + 1];
        a /= 2;
    }
}
void uptade_y(int a , int value)
{
    a += (1 << pot);
    tree_y[a] = mp(value , a - (1 << pot));
    a /= 2;
    while(a > 0)
    {
        if(tree_y[a * 2].first > tree_y[a * 2 + 1].first)
            tree_y[a] = tree_y[a * 2];
        else 
            tree_y[a] = tree_y[a * 2 + 1];
        a /= 2;
    }
}
pair <int , int> query_x(int l , int r)
{
    l += (1 << pot);
    r += (1 << pot);
    int ans = 0;
    int id = 0;
    while(l <= r)
    {
        if(l % 2 == 1)
        {
            if(tree_x[l].first > ans)
            {
                ans = tree_x[l].first;
                id = tree_x[l].second;
            }
            l++;
        }
        if(r % 2 == 0)
        {
            if(tree_x[r].first > ans)
            {
                ans = tree_x[r].first;
                id = tree_x[r].second;
            }
            r--;
        }
        r /= 2;
        l /= 2;
    }
    return mp(ans , id);
}
pair <int , int> query_y(int l , int r)
{
    l += (1 << pot);
    r += (1 << pot);
    int ans = 0;
    int id = 0;
    while(l <= r)
    {
        if(l % 2 == 1)
        {
            if(tree_y[l].first > ans)
            {
                ans = tree_y[l].first;
                id = tree_y[l].second;
            }
            l++;
        }
        if(r % 2 == 0)
        {
            if(tree_y[r].first > ans)
            {
                ans = tree_y[r].first;
                id = tree_y[r].second;
            }
            r--;
        }
        r /= 2;
        l /= 2;
    }
    return mp(ans , id);
}
int wyn = 0;
void rek(int a , int b , int c , int d)
{
    //cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    if(a >= b && c >= d)return ;
    auto[max_y , id_y] = query_y(a , b - 1);
    auto[max_x , id_x] = query_x(c , d - 1);
    if(max_y > max_x)
    {
        wyn += max_y;
        rek(a , id_y , c , d);
        rek(id_y + 1 , b , c , d);
        return ;
    }
    else
    {
        wyn += max_x;
        rek(a , b , c , id_x);
        rek(a , b , id_x + 1 , d);
        return ;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> m >> n;
    for(int i = 1; i < m; i++)
    {
        int a;
        cin >> a;
        uptade_x(i - 1 , a);
    }
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        uptade_y(i - 1 , a);
    }
    rek(0 , n - 1 , 0 , m - 1);
    cout << wyn << '\n';
}