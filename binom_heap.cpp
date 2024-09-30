#include <iostream>
#include<vector>
#include <cmath>
using namespace std;
vector<int> to_bin(long long x) {
    vector<int> res;
    while (x != 0) {
        int a = x % 2;
        res.push_back(a);
       x = x / 2;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    bool is_binom=true;
        vector<int> resu = to_bin(n);
        for (int i = 0; i < resu.size(); i++) {
            if (resu[i] == 1) {
                cout << i << "\n";
                is_binom = false;
            }
        }
        if (is_binom) {
            cout << -1;
        }
}
