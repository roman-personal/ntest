#include "task1.h"
#include <stdexcept>

void calculate_primes(int n, int* primes) {
    if (n < 1)
        throw std::invalid_argument("N should be greater than zero");
    if (primes == nullptr)
        throw std::invalid_argument("Primes should not be null");
    primes[0] = 2;
    int value = 3;
    int i = 1;
    while (i < n) {
        bool is_prime = true;
        for (int j = 0; j < i && is_prime; j++)
            is_prime = value % primes[j] != 0;
        if (is_prime)
            primes[i++] = value;
        value++;
    }
}