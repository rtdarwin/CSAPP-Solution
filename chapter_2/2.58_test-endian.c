#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_little_endian( void )
{
	int i = 1;
	if( *( (unsigned char*)&i ) )
		return true;
	else
		return false;
}

int main( void )
{
	if( is_little_endian() ){
		printf( "little_endian machine\n" );
	} else {
		printf( "big_endian machine\n" );
	}
}
