#include <stdio.h>
void fibonacci (int num);
void main()
{
	int num = 0;

	printf("Enter number of terms: ");
	scanf("%d", &num);
	fibonacci(num);
}

void fibonacci (int num)
{
	int a, b, c, i = 3;
	a = 0;
	b = 1;

	if (num == 1)
	{
		printf("%d", a);
	}

	if (num >= 2)
	{
		printf("%d\t%d", a, b);
	}

	for (i=3; i<= num; i++)
	{
		c = a+b;
		printf("\t%d", c);
		a = b;
		b = c;
	}
}
