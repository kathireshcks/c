#include<stdio.h>

int main()
{
	/*char k[10]="kathir";
	char *h=k;
	printf("%d",strlen(h));
	h++;
	printf("%d",strlen(h));
	*/
	
	char h[10]="abcd";
	char *k=h;
	int i,j,p;
	int l=strlen(k);
	for(i=0;i<l;i++)
	{
		
		for(p=0;p<strlen(k);p++)
		{
			for(j=0;j<p+1;j++)
			{
				printf("%c",k[j]);
			}
			printf("\n");
		}
		k++;
	}
	
	
}
