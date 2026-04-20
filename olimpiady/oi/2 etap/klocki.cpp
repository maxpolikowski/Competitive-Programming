#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    long long n , m;
    cin >> n >> m;
    vector <long long> v(n + 1);
    for(long long i = 1; i <= n; i++)cin >> v[i];
    while(m--)
    {
        long long k;
        cin >> k;
        vector <long long> a(n + 1);
        a[0]  = 0;
        for(long long i = 1; i <= n; i++)a[i] = v[i] - k + a[i - 1];
        vector <long long> minpref , maxsuf;
        long long aktmin = LLONG_MAX , aktmax = LLONG_MIN;
        for(long long i = 0; i <= n; i++)
        {
            if(a[i] < aktmin)
            {
                aktmin = a[i];
                minpref.push_back(i);
            }
        }
        for(long long i = n; i >= 0; i--)
        {
            if(a[i] > aktmax)
            {
                maxsuf.push_back(i);
                aktmax = a[i];
            }
        }
        long long id_max = 0;
        long long wynik = 0;
        for(long long id_min = (long long) minpref.size() - 1; id_min >= 0; id_min--)
        {
            while(id_max + 1 < maxsuf.size() && a[minpref[id_min]] > a[maxsuf[id_max]])
            {
                id_max++;
            }
            wynik = max(wynik, maxsuf[id_max] - minpref[id_min]);
        }
        cout << wynik << " ";
    }
}