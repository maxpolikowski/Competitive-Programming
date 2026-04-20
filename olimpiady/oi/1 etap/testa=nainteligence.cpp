//kiedys pisalem
//nawet nie chce mi sie tego porzodkowac
//czemu deklaruje bitsy i vectora :
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <pair<int,int> >   y[1000001];
std::vector <pair <int , int> > pomocnik;
int  t[1000001], x;

bool wynik[1000001] = {false};
vector <int> podciogi[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> k;
            for(int j=0; j<k; j++){

                cin >> x;
                podciogi[i].push_back(x);
            }
            y[podciogi[i][0]].push_back({i , 0});
    }
    for(int i=0; i<n; i++){
        int liczba = t[i];
        for(int j=0; j<y[liczba].size(); j++){
            pomocnik.push_back(y[liczba][j]);
            pomocnik.back().second++;
        }
        y[t[i]].clear();
        for(int j=0; j<pomocnik.size(); j++){
            int nrPodc = pomocnik[j].first;
            int poz = pomocnik[j].second;
            if(poz>=podciogi[nrPodc].size()){
                wynik[nrPodc]=true;
            }
            else{
                y[podciogi[nrPodc][poz]].push_back(pomocnik[j]);
            }

            

        }
        pomocnik.clear();






    }
for(int i=0; i<m; i++){
    if(wynik[i]){
        cout << "TAK\n";
    }
    else{
        cout << "NIE\n";
    }

}

}