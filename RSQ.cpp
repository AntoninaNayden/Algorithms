#include <iostream>
#include <cmath>
#include<string>
using namespace std;
long long FindSum(long long l, long long r, long long& m, long long* res, long long* arr) {
	long long bleft = l / m;
	long long bright = r / m;
	if (bleft == bright) {
		long long sum = 0;
		for (long long i = l; i < r; i++) {
			sum += arr[i];
		}
		return sum;
	}
	else {
		long long sum = 0;
		for (long long i = l; i < r; i++) {
			if (i % m == 0 && i / m != bright) {
				sum += res[i / m];
				i += m - 1;
			}
			else {
				sum += arr[i];
			}
		}
		return sum;
	}
}
void Add(long long i, long long& m, long long addit, long long* res, long long* arr) {
	long long x = i / m;
	arr[i] += addit;
	res[x] += addit;
}
int main()
{
	long long n;
	cin >> n;
	long long* arr = new long long[n];
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		//cin >> arr[i];
	}
	// wright questions & cout
	long long m = sqrt(n);
	long long del;
	if (n % m != 0) del = n / m + 1;
	else del = n / m;
	long long ost = n % m;
	long long* res = new long long[del];
	for (long long i = 0; i < del; i++) {
		long long sum = 0;
		if (i == del - 1) {
			if (ost == 0) {
				for (long long j = 0; j < m; j++) {
					sum += arr[i * m + j];
				}
			}
			else {
				for (long long j = 0; j < ost; j++) {
					sum += arr[i * m + j];
				}
				for (long long j = ost; j < m; j++) {
					break;
				}
			}
		}
		else {
			for (long long j = 0; j < m; j++) {
				sum += arr[i * m + j];
			}
		}
		res[i] = sum;
		//cout << res[i]<<" ";
	}
	//cout << "\n";

	int taska;
	//cin >> taska;
	scanf("%d", &taska);
	string function;
	long long first, second;
	for (long long i = 0; i < taska; i++) {
		cin >> function >> first >> second;
		if (function == "FindSum") {
			cout << FindSum(first, second, m, res, arr) << "\n";
		}
		if (function == "Add") {
			Add(first, m, second, res, arr);
			
		}
	}

}