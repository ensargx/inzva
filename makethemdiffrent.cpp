#include <bits/stdc++.h>

#define ll long long

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    ll N;
    std::string arr;

    std::cin >> N;
    std::cin >> arr;

    ll c1 = 0;
    ll c2 = 0;
    for (ll i = 0; i < N; i++)
    {
        if (i%2 == arr[i]-'0')
            c1++;
        else
            c2++;
    }

    std::cout << std::min(c1, c2) << std::endl;

    return 0;
}