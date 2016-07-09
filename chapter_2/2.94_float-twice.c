#include<stdio.h>

typedef unsigned float_bits;

float float_twice (float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xff;
	unsigned frac = f & 0x7fffff;

	/* Do not NaN and Inf go down */
	if (exp == 0xff && frac) {
		/* NaN */
		return f;
	} else if (exp == 0xff) {
		/* Infinite */
		return f;
	}

	/* Now f is either Denormalized or Normalized */
	float result = f;
	unsigned leading_frac = frac & 0x400000;
	if (leading_frac) {
		if (!exp)
			/* Denormalized to Normalized */
			result = sign << 31 | (exp + 1) << 23
				| ( (frac << 1) & 0x7fffff );
		else if (exp == 0xfe)
			/* Normalized to Inf */
			result = sign << 31 | 0x7f8000000;
	} else {
		if (!exp)
			/* Denormalized to Denormalized */
			result = sign << 31
				| ( (frac << 1) & 0x7fffff );
		else
			/* Normalized to Normalized */
			result = sign << 31 | (exp+1) << 23 | frac;
	}
		
	return result;
}

