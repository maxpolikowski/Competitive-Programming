#include <bits/stdc++.h>
#define int long long
//segtree segment segment
#define mp make_pair
#define ld long double
#define pb push_back
using namespace std;
int tree[(1 << 19) + 7];
int lazy[(1 << 19) + 7];
void push(int node)
{
    tree[node * 2] += lazy[node];
    lazy[node * 2] += lazy[node];
    tree[node * 2 + 1] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}
void uptade(int node , int l , int r , int a , int b , int x)
{
    if(l > r)return ;
    if(l == a && r == b)
    {
        tree[node] += x;
        lazy[node] += x;
        return ;
    }
    push(node);
    int mid = (a + b) / 2;
    uptade(node * 2 , l , min(r , mid) , a , mid , x);
    uptade(node * 2 + 1 , max(l , mid + 1) , r , mid + 1 , b , x);
    tree[node] = min(tree[node * 2] , tree[node * 2 + 1]);
}
int query(int node , int l , int r , int a , int b)
{
    if(l > r)return 1e9;
    if(l == a && r == b)
    {
        return tree[node];
    }
    push(node);
    int mid = (a + b) / 2;
    return min(query(node * 2 , l , min(mid , r) , a , mid) , query(node * 2 + 1 , max(mid + 1 , l) , r , mid + 1 , b));
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m , z;
    cin >> n >> m >> z;
    for(int i = 1; i <= n; i++)
    {
        uptade(1 , i , i , 1 , (1 << 17) , m);
    }
    while(z--)
    {
        int p , k , r;
        cin >> p >> k >> r;
        k--;
        if(query(1 , p , k , 1 , (1 << 17)) >= r)
        {
            uptade(1 , p , k , 1 , (1 << 17) , -r);
            cout << "T\n";
        }
        else cout << "N\n";
    }
}