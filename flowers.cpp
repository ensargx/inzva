#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    int x, y;
    std::cin >> x >> y;

    std::vector<std::vector<bool>> isFlower(n, std::vector<bool>(m, false));
    for (int i = 0; i < k; i++)
    {
        int xf, yf;
        std::cin >> xf >> yf;
        isFlower[xf - 1][yf - 1] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isFlower[i][j])
            {
                int fx = i + 1, fy = j + 1;
                int xdiff = std::abs(fx - x);
                int ydiff = std::abs(fy - y);

                if (xdiff == ydiff)
                {
                    if (xdiff % 2 == 1)
                    {
                        ans++;
                    }
                }
                else if (xdiff > ydiff)
                {
                    if (xdiff % 2 == 1)
                    {
                        ans++;
                    }
                }
                else
                {
                    if (ydiff % 2 == 1)
                    {
                        ans++;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}