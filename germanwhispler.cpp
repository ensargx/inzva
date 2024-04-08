// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

#define MOD 1000000007

int main()
{
    // write your code here
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    long long ans = 0;

    std::array<long long, 10> row1;
    std::array<long long, 10> row2;
    std::array<long long, 10> temp;

    for (int i = 1; i <= 9; i++)
    {
        row1[i] = 1;
    }

    for (int i = 1; i <= 9; i++)
    {
        row2[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            row2[j] = 0;
        }
        for (int j = 1; j <= 5; j++)
        {
            for (int k = j + 5; k <= 9; k++)
            {
                row2[j] += row1[k];
                row2[j] %= MOD;
            }
        }
        for (int j = 6; j <= 9; j++)
        {
            for (int k = j - 5; k >= 1; k--)
            {
                row2[j] += row1[k];
                row2[j] %= MOD;
            }
        }
        temp = row1;
        row1 = row2;
        row2 = temp;

        /*
        std::cout << "i: " << i << "\n";
        std::cout << "Row1: ";
        for (int i = 1; i <= 9; i++)
        {
            std::cout << row1[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Row2: ";
        for (int i = 1; i <= 9; i++)
        {
            std::cout << row2[i] << " ";
        }
        std::cout << std::endl;
        */
    }

    for (int i = 1; i <= 9; i++)
    {
        ans += row1[i];
        ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}