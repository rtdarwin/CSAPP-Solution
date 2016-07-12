#include<stdio.h>


int loop (int x, int n)
{
	int result = 143165765;
	int mask;
	for (mask = -2146483648; mask != 0; mask <<= (char)n){
		result ^= (mask & x);
	}
	return result;
}

