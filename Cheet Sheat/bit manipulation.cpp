#include <iostream>

// 1. Get the i-th bit (returns 0 or 1)
bool getBit(int num, int i) {
    return (num & (1 << i)) != 0; // Check if bit is set
}

// 2. Set the i-th bit to 1
int setBit(int num, int i) {
    return num | (1 << i); // Forces bit to be 1
}

// 3. Clear the i-th bit to 0
int clearBit(int num, int i) {
    return num & ~(1 << i); // Inverted mask forces bit to 0
}

// 4. Toggle the i-th bit (1 -> 0, 0 -> 1)
int toggleBit(int num, int i) {
    return num ^ (1 << i); // XOR flips the bit
}

// 5. Check if a number is a power of 2
bool isPowerOfTwo(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}
