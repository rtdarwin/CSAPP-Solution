#include<stdio.h>
#include<stdlib.h>

int int_size_is_32_ED1()
{
	return ( 1 << 31 ) < 0;
}


int int_size_is_32_ED2()
{
	//Is it really OK to divide 16 to 8+8?
	return ( ( 0xffff << 8 ) << 8 ) < 0;
}


int main()
{
	printf( "%d\n", int_size_is_32_ED1() );
	printf( "%d\n", int_size_is_32_ED2() );
	return 0;
}
