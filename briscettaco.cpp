// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

long long combinate(long long n)
{
    return n * (n - 1) / 2;
}

int main()
{
    // write your code here
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long N, M;
    std::cin >> N >> M;

    // Coordinates for N tacos
    std::map<long long, long long> distCount;
    long long total = 0;
    for (long long i = 0; i < N; i++)
    {
        long long x, y;
        std::cin >> x >> y;

        long long distY = x * M - y;
        distCount[distY]++;
    }

    // Calculate the number of pairs of tacos
    for (auto it = distCount.begin(); it != distCount.end(); it++)
    {
        long long count = it->second;
        // std::cout << it->first << " " << count << std::endl;
        if (count > 1)
            total += combinate(count);
    }

    std::cout << total << std::endl;

    return 0;
}
