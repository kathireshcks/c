#include<stdio.h>
#include<conio.h>
#include<string.h>

int reverse(char *s,int l)
{
	if(*s == ' ' || l==0)
	{
		if(l==0)
			print(s);
		else
		{
			print(s+1);
			printf(" ");
			reverse(s-1,--l);
		}	
	}
	else{
		if(l)
		reverse(s-1,--l);
	}
}

int print(char *p)
{
		if(*p != ' ')
		{
			printf("%c",*p);
			print(p+1);
		}
}

int main(){
	
	char s[10];
	
	printf("Enter the string :");
	gets(s);
	
	reverse(&s[strlen(s)],strlen(s));	
	
}
