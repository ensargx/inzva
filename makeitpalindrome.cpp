#include <iostream>
#include <bits/stdc++.h>

char solve(std::string s)
{
    int n = s.length();
    if (n == 0)
        return '$';

    if (s[n] == s[n - 1])
        return solve(s.substr(1, n - 2));

    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = s.length();

    char toDelete = solve(s);
    std::cout << toDelete << std::endl;

    return 0;
}