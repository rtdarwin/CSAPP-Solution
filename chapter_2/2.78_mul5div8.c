#include<stdio.h>
#include<stdlib.h>

/*
 * NOTE: Do not cast int to long to simplify evaluation
 *
 * Because:
 * 1) You can't cast long to long when you have to evaluate a long type number.
 * 2) When the int and long have the same length, it results in wrong.
 * 3) Can't emulate the real x*5/8 evaluation, because if long is longer than int,
 *    it will not overflow.
 */
int mul5div8 (int x)
{
	unsigned mask = 0x7;
	x = ( x << 2 ) + x;
	unsigned last_three = x & mask;
	x = x >> 3;
	/* if last_three is not zero */
	last_three && ( x += 1 );

	return x;
}

int main (void)
{
	printf( "%d\n", mul5div8( -7 ) );
	return 0;
}
