#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int amount;
    cin >> amount;
    int sizes = amount * 2;
    vector<int> matrixs(sizes);
    for (int i = 0; i < sizes; i++)
    {
        int a;
        cin >> a;
        matrixs[i] = a;
    }

    int** F = new int* [amount];
    for (int i = 0; i < amount; i++)
    {
        F[i] = new int[amount]; // Создание строки размером amount
        for (int j = 0; j < amount; j++)
        {
            F[i][j] = 0;
        }
    }
    for (int i = 0; i < amount; ++i)
    {
        F[i][i] = 0;
    }
    for (int i = 0; i < amount - 1; i++)
    {
        int j = i + 1;
        F[i][i + 1] = matrixs[i * 2] * matrixs[i * 2 + 1] * matrixs[j * 2 + 1];;
    }
    for (int i = 0; i < amount; i++)
    {
        for (int j = i; j < amount; j++)
        {
            if (i == j)
                continue;
            else if (i == j + 1)
                continue;
            else
            {
                vector<int> search_min;
                int x;
                for (int k = i; k < j; k++)
                {
                    x = F[i][k] + F[k + 1][j] + matrixs[i * 2] * matrixs[k * 2 + 1] * matrixs[j * 2 + 1];
                    search_min.push_back(x);
                }
                auto minimal = min_element(search_min.begin(), search_min.end());
                F[i][j] = *minimal;
            }
        }
    }
    cout << F[amount-1][amount - 1];
    for (int j = 0; j < amount; j++)
    {
        delete[] F[j];
    }
    delete[] F;
}