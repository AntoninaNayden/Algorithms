#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> amount;
bool mycompare(int a, int b) {
	return amount[a] > amount[b];
}

int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	cin >> n;
	long long controlpoint = 0;
	priority_queue <int, vector < int >, decltype(mycompare)* > towns(mycompare);
	vector<vector<int>> myroads;
	bool* isvisited = new bool[n];
	bool* controlled = new bool[n];
	for (int i = 0; i < n; i++) {
		isvisited[i] = false;
		controlled[i] = false;
	}
	// create roads
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		amount.push_back(y);
		vector<int>iamhelper(amount[i]);
		for (int j = 0; j < amount[i]; j++) {
			int x;
			cin >> x;
			iamhelper[j] = x - 1;
		}
		myroads.push_back(iamhelper);
	}
	int versh;

	for (int i = 0; i < n; i++) {
		towns.push(i);
	}


	while (!towns.empty()) {
		versh = towns.top();
		for (int i = 0; i < amount[towns.top()]; i++) {
			if (!isvisited[myroads[versh][i]]) {
				towns.push(myroads[versh][i]);
				isvisited[myroads[versh][i]] = true;
				if (!controlled[myroads[versh][i]] && !controlled[versh]) {
					controlled[myroads[versh][i]] = true;
					controlpoint += 1;
				}
			}
			if (i == 0)isvisited[versh] = true;
		}
		towns.pop();
	}
	cout << controlpoint;
}