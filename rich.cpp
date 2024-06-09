#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k; 
    std::vector<long long> prices(n);

    for (int i = 0; i < n; i++)
        std::cin >> prices[i];

    // formula for  : i = m-k+2 to m            (on the last k days)
    // sums of gains: max(0, prices[i] - prices[i-i])
    // sums of loses: max(0, prices[i-1] - prices[i])
    // calculate dmi: 100* (sum of gains) / (sum of gains + sum of loses)

    // calculate the sums of gains and loses for the last k days
    std::vector<long long> gains(n); // gains[i] = sum of gains from day 0 to day i
    std::vector<long long> loses(n); // loses[i] = sum of loses from day 0 to day i
    gains[0] = 0;
    loses[0] = 0;
    for (int i = 1; i < n; i++)
    {
        gains[i] = gains[i-1] + std::max(0LL, prices[i] - prices[i-1]);
        loses[i] = loses[i-1] + std::max(0LL, prices[i-1] - prices[i]);
    }
    
    double dmi = 0;
    long long sum_of_gains = 0;
    long long sum_of_loses = 0;
    int pn = 0;

    for (int i = k-1; i < n; i++)
    {
        sum_of_gains = gains[i] - gains[i-k+1];
        sum_of_loses = loses[i] - loses[i-k+1];
        dmi = 100.0 * sum_of_gains / (sum_of_gains + sum_of_loses);
        if (sum_of_gains + sum_of_loses == 0) dmi = 0;
        if (dmi > 65)   pn = 2;
        else if (dmi < 35)  pn = 1;
        else pn = 0;
        std::cout << std::fixed << std::setprecision(1) << dmi << " " << pn << "\n";
    }

    return 0;

    // dmi for day k (k=3)
    int m=3;
    sum_of_gains = gains[m] - gains[m-k+1];
    sum_of_loses = loses[m] - loses[m-k+1];
    dmi = 100.0 * sum_of_gains / (sum_of_gains + sum_of_loses);
    std::cout << std::fixed << std::setprecision(9) << dmi << std::endl;

    m = 5;
    sum_of_gains = gains[m] - gains[m-k+1];
    sum_of_loses = loses[m] - loses[m-k+1];
    dmi = 100.0 * sum_of_gains / (sum_of_gains + sum_of_loses);
    std::cout << std::fixed << std::setprecision(9) << dmi << std::endl;


    m=5;
    sum_of_gains = 0;
    sum_of_loses = 0;
    for (int i = m-k+2; i <= m; i++)
    {
        std::cout << "i: " << i << std::endl;
        sum_of_gains += std::max(0LL, prices[i] - prices[i-1]);
        sum_of_loses += std::max(0LL, prices[i-1] - prices[i]);
    }
    dmi = 100.0 * sum_of_gains / (sum_of_gains + sum_of_loses);
    std::cout << std::fixed << std::setprecision(9) << dmi << std::endl;

    return 0;
}