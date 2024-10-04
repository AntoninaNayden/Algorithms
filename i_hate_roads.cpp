#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m,q;
    cin >> n >> m >> q;
    vector<int> towns(n + 1);
    for (int i = 1; i < n + 1; i++) {
        towns[i] = i;
    }
    vector<int> broad(m + 1);
    vector<int> eroad(m + 1);
    for (int i = 1; i < m + 1; i++) {
        cin >> broad[i] >> eroad[i];
    }
    vector<int> i_hate_roads(q+1);
    for (int i = 1; i < q + 1; i++) {
        cin >> i_hate_roads[i];
    }
    int** F = new int* [n+1];
    for (int i = 0; i < n + 1; i++) {
        F[i] = new int[n+1];
        for (int j = 0; j < n + 1; j++) {
            F[i][j] = 1;
        }
    }
    for (int k = 1; k < q + 1; k++) {
        int sum = 0;  
            for (int j = 1; j < n + 1; j++) {
                //F[j][broad[k]] = 0;
                F[broad[i_hate_roads[k]]][eroad[i_hate_roads[k]]] = 0;
                F[eroad[i_hate_roads[k]]][broad[i_hate_roads[k]]] = 0;
                if (F[broad[i_hate_roads[k]]][j] == 0) sum += 1;
            }   
        if (sum >= 3) {
            for (int i = k; i < q + 1; i++) {
                cout << 0;
            }
            break;
        }
        else cout << 1;
    }
}
