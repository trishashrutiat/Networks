#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int send(int b[30],int k)
{
   int s=0,i,cs=0;
   for(i=0;i<k;i++)
   {
      s=s+b[i];
   }
   printf("\n--sum is %d ",s);
   cs= ~s;
   printf("\n---sender's checksum is %d---\n",cs);
   return cs;
}
int receive(int c[30],int k,int chk)
{
   int cs,i,s=0;
   for(i=0;i<k;i++)
      s=s+c[i];
   printf("\n---receiver sum is %d ",s);
   s=s+chk;
   cs=~s;
   printf("\n---receiver's checksum is %d---\n",cs);
   return cs;
}
int main()
{
   int arr[30],i,m,schk,rchk;
   printf("\n-----CHECK SUM METHOD------\n");
   printf("\nenter the length of the dataword : ");
   scanf("%d",&m);
   printf("\nenter the data or the strings    : ");
   for(i=0;i<m;i++)
      scanf("%d",&arr[i]);
   schk=send(arr,m);
   rchk=receive(arr,m,schk);

   if(rchk == 0)
      printf("\n no error in transmission\n");
   else
      printf("\n erraneous transmission\n");
   return 0;
}




