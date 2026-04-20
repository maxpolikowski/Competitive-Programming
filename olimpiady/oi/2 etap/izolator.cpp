#include <bits/stdc++.h>
using namespace std;
//dawno temu pisalem
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    unsigned long long int n,l=0,k;
    cin >> n;
    int t[n];
    for(int i=0; i<n; i++){
        cin >> t[i];
        l+=t[i];
    }
    sort(t , t+n);
    for(int i=0; i<n; i++){
        l+=max(0 , t[n-1]-t[i]);
        n--;
    }
    cout << l;
}