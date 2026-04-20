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
        int k;
        cin >> k;
        vector <bool> t(k + 5 , false);
        queue <pair <long long , string> > w;
        w.push(pair(1 % k , "1"));
        t[1] = true;
        while(!w.empty())
        {
            auto[x , y] = w.front();
            if(x == 0)
            {
                cout << y << '\n';
                break;
            }
            int a = 10 * x , b = 10 * x + 1;
            if(!t[a % k])
            {
                w.push(pair(a % k , y + '0'));
                t[a % k] = true;
            }
            if(!t[b % k])
            {
                w.push(pair(b % k , y + '1'));
                t[b % k] = true;
            }
            w.pop();
        }
        if(w.empty())cout << "BRAK\n";
    }
}