#include "task4.h"
#include <bitset>

std::pair<uint32_t, uint32_t> get_min_max(uint32_t value) {
    std::bitset<32> bits(value); 
    auto count = bits.count();
    uint32_t result = 0;
    uint32_t mask = 1;
    for (int i = 0; i < count; i++) {
        result |= mask;
        mask <<= 1;
    }
    return std::make_pair(result, result << (32 - count));
}