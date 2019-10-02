/* Linked list operations:  Insertion from front
                            Insertion from back
                            Insertion from any position
                            Deletion from front
                            Deletion from back
                            Deletion from any position
                            Traversal */
#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
void insertf(void); 
void insertb(void); 
void inserta(void); 
void deletf(void); 
void deletb(void); 
void deleta(void); 
void tra(void); 
struct node 
{ 
    int data; 
    struct node *link; 
}; 
struct node *head=0; 
void main() 
{ 
    int ch; 
    clrscr();
    printf("_____________________________Instructions_____________________________\n");
	printf("Insertion from front - 1\nInsertion from back - 2\nInsertion from any position - 3\nDeletion from front - 4\nDeletion from back - 5\nDeletion from any position -6\nTraversal - 7\nExit - 8\n");
    printf("______________________________________________________________________\n");
    while(1) 
    { 
	    printf("Enter the choice\n");
        scanf("%d",&ch); 
        if(ch==8) 
        break; 
        switch(ch) 
        { 
            case 1: 
            //insertion at front
            { 
                insertf(); 
                tra();
                printf("\n"); 
                break; 
            } 
            case 2: 
            //insertion at back
            { 
                insertb(); 
                tra();
                printf("\n"); 
                break; 
            } 
            case 3:
            //insertion at any position 
            { 
                inserta(); 
                tra();
                printf("\n");
                break; 
            } 
            case 4:
            //deletion from front
            { 
                deletf(); 
                tra();
                printf("\n");
                break; 
            } 
            case 5:
            //deletion from back
            { 
                deletb(); 
                tra();
                printf("\n");
                break; 
            }
            case 6: 
            //deletion from any position
            { 
                deleta(); 
                tra();
                printf("\n");
                break; 
            }
            case 7:
            //traveral
            { 
                tra();
                printf("\n");
                break; 
            }
            default:
                printf("Wrong Input\n");//any other value
            }
        }
    printf("EXITING - PRESS ANY KEY");
    getch();
}

//function declerations

void insertf()//insertion at front
{
   struct node *newnode, *t;
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter data to begin insert\n");
   scanf("%d",&newnode->data);
   if(head==0)
   {
       head=newnode;
   }
   else
   {
       newnode->link=head;
       head=newnode;
   }
}
void insertb()//insertion at back
{
    struct node *p, *t1;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Element: ");
    scanf("%d",&p->data);
    p->link=0;
    if(head==0)
    {
        head=p;
    }
    else{
        t1=head;
        while(t1->link!=0)
        {
            t1=t1->link;
        }
        t1->link=p;
    }
}
void inserta()//insertion at any position
{
    int pos, i=1, count=1;
    struct node *temp1, *newnod;
    if(head==0)
    {
        printf("Insertion not possible");
    }
    else
    {
        temp1=head;
        while(temp1->link!=0)
        {
            count++;
	    temp1=temp1->link;
        }
        printf("Total number node is %d\n",count);
        newnod=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data part: ");
        scanf("%d",&newnod->data);
        newnod->link=0;
        printf("Enter the Position after which you want to insert: ");
        scanf("%d",&pos);
        if(count<pos)
        {
            printf("Not possible to insert");
        }
        else
        {
            temp1=head;
            while(i!=pos)
            {
                temp1=temp1->link;
		i++;
	    }
            newnod->link=temp1->link;
            temp1->link=newnod;
        }
    }
}
void deletf()//deletion from front
{
    struct node *temp;
    head=head->link;
    temp=head;
}
void deletb()//deletion from back
{
    struct node *temp, *prev;
    temp=head;
    if(head==0)
    {
        printf("Deletion not possible");
    }
    else if(temp->link==0)
    {
        free(temp);
    }
    else{
        while(temp->link!=0)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=0;
    }
}
void deleta()//deletion from any position
{
    int pos, i=1, c=1;
    struct node *temp2, *nex;
    temp2=head;
    if(head==0)
    {
        printf("Deletion not possible");
    }
    else{
        while(temp2->link!=0)
        {
            c++;
            temp2=temp2->link;
        }
        printf("Total node = %d\n",c);
        printf("Enter the position after which you want to delete: ");
        scanf("%d",&pos);
        if(c<pos)
        {
            printf("Deletion not possible");
        }
        else
        {
            temp2=head;
            while(i<pos-1)
            {
                temp2=temp2->link;
                i++;                
            }
            nex=temp2->link;
            temp2->link=nex->link;
        }
    }
}
void tra()//traversal
{
    struct node *t;
    t=head;
    while(t!=0)
    {
        printf("%d-->",t->data);
        t=t->link;
    }
}