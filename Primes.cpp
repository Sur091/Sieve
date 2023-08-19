//
// Created by suraj on 8/19/2023.
//

#include "Primes.h"

#include <iostream>
#include <bitset>

Primes::Primes(uint32_t limit)
: no_of_primes_(0), list_of_primes_(nullptr), limit_(limit)
{
    // Initializing the array
    list_of_primes_ = new uint64_t[Required64BitNumbers()];
    list_of_primes_[0] = kFirstCase;
    for (uint32_t i = 1; i < Required64BitNumbers(); i++)
    {
        list_of_primes_[i] = kAlternateOnes;
    }

    // Sieve of Eratosthenes
    for (uint32_t p = 3; p * p <= limit_; p += 2)
    {
        if (ReadBitFor(p))
        {
            for (uint32_t i = p * p; i <= limit_; i += 2*p)
            {
                ClearBitFor(i);
            }
        }
    }

    // Handling the extra bits
    uint32_t extra_bits = 63u - (limit_ % 64u);
    list_of_primes_[Required64BitNumbers()-1] &= (list_of_primes_[Required64BitNumbers()-1] << extra_bits) >> extra_bits;

    // Count Primes
    for (uint32_t i = 0; i < Required64BitNumbers(); i++)
    {
        no_of_primes_ += CountBits(list_of_primes_[i]);
    }

}

Primes::~Primes()
{
    delete[] list_of_primes_;
}

bool Primes::ReadBitFor(uint32_t number) {
    return (list_of_primes_[number / 64llu] >> (number % 64llu)) & 1llu;
}

void Primes::ClearBitFor(uint32_t number) {
    list_of_primes_[number / 64llu] &= ~(1llu << (number % 64llu)) ;
}

uint32_t Primes::CountBits(uint64_t number) {
    uint32_t count = 0;
    for (; number!=0; count++)
    {
        number &= number - 1;
    }
    return count;
}

void Primes::PrintPrimes() {
    for (uint32_t i = 0; i <= limit_; i++)
    {
        if (ReadBitFor(i))
        {
            std::cout << i << '\t';
        }
    }
    std::cout << std::endl;
}


