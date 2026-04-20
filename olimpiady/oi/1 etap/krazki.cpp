#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector <int> rura(n + 8) , krazki(m + 8);
    rura[0] = -1;
    cin >> rura[1];
    for(int i = 2; i <= n; i++)
    {
        cin >> rura[i];
        rura[i] = min(rura[i] , rura[i - 1]);
    }
    for(int i = 1; i <= m; i++)cin >> krazki[i];
    int p = n + 1;
    for(int i = 1; i <= m; i++)
    {
        int pocz = 0 , kon = p - 1;
        while(pocz < kon)
        {
            int mid = (pocz + kon + 1) / 2;
            if(krazki[i] > rura[mid])kon = mid - 1;
            else pocz = mid;
        }
        p = kon;
        if(p <= 0)
        {
            cout << 0;
            return 0;
        }
    }
    cout << p;
}