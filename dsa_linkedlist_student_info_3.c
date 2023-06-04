#include<stdio.h>
#include<stdlib.h>
struct student
{
 char name[30];
 int rno;
 float marks;
 struct student *next;
};
struct student *head;
struct student* insert_at_beg(struct student *);
struct student* insert_at_end(struct student *);
struct student* delete_at_beg(struct student *);
struct student* delete_at_end(struct student *);
void display(struct student *);
struct student *temp,*temp1,*newstudent;
main()
{
int ch;
head=NULL;


   while(1)
   {
     printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
     printf("1) insert at the begining\n");
     printf("2) insert at the end\n");
     printf("3) delete from begining\n");
     printf("4) delete from the end\n");
     printf("5) display the linked list\n");
     printf("6) exit\n");
     printf("+++++++++++++++++++++++++++++++++++++++++++++\n");

     printf("\n--> Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newstudent=(struct student*)malloc(sizeof(struct student));
             printf("Enter the Student name roll no and marks\n");
             scanf("%s%d%f",&newstudent->name,&newstudent->rno,&newstudent->marks);
             head=insert_at_beg(newstudent);
             break;
    case 2: newstudent=(struct student*)malloc(sizeof(struct student));
             printf("Enter the Student name roll no and marks\n");
             scanf("%s%d%f",&newstudent->name,&newstudent->rno,&newstudent->marks);
             head=insert_at_end(newstudent);
             break;
    case 3: if(head==NULL)
             printf("NO STUDENT PRESENT---cant delete\n");
             else
             {
                head=delete_at_beg(head);
             }
             break;
    case 4: if(head==NULL)
             printf("NO STUDENT PRESENT---cant delete\n");
             else
             {
                head=delete_at_end(head);
             }
             break;
    case 5: display(head);break;
    case 6: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
}

struct student* insert_at_beg(struct student *newstudent)
{
   if(head==NULL)
   {
     head=newstudent;
     head->next=NULL;
     return(head);
   }
   else
   {
     newstudent->next=head;
     head=newstudent;
     return(head);
   }
}


struct student* insert_at_end(struct student *newstudent)
{
   if(head==NULL)
   {
     head=newstudent;
     head->next=NULL;
     return(head);
   }
   else
   {
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;

     }
     temp->next=newstudent;
        newstudent->next=NULL;
        return(head);

   }
}

void display(struct student *head)
{
   if(head==NULL)
   {
     printf("NO STUDENT PRESENT\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("Name=%s\t RNo=%d\t Marks=%f\n",temp->name,temp->rno,temp->marks);
         temp=temp->next;
      }
      printf("\n");
   }
}

struct student* delete_at_beg(struct student *head)
{
    if(head==NULL)
    {
        printf("NO STUDENT PRESENT---cant delete\n\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("student deleted==>name=%s\t rno=%d\t marks=%f\n",head->name,head->rno,head->marks);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           head=head->next;
           printf("student deleted==>name=%s\t rno=%d\t marks=%f\n",temp->name,temp->rno,temp->marks);
           free(temp);
           return(head);

       }
    }

}


struct student* delete_at_end(struct student *head)
{
    if(head==NULL)
    {
        printf("NO STUDENT PRESENT---cant delete\n");
    }
    else
    {
       if(head->next==NULL)
       {
            printf("student deleted==>name=%s\t rno=%d\t marks=%f\n",head->name,head->rno,head->marks);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;

           while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
          printf("student deleted==>name=%s\t rno=%d\t marks=%f\n",temp->name,temp->rno,temp->marks);
           free(temp);
           temp1->next=NULL;
           return(head);

       }
    }

}


