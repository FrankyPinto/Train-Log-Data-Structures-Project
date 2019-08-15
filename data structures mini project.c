#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int train_coachno;
char train_type;
char source[15];
char dest[15];
int pf;
struct node *next;};

struct node *start=NULL;

struct node *create_newnode(struct node *start)
{
    int cno,pfn;char tt;char s[15],d[15];
    struct node *ptr,*newnode;
    printf("Enter the no of coaches:");
    scanf("%d",&cno);
    printf("Enter the train type:\nF for fast\nS for slow\n");
    scanf(" %c", &tt);
    printf("Enter the source:");
    scanf("%s",s);
    printf("Enter the destination:");
    scanf("%s",d);
    if(tt=='F')
        pfn=3;
    else
        pfn=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->train_coachno=cno;
    newnode->train_type=tt;
    strcpy(newnode->source,s);
    strcpy(newnode->dest,d);
    newnode->pf=pfn;
    if(start==NULL)
    {
    newnode->next=NULL;
    start=newnode;
    return start;
    }
    else{
    newnode->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newnode;
    return start;
    }
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("No Entry found\n");
    else{
    while(ptr!=NULL)
    {
        printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        ptr=ptr->next;
    }
}
return start;
}

void sortontype(struct node *start)
{
    struct node *ptr;
    char type;
    printf("Enter type on which train type sorting is to be done:\n");
    scanf(" %c", &type);
    printf("Details of Train Type %c:\n",type);
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->train_type==type)
        {
             printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        }
        ptr=ptr->next;
    }
}

void sortoncno(struct node *start)
{
    struct node *ptr;
    int n;
    printf("Enter coach no on which sorting is to be done:\n");
    scanf("%d",&n);
    printf("Details of trains with no of coaches %d:\n",n);
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->train_coachno==n)
        {
            printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        }
        ptr=ptr->next;
    }
}

void sortbysource(struct node *start)
{
    struct node *ptr;
    char src[15];
    printf("Enter source station on which sorting is to be done:");
    scanf("%s",src);
    printf("Details of trains with source %s:\n",src);
    ptr=start;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->source,src)==0)
        {
            printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        }
        ptr=ptr->next;
    }
}

void sortbydest(struct node *start)
{
    struct node *ptr;
    char des[15];
    printf("Enter source station on which sorting is to be done:");
    scanf("%s",des);
    printf("Details of trains with destination %s:\n",des);
    ptr=start;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->dest,des)==0)
        {
            printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        }
        ptr=ptr->next;
    }
}

void sortonpfno(struct node *start)
{
    struct node *ptr;
    int n;
    printf("Enter platform no on which sorting is to be done:\n");
    scanf("%d",&n);
    printf("Details of trains with platform no %d:\n",n);
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->pf==n)
        {
            printf("\nNo of coaches of train:%d\nTrain type:%c\nSource:%s\nDestination:%s\nPlatform No:%d\n\n",ptr->train_coachno,ptr->train_type,ptr->source,ptr->dest,ptr->pf);
        }
        ptr=ptr->next;
    }
}

void sort(struct node *start)
{
    int sp=0;
    do{
    printf("Enter sorting parameter:\n");
    printf("1.Based on train type\n2.Based on no of coaches\n3.Based on Source\n4.Based on Destination\n5.Based on platform no\n6.Exit\n");
    scanf("%d",&sp);
    switch(sp)
    {
case 1:
    sortontype(start);break;
case 2:
    sortoncno(start);break;
case 3:
    sortbysource(start);break;
case 4:
    sortbydest(start);break;
case 5:
    sortonpfno(start);break;
    }
}while(sp!=6);
}

void main()
{
int n1=0;
do{
printf("Enter your choice\n");
printf("1.Enter new record\n2.Display entire list\n3.Sort\n4.Exit\n");
scanf("%d",&n1);
switch(n1)
{
case 1:
    start=create_newnode(start);break;
case 2:
    start=display(start);break;
case 3:
    sort(start);break;
}
}while(n1!=4);
}

/*
Complexity:
Worst case: O(n)
Average case: O(n)
Best case: O(1)
*/
