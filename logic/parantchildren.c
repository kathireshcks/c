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


