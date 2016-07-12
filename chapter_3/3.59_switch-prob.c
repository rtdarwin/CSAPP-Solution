int switch_prob (int x, int n)
{
	int result= x;

	switch (n) {
	case 0x28:
	case 0x2a:
		result = x << 3;
		break;
	case 0x29:
		result = x + 11;
		break;
	case 0x2b:
		result = x >> 3;
		break;
	case 0x2c:
		result = (7 * x) * (7 * x) + 0x11;
		break;
	default:
		result = x + 0x11;
	}
	return result;
}

