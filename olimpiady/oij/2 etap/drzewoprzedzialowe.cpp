#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	vector <long long> pot(k + 2);
	pot[0] = 1;
	for(int i = 1; i <= k + 1; i++)pot[i] = pot[i - 1] * 2;
	long long left = pot[k] , right = 0;
	int n;
	cin >> n;
	while(n--)
	{
	    long long a;
	    cin >> a;
	    int id = 0;
	    while(pot[id + 1] <= a)id++;
	    int g = k - id;
	    long long le = (1LL << g);
	    left = min(left , le * (a - pot[id]));
	    right = max(right , le * (a - pot[id] + 1) - 1);
	}
	cout << left << ' ' << right;
}