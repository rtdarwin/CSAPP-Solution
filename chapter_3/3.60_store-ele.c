int A[11][7][9];

int store_ele (int i, int j, int k, int *dest)
{
	*dest = A[i][j][k];
	return sizeof(A);
}


/*
 * &A[i][j][k] = 4 ( T*S*i + T*j + k ) + X_{A}
 *
 * R = 11, S = 7, T = 9
 */
