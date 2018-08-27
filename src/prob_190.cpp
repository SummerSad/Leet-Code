#include <stdint.h>
#include <stdio.h>

// Reverse bits of a given 32 bits unsigned integer.
uint32_t reverseBits(uint32_t n)
{
	uint32_t reverse_n = 0;
	int num_bits = 32;
	for (int i = 0; i < num_bits; ++i) {
		reverse_n = reverse_n * 2 + n % 2;
		n /= 2;
	}
	return reverse_n;
}

int main()
{
	return 0;
}
