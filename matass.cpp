#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    ifstream file;
    file.open("input.txt");
    int amount;
    file >> amount;
    int sizes = amount * 2;
    int* dynamicArray = new int[sizes];
    for (int i = 0; i < sizes; i++) {
        file >> dynamicArray[i];
    }

    int** F = new int* [amount];
    for (int i = 0; i < amount; i++) {
        F[i] = new int[amount]; // Создание строки размером amount
        for (int j = 0; j < amount; j++) {
            F[i][j] = 0;
        }
    }

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (i > j) {
                F[i][j] = -1;
            }
            else {
                F[i][j] = 0;
            }
        }
    }
    /*for (int i = amount - 2; i >= 0; i--) {
    for(int j = i+1)
    }*/
 // reverse(matrixs.begin(), matrixs.end());
for (int i = amount - 2; i >= 0; i--) {
    for (int j = i+1; j<amount; j++) {
        if(j==i+1) F[i][j] = dynamicArray[i * 2] * dynamicArray[i * 2 + 1] * dynamicArray[j * 2 + 1];
        else {
            F[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + dynamicArray[i * 2] * dynamicArray[k * 2 + 1] * dynamicArray[j * 2 + 1]);
            }
        }
    }
}


 ofstream file2("output.txt");
 file2<< F[0][amount - 1];
    
 file.close();
 file2.close();
 delete[] dynamicArray;
}

