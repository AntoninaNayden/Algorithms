#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    long long n, k;
    cin >> n >> k;
    priority_queue <pair<long long,long long>, vector<pair<long long, long long> >, greater<> > mags;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        mags.push(make_pair(x,y));
    }

    long long sumator = 0;
    for (long long j = 0; j < k; j++) {
        auto x = mags.top();
        sumator += x.first;
        mags.pop();
        mags.push(make_pair(x.first+x.second,x.second));
    }
    cout << sumator;
}