#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,l,t;
	char input[20];
	printf("Enter the input :\n");
	scanf("%s",&input);
	l=strlen(input);
	for(i=0;i<l;i++)
	{
		if(input[i+2]-48>=0 && input[i+2]-48<=9)
		{
			t=((input[i+1]-48)*10)+(input[i+2]-48);	
			for(j=0;j<t;j++)
			{
				printf("%c",input[i]);
			}
			i++;
			i++;
		}else
		{
			for(j=0;j<input[i+1]-48;j++)
			{
				printf("%c",input[i]);
			}
			i++;
		}
	}
	
}
