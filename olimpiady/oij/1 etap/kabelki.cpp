#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    n += n;
    vector <pair <int , int> > v(n);
    for(int i = 0; i < n; i++)cin >> v[i].second >> v[i].first;
    sort(v.begin() , v.end());
    for(int i = 0; i < n; i += 2)cout << v[i].second << ' ' << v[i].first << ' ' << v[i + 1].second << ' ' << v[i + 1].first << '\n';
    return 0;
}