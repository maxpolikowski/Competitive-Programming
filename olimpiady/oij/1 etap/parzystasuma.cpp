#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a , b , c;
    cin >> a >> b >> c;
    cout << "TAK\n";
    if((a + b) % 2 == 0)cout << a << ' ' << b;
    else if((b + c) % 2 == 0)cout << b << ' ' << c;
    else if((a + c) % 2 == 0)cout << a << ' ' << c;
    return 0;
}