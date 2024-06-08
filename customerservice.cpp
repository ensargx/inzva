#include <bits/stdc++.h>

struct node
{
    int s;
    node *next[];
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    node nodes[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i].s = i;
    }

    return 0;
}