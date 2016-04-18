#include<stdio.h>
#include<stdlib.h>

/* Divide by power of two.  Assume 0 <= k < w -1 */
int divide_power2( int x, int k )
{
	int w = sizeof( int ) << 3;
	unsigned is_negative = x & ( 1 << (w-1) );
	int result = x >> k;

	/* If x is negative, use ( x + y - 1 ) >> 2^k */
	int y = 1 << k;
	is_negative && ( result = (x+y-1) >> k );

	return result;
}

int main()
{
	if( divide_power2( -5, 2 ) == -5/4
	    && divide_power2( 5, 2 ) == 5/4 ){
		printf( "correct\n" );
	}
	return 0;
}
