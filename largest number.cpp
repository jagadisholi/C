#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,c,max;
	printf("enter the three number :");
	scanf("%d %d %d",&a ,&b ,&c);
	if(a > b && a > c)
	{
		max = a;
	}
	else if(b > c && b > a)
	{
		max = b;
	}
	else {
		max = c;
	}
return 0;
}
