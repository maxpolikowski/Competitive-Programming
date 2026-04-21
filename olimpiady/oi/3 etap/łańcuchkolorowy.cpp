#include <bits/stdc++.h>
using namespace std;
long long T[1000001]; long long T2[1000001];
vector <long long> v , v2 , v3;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    long long a,b,c,p = 0, k = 0 , s = 0 , dp = 0, l = 0 , sumt = 0;
    cin >> a >> b;
    for(int i = 0; i < b; i++)
    {
        cin >> c;
        v.push_back(c);
        dp += c;
    }
    for(int i = 0; i < b; i++)
    {
        cin >> c;
        v2.push_back(c);
        T2[c] = v[i];
    }
    for(int i = 0; i < a; i++)
    {
        cin >> c;
        v3.push_back(c);
    }
    while(k < dp && k < v3.size())
    {
        T[v3[k]]++;
        if(T[v3[k]] == T2[v3[k]])sumt++;
        else if(T[v3[k]] == 1 + T2[v3[k]])sumt--;
        k++;
    }
    if(sumt == v.size())l++;
    for(int i = k; i < v3.size(); i++)
    {
        if(T[v3[p]] == T2[v3[p]])sumt--;
        else if(T[v3[p]] - 1 == T2[v3[p]])sumt++;
        T[v3[p]]--;
        p++;
        if(T[v3[i]] == T2[v3[i]])sumt--;
        else if(T[v3[i]] + 1 == T2[v3[i]])sumt++;
        T[v3[i]]++;
        if(sumt == v.size())l++;
    }
    cout << l;
    return 0;
}