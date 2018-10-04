
/* 
* C program to implement link list
* Author:Abhishek Kadariya
* Ref : Data Structure using c and c++, chapter 4, page no: 191
*/

#include<stdio.h>
#include<stdlib.h>


struct node{
	int info;
	struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void insert_at_front(nodeptr*,int);
int remove_from_front(nodeptr*);
void free_node(nodeptr);
void display_list(nodeptr);

int main(){
	
	nodeptr p;
	p=NULL;
	insert_at_front(&p,3);
	insert_at_front(&p,6);
	insert_at_front(&p,7);
	insert_at_front(&p,8);


    display_list(p);
    printf("remove = %d\n",remove_from_front(&p));
    printf("remove = %d\n",remove_from_front(&p));
    printf("remove = %d\n",remove_from_front(&p));
    printf("remove = %d\n",remove_from_front(&p));
     printf("remove = %d\n",remove_from_front(&p));
    display_list(p);
 

}


nodeptr getnode(){
	return (nodeptr)malloc(sizeof(nodeptr));
}


//function to free node 
void free_node(nodeptr p){
	free(p);
}
//function to insert at front
void insert_at_front(nodeptr* p,int x){
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}
//function to display the list
void display_list(nodeptr p){
	nodeptr ptr=p;
	while(ptr!=NULL){
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
	printf("\n");
}

//function to remove from front


int remove_from_front(nodeptr *p)	{
   if(*p==NULL)
   {
       printf("\nUnderflow\n"); 
       exit(0);
   }
   else
    
    {
        nodeptr q;
        int x;
        q=*p;
        *p= q->next;
        x=q->info;
        return x;
        freenode(q);
    }

}

void rev(nodeptr *p){
    nodeptr current;
    nodeptr prev;
    nodeptr next;
    prev=NULL;
    current=*p;
    next=*p;
    while(current!=NULL){
        next=next->next;
        current->next=prev;
        prev = current;
        current = next;
    }
    *p=prev;

}

