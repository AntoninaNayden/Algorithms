#include <iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int * fathers =new int[n];
    for (int i = 0; i < n; i++) {
        fathers[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        fathers[y-1] = x;
    }
   for (int i = 0; i < n; i++) {
        cout << fathers[i]<<" ";
    }
}

