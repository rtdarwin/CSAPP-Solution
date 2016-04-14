#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int saturating_add( int x, int y )
{
	int w = sizeof( int ) << 3;
	int z = x + y;

	unsigned lx = x & ( 1 << ( w - 1 ) );
	unsigned ly = y & ( 1 << ( w - 1 ) );
	unsigned lz = z & ( 1 << ( w - 1 ) );

	/*
	 * lz = 1000...000?
	 * lx equals ly?
	 * lz differs from lx and ly?
	 * If so, negative overflow
	 */
	lz  && !( lx ^ ly ) && ( lz ^ lx ) && ( z = INT_MIN );
	/*
	 * lz = 0000...000?
	 * lx equals ly?
	 * lz differs from lx and ly?
	 * If so, positive overflow
	 */
	!lz && !( lx ^ ly ) && ( lz ^ lx ) && ( z = INT_MAX );

	return z;
}


int main()
{
	printf( "%#x\n", saturating_add( 0x1fffffff, 1 ) );
	printf( "%#x\n", saturating_add( 0xffffffff, 1 ) );
	printf( "%#x\n", saturating_add( 0x7fffffff, 3 ) );
	return 0;
}
