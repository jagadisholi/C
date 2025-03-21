#include<stdio.h>
#include<conio.h>
int main(){
	int a,b,c,middle;
	printf("Enter the value of a , b and c");
	scanf("%d %d %d",&a,&b,&c);
	if(a > b && a < c){
		middle=a;
		
	}
	else if(b > a && b < c){
		middle=b;
	}
	else{
		middle = c;
	}
	printf("the middle number is  : %d ",middle);
	return 0;
}
