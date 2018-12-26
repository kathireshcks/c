#include<stdio.h>
#include<conio.h>

int main()
{
	int n=6;
	int m[6][6];
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			m[j][i]=c++;
		}
	}
	
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if((i==0 && j==0) || (i==1 && j==0))
			printf("\t");
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
}
