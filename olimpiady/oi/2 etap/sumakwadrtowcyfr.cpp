#include <bits/stdc++.h>
using namespace std;
void solve(string n)
{
    if(n == "4" || n == "1")return ;
    long long s = 0;
    for(char c : n)
    {
        int l = c - '0';
        s += l * l;
    }
    cout << s << ' ';
    string N = to_string(s);
    solve(N);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        cout << n << ' ';
        solve(n);
        cout << '\n';
    }
}