#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
 * NOTE: Do not cast int to long to simplify evaluation
 *
 * Because:
 * 1) You can't cast long to long when you have to evaluate a long type number.
 * 2) When the int and long have the same length, it result in wrong answer.
 */

/*
 * 此题不同于 2.78，要求不溢出，
 */
int fiveeights (int x)
{
	int w = sizeof(int) << 3;
	unsigned is_negative = x & ( 1 << (w-1) );
	int abs_x = x;
	is_negative && ( abs_x = -x );

	/* 统一化为正数计算 */
	unsigned last_one = abs_x & 1;
	unsigned last_three = abs_x & 0x7;
	int tmp = (abs_x >> 1) + (abs_x >> 3);
	bool carriage_bit = ( ( last_one << 2 ) + ( last_three ) )
		& 0x8;
	int result = tmp + carriage_bit;

	/* for negative x */
	is_negative && ( result = -result );

	return result;
}

int main (void)
{
	for( int i = 7; i < 32; i++ ) {
		printf( "%d\t", i );
		printf( "%d\t", fiveeights( i ) );
		printf( "%d\n", fiveeights( -i ) );
	}
	return 0;

}
