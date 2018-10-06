#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int print(int row,int column)
{
	int rmin=0;
	int rmax=row;
	int cmin=0;
	int cmax=column;
	int i,j;
	int t=6;
	
	int mat[row][column];
	while(t>0)
	{
		for(i=cmin;i<cmax;i++)
			mat[rmin][i]=t;
		rmin++;
		
		
		for(i=rmin;i<rmax;i++)
			mat[i][cmax-1]=t;
		cmax--;
		
		
		for(i=cmax-1;i>=cmin;i--)
			mat[rmax-1][i]=t;
		rmax--;
		
		for(i=rmax-1;i>=rmin;i--)
			mat[i][cmin]=t;
		cmin++;
		
		t--;
	}

	/*for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			mat[i][j]=1;
		}
		
	}*/

	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	print(6,6);
}
