#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char n1[20],n2[20];
	
	scanf("%s",&n1);
	scanf("%s",&n2);
	
	int l1,l2;
	
	l1=strlen(n1);
	l2=strlen(n2);
	
	int t=0;
	int l=(l1>l2)?l1:l2;
	int s[20];
	int i=0;
	while(l>0)
	{
		if(n1[l1-1]!=n2[l2-1])
		{	
			if(t==0)
			{
				s[i]=1;
				i++;
			}
			else
			{
				s[i]=0;
				i++;
				t=1;
			}
		}else if(n1[l1-1]=='1'&&n2[l2-1]=='1')
		{	
			if(t==0)
			{
				s[i]=0;
				i++;
				t=1;
			}else
			{
				s[i]=1;
				i++;
				t=1;
			}
		}else
		{
			if(t==1)
			{
				s[i]=1;
				i++;
				t=0;
			}
			else
			{
				s[i]=0;
				i++;
			}
		}
		l--;
		l1--;
		l2--;
	}
	int j;
	for(j=i-1;j>=0;j--)
	{
		printf("%d",s[j]);
	}
		
	
	
}
