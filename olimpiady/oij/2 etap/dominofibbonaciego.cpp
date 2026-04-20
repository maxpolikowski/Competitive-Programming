#include <bits/stdc++.h>
using namespace std;
#define int long long
#define  mp  make_pair
signed main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n , h;
    cin >> n >> h;
    vector <int> fib(n + 7);
    int sum_fib = 0;
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for(int i = 1; i <= n; i++)sum_fib += fib[i];
    if(h == 1)
    {
        cout << sum_fib << '\n';
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cout << sum << ' ' << 0 << ' ' << sum + fib[i] << ' ' << 1 << '\n';
            sum += fib[i];
        }
        return 0;
    }
    if(h == 2)
    {
        int uno = 0 , dos = 0;
        for(int i = n; i >= 1; i--)
        {
            if(uno < dos)uno += fib[i];
            else dos += fib[i];
        }
        cout << max(uno , dos) << '\n';
        uno = 0; dos = 0;
        for(int i = n; i >= 1; i--)
        {
            if(uno < dos)
            {
                cout << uno << ' ' << 0 << ' ' << uno + fib[i] << ' ' << 1 << '\n';
                uno += fib[i];
            }
            else
            {
                cout << dos << ' ' << 1 << ' ' << dos + fib[i] << ' ' << 2 << '\n';
                dos += fib[i];
            }
        }
        return 0;
    }
    if(h == 3)
    {
        cout << fib[n] << '\n';
        cout << 0 << ' ' << 0 << ' ' << fib[n] << ' ' << 1 << '\n';
        if(n == 1)return 0;
        cout << 0 << ' ' << 1 << ' ' << fib[n - 1] << ' ' << 2 << '\n';
        if(n == 2)return 0;
        cout << fib[n - 1] << ' ' << 1 << ' ' << fib[n] << ' ' << 2 << '\n';
        if(n == 3)return 0;
        int sum = 0;
        for(int i = 1; i <= n - 3; i++)
        {
            cout << sum << ' ' << 2 << ' ' << sum + fib[i] << ' ' << 3 << '\n';
            sum += fib[i];
        }
        return 0;
    }
    if(h >= sum_fib || n <= 2)
    {
        cout << 1 << '\n';
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cout << 0 << ' ' << sum << ' ' << 1 << ' ' << sum + fib[i] << '\n';
            sum += fib[i];
        }
        return 0;
    }
    int uno = 0 , dos = 0;
    for(int i = n; i >= 1; i--)
    {
        if(uno < dos)uno += fib[i];
        else dos += fib[i];
    }
    if(h >= max(uno , dos))
    {
        cout << 2 << '\n';
        uno = 0; dos = 0;
        for(int i = n; i >= 1; i--)
        {
            if(uno < dos)
            {
                cout << 0 << ' ' << uno << ' ' << 1 << ' ' << uno + fib[i] << '\n';
                uno += fib[i];
            }
            else
            {
                cout << 1 << ' ' << dos << ' ' << 2 << ' ' << dos + fib[i] << '\n';
                dos += fib[i];
            }
        }
        return 0;
    }
    if(h >= fib[n])
    {
        cout << 3 << '\n';
        cout << 0 << ' ' << 0 << ' ' << 1 << ' ' << fib[n] << '\n';
        if(n == 1)return 0;
        cout << 1 << ' ' << 0 << ' ' << 2 << ' ' << fib[n - 1] << '\n';
        if(n == 2)return 0;
        cout << 1 << ' ' << fib[n - 1] << ' ' << 2 << ' ' << fib[n] << '\n';
        if(n == 3)return 0;
        int sum = 0;
        for(int i = 1; i <= n - 3; i++)
        {
            cout << 2 << ' ' << sum << ' ' << 3 << ' ' << sum + fib[i] << '\n';
            sum += fib[i];
        }
        return 0;
    }
    cout << fib[n] << '\n';
    cout << 0 << ' ' << 0 << ' ' << fib[n] << ' ' << 1 << '\n';
    if(n == 1)return 0;
    cout << 0 << ' ' << 1 << ' ' << fib[n - 1] << ' ' << 2 << '\n';
    if(n == 2)return 0;
    cout << fib[n - 1] << ' ' << 1 << ' ' << fib[n] << ' ' << 2 << '\n';
    if(n == 3)return 0;
    int sum = 0;
    for(int i = 1; i <= n - 3; i++)
    {
        cout << sum << ' ' << 2 << ' ' << sum + fib[i] << ' ' << 3 << '\n';
        sum += fib[i];
    }
    return 0;
}