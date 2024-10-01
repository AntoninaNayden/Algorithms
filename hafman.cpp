#include <iostream>
#include<vector>
#include <queue>

using namespace std;
 
int main()
{
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<long long> myleaves;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		myleaves.push_back(a);
	}
	long long result = 0;
	priority_queue<long long, vector<long long>, greater<long long> > qversh(myleaves.begin(), myleaves.end());
	for (int i = 0; i < n - 1; i++) {
		long long Sum;
		Sum = qversh.top();
		qversh.pop();
		Sum += qversh.top();
		qversh.pop();
		qversh.push(Sum);
		result += Sum;
		if (i == n - 2) {
			cout << result;
		}
	}

}

