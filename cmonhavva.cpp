/* 
 * Problem: C'mon Havva, just let me in..
 * URL: https://algoleague.com/contest/problem-of-the-week/problem/cmon-havva-just-let-me-in/detail
 */

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    char str[n];
    std::cin >> str;

    int count = 0;
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++)
    {
        l = i - 1;
        r = i;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            count++;
            l--;
            r++;
        }
    }

    for (int i = 1; i < n; i++)
    {
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            count++;
            l--;
            r++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
