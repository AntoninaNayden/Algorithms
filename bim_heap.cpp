#include <iostream>
#include<vector>
using namespace std;

int main()
{
  /*  freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n;
    cin >> n;
    bool res = true;
    vector<int> bin_heap(n);
    for (int i = 0; i < n; i++) {
        cin >> bin_heap[i];
    }
    for (int i = 0; i < n/2 ; i++) {
        if (i == n / 2 - 1) {
            if (n % 2 == 0) {
                if (bin_heap[2 * i + 1] < bin_heap[i]) {
                    res = false;
                    break;
                }
            }
            else {
                if (bin_heap[2 * i + 1] < bin_heap[i] || bin_heap[2 * (i + 1)] < bin_heap[i]) {
                    res = false;
                    break;
                }
            
            }
        }
        else {
            if (bin_heap[2 * i + 1] < bin_heap[i] || bin_heap[2 * (i + 1)] < bin_heap[i]) {
                res = false;
                break;
            }
        }
    }
    if (res) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    
}

