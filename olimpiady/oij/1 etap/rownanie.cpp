#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a , b , c;
    long long x , y;
    cin >> a >> b >> c >> x >> y;
    if(a * x + b * y == c)cout << "TAK";
    else cout << "NIE";
    return 0;
}