#include <stdint.h>
#include <stdio.h>

// Write a function that takes an unsigned integer and returns the number of '1'
// bits it has (also known as the Hamming weight).
int hammingWeight(uint32_t n)
{
	int count_one_bit = 0;
	while (n > 0) {
		count_one_bit += n % 2;
		n /= 2;
	}
	return count_one_bit;
}

int main()
{
	return 0;
}
