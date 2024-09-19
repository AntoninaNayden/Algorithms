#include <iostream>
#include<vector>

using namespace std;
void i_eat_women(vector <int>& a, int& b) {
	vector<int> F;
	vector<int> where_them;
	if (b == 2) {
		cout << -1;
		return;
	}
	F.push_back(a[0]);
	F.push_back(-23456);
	F.push_back(a[0] + a[2]);
	for (int i = 3; i < b; i++) {
		if (F[i - 2] > F[i - 3]) {
			F.push_back(F[i - 2] + a[i]);	
		}
		else {
			F.push_back(F[i - 3] + a[i]);
		}
	}
	where_them.push_back(b);
	int i = b;
	while (i > 0) {
		int x = F[i - 1] - a[i - 1];
		if (i - 3 >= 0 && F[i - 3] == x) {
			where_them.push_back(i - 2);
			i -= 2;
		}
		else if (i - 4 >= 0 && F[i - 4] == x) {
			where_them.push_back(i - 3);
			i -= 3;
		}
		else { 
			i = 0;
		}
		
	}
	reverse(where_them.begin(), where_them.end());
	cout << F[b - 1];
	cout << "\n";
	for (int i = 0; i < where_them.size(); i++) {
		cout << where_them[i]<<" ";
	}
	
}
int main()
{
	int cochka;
	cin >> cochka;
	vector <int> for_frog;
	for (int i = 0; i < cochka ; i++) {
		int n;
		cin >> n;
		for_frog.push_back(n);
	}
	 i_eat_women(for_frog, cochka);

}
