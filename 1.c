#include <stdio.h>

int func1(int m)
{
	int x,y,z;
	z = m % 10;
	y = m / 10 % 10;
	x = m / 100;
	if((func2(x) + func2(y) + func2(z)) == m)
	{
		return 1;
	}
	else
    {
        return 0;
    }
}

int func2(int n)
{
	int sum;
	sum = n*n*n;
	return sum;
}

int main()
{
	int i;
	for(i=100;i<999;i++)
	{
		if(func1(i))
		{
			printf("%d\n",i);
		}

	}
	return 0;
}
