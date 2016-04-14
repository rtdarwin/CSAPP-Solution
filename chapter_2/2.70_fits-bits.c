#include<stdio.h>
#include<stdlib.h>

/*
 * Return 1 when x can be represented as an n-bits, 2's complement number;
 * 	  0 otherwise
 * Assume 1 <= n <= w
 */

/* 问题是关于补码二进制数的扩展与截断问题的 */
int fits_bits( int x, int n )
{
	/*
	 * If leftmost ( w - n + 1 ) bits are all 0s or all 1s, it can fit into n bits
	 * Firstly, judge whether all 1s
	 * Then,    judge whether all 0s 
	 */
	int w = sizeof(int) << 3;
	return     !(  ( (unsigned)x >> ( n - 1 ) )
		      ^( ( 1 << ( w - n + 1 ) ) - 1 ) )
		|| !( (unsigned)x >> ( n - 1 ) );
}


int main()
{
	printf( "%d\n", fits_bits( 0x0000ffff, 15 ) );
	printf( "%d\n", fits_bits( 0x0000ffff, 16 ) );
	printf( "%d\n", fits_bits( 0x0000ffff, 17 ) );
	printf( "%d\n", fits_bits( 0xffffffff,  2 ) );
	printf( "%d\n", fits_bits( 0xff123434, 24 ) );
	return 0;
}

