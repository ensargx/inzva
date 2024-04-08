#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long divide_cnt, size;
    std::cin >> divide_cnt >> size;

    long long min_size = size / (divide_cnt + 1);
    long long max_size = min_size + 1;

    long long min_size_count = divide_cnt + 1 - size % (divide_cnt + 1);
    long long max_size_count = size % (divide_cnt + 1);

    // std::cout << "min_size: " << min_size << " min_size_count: " << min_size_count << std::endl;
    // std::cout << "max_size: " << max_size << " max_size_count: " << max_size_count << std::endl;

    long long result = min_size * min_size * min_size_count + max_size * max_size * max_size_count;
    std::cout << result << std::endl;
}