#include<stdio.h>
#include<stdlib.h>

/*
 * Do rotating right shift.  Assume 0 <= n < w
 * Example when x = 0x12345678 and w = 32:
 * 	n = 4  -> 0x81234567
 * 	n = 20 -> 0x45678123
 */
unsigned rotate_right( unsigned x, int n )
{
	// Record.
	int right = ( ( 1 << n ) - 1 ) & x;
	// Logical right shift
	x >>= n;
	// Recover, Here `value computed is not used` results a warning.
	!n || (x |= ( right << ( sizeof(unsigned)*8 - n ) ) );

	return x;
}


int main(void)
{
	int x = 0x12345678;
	printf( "%#x\n", rotate_right( x, 0 ) );
	printf( "%#x\n", rotate_right( x, 4 ) );
	printf( "%#x\n", rotate_right( x, 20) );

	return 0;
}

