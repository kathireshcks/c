#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char m[5][5]={"welco","metoz","ohoco","rpora","tion"};
	
	int i,j;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c",m[i][j]);
		}
		printf("\n");
	}
	char f[5];
	printf("\n Enter the find word :");
	scanf("%s",&f);
	int c,sl=strlen(f);
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(m[i][j]==f[0])
			{
			
				int k,t=j;
				c=0;
				for(k=0;k<sl;k++)
				{
					
					if(f[k]!=m[i][t])
					{
						break;
					}
					c++;
					t++;
				}
				
				if(c==sl)
				{
					printf("\n%s : find",f);
					break;
				}
			}
			if(c==sl)
				break;
		}
	}
	
	c=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(m[j][i]==f[0])
			{
			
				int k,t=j;
				c=0;
				for(k=0;k<sl;k++)
				{
					
					if(f[k]!=m[t][i])
					{
						break;
					}
					c++;
					t++;
				}
				
				if(c==sl)
				{
					printf("\n%s : find",f);
					break;
				}
			}
			
			
			if(c==sl)
				break;
		}
	}
	
	
}
