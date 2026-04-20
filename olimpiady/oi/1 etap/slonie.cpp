#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    long long n , MIn = 1e9;
    cin >> n;
    vector <long long> v(n + 7) , masa(n + 7) , pom(n + 7);
    for(long long i = 1; i <= n; i++)
    {
        cin >> masa[i];
        MIn = min(MIn , masa[i]);
    }
    for(long long i = 1; i <= n; i++)cin >> v[i];
    for(long long i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        pom[a] = v[i];
    }
    long long s = 0;
    vector <bool> b(n + 7 , false);
    for(long long i = 1; i <= n; i++)
    {
        long long poz = i , l = 0 , Min = 1e9;
        long long sum = 0;
        while(!b[poz])
        {
            l++;
            sum += masa[poz];
            b[poz] = true;
            Min = min(Min , masa[poz]);
            poz = pom[poz];
        }
        if(l > 0)s += min(sum + (l - 2) * Min , sum + Min + (l + 1) * MIn);
    }
    cout << s;
    return 0;
}