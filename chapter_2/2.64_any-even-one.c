#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Return 1 when any even bit of x equals 1; 0 ohterwise.
 * Assume w=32
 */

/* Assume count from 0
 */
int any_even_one( unsigned x )
{
	return (bool)( x & 0x55555555 );
}

int main( void )
{
	printf( "%x\n", any_even_one( 0x22222200 ) );
	printf( "%x\n", any_even_one( 0x32222222 ) );
	printf( "%x\n", any_even_one( 0x22222223 ) );
	return 0;
}
