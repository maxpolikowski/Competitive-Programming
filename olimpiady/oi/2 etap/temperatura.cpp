#include <bits/stdc++.h>
using namespace std;
deque <int> kolejka;
deque<int> kolejka_maksimuw;
void dodaj(int wartosc)
{
    kolejka.push_back(wartosc);
    while(!kolejka_maksimuw.empty() && kolejka_maksimuw.back() < wartosc)
        kolejka_maksimuw.pop_back();
    kolejka_maksimuw.push_back(wartosc);
}
void usun_najstarszy_element()
{
    int najstarszy = kolejka.front();
    kolejka.pop_front();
    if(!kolejka_maksimuw.empty() && kolejka_maksimuw.front() == najstarszy)
        kolejka_maksimuw.pop_front();
}
int maksimum()
{
    if(kolejka_maksimuw.empty())return -INT_MAX;
    return kolejka_maksimuw.front();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , a , b;
    cin >> n;
    int l = 0 , l_m = 1;
    while(n--)
    {
        cin >> a >> b;
        while(maksimum() > b)
        {
            usun_najstarszy_element();
            l--;
        }
        l++;
        l_m = max(l_m , l);
        dodaj(a);
    }
    cout << l_m;
    return 0;
}