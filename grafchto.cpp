#include <iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector<int> > mycout;
    for (int i = 0; i < n; i++) {
        vector<int> x;
        x.push_back(0);
        mycout.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mycout[x - 1][0] += 1;
        mycout[x-1].push_back(y);
        mycout[y - 1][0] += 1;
        mycout[y - 1].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mycout[i].size(); j++) {
            cout << mycout[i][j]<<" ";
        }
        cout << "\n";
    }
}

