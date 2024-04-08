// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

long long calculateEbob(long long a, long long b)
{
    if (b == 0)
        return a;
    return calculateEbob(b, a % b);
}

long long calculateEkok(long long a, long long b)
{
    return (a * b) / calculateEbob(a, b);
}

int main()
{
    // write your code here
    long long N, a, M;
    std::cin >> N >> a >> M;

    // WHY ITS NOT WORKING
    long long ekok = calculateEkok(M, a);
    long long k = ekok / a - 1;
    long long l = ekok / M - 1;

    long long res = k + l + 1;
    std::cout << res << std::endl;

    return 0;
}
