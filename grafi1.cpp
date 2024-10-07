#include <iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >>m ;
    vector<int > rebra(2*m);
    for (int i = 0; i < m; i++) {
        int x;
        int y;
        cin >> x >> y;
        rebra[i * 2] = x;
        rebra[i * 2 + 1] = y;
    }
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        arr[rebra[i * 2]-1][rebra[i * 2 + 1]-1] = 1;
        arr[rebra[i * 2 + 1]-1][rebra[i * 2]-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << "\n";
    }
}