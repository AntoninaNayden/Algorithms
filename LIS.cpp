#include <iostream>
#include<vector>
#include <algorithm>
#include <fstream>
using namespace std;
int Binary(vector <int>& a, int& x) {
	int L = 0;
	int R = a.size();
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

int main()
{
	ifstream file;
	file.open("input.txt");
	int size;
	file>> size;
	vector <int> sequence(size);
	vector <int> numbers(size+1);
	for (int i = 0; i < size; i++) {
		int a;
		file >> a;
		sequence[i]=a;
	}
	numbers[0] = INT_MIN;
	for (int i = 1; i < size + 1; i++) {
		numbers[i] = INT_MAX;
	}
	int L;
	for (int i = 0; i < size; i++) {
		int l = Binary(numbers, sequence[i]);
		if (numbers[l - 1] < sequence[i]) {
			numbers[l] = sequence[i];
			L = max(L, l);
		}
		
	}
	ofstream file2("output.txt");
	file2 << L;
	
	file.close();
	file2.close();
}
