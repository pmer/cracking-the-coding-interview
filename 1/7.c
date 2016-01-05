#include <stdint.h>
#include <stdio.h>

// i is row
// j is column

static void
printMatrix(uint32_t *m, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", m[i * n + j]);
		printf("\n");
	}
	printf("\n");
}

static void
swap2(uint32_t *a, uint32_t *b)
{
	uint32_t c = *a;

	*a = *b;
	*b = c;
}

static void
swap4(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d)
{
	uint32_t n = *a;

	swap2(&n, b);
	swap2(&n, c);
	swap2(&n, d);
	swap2(&n, a);
}

static void
rotate4(uint32_t *m, int n, int i1, int j1)
{
	int i2 = n - j1 - 1;
	int j2 = i1;

	int i3 = n - i1 - 1;
	int j3 = n - j1 - 1;

	int i4 = j1;
	int j4 = n - i1 - 1;

	swap4(&m[i1 * n + j1],
	      &m[i2 * n + j2],
	      &m[i3 * n + j3],
	      &m[i4 * n + j4]);
}

static void
rotate90(uint32_t *m, int n)
{
	for (int i = 0; i < (n+1)/2; i++)
		for (int j = 0; j < n/2; j++)
			rotate4(m, n, i, j);
}

static void
rotate5(uint32_t *m, int n)
{
	printf("\t\t%dx%d Matrix\n", n, n);
	printMatrix(m, n);
	for (int i = 0; i < 4; i++) {
		rotate90(m, n);
		printMatrix(m, n);
	}
	printf("\n\n");
}

int main()
{
	uint32_t m1[1] = {
		1
	};
	int n1 = 1;

	uint32_t m2[4] = {
		1, 2,
		3, 4
	};
	int n2 = 2;

	uint32_t m3[9] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int n3 = 3;

	uint32_t m4[16] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};
	int n4 = 4;

	rotate5(m1, n1);
	rotate5(m2, n2);
	rotate5(m3, n3);
	rotate5(m4, n4);

	return 0;
}
