#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len=4;
int main()
{
	int mat[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	
	int i,j;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	int rowmin=0;
	int rowmax=len;
	int colmin=0;
	int colmax=len;
	printf("\n\n");
	len=len/2;
	while(len)
	{
		
		for(i=colmin;i<colmax;i++)
			printf("%d\t",mat[rowmin][i]);
		rowmin++;
		
		for(i=rowmin;i<rowmax;i++)
			printf("%d\t",mat[i][rowmax-1]);
		colmax--;
		
		for(i=colmax-1;i>=colmin;i--)
			printf("%d\t",mat[rowmax-1][i]);
		rowmax--;	
		
		for(i=rowmax-1;i>=rowmin;i--)
			printf("%d\t",mat[i][rowmin-1]);
		colmin++;
		len--;
	}
	
}
