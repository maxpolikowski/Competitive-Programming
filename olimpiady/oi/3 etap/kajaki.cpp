#include <bits/stdc++.h>
using namespace std;
//probuje dac najzejszego i najciezszego do jednej lodki 
//i jak sie da to daje ich razem
//, a jak nie to biore najciezszego do jednej lodki
int main()
{
	int m , n;
    int ans = 0;
	cin >> m >> n;
    int right = n - 1;
    int left = 0;
	vector <int> v(n);
	for(int i = 0; i <  n; i++)
		cin >> v[i];
    sort(v.begin() , v.end());
    while(left <= right)
    {
        if(v[left] + v[right] <= m)
        {
            ans++;
            right--;
            left++;
        }
        else
        {
            ans++;
            right--;
        }
    }
    cout << ans;
}