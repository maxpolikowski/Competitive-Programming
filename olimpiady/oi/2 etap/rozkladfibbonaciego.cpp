#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        long long k;
        cin >> k;
        vector <long long> fib(100);
        fib[0] = 0;
        fib[1] = 1;
        int i = 1;
        while(fib[i] <= k)
        {
            fib[i + 1] = fib[i] + fib[i - 1];
            i++;
        }
        int r = 0;
        while(k > 0)
        {
            if(k - fib[i - 1] <= fib[i] - k)
            {
                k -= fib[i - 1];
            }
            else {
                k = fib[i] - k;
            }
            r++;
            while(fib[i - 1] > k)i--;
        }
        cout << r << '\n';
    }
    return 0;
}