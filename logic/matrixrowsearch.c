#include<stdio.h>
#include<string.h>

int main()
{
	char string[6][5]={"WELCO","METOZ","OHOCO","RPARA","TION"};
	char s[10];
	int i,j,flag=0,k;
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c\t",string[i][j]);
		}
		printf("\n");
	}
	scanf("%s",&s);
	
	//search row 
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			if(string[i][j]==s[0])
			{
				int l=i,m=j;
				for(k=0;k<strlen(s);k++)
				{
					if(s[k]==string[l][m])
						flag=1;
					else
					{
						flag=0;
						break;
					}
					
					m++;
				}
			}
			if(flag)
			break;
		}
		if(flag)
		break;
	}
	if(flag)
		printf("find");
	else
	printf("not find");
}
