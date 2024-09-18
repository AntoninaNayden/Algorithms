#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Binary(vector <int> a,int x) {
	int L = 0;
	int R = a.size() ;
	while (L < R) {
		int C = (L + R) / 2;
		if (a[C] >= x) {
			R = C;
		}
		else {
			L = C + 1;
		}
	
	}
	return L;
}
int Isithere(vector<int>& a, int& x) {
	int help = *max_element(a.begin(), a.end());
	int help2 = *min_element(a.begin(), a.end());
	if (x > help || x < help2) {
		return 0;
	}
	else {
	int z = Binary(a, x);
	if (a[z] == x) {
	return 1;
	}
    else return 0;
		
	}
}


int BinaryBigger(vector<int>&a, int& x) {
	int y = Binary(a, x);
	int help = *max_element(a.begin(), a.end());
	if (x > help) {
		return a.size();
	}
	if (a[y] == a[a.size() - 1]) return y+1;
	else {
		if (Isithere(a, x) == 1) {
			while (a[y + 1] == a[y]) {
				y += 1;
				if (a[y] == a[a.size() - 1]) return y + 1;
			}
			return y + 1;
		}
		else return y;
	}
}


int main()
{
	int amount_of_elements;
	cin >> amount_of_elements;
	vector <int> a;
	for (int i = 0; i < amount_of_elements;i++) {
		int x;
		cin >> x;
		a.push_back(x);

	}
	//sort(a.begin(), a.end());

	int amount_of_q;
	cin >> amount_of_q;
	vector <int> b;
	for (int i = 0; i < amount_of_q; i++) {
		int x;
		cin >> x;
		b.push_back(x);

	}
	//sort(b.begin(), b.end());

	
	for (int i = 0; i < b.size(); i++) {
		cout << Isithere(a, b[i]) << " " << Binary(a, b[i]) << " "  << BinaryBigger(a, b[i]) << endl  ;
	}
}


