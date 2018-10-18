#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
	int id;
	char name[20];
	char email[20];
	char password[20];
	struct user* next;
	struct inboxdata* inbox;
	struct outboxdata* outbox;
};

struct inboxdata{
	char from[20];
	char msg[50];
	struct inboxdata* next;
};

struct outboxdata{
	char to[20];
	char msg[50];
	struct outboxdata* next;
};
int signup(struct user** node)
{
	
	
	struct user* newnode=(struct user*)malloc(sizeof(struct user));
	struct user* lastnode=(*node);
	struct user* emailcheck=(*node);
	printf("\nEnter the data");
	printf("\nName :");
	scanf("%s",&newnode->name);
	printf("\nEmail : ");
	scanf("%s",&newnode->email);
	printf("\nPassword :");
	scanf("%s",&newnode->password);
	newnode->next=NULL;
	newnode->inbox=NULL;
	newnode->outbox=NULL;
	if((*node)!=NULL)
	while(emailcheck!=NULL)
	{
		if(strcmp(lastnode->email,newnode->email)==0)
		{
			printf("\n This mailid Already Used");
			return;
		}
		emailcheck=emailcheck->next;
	}
	
	if((*node)==NULL)
	{
		(*node)=newnode;
		
		return;
	}else{
		
		while(lastnode->next != NULL)
		{
			lastnode=lastnode->next;	
		}
		
		lastnode->next=newnode;
	}
}


int signin(struct user** node)
{

	char email[20],password[20];

	struct user* begin=(*node);
	struct user* lastnode=(*node);
	printf("\nEnter the login data");
	printf("\nEmail : ");
	scanf("%s",&email);
	printf("\nPassword : ");
	scanf("%s",&password);
	
	if((*node)==NULL)
	{
		printf("\n No Record Found");
		return;
	}else{
		while(lastnode!=NULL)
		{
			if(strcmp(lastnode->email,email)==0)
			{
				break;
			}
			lastnode=lastnode->next;
		}
		
		if(lastnode==NULL)
		{
			printf("\n No account existed");
			return;
		}
		
		if(strcmp(lastnode->password,password)!=0)
		{
			printf("\n Your Password is wrong");
			return;
		}
		
		printf("\n Login Successfully");
		int s;
		do{
			printf("\n1.Inbox\n2.Outbox\n3.Send Mail\n4.Logout");
			scanf("%d",&s);
			switch(s)
			{
				case 1:
					inbox(&lastnode);
					break;
				case 2:
					outbox(&lastnode);
					break;
				case 3:
					sendmail(&lastnode,&begin);
					break;
				case 4:
					printf("\n Logout sucessfully Completed");
					break;
				default:
					printf("\n Select correct option");
					break;
			}
		}while(s!=4);
	}
	
	
	
}

int inbox(struct user** node)
{
	struct user* temp=(*node);
	struct inboxdata* inbox=temp->inbox;
	
	
	if(inbox==NULL)
	{
		printf("\n Your inbox is empty");
		return;
	}else{
		printf("\nFrom\tmsg");
		while(inbox!=NULL)
		{
			printf("\n%s\t%s",inbox->from,inbox->msg);
			inbox=inbox->next;
		}
	}
}

int outbox(struct user** node)
{
	
	struct user* temp=(*node);
	struct outboxdata* outbox=temp->outbox;
	
	
	if(outbox==NULL)
	{
		printf("\n Your outbox is empty");
		return;
	}else{
		printf("\nFrom\tmsg");
		while(outbox!=NULL)
		{
			printf("\n%s\t%s",outbox->to,outbox->msg);
			outbox=outbox->next;
		}
	}
}

int sendmail(struct user** node,struct user** begin)
{
	struct user* btemp=(*begin);
	struct user* temp=(*node);
	struct outboxdata* otemp=temp->outbox;
	struct inboxdata* inbox=(struct inboxdata*)malloc(sizeof(struct inboxdata));
	struct outboxdata* outbox=(struct outboxdata*)malloc(sizeof(struct outboxdata));
	char email[20],msg[50];
	printf("\n Enter the new mail data");
	printf("\n To : ");
	scanf("%s",&email);
	strcpy(inbox->from,temp->email);
	strcpy(outbox->to,email);
	printf("\n Message :");
	scanf("%s",&msg);
	strcpy(inbox->msg,msg);
	strcpy(outbox->msg,msg);
	inbox->next=NULL;
	outbox->next=NULL;
	
	while(btemp!=NULL)
	{
		if(strcmp(btemp->email,email)==0)
		{
			struct inboxdata* itemp=btemp->inbox;
			if(btemp->inbox==NULL)
			{
				btemp->inbox=inbox;
			}else{
				while(itemp->next!=NULL)
				{
					itemp=itemp->next;
				}
				itemp->next=inbox;
			}
			break;
		}
		btemp=btemp->next;
		
	}
	if(btemp==NULL)
	 {
	 	printf("\n No Email id found  ");
	 	return;
	 }

		
	if(temp->outbox==NULL)
	{
		temp->outbox=outbox;	
	}else{
		
		while(otemp->next!=NULL)
		{
			otemp=otemp->next;
		}
		otemp->next=outbox;
	}
	
}


int display(struct user** node)
{
	struct user* temp=(*node);
	
	if((*node)==NULL)
	{
		printf("\n No data find");
		return;
	}else{
		printf("\nName\tEmail");
		while(temp != NULL)
		{
			printf("\n%s\t%s",temp->name,temp->email);
			temp=temp->next;
		}
	}
}

int main()
{
	struct user* node=(struct user*)malloc(sizeof(struct user));
	node=NULL;
	int s;
	do{
		printf("\n Enter the Mail Sysytem ");
		printf("\n1.signup\n2.signin\n3.Display\n4.Exit");
		scanf("%d",&s);
		
		switch(s){
			case 1:
				signup(&node);
				break;
			case 2:
				signin(&node);
				break;
			case 3:
				display(&node);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nEnter the correct option");
				break;
		}
	}while(s!=4);
}
