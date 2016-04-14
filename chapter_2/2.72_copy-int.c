#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Copy integer into buffer if space is aviliable */
void copy_int( int val, void *buf, int maxbytes )
{
	if( (size_t)maxbytes > sizeof( val ) ){
		memcpy( buf, (void *)&val, sizeof( val ) );
	}
}
