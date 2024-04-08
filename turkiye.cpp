#include <iostream>
#include <array>
#include <cmath>

#define PRIME_COUNT 1000

constexpr std::array<long long, PRIME_COUNT> calculatePrimes(long long max) 
{
    std::array<long long, PRIME_COUNT> primes {};
    long long primeCount = 0;

    std::array<bool, 100000> isPrime {};
    for (long long i = 0; i < max; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i < max; i++)
    {
        if (isPrime[i])
        {
            primes[primeCount++] = i;
            for (long long j = i*i; j < max; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N;
    std::cin >> N;

    constexpr long long maxPrime = 100000;
    std::array<long long, PRIME_COUNT> primes = calculatePrimes(maxPrime+1);

    long long result = 0;
    for (long long q : primes)
    {
        long long q5 = q * q * q * q * q;
        if (q5 > N)
            break;

        long long p = 1;
        while (q5 * p <= N && p <= q)
        {
            // std::cout << q5 << " " << p << std::endl;
            result++;
            p++;
        }
        
    }

    std::cout << result << std::endl;

    return 0;
}
