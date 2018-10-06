#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,f[50];
	char s[50],t[50];
	gets(s);
	int l=strlen(s);
	int fl=0;
	int sl=0;
	for(i=0;i<l;i++)
	{
		
		if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)
		{
			t[sl]=s[i];
			sl++;
		}
		else
		{
			f[fl]=i;
			fl++;
		}
	}
	
	for(i=0;i<l;i++)
	{
		int temp=0;
		for(j=0;j<fl;j++)
		{
			if(f[j]==i)
			 temp=1;
		}
		if(temp)
		{
			printf("%c",s[i]);
		}
		else{
			printf("%c",t[sl-1]);
			sl--;
		}
	}
	
}
