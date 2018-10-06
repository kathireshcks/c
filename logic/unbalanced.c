#include<stdio.h>
#include<string.h>
int check(char s[])
{
		int l,i,j,flag=0;
	l=strlen(s);


	for(i=0;i<l;i++)
	{
		if(s[i]=='(')
		{
			
			flag++;	
		}	
		else if(s[i]==')')
		{
			
			flag--;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else{
		return 0;
	}
	

}


int main()
{
	char s[20]="((v)))";
	
	int i,j,flag,l;
	l=strlen(s);
	
	int set[20];
	int st=0;
	int unset[20];
	int ust=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='(')
		{
			set[st++]=i;		
		}	
		else if(s[i]==')')
		{
			unset[ust++]=i;
		}
	}
	int val=check(s);
	int max=(st>ust)?st:ust;
	char test[20],final[20];
	
	while(max)
	{
		strcpy(test,s);
		if(!val)
		{
			if(st>ust)
			{
				
				for(i=set[max];i<l;i++)
				{
					test[set[max]]=test[set[max]+1];	
				}
				strcpy(final,test);				
			}
			else if(st<ust)
			{
				for(i=unset[max];i<l;i++)
				{
					test[unset[max]]=test[unset[max]+1];	
				}
				strcpy(final,test);
			}
		}
		int v=check(final);
		if(v)
		printf("%s\n",final);
		max--;
	}
	
}
