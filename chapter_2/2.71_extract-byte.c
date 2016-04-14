#include<stdio.h>
#include<stdlib.h>

/* Extract byte from word. Return as signed integer. */
int xbyte( unsigned word, int bytenum )
{
	// Note: have to convert word to int-type.
	return ( (int)word << ( ( 3 - bytenum ) << 3 ) ) >> 24 ;
}

int main()
{
	printf( "%d\n", xbyte( 0xffff1fff, 1 ) );
	printf( "%d\n", xbyte( 0xffffffff, 3 ) );

	return 0;
}
