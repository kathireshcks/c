#include<stdio.h>
#include<string.h>
#define arrlen 4


int rotateclockwise(int mat[arrlen][arrlen],int i,int j)
{
	int temp=0;
	int n=arrlen;
	temp=mat[i][j];
	mat[i][j]=mat[n-1-j][i];
	mat[n-1-j][i]=mat[n-1-i][n-1-j];
	mat[n-1-i][n-1-j]=mat[j][n-1-i];
	mat[j][n-1-i]=temp;
	
	
	return mat[arrlen][arrlen];
}



int rotateclock(int mat[arrlen][arrlen],int i,int j)
{
	int t=0,n=arrlen;
	t=mat[i][j];
	mat[i][j]=mat[n-1-j][i];
	mat[n-1-j][i]=mat[n-1-i][n-1-j];
	mat[n-1-i][n-1-j]=mat[j][n-1-i];
	mat[j][n-1-i]=t;
	
	
	
	return mat[arrlen][arrlen];
}

int rotateanticlock(int mat[arrlen][arrlen],int i,int j)
{
	int t=0,n=arrlen;
	t=mat[i][j];
	mat[i][j]=mat[j][n-1-i];
	mat[j][n-1-i]=mat[n-1-i][n-1-j];
	mat[n-1-i][n-1-j]=mat[n-1-j][i];
	mat[n-1-j][i]=t;
	return mat[arrlen][arrlen];
}


int main()
{
	int i,j,mat[arrlen][arrlen]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	
	
	for(i=0;i<arrlen;i++)
	{
		for(j=0;j<arrlen;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	int select;
	printf("\n1.Rotateclockwise\n2.AntiClockwise");
	scanf("%d",&select);
	switch(select)
	{
		case 1:{
			for(j=0;j<(arrlen/2);j++)
			for(i=0;i<arrlen-1-i;i++)
			mat[arrlen][arrlen]=rotateclockwise(mat,j,i);
			
			break;
		}
		case 2:
			{
				for(j=0;j<(arrlen/2);j++)
				for(i=0;i<arrlen-1-i;i++)
				mat[arrlen][arrlen]=rotateanticlock(mat,j,i);
				
				
				break;
			}
		default:
			printf("\nNo Change");
		break;
	}
	
	printf("\n\n\n");
	
	for(i=0;i<arrlen;i++)
	{
		for(j=0;j<arrlen;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}	
}
