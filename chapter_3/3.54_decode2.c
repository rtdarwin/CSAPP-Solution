#include<stdio.h>

int decode2 (int x, int y, int z)
{
	int t1 = ( z - y ) ^ x;
	int t2 = ( ( z - y ) << 15 ) >> 15;
	return t1 * t2;
}

