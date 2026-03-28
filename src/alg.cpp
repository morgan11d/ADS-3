#include <iostream>
#include <cstdint>

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    
    return length;
}

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        
        if (num > maxVal) {
            maxVal = num;
        }
    }
    
    return maxVal;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int bestNum = lbound;
    unsigned int bestLen = collatzLen(lbound);
    uint64_t bestMaxVal = collatzMaxValue(lbound);
    
    for (uint64_t num = lbound + 1; num <= rbound; num++) {
        unsigned int currentLen = collatzLen(num);
        
        if (currentLen > bestLen) {
            bestLen = currentLen;
            bestNum = num;
            bestMaxVal = collatzMaxValue(num);
        }
    }
    
    *maxlen = bestLen;
    
    std::cout << bestNum << std::endl;
    std::cout << bestMaxVal << std::endl;
    std::cout << bestLen << std::endl;
    
    return bestNum;
}
