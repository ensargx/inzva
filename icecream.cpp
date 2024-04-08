#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> icecreams(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> icecreams[i];
    }

    int min = icecreams[0];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (icecreams[i] < min)
        {
            min = icecreams[i];
        }
        sum += icecreams[i];
    }

    std::cout << sum - min << std::endl;

    return 0;
}