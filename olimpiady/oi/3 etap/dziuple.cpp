#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = long long;
#define pb push_back
const int max_n = 1e6;
bool odw[max_n + 7];
ll sil[max_n + 7];
int n;
int w = 0;
vector <int> v[max_n + 7];
int stopnie[max_n + 7];
vector <int> spojna;
int k;
vector <vector <int> > skladowe;
bool is_cykl(int start)
{
	stack <pair<int , int> > s;
	s.push(mp(start , -1));
	odw[start] = true;
	while(!s.empty())
	{
		auto[a , p] = s.top();
		s.pop();
		spojna.pb(a);
		for(int i : v[a])
		{
			if(i == p)continue;
			if(odw[i])return true;
			s.push(mp(i , a));
			odw[i] = true;
		}
	}
	return false;
}
bool cykl()
{
	for(int i = 1; i <= n; i++)
	{
		if(!odw[i])
		{
			if(is_cykl(i))return true;
			skladowe.pb(spojna);
			spojna.clear();
		}
	}
	return false;
}
bool bad()
{
	for(int i = 1; i <= n; i++)
	{
		int l = 0;
		for(int j : v[i])
		{
			if(stopnie[j] > 1)l++;
		}
		if(l > 2)return true;
	}
	return false;
}
int duze_skladowe()
{
	ll ans = 1;
	int l = 0;
	for(vector <int> skladowa : skladowe)
	{
		if(skladowa.size() == 1)continue;
		int t = 0;
		l++;
		for(int i : skladowa)
		{
			if(stopnie[i] > 1)
			{
				t++;
				int s = 0;
				for(int j : v[i])
				{
					if(stopnie[j] == 1)s++;
				}
				ans *= sil[s];
				ans %= k;
			}
		}
		w += (int)skladowa.size();
		if(t <= 1)ans *= 2;
		else ans *= 4;
		ans %= k;
	}
	ans *= sil[l];
	ans %= k;
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m >> k;
	sil[0] = 1;
	sil[1] = 1;
	for(ll i = 2; i <= n; i++)
	{
		sil[i] = sil[i - 1] * i;
		sil[i] %= k;
	}
	if(m >= n)
	{
		cout << 0;
		return 0;
	}
	while(m--)
	{
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		stopnie[a]++;
		stopnie[b]++;
	}
	if(cykl() || bad())
	{
		cout << 0;
		return 0;
	}
	ll ans = duze_skladowe();
	for(ll i = w + 2; i <= n + 1; i++)
	{
		ans *= i;
		ans %= k;
	}
	cout << ans;
	return 0;
}