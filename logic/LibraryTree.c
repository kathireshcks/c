#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct main{
	char headline[20];
	char detail[100];
	struct main *right;
	struct main *left;
};

int print_inorder(struct main** tree) {
	
	 if ((*tree) ){
	 	
	 print_inorder(&(*tree)->left);
	 printf("\n %s : %s",(*tree)->headline,(*tree)->detail);
	 print_inorder(&(*tree)->right);
	 }
	}
	
	int print_preorder(struct main** tree) {
	
	 if ((*tree)) {
	 printf("\n %s : %s",(*tree)->headline,(*tree)->detail);	
	 print_preorder(&(*tree)->left);
	 
	 print_preorder(&(*tree)->right);
	 }
	}

int print_postorder(struct main** tree) {
	
	 if ((*tree)) {
	 	
	 print_postorder(&(*tree)->left);
	 print_postorder(&(*tree)->right);
	 printf("\n %s : %s",(*tree)->headline,(*tree)->detail);
	 }
	}


int searchbook(struct main** tree, char val[20]) {
	
	struct main *temp = (*tree);
	
	 if(!(*tree)) {
		printf("\n Empty !");
		
	  }else{
		 if(strcmp(val , temp->headline) == 0) {
		 	printf("\n %s",temp->detail);
		  } else if(strcmp(val , temp->headline) > 0){
		    searchbook(&temp->left, val);
		  } else if(strcmp(val , temp->headline) < 0){
		    searchbook(&temp->right, val);
	  	  }
  		}
 }


int delete_tree(struct main** tree) {
	
 if ((*tree)) {
   delete_tree(&(*tree)->left);
   delete_tree(&(*tree)->right);
   free((*tree));
  }
 }

void insertbook(struct main** tree, struct main** val) {
	
	
	 if(!(*tree)) {
	   (*tree) = (*val);
	   return;
	 }
	 else{
	 		 
		 /*if((*val)->headline < (*tree)->headline) {
		      insertbook(&(*tree)->left, &(*val));
		 } else if((*val)->headline > (*tree)->headline) {   	
		     insertbook(&(*tree)->right, &(*val));
		 }*/
		 if(strcmp((*val)->headline , (*tree)->headline) > 0) {
		      insertbook(&(*tree)->left, &(*val));
		 } else if(strcmp((*val)->headline , (*tree)->headline) < 0) {   	
		     insertbook(&(*tree)->right, &(*val));
		 }
	}
}


void main()
{
	struct main* node =(struct main*)malloc(sizeof(struct main));
	
	node = NULL;
	int s;
	char t[20];
	
	do{
		struct main* temp=(struct main*)malloc(sizeof(struct main));
		printf("\n *********** Welcome to Book Shop ********");
		printf("\n Enter the option");
		printf("\n 1. Isert book details \n 2. Search Book \n 3.Inorder \n 4.Preorder \n 5.Post order \n 6.Delete All Nodes \n 7. Exit\n");
		scanf("%d",&s);
		switch(s){
		
			case 1:
				
				printf("\n Enter the headline\n");
				scanf("%s",&temp->headline);
				
				printf("\n Enter the Detail\n");
				scanf("%s",&temp->detail);
				
				temp->left=NULL;
				temp->right=NULL;
					
				insertbook(&node,&temp);
				break;
				
			case 2:
				printf("\n search name : \n");
				scanf("%s",&t);
				
				searchbook(&node,t);
				break;
			case 3:
				print_inorder(&node);
				break;
			case 4:
				print_preorder(&node);
				break;
			case 5:
				print_postorder(&node);
				break;
			case 6:
				delete_tree(&node);
				break;
			case 7:
				exit(0);
				break;
			
						
			default:
				printf("\n please Enter the correct option");
				break;		
		}
	}while(s != 7);
	
}
