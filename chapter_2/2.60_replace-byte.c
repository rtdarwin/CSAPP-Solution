#include<stdio.h>
#include<stdlib.h>

unsigned replace_byte( unsigned x, unsigned char b, int i )
{
	*( (unsigned char *)&x + i ) = b;
	return x;
}


int main( void )
{
	unsigned source = 0x12345678;
	printf( "%#x\n", source );
	printf( "%#x\n", replace_byte( source, 0xab, 2 ) );
	printf( "%#x\n", replace_byte( source, 0xab, 0 ) );

	return 0;
}
