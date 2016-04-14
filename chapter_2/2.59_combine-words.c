#include<stdio.h>
#include<stdlib.h>

unsigned combine_word( unsigned int s, unsigned int t )
{
	unsigned int result = 0;
		*( (unsigned char*)&result )
			= *( (unsigned char*)&s );
	for( size_t i = 1; i < sizeof(unsigned int); i++ ){
		*( (unsigned char*)&result + i )
			= *( (unsigned char*)&t + i );
	}

	return result;
}



int main( void )
{
	unsigned s = 0x89abcdef;
	unsigned t = 0x76543210;
	printf( "%#x\n%#x\n", s, t );
	
	unsigned result = combine_word( s, t );
	printf( "%#x\n", result );
	
	return 0;
}
