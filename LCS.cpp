#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int amount;
    cin >> amount;
    int* sequense1 = new int[amount];
    int* sequense2 = new int[amount];
    
    for (int i = 0; i < amount; i++) {
        cin >> sequense1[i];
    }
    for (int j = 0; j < amount; j++) {
        cin >> sequense2[j];
    }
    int** F = new int* [amount+1];
    for (int i = 0; i < amount+1; i++) {
        F[i] = new int[amount+1]; // Создание строки размером amount
        for (int j = 0; j < amount+1; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            }
            else {
                if (sequense1[i-1] == sequense2[j-1]) {
                    F[i][j] = F[i - 1][j - 1] + 1;
                }
                else {
                    F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                }
            }
        }
    }
   
    vector<int> sequense3;
    vector<int> sequense4;

    int i = amount;
    int j = amount;
    while (i > 0 && j > 0) {
        if (sequense1[i - 1] == sequense2[j - 1]) {
            sequense3.push_back(i - 1);
            sequense4.push_back(j - 1);
            i--;
            j--;
        }
        else if(F[i-1][j]==F[i][j]) {
            i--;
        }
        else {
            j--;
        }
    
    }

    cout << F[amount][amount];
    cout << "\n";
    reverse(sequense3.begin(), sequense3.end());
    reverse(sequense4.begin(), sequense4.end());
    for (int i = 0; i < F[amount][amount]; i++) {
        cout << sequense3[i]<<" ";
    }
    cout << "\n";
    for (int j = 0; j < F[amount][amount]; j++) {
        cout << sequense4[j]<<" ";
    }

}

