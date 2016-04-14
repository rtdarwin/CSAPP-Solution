#include<stdio.h>
#include<stdlib.h>

void show_bytes( unsigned char *start, int length )
{
	for( int i = 0; i < length; i++ ){
		printf( " %x", *(start + i ) );
	}
	putchar( '\n' );
}

void show_short( short x )
{
	show_bytes( (unsigned char *)&x, sizeof( short ) );
}

void show_int( int x )
{
	show_bytes( (unsigned char *)&x, sizeof( int ) );
}

void show_float( float x )
{
	show_bytes( (unsigned char *)&x, sizeof( float ) );
}

void show_double( double x )
{
	show_bytes( (unsigned char *)&x, sizeof( double ) );
}

int main( void )
{
	show_short( -1 );
	show_int( -1 );
	show_float( 2e8 );
	show_double( 2e8 );
	return 0;
}

