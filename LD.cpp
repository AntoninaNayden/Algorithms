#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;
int main()
{
	ifstream file;
	file.open("in.txt");
	int x,y,z;
	file >> x >> y >> z;
	string firstword;
	string secondword;
	file >> firstword;
	file >> secondword;
	int size1 = firstword.size();
	int size2 = secondword.size();
	int** F = new int* [size1+1];
	for (int i = 0; i < size1+1; i++) {
		F[i] = new int[size2+1];
		for (int j = 0; j < size2+1; j++) {
			int sigma ;
			if (j == 0) {
				F[i][j] = i * x;
				continue;
			}
			else if (i == 0) {
				F[i][j] = j * y;
				continue;
			}
			if (firstword[i-1] == secondword[j-1]) {
			 sigma = 0;
			}
			else {
				sigma = 1; 
			}
				int aks = min(F[i - 1][j] + x, F[i][j - 1] + y );
				F[i][j] = min(aks, F[i - 1][j - 1] + sigma * z);

		}
	}
	ofstream file2("out.txt");
	file2 << F[size1 ][size2];
	file.close();
	file2.close();
}

