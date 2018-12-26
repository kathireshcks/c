#include<stdio.h>
#include<string.h>

int main()
{
	char s1[10],s2[10];
	
	printf("\n Enter the s1 :");
	scanf("\n%s",&s1);
	printf("\n Enter the s2 :");
	scanf("\n%s",&s2);
	
	int i,j,s1l=strlen(s1),s2l=strlen(s2);
	
	int c,w=0;
	
	if(s1l==s2l)
	for(i=0;i<s1l;i++)
	{
		
		if(s1[0]==s2[i] || s2[i]==42)
		{
			int h=i,c=0;
			for(j=0;j<s1l;j++)
			{
				if(s1[j]!=s2[h] && s2[i]!=42)
				{
					break;
				}
				h++;
				c++;
			}
		
		if(c==s1l)
		{
			w=1;
				break;	
		}
			
		}
		
	}
	
	if(w)
		printf("\nYES");
	else
		printf("\nNO");
}
