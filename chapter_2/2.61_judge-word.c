#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


bool judge_int( int x )
{
	// from A to D
	return ( !( x ^ ~0 ) )
		|| ( !x )
		|| ( !( ( x << ( ( sizeof(int) - 1 ) * 8 ) ) ^ ~0 ) )
		|| ( !( x << ( ( sizeof(int) - 1 ) * 8 ) ) );

}

int main( void ){
	printf( "%d\n%d\n%d\n%d\n",
			judge_int( -1 ),
			judge_int( 0 ),
			judge_int( 0xff << 8 ),
			judge_int( 0xff << ( sizeof(int) -1 ) * 8 )
		);

	printf( "%d\n%d\n%d\n",
			judge_int( -2 ),
			judge_int( 3 ),
			judge_int( 0xff << 7 )
		);
	return 0;
}
