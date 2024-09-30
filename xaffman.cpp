#include <iostream>
#include <vector>
using namespace std;
int sumator(vector<int> &x) {
    vector<int>summ;
    summ[0] = x[0] + x[1];
    for (int i = 1; 0 < summ.size(); i++) {
        summ.push_back(0);
    }
    for (int i = 2; i < x.size(); i++) {
    
    }
}
int main()
{
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vvod(n);
    vector<int> sum(n - 1);
    vector<int> high(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> vvod[i];
    }
    sum[0] = vvod[0] + vvod[1]; 
    for (int i = 1; i < n-1; i++) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {  
        high[i] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (sum[i - 1] == 0) {
            if (i == n - 1) {
                sum[i - 1] = sum[i - 2] + vvod[i];
                for (int j = 0; j < i; j++) {
                    high[j] += 1;
                }
            }
            else {
                if (sum[i - 2] + vvod[i] > vvod[i] + vvod[i + 1]) {
                    sum[i - 1] = vvod[i] + vvod[i + 1];

                }
                else {
                    sum[i - 1] = sum[i - 2] + vvod[i];
                    for (int j = 0; j < i; j++) {
                        high[j] += 1;
                    }
                }
            }

        }
        else {
            if (sum[i - 2] + sum[i - 1] < sum[i - 2] + vvod[i]) {
                sum[i]=sum[]
            }
            else {
            }
        }
    }
    int Sum = 0;
    for (int i = 0; i < n ; i++) {
        Sum += high[i] * vvod[i];
    }
    cout << Sum;
}

