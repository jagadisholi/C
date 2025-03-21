#include<stdio.h>
int main ()
{
	char ch;
	printf("enter the alphabet");
	scanf("%c", &ch);
	if((ch>='a' && ch <='z')||(ch>='A' && ch<='Z'))
	{
		if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u'||
		   ch =='A' || ch =='E' ||ch =='I' || ch =='O'|| ch =='U'){
		   
		printf("The vowel number is : %c",ch);
	}
	else 
	{
		printf("the Letter is consonent : %c",ch);
	}
}else{
	printf("invalid input");
}
	return 0;
}
