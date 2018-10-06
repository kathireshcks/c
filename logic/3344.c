#include<stdio.h>
#include<string.h>

int main()
{
	int i=0,j=0;
	int t;
	t=1;
	while(t<100000)
	{
		int temp=t;
		int flag=1;
		while(temp>10)
		{
			int h=temp%10;
			temp=temp/10;
			if(h!=3&&h!=4)
			flag=0;
		}
		if((temp==3||temp==4)&&flag==1)
		printf("%d ",t);
		
		t++;
	}
}
