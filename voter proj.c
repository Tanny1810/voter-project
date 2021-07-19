#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
     int a,i,found,z;
     char nam[25],v[25];
     struct voters
   {
       char voterid[25];
       char name[25];
       int age;
       char address[50];
   };
   struct voters s1[10];

/*Add file path here*/	
    fp=fopen("add_file_path","a");
    if(fp==NULL)
    {
        puts("cannot open file");
        exit(1);
    }
    else
    {

   printf("enter no of voters = ");
   scanf("%d",&a);

   for(i=0;i<a;i++)
        {
           q:
       fflush(stdin);
       puts("enter voter's age");
       scanf("%d",&s1[i].age);
       if(s1[i].age<18)
       {
           printf("you are not eligible to vote\n\n");
           goto q;
       }
       fflush(stdin);
       puts("enter voter's ID");
       gets(s1[i].voterid);
       fflush(stdin);
       puts("enter voter's name");
       gets(s1[i].name);
       fflush(stdin);
       puts("enter voters address");
       gets(s1[i].address);

       printf("\n\n******************************************************************************************************************\n\n");
        }

        fprintf(fp,"voter ID\t\tname\t\t\tage\t\t\taddress\n\n");
    }

   for(i=0;i<a;i++)
   {
       fprintf(fp,"%s\t\t\t%s\t\t\t%d\t\t\t%s\n",s1[i].voterid,s1[i].name,s1[i].age,s1[i].address);
       fprintf(fp,"\n\n******************************************************************************************************************\n\n");
   }

   int n;
   p:

   while(1)
   {
   printf("select any option from the given below\n\n");
   printf("1. display all voter list\n");
   printf("2. search and display voter data on the basis of voter ID\n");
   printf("3. search and display voter data on the basis of voter age between 18 and 25\n");
   printf("4. search and display voter data on the basis of voter name\n");
   printf("5. search and update voter data by using voter's ID\n");
   printf("6. EXIT");

   printf("\n\nenter option = ");
   scanf("%d",&n);


   switch(n)
   {
   case 1:
       printf("DISPLAY INFO\n\n");

       for(i=0;i<a;i++)
       {
           printf("NAME = %s\n",s1[i].name);
           printf("AGE = %d\n",s1[i].age);
           printf("voter ID = %s\n",s1[i].voterid);
           printf("ADDRESS = %s\n",s1[i].address);
           printf("\n****************************\n\n");
       }

           printf("\n\n*all available records have been displayed*\n\n");
           goto p;


    break;

   case 2:
       printf("enter voter ID you want to search = ");
       fflush(stdin);
       gets(v);
       found=-1;
       for(i=0;i<a;i++)
       {
           z=strcmp(s1[i].voterid,v);
           if(z==0)
           {
               found=i;
               printf("search successful\n\n");
               printf("voter ID = %s\n",s1[i].voterid);
               printf("NAME = %s\n",s1[i].name);
               printf("AGE = %d\n",s1[i].age);
               printf("ADDRESS = %s\n",s1[i].address);
               break;
           }
       }
       if(found==-1)
           {
               printf("*requested voter ID not found\n\n");
           }
       goto p;

   case 3:

       printf("To display voters between the age of 18 and 25\n\n");
       found=-1;
       for(i=0;i<a;i++)
       {
           if(s1[i].age>=18&&s1[i].age<=25)
           {
               found=i;
               printf("voter ID = %s\n",s1[i].voterid);
               printf("NAME = %s\n",s1[i].name);
               printf("AGE = %d\n",s1[i].age);
               printf("ADDRESS = %s\n",s1[i].address);


           }
       }
       if(found==-1)
           {
               printf("their is no voter between the age of 18 and 25\n\n");
           }
        goto p;
   case 4:

    puts("enter voter name");
    fflush(stdin);
    gets(nam);

    found=-1;
    for(i=0;i<a;i++)
    {
        z=strcmp(s1[i].name,nam);

        if(z==0)
        {
               found=i;
               printf("voter ID = %s\n",s1[i].voterid);
               printf("NAME = %s\n",s1[i].name);
               printf("AGE = %d\n",s1[i].age);
               printf("ADDRESS = %s\n",s1[i].address);
               break;
        }
    }
    if(found==-1)
        {
            printf("voter by the name of %s not found\n\n",nam);
        }

    goto p;

    case 5:

        printf("enter voter ID you want to search = ");
       fflush(stdin);
       gets(v);
       found=-1;
       for(i=0;i<a;i++)
       {
           z=strcmp(s1[i].voterid,v);
           if(z==0)
           {
               found=i;
               printf("search successful\n\n");
               printf("voter ID = %s\n",s1[i].voterid);
               printf("NAME = %s\n",s1[i].name);
               printf("AGE = %d\n",s1[i].age);
               printf("ADDRESS = %s\n\n",s1[i].address);
               break;
           }
       }
       if(found==-1)
           {
               printf("*requested voter ID not found\n\n");
           }

       fflush(stdin);
       puts("enter voter's age");
       scanf("%d",&s1[i].age);
       if(s1[i].age<18)
       {
           printf("you are not eligible to vote\n\n");
           goto q;
       }
       fflush(stdin);
       puts("enter voter's name");
       gets(s1[i].name);
       fflush(stdin);
       puts("enter voters address");
       gets(s1[i].address);

       printf("\n***UPDATED INFO***\n\n");
       printf("NAME = %s\n",s1[i].name);
       printf("AGE = %d\n",s1[i].age);
       printf("ADDRESS = %s\n",s1[i].address);
           goto p;

    case 6:
        exit(0);


    default:
        printf("please select a valid option\n");
        goto p;
   }

   }
}
