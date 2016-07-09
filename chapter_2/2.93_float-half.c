#include<stdio.h>

typedef unsigned float_bits;

float float_half (float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xff;
	unsigned frac = f & 0x7fffff;

	float result;
	if (exp == 0xff && frac) {
		/* NaN */
		result = f;
	} else if (exp == 0xff) {
		/* Infinite */
		result = f;
	} else if (!exp) {
		/* Denormalized */
		result = sign << 31 | exp << 23 | frac >> 1;
	} else if (exp == 1) {
		/* Nomalized to Denomalized */
		result = sign << 31 | frac >> 1;
	} else {
		/* Normalized to Normalized */
		result = sign << 31 | (exp-1) << 23 | frac;
	}

	return result;
}

