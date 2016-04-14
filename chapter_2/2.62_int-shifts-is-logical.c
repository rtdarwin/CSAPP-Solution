#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool int_shifts_are_logical()
{
	int x = 1;
	x <<= ( ( sizeof(int) << 3 ) - 1 );
	/* If the shift is arthimetical, ( x >> bla ) will be 1111....1111
	 * Only ( 1111....1111 ^ ~0 ) is 0000.0000
	 * Other cases are not zero
	 */
	return ( ( x >> ( ( sizeof(int) << 3 ) - 1 ) ) ^ ~0 );
}

int main( void )
{
	printf( "%d\n", int_shifts_are_logical() );
	return 0;
}
