#include <bits/stdc++.h>

long long areaof(int x1, int y1, int x2, int y2, const std::vector<std::vector<long long>>& dp)
{
    // Make sure x1,y1 is the bottom-right corner
    if (x1 < x2)
        std::swap(x1, x2);
    if (y1 < y2)
        std::swap(y1, y2);

    // Handle the case where x2 or y2 is zero properly to avoid out of bounds access
    long long total = dp[x1][y1];
    long long left = (x2 > 0) ? dp[x2-1][y1] : 0;
    long long top = (y2 > 0) ? dp[x1][y2-1] : 0;
    long long corner = (x2 > 0 && y2 > 0) ? dp[x2-1][y2-1] : 0;

    return total - left - top + corner;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> a(n, std::vector<char>(m, 0));
    std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(m+1, 0));
    std::vector<std::pair<int,int>> i_ler;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            std::cin >> c;
            a[i][j] = c;
            if (c == 'i')
                i_ler.push_back(std::make_pair(i+1, j+1));
        }
    }
    int max_x = 0;
    int max_y = 0;
    int max_dp = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if (a[i-1][j-1] == 'a')
            {
                dp[i][j]++;
            }
            else if (a[i-1][j-1] == 'b')
            {
                dp[i][j]--;
            }
            if (dp[i][j] > max_dp)
            {
                max_dp = dp[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
/*
    // print dp
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/
    int selected_x = 0;
    int selected_y = 0;
    // std::cout << areaof(3, 3, 2, 2, dp);
    long long max = 0;
    for (auto [ix, iy] : i_ler)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == ix && j == iy) continue;
                long long area = areaof(i, j, ix, iy, dp);
                if (area > max)
                {
                    max = area;
                    selected_x = i;
                    selected_y = j;
                }
                // max = std::max(max, areaof(i, j, max_x, max_y, dp));
            }
        }
    }

    std::cout << max << std::endl;
    // std::cout << selected_x << " " << selected_y << std::endl;

    return 0;
}