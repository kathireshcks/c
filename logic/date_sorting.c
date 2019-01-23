#include<stdio.h>
#include<string.h>

struct date{
	int year;
	int month;
	int date;
}a[10];

int main()
{
	int m,i,j;
	printf("Enter the val:");
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		printf("\n year :");
		scanf("%d",&a[i].year);
		printf("\n month :");
		scanf("%d",&a[i].month);
		printf("\n date :");
		scanf("%d",&a[i].date);
	}
	
	printf("\n\ndate\tmonth\tyear");
	for(i=0;i<m;i++)
	{
		printf("\n%d\t%d\t%d",a[i].date,a[i].month,a[i].year);
	}
	
	
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(a[i].year>a[j].year)
			{
				struct date temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else if(a[i].year==a[j].year && a[i].month>a[j].month)
			{
				struct date temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}
			else if(a[i].year==a[j].year && a[i].month==a[j].month && a[i].date>a[j].date) 
			{
				struct date temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}
		}
	}
	
	printf("\n\ndate\tmonth\tyear");
	for(i=0;i<m;i++)
	{
		printf("\n%d\t%d\t%d",a[i].date,a[i].month,a[i].year);
	}
	
}
