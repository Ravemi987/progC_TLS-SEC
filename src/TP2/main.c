#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int questionOne(int n) {
    return n << 1;
}

uint32_t questionTwo(uint32_t a, uint32_t b) {
    uint32_t c = ((a >> 16) & 0xFFFF) | ((b & 0xFFFF) << 16);
    return c;
}

uint32_t questionThree(uint32_t a, uint32_t b) {
    return (a ^ b) == (1 << 10);
}

int bitcount(int n) {
    int x = n;
    int count = 0;

    while (x != 0) {
        if (x & 0x1) count++;
        x = x >> 1;
    }

    return count;
}

int main(void) {

    int i = 2;

    printf("Question 1 : %d\n", questionOne(i));
    printf("Question 2 : %x\n", questionTwo(0x11223344, 0x55667788));
    printf("Question 3 : %x\n", questionThree(0x00000000, 0x00000400));
    printf("Question 4 : %d\n", bitcount(0b10110010));

}
