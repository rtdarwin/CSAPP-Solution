#include<math.h>
#include<float.h>

float b2f (unsigned u);
unsigned f2b (float f);


float b2f (unsigned u)
{

	union {
		float fp;
		unsigned bits;
	} value;

	value.bits = u;
	return value.fp;
}

unsigned f2b (float f)
{
	union {
		float fp;
		unsigned bits;
	} value;

	value.fp = f;
	return value.bits;
}

