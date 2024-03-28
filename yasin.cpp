/* 
 * Problem: Yasin's Running Practice
 * URL: https://algoleague.com/contest/problem-of-the-week/problem/yasins-running-practice/detail
 */

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;
    n++;
    long long ans = n;

    while ((n=n-2) > 2)
    {
        // n-=2;
        // if (n<3)
        //     break;
        long long tmp = n / 3;
        ans -= 2*tmp;
        n = tmp;
    }
    std::cout << ans - 1 << '\n';

    return 0;
}
