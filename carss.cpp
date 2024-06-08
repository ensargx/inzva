#include <bits/stdc++.h>

void bfs(std::array<std::array<int, 1000>, 1000>& dist, std::vector<std::pair<int, int>> startPos, int n, int m, std::array<std::array<bool, 1000>, 1000>& visited)
{
    std::queue<std::pair<int, int>> q;
    for (auto [x, y] : startPos)
    {
        q.push({x, y});
        visited[x][y] = true;
        dist[x][y] = 0; // dist[startPos] = 0
    }

    std::array<int, 4> dx = {-1, 1, 0, 0};
    std::array<int, 4> dy = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && dist[nx][ny] != -1)
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // . -> grass
    // # -> fence
    // M -> tractor
    // A -> initial pos
    std::array<std::array<char, 1000>, 1000> farm;
    std::array<std::array<int, 1000>, 1000> mcq;
    std::array<std::array<int, 1000>, 1000> tractors;
    std::array<std::array<bool, 1000>, 1000> visited;
    std::vector<std::pair<int, int>> tractorPos;
    int mcqX, mcqY;

    int n, m;
    std::cin >> n >> m;
    char in;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            tractors[i][j] = INT_MAX;
            mcq[i][j] = INT_MAX;
            std::cin >> in;
            farm[i][j] = in;
            if (in == 'M')
            {
                tractorPos.push_back(std::make_pair(i, j));
            }
            else if (in == 'A')
            {
                mcqX = i;
                mcqY = j;
            }
            else if (in == '#')
            {
                tractors[i][j] = -1;
                mcq[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) visited[i].fill(false);

    bfs(tractors, tractorPos, n, m, visited);

    // find the minimum moves for mcq to reach each cell
    mcq[mcqX][mcqY] = 0;
    for (int i = 0; i < n; i++) visited[i].fill(false);
    std::vector<std::pair<int, int>> mcqPos = {std::make_pair(mcqX, mcqY)};
    bfs(mcq, mcqPos, n, m, visited);

    // find the minimum moves to escape
    int min = -1;
    // check for top row
    for (int i = 0; i < m; i++)
    {
        if (mcq[0][i] != -1)
        {
            int moves = mcq[0][i];
            // check if tractor can reach this cell
            if (tractors[0][i] != -1 && tractors[0][i] > moves)
            {
                if (min == -1 || moves < min)
                {
                    min = moves;
                }
            }
        }
    }

    // check for bottom row
    for (int i = 0; i < m; i++)
    {
        if (mcq[n - 1][i] != -1)
        {
            int moves = mcq[n - 1][i];
            // check if tractor can reach this cell
            if (tractors[n - 1][i] != -1 && tractors[n - 1][i] > moves)
            {
                if (min == -1 || moves < min)
                {
                    min = moves;
                }
            }
        }
    }

    // check for left column
    for (int i = 0; i < n; i++)
    {
        if (mcq[i][0] != -1)
        {
            int moves = mcq[i][0];
            // check if tractor can reach this cell
            if (tractors[i][0] != -1 && tractors[i][0] > moves)
            {
                if (min == -1 || moves < min)
                {
                    min = moves;
                }
            }
        }
    }

    // check for right column
    for (int i = 0; i < n; i++)
    {
        if (mcq[i][m - 1] != -1)
        {
            int moves = mcq[i][m - 1];
            // check if tractor can reach this cell
            if (tractors[i][m - 1] != -1 && tractors[i][m - 1] > moves)
            {
                if (min == -1 || moves < min)
                {
                    min = moves;
                }
            }
        }
    }

    std::cout << min << std::endl;
}