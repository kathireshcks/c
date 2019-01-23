#include<stdio.h>

int main()
{
	char s1[10],s[10]="program";
	
	int l=strlen(s),i,j=0;
	int m=(l/2)+1;
	
	
	for(i=m;i<=l;i++)
	{
		s1[j]=s[i-1];
		j++;
	}
	for(i=0;i<m-1;i++)
	{
		s1[j]=s[i];
		j++;
	}
	
	printf("%s\n\n\n",s1);
	
	for(i=0;i<l;i++)
	{
		for(j=0;j<(l*2)-(i*2);j++)
		{
			printf(" ");
			
		}
		for(j=0;j<=i;j++)
		{
			printf("%c",s1[j]);
		}
		printf("\n");
	}
	
	
}
