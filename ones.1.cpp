#include <iostream>
using namespace std;
	
int main()
{
	
	int n, k;
	cin >> n >> k;
	int** F = new int* [n+1];
	
	for (int i = 0; i < n+1; i++) {
		F[i] = new int[n+1]; // Создание строки размером n
		for (int j = 0; j < n+1; j++) {
			if (j == 0) F[i][j] = 1;
			else if (i == j) F[i][j] = 1;
			else if (j > i) F[i][j] = 0;
			else {
				F[i][j] = F[i - 1][j - 1]%1000000007 + F[i - 1][j]%1000000007;
			}
		}
	}
	cout << F[n][k] % 1000000007;
}
