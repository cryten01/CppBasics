
#ifndef CPPBASICS_MATH_H
#define CPPBASICS_MATH_H

#include <math.h>
#include <array>

/**
 * Count Primes
 * Sieve of Eratosthenes
 * @param n
 * @return
 */
int countPrimes(int n) {
    // 0,1 case
    if (n <= 1) { return 0; }

    // 2-n case
    std::vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;

    // Counting the numbers which are not prime
    int falseCount = 2;

    // Composite numbers have at least 2 factors -> at least 1 of must be < sqrt(n)
    // because sqrt(3) * sqrt(3) = 3 || 3 * 3 == 6 => < n
    for (int i = 2; i * i < n; i++) {
        if (primes[i]) {
            // Possible because previous one should already be marked out
            for (int j = i; j * i < n; j++) {
                // Mark as false if still true
                if (primes[j * i]) {
                    primes[j * i] = false;
                    falseCount++;
                }
            }
        }
    }

    return n - falseCount;
}

/**
 * 326. Power of Three
 * @param n
 * @return
 */
bool isPowerOfThree(int n) {
    while (n >= 3) {
        if (n % 3 != 0) { return false; }
        n /= 3;
    }

    return n == 1;
}

#endif //CPPBASICS_MATH_H
