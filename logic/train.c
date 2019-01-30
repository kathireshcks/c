#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
	char name[10];
	char email[20];
	char password[20];
	struct booking* book;
	struct user* next;
};
struct booking{
	char start[10];
	char end[10];
	char name[10];
	char phone[10];
	int id;
	struct booking* next;
};

struct avail{
	int no;
	char name[10];
	char email[20];
};

int i=1;
/*int booking(struct user** node)
{
	struct user* lastnode=(*node);
		
}
*/


/*int histrydata(struct user** node)
{
	struct user* data=(*node);
	struct booking* histry=data->book;
	printf("\n****** Histry ******\n");
	if(histry==NULL)
	{
		printf("\n No histry");
	}else{
		printf("\nName\tPhone\tStart\tEnd");
		
		while(histry!=NULL)
		{
			printf("\n%s\t%s\t%s\t%s\t",histry->name,histry->phone,histry->start,histry->end);
			histry=histry->next;
		}
	}
}*/


int histrydata(struct booking** node)
{
	struct booking* histry=(*node);
	if(histry!=NULL)
	{
		histrydata(&histry->next);
		printf("\n%s\t%s\t%s\t%s\t",histry->name,histry->phone,histry->start,histry->end);
	}
}

int bookingdata(struct user** node)
{
	printf("\n Enter booking data");
	struct user* data=(*node);
	struct booking* book=data->book;
	struct booking* tik=(struct booking*)malloc(sizeof(struct booking));
	printf("\n****** Booking ******");
	printf("\n Enter the name :");
	scanf("\n%s",&tik->name);
	printf("\n Starting point : ");
	scanf("\n%s",&tik->start);
	printf("\n End point :");
	scanf("\n%s",&tik->end);
	printf("\n Enter the phone number");
	scanf("\n%s",&tik->phone);
	tik->id=i++;
	tik->next=NULL;
	if(data->book==NULL)
	{
		data->book=tik;
	}else{
		while(book->next!=NULL)
		{
			book=book->next;
		}
		book->next=tik;
	}

}
/*
int login(struct user** node)
{
	struct user* lastnode=(*node);
	struct user* email=(*node);
	//struct booking* tik=(struct booking*)malloc(sizeof(struct booking));
	
	char emailc[20],password[10];
	printf("\n Enter the email :\n");
	scanf("%s",&emailc);
	
	if((*node)!=NULL)
	{
		while(email!=NULL)
		{
			if(strcmp(email->email,emailc)==0)
			{
				printf("\n Enter the password :\n");
				scanf("%s",&password);
				
				if(strcmp(password,email->password)==0)
				{
					printf("\n login scuccess");
					
					
					int se;
					do{
						//struct booking* book=email->book;	
						//struct booking* histry=email->book;	
						printf("\n\n1. Booking\n3.logout\n$. histry\n");
						scanf("%d",&se);
						switch(se)
						{
							case 1:
								bookingdata(&email->book);
							break;
							case 4:
								histrydata(&email->book);
								/*printf("\n****** Histry ******\n");
								if(histry==NULL)
								{
									printf("\n No histry");
								}else{
									printf("\nName\tPhone\tStart\tEnd");
									
									while(histry!=NULL)
									{
										printf("\n%s\t%s\t%s\t%s\t",histry->name,histry->phone,histry->start,histry->end);
										histry=histry->next;
										printf("\n----------------------> %d",histry);
									}
								}
								break;
							case 3:
								printf("\n logout");
								return 0;
							break;
							default:
								printf("\n Select correct option");
							break;
						}
					}while(se!=3);
				
				}else{
					printf("\n Incorrect Password !");
					return 0;
				}
			}
			email=email->next;
		}
		printf("\nNo email is available !");
		return 0;
	}else{
		printf("\nNo email is available !");
		return 0;
	}
}
*/

int cancelticket(struct user** node)
{
	struct user* bk=(*node);
	struct booking* data=bk->book;
	int id;
	struct booking* temp;
	printf("\n Enter the id :");
	
	scanf("%d",&id);	
	
	if(bk->book==NULL)
	{
		printf("\n No data");
	}else{
		
		while(data!=NULL)
		{
			if(data->id==id)
			{
				break;
			}
			temp=data;
			data=data->next;
		}
		temp->next=data->next;
	}
}

int login(struct user** node)
{
	struct user* book=(*node);
	char email[20],password[10];
	
	printf("\nEnter the email :\n");
	scanf("%s",email);
	printf("\nEnter the password :\n");
	scanf("%s",password);
	if(book!=NULL)
	{
		while(book!=NULL)
		{
			if(strcmp(book->email,email)==0)
			{
				break;
			}
			book=book->next;
		}
		if(book==NULL)
		{
			printf("\n No email found");
			return 0;
		}
		
		if(strcmp(book->password,password)!=0)
		{
			printf("\n Password Incorrect");
			return 0;
		}
		
		printf("\n login successfully");
		int ex;
		do{
			printf("\n1. booking\n2. histry\n3. logout\n");
			scanf("%d",&ex);
			printf("\n your selection %d",ex);
			switch(ex)
			{
				case 1:
					printf("\n enter 1:");
					bookingdata(&book);
				break;
				case 2:
					printf("\nName\tPhone\tStart\tEnd");
					histrydata(&book->book);
				break;
				case 3:
					printf("\n Logout successully");
					return 0;
				break;
				case 4:
					printf("\n Cancel ticket");
					cancelticket(&book);
				break;
				default:
					printf("\n Enter correct option");
				break;
			}
		}while(ex!=3);
		
	}else{
		printf("\n No record Found");
	}
}

int display(struct user** node)
{
	struct user* lastnode=(*node);
	printf("\nName\tEmail");
	while(lastnode!=NULL)
	{
		printf("\n%s\t%s",lastnode->name,lastnode->email);
		lastnode=lastnode->next;
	}
}

int insert(struct user** node)
{
	struct user* lastnode=(*node);
	struct user* email=(*node);
	struct user* data=(struct user*)malloc(sizeof(struct user));
	printf("\n Enter the name :");
	scanf("%s",&data->name);
	printf("\n Enter the email :");
	
	scanf("%s",&data->email);
	
	if((*node)!=NULL)
	{
		while(email!=NULL)
		{
			if(strcmp(email->email,data->email)==0)
			{
				printf("\n This mail-id already available ");
				return 0;
			}
			email=email->next;
			
		}
	}
	data->next=NULL;
	data->book=NULL;
	strcpy(data->password,"1234");
	if((*node)==NULL)
	{
		*node=data;				
	}
	else{
		while(lastnode->next!=NULL)
		{
			lastnode=lastnode->next;
		}
		lastnode->next=data;
	}
}

int main()
{
	struct user* node=(struct user*)malloc(sizeof(struct user));
	node=NULL;
	int ex;
	
	
	do{
		printf("\n\n1. Signup\n2. display\n3. login\n5.exit\n");
		scanf("%d",&ex);
		
		switch(ex)
		{
			case 1:
				insert(&node);
			break;
			case 2:
				display(&node);
			break;
			case 3:
				login(&node);
			break;
			case 5:
				exit(0);
			break;
			default:
				printf("\n Enter the correct option :");
			break;
		}
		
	}while(ex!=5);
	
	
}
