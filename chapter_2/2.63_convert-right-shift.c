#include<stdio.h>
#include<stdlib.h>

int sra( int x, int k )
{
	//Perform shift logically
	int xsrl = (unsigned) x >> k;
	//Convert
	unsigned mask = 0;
	if( x < 0 ){
		int w = sizeof(int) << 3;
		for( int i = w - k; i < w; i++ ){
			mask |= ( 1 << i );
		}
	}
	//else, keep xsrl.
	return xsrl | mask;
}


unsigned srl( unsigned x, int k )
{
	//Preform shift arithmetically
	unsigned xsra = (int) x >> k;
	//Convert
	unsigned mask = ~0;
	if( (int)x < 0 ){
		mask = 0;
		int w = sizeof(int) << 3;
		for( int i = 0; i < w - k; i++ ){
			mask |= ( 1 << i );
		}
	}
	//else, keep xsra.
	return xsra & mask;
}


int main( void )
{
	printf( "%#x\n", sra( -1, 3 ) );

	printf( "%#x\n", srl( -1, 3 ) );

	return 0;
}
