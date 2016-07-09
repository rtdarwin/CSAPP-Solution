#include<stdio.h>
#include<stdlib.h>

/*
 * NOTE: Do not cast int to long
 *
 * Because:
 * - Can't emulate the real x*5/8 evaluation, because if long is longer than int,
 *    it will not overflow.
 */
int mul5div8 (int x)
{
	/* for positive x */
	x = ( x << 2 ) + x;
	x = x >> 3;

	/* for negative x, add following steps */
	int w = sizeof(int) << 3;
	unsigned is_negative = x & ( 1 << (w-1) );
	unsigned mask = 0x7;
	unsigned last_three = x & mask;
	is_negative && last_three && ( x += 1 );

	return x;
}

int main (void)
{
	printf( "%d\n", mul5div8( 7 ) );
	printf( "%d\n", mul5div8( -7 ) );
	return 0;
}
