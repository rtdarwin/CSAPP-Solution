#include<limits.h>

/*
 * NOTE: Do not think about the low-level implementation of addu, addi
 *       just use the function provided by the library.
 *
 * Assume sign_hign_prod return the high w-bits of the multiply of x, y
 * with a modification to make it correct.
 */
extern int signed_high_prod( int x, int y );


/* According to equation(2.18) in textbook. */
unsigned unsigned_high_prod( unsigned x, unsigned y )
{
	unsigned lx = ( x > INT_MAX )? 1: 0;
	unsigned ly = ( y > INT_MAX )? 1: 0;
	int signed_high = signed_high_prod( (unsigned)x, (unsigned)y );
	return (unsigned)signed_high + ( lx * y + ly * x );
}
