#include <iostream>
#include<vector>
using namespace std;
class vershina {
public:
	int meaning;
	int visited;
	vershina() {
		visited = 0;
		meaning = 0;
	}
};
bool dfs(int x, int** &arr, int& n, vector<vershina> &base,int &sumator) {
	base[x].visited = 1;
	for (int k = 0; k < n; k++) {
		if (arr[x][k] == 1) {
			arr[k][x] = 0;
			sumator += 1;
			if (base[k].visited == 0) {
				
			 dfs(k, arr, n, base,sumator);
			}
			else {
				return false;
			}
		}
		else {
			continue;
		}
	}
	return true;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sumator = 0;
	vector<vershina> base(n);
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		base[i].meaning = i;
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	if (dfs(0, arr, n, base,sumator) && (sumator+1) == n) cout << "Yes";
	else cout << "No";

}
