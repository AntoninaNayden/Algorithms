#include <iostream>
using namespace std;
unsigned long long F(long long n, long long b) {
		unsigned long long  result = 1;
		while (n != 0) {
			if ((n & 1) != 0) {
				result = ((result % 1000000007) * (b % 1000000007))%1000000007;
			}
			b = ((b % 1000000007)*(b % 1000000007))%1000000007;
			n >>= 1;
		}
		return result % 1000000007;
}

	/*if (n == 0) return 1;
	else if (n == 1) return b;
	else {
		if (n % 2 == 0) {
			long long f = (F(n / 2, b) * F(n / 2, b)) % 1000000007 ;
			return f;
	    }
		else {
			long long f = (F((n-1) / 2, b) * F((n-1) / 2, b)*b) % 1000000007;
			return f;
		}
		
	}*/

unsigned long long Aboba(long long n, long long k) {
	if (k == n) return 1;
	else if (k == 0) return 1;
	if (n - k == 1) {
		return n;
	}
	else {
		unsigned long long result = (((k + 1) % 1000000007) * (F(1000000005, (n - k)) % 1000000007)) % 1000000007;
		for (int i = 1; i < n - k; i++) {
			result = ((((result  * (k + 1 + i))%1000000007) * ((F(1000000005, (n - k - i)))) % 1000000007) % 1000000007);

		// 1/n-k-i = (n-k-i)^1000000005
		}
		return result % 1000000007;
	}
}

int main()
{
	long long n, k;
	cin >> n >> k;
    cout << Aboba(n, k);
	 
}
