//
// Created by suraj on 8/19/2023.
//

#ifndef TRIAL_PRIMES_H
#define TRIAL_PRIMES_H


#include <cstdint>

class Primes{
public:
    explicit Primes(uint32_t limit);
    ~Primes();

    inline bool IsPrime(uint32_t number) { return ReadBitFor(number); };
    void PrintPrimes();

    [[nodiscard]] inline uint32_t get_no_of_primes() const { return no_of_primes_; };
    [[nodiscard]] inline uint32_t get_limit() const { return limit_; };
private:
    uint32_t no_of_primes_{};
    uint64_t* list_of_primes_;
    const uint32_t limit_;
private:
    [[nodiscard]] inline uint32_t Required64BitNumbers() const { return 1U + limit_/64U; };
    bool ReadBitFor(uint32_t number);
    void ClearBitFor(uint32_t number);
    static uint32_t CountBits(uint64_t number);

    static const uint64_t kAllOnes = 0xffffffffffffffff;       // 0b1111111111111111111111111111111111111111111111111111111111111111
    static const uint64_t kAlternateOnes = 0xaaaaaaaaaaaaaaaa; // 0b1010101010101010101010101010101010101010101010101010101010101010
    static const uint64_t kFirstCase = 0xaaaaaaaaaaaaaaac;     // 0b1010101010101010101010101010101010101010101010101010101010101100

};


#endif //TRIAL_PRIMES_H
