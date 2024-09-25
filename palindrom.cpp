#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<string>
using namespace std;
int main()
{
    ifstream file;
    file.open("input.txt");
    string myword;
    file >> myword;
    int wsize = myword.length();
    vector <char> word;
    for (int i = 0; i < wsize; i++) {
        word.push_back(myword[i]);
    }

  int** F = new int* [wsize];
    for (int i = wsize-1; i >= 0; i--) {
        F[i] = new int [wsize];
        for (int j = 0; j < wsize; j++) {
            if (i > j) F[i][j] = 0;
            else {
                if (j == i) {
                    F[i][j] = 1;
                }
                else if (j == i + 1) {
                    if (word[i] == word[j]) {
                        F[i][j] = 2;
                    }
                    else F[i][j] = 1;
                }
                else {
                    if (word[i] == word[j]) F[i][j] = F[i + 1][j - 1] + 2;
                    else F[i][j] = max(F[i][j - 1], F[i + 1][j]);
                }
            }
        }
    }
    ofstream file2("output.txt");
    int pallength = F[0][wsize - 1];
    file2 << pallength << "\n";
    vector <char> result;
    int i = 0;
    int j = wsize - 1;
    while (i<=j) {
        if (word[i] == word[j]) {
            result.push_back(word[i]);
            j--;
            i++;
        }
        else {
            if (F[i][j - 1] > F[i + 1][j]) {
                j--;
            }
            else i++;
        }
    }
    if (pallength % 2 == 0) {
        for (int i = result.size() - 1; i >= 0; i--) {
            result.push_back(result[i]);
        }
    }
    else {
        for (int i = result.size() - 2; i >= 0; i--) {
            result.push_back(result[i]);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        file2<< result[i];
    }
    file.close();
    file2.close();
}
