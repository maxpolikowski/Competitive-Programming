#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool u = false , d = false;
    while(n--)
    {
        int a;
        cin >> a;
        if(a % 3 == 0)u = true;
        if(a % 2 == 0)d = true;
    }
    if(u && d)cout << "TAK";
    else cout << "NIE";
    return 0;
}