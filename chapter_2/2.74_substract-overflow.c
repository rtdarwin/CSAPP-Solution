#include<stdio.h>
#include<stdlib.h>

/* Determine whether subtracting arguments will cause overflow */
int tsub_ovf( int x, int y )
{
	int w = sizeof( int ) << 3;
	int z = x - y;

	unsigned lx = x & ( 1 << ( w - 1 ) );
	unsigned ly = y & ( 1 << ( w - 1 ) );
	unsigned lz = z & ( 1 << ( w - 1 ) );

	/*
	 * lx differs from ly?
	 * lz differs from lx?
	 * If both, overflow
	 */
	return ( lx ^ ly ) && ( lx ^ lz );
}


int main()
{
	printf( "%d\n", tsub_ovf( 1, -1 ) );
	printf( "%d\n", tsub_ovf( 0x80000000,  1 ) );
	printf( "%d\n", tsub_ovf( 0x80000000, -1 ) );
	return 0;
}
