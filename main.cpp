#include <iostream>
#include <cstdint>

#include "Primes.h"

int main() {
    uint32_t num;

    std::cout << "Enter a number:";
    std::cin >> num;

    Primes prime(num);

    std::cout << "The number of primes below " << prime.get_limit() << " is " << prime.get_no_of_primes() << std::endl;
    prime.PrintPrimes();
    std::cout << std::endl;

    return 0;
}
