#include<stdio.h>
#include<stdlib.h>

/*
 * Make with least signficant n bits set to 1
 * Example: n = 6 --> 0x3f, n = 17 --> 0x1ffff
 * Assume 1 <= n <= w
 */
int lower_bits( int x, int n )
{
	int result = ~0;
	int n_equals_w = !( n ^ (sizeof(int) << 3 ) );
	// If not n equals n, then result = ...
	n_equals_w || ( result = x | ( ( 1 << n ) - 1 ) );

	return result;
}

int main()
{
	printf( "%#x\n", lower_bits( 0, 32 ) );
	return 0;
}
