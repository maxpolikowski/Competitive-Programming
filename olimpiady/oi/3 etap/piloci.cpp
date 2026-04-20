#include <bits/stdc++.h>
using namespace std;
deque <int> kolejka;
deque<int> kolejka_minimuw;
deque<int> kolejka_maksimuw;
void dodaj(int wartosc)
{
    kolejka.push_back(wartosc);
    while(!kolejka_minimuw.empty() && kolejka_minimuw.back() > wartosc)
        kolejka_minimuw.pop_back();
    kolejka_minimuw.push_back(wartosc);
    while(!kolejka_maksimuw.empty() && kolejka_maksimuw.back() < wartosc)
        kolejka_maksimuw.pop_back();
    kolejka_maksimuw.push_back(wartosc);
}
void usun_najstarszy_element()
{
    int najstarszy = kolejka.front();
    kolejka.pop_front();
    if(!kolejka_minimuw.empty() && kolejka_minimuw.front() == najstarszy)
        kolejka_minimuw.pop_front();
    if(!kolejka_maksimuw.empty() && kolejka_maksimuw.front() == najstarszy)
        kolejka_maksimuw.pop_front();
}
int minimum()
{
    return kolejka_minimuw.front();
}
int maksimum()
{
    return kolejka_maksimuw.front();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t , n , l = 0 , lm = 0;
    cin >> t >> n;
    int T[n + 7];
    for(int i = 0; i < n; i++)
    {
        cin >> T[i];
        dodaj(T[i]);
        while(maksimum() - minimum() > t)
        {
            usun_najstarszy_element();
            l--;
        }
            l++;
            lm = max(lm , l);
    }
    cout << lm;
    return 0;
}