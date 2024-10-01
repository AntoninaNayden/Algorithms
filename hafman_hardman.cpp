#include <iostream>
#include<vector>
using namespace std;

int main()
{
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<long long> myleaves(n + 2);
    vector<long long>  summa(n + 2);
    for (int i = 0; i < n + 2; i++) {
        if (i == n || i == n + 1) {
            myleaves[i] = INT64_MAX / 2;
        }
        else {
            long long a;
            scanf("%lld", &a);
            myleaves[i] = a;
        }
    }
    for (int i = 0; i < n + 2; i++) {
        summa[i] = INT64_MAX / 2;
    }
    int i = 0;
    int j = 0;
    long long result = 0;
    for (int k = 0; k < n - 1; k++) {
        if (myleaves[i] + myleaves[i + 1] <= summa[j] + summa[j + 1] &&
            myleaves[i] + myleaves[i + 1] <= myleaves[i] + summa[j]) {

            summa[k] = myleaves[i] + myleaves[i + 1];
            result += summa[k];
            i += 2;
            continue;
        }
        if (summa[j] + summa[j + 1] <= myleaves[i] + myleaves[i + 1] &&
            summa[j] + summa[j + 1] <= myleaves[i] + summa[j]) {
            summa[k] = summa[j] + summa[j + 1];
            result += summa[k];
            j += 2;
            continue;
        }
        if (myleaves[i] + summa[j] <= myleaves[i] + myleaves[i + 1] &&
            myleaves[i] + summa[j] <= summa[j] + summa[j + 1]) {
            summa[k] = myleaves[i] + summa[j];
            result += summa[k];
            i++;
            j++;
            continue;
        }

    }
    printf("%lld", result);

}