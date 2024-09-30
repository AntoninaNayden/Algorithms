#include <iostream>
#include<vector>
#include <cmath>
using namespace std;
int leader_is(int v, vector<int> &myvec) {
        if (myvec[v] < 0) {
            return v; // возвращает индекс лидера
        }
        else {
            return leader_is(myvec[v], myvec);
        }
    
}
void fight_between_leaders(int i, vector <int> broad, vector <int> eroad, vector<int> towns, int comp_svz) {
    if (towns[broad[i]]  < towns[eroad[i]]) {
        towns[broad[i]] += towns[eroad[i]];
        towns[eroad[i]] = broad[i];
        comp_svz -= 1;
    }

    else {
        towns[eroad[i]] += towns[broad[i]];
        towns[broad[i]] = eroad[i];
        comp_svz -= 1;
    }
}


int main()
{
    /* freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);*/
    int n, m;
    cin >> n >> m;
    int comp_svz;
    comp_svz = n;
    vector<int> towns(n + 1);
    for (int i = 1; i < n + 1; i++) {
        towns[i] = -1;
    }
    vector<int> broad(m + 1);
    vector<int> eroad(m + 1);
    for (int i = 1; i < m + 1; i++) {
        cin >> broad[i] >> eroad[i];
    }
    for (int i = 1; i < m + 1; i++) {

        if (towns[broad[i]] < 0 && towns[eroad[i]] < 0) {
            fight_between_leaders(i, broad, eroad, towns, comp_svz);
        }

        else {
            if (towns[broad[i]] > 0 || towns[eroad[i]] > 0) {
                broad[i] = leader_is(broad[i], towns);
                eroad[i] = leader_is(eroad[i], towns);
            }
            /*else if (towns[broad[i]] > 0) {
                broad[i] = leader_is(towns[broad[i]], towns);
            }
            else {
                eroad[i] = leader_is(towns[eroad[i]], towns);
            }*/
            if (eroad[i] != broad[i]) {
                fight_between_leaders(i, broad, eroad, towns, comp_svz);
            }
            
        }
         cout << comp_svz << "\n";
       
    }


}