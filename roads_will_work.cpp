#include <iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;
int leader_is(int v, vector<int>& myvec) {
    if (myvec[v] < 0) {
        return v; // возвращает индекс лидера
    }
    else {
        return leader_is(myvec[v], myvec);
    }

}
void fight_between_leaders(int i, vector <int>& broad, vector <int>& eroad, vector<int>& towns, int& comp_svz) {
    if (towns[broad[i]] < towns[eroad[i]]) {
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
  freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int comp_svz;
    comp_svz = n;
    vector<int> towns(n + 1);
    for (int i = 1; i < n + 1; i++) {
        towns[i] = -1;
    }
    vector<int> broad;
    vector<int> eroad;
    broad.push_back(0);
    eroad.push_back(0);
    vector<bool> isithere(m+1,false);
    vector<int> kingkong(q);
    vector<int> revkingkong(q);
   
    for (int i = 1; i < m + 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        broad.push_back(a);
        eroad.push_back(b);
    }
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &kingkong[i]);
        isithere[kingkong[i]] = true;
    }
    reverse(kingkong.begin(), kingkong.end());

    for (int i = 1; i < m + 1; i++) {
        if (isithere[i] == false) {
            if (towns[broad[i]] < 0 && towns[eroad[i]] < 0) {
                fight_between_leaders(i, broad, eroad, towns, comp_svz);
            }

            else {
                if (towns[broad[i]] > 0 || towns[eroad[i]] > 0) {
                    broad[i] = leader_is(broad[i], towns);
                    eroad[i] = leader_is(eroad[i], towns);
                }

                if (eroad[i] != broad[i]) {
                    fight_between_leaders(i, broad, eroad, towns, comp_svz);
                }

            }
        }
    }
   
    for (int i = 0; i < q ; i++) {
        if (comp_svz == 1) {
            revkingkong[i] = 1;
        }
        else {
            revkingkong[i] = 0;
        }

        if (towns[broad[kingkong[i]]] < 0 && towns[eroad[kingkong[i]]] < 0) {
            fight_between_leaders(kingkong[i], broad, eroad, towns, comp_svz);
        }

        else {
            if (towns[broad[kingkong[i]]] > 0 || towns[eroad[kingkong[i]]] > 0) {
                broad[kingkong[i]] = leader_is(broad[kingkong[i]], towns);
                eroad[kingkong[i]] = leader_is(eroad[kingkong[i]], towns);
            }
            
            if (eroad[kingkong[i]] != broad[kingkong[i]]) {
                fight_between_leaders(kingkong[i], broad, eroad, towns, comp_svz);
            }

        }
        

    }
    for (int i = q - 1; i >= 0; i--) {
         printf("%d",&revkingkong[i]);
    }

}
