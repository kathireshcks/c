#include<stdio.h>
#include<string.h>
int n;
char name[20];

struct reln{
char child[20];
char father[20];
}r[10];

int count=0;
void countChildren(char name[])
    {
    int j;
    for(j=0;j<n;j++)
        {
        if(strcmp(name,r[j].father)==0)
            {
            count++;
            countChildren(r[j].child);
            }
        }
    }

void main()
{
int i;
printf("\nEnter the number of inputs: ");
scanf("%d",&n);
for(i=0;i<n;i++)
    {
    scanf("%s",r[i].child);
    scanf("%s",r[i].father);
    }
printf("\nEnter name of the one whose no. of grandchildren is needed: ");
scanf("%s",name);
for(i=0;i<n;i++)
    {
    if(strcmp(r[i].father,name)==0)
        countChildren(r[i].child);
    }
printf("\nNo .of grandchildren of %s=%d",name,count);
}

















#include<stdio.h>
#include<string.h>

struct data{
	char father[10];
	char child[10];
};


struct data *po;

int temp,k;

int find(char t[10])
{
	int i;
	for(i=0;i<k;i++)
	{
		if(strcmp(t,(po+i)->father)==0)
		{
			temp++;
			find((po+i)->child);	
		}		
	}
}

int main()
{
	
	
	int i;
	char st[10];
	
	printf("\n Enter the val:");
	scanf("%d",&k);
	
	po=(struct data*)malloc(k*sizeof(struct data));
	
	for(i=0;i<k;i++)
	{
		printf("\n Enter the parent :");
		scanf("%s",(po+i)->father);
		printf("\n Enter the child :");
		scanf("%s",(po+i)->child);
	}
	
	for(i=0;i<k;i++)
	{
		printf("\n <' %s '  ' %s '>",(po+i)->father,(po+i)->child);
	
	}
	
	printf("\n search string:");
	scanf("\n%s",st);
	
	find(st);
	
	printf("\n final :%d",temp);
		
}
