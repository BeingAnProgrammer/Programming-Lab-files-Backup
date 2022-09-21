// This is a program for implementing reader_writer problem
// 

#include<stdio.h>
#include<stdlib.h>
int main()
{
   typedef int semaphore;
   semaphore sread=0,swrite=0;
   int ch,r=0;
   printf("Reader writer\n");
   do
   {
      
       printf("Menu");
       printf("\n1.Read from file");
       printf("\n2.Write to file");
       printf("\n3.Exit the reader");
       printf("\n4.Exit the writer");
       printf("\n5.Exit");
       scanf("%d",&ch);
       printf("\nEnter your choice:%d",ch);
       switch(ch)
       {
           case 1:if(swrite==0)
           {
               sread=1;
               r+=1;
               printf("\nReader %d reads\n",r);

           }
           else
           {
               printf("\nNot possible\n");
           }
           break;
           case 2:if(sread==0 && swrite==0)
           {
               swrite=1;
               printf("\nwriter in progress\n");
           }
           else if(swrite==1)
           {
               printf("\nwriter writes the file\n");
           }
           else if(sread==1)
           {
               printf("\nCan not write while reader reads the file\n");
           }
           else
           {
               printf("\nCannot write file\n");
           }
           break;
           case 3:if(r!=0)
           {
               printf("\nThe reader %d closes the file\n",r);
               r-=1;
           }
           else if(r==0)
           {
               printf("\nOnly one reader file\n");
           }
           else
           {
               printf("%d Reader are reading the file\n",r);
           }
           break;
           case 4:if(swrite==1)
           {
               printf("\nwriter close the file\n");
               swrite=0;
           }
           else
           {
               printf("\nThere is no writer in the file\n");
           }
           break;
           case 5:exit(0);
       }
   }
   while(ch<6);
}