// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

int main()
{
    // write your code here
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> friends(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    std::vector<int> line;

    for (int i = 1; i <= N; i++)
    {
    }

    return 0;
}
