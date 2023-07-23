#include<stdio.h>
#include<stdlib.h>
int bstuff(int *data,int *stuff,int n,int k)
{
   int i,j,s;
   int count=0;
   for(i=0;i<n;i++)
   {
      if(data[i]==0 && i%8==0)
      {
         count++;
      }
      else if(data[i]==1 && count>0)
      {
         count++;
      }
      else
      {
         stuff=(int *)realloc(stuff,sizeof(int)*(k+8));
         s=i-count;
         for(j=0;j<8;j++)
         {
            stuff[k]=data[s];
            k++;
            s++;
         }
         i+=7-count;
         count=0;
     }
      if(count==7)
      {
         stuff=(int *)realloc(stuff,sizeof(int)*(k+16));
         stuff[k]=0;
         k++;
         for(j=1;j<=7;j++)
         {
            stuff[k]=1;
            k++;
         }
         s=i-count+1;
         for(j=0;j<8;j++)
         {
            stuff[k]=data[s];
            k++;
            s++;
         }
         i+=8-count;
         count=0;
    }
   }
   return k;
}
int destuff(int *data,int *stuff,int n,int k)
{
      int i,j,s;
      int count=0;
      for(i=0;i<n;i++)
      {
         if(data[i]==0 && i%8==0)
         {
            count++;
         }
         else if(data[i]==1 && count>0)
         {
            count++;
         }
         else
         {
            stuff=(int *)realloc(stuff,sizeof(int)*(k+8));
            s=i-count;
            for(j=0;j<8;j++)
            {
               stuff[k]=data[s];
               k++;
               s++;
            }
            i+=7-count;
            count=0;
         }
         if(count==7)
         {

            if(data[i+1]==1)
            {

                  s=i+1-count+8;
                 for(j=0;j<8;j++)
                  {
                      stuff[k]=data[s];
                       k++;
                       s++;
                 }
                 i+=15-count+1;
            }
            else
            {
                i+=7-count+1;
            }
            count=0;
         }
      }
        printf("Destuffed data\n");
        for(i=0;i<k;i++)
        {
            printf("%d",stuff[i]);
            if((i+1)%8==0)
            {
                     printf("\t");
            }
       }
     return k;
}

int main()
{
   int *data,i,*stuff,k=0,n;
   printf("Enter the number of bits\n");
   scanf("%d",&n);
   printf("Enter the  bits\n");
   data=(int *)malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&data[i]);
   }
   stuff=(int *)malloc(sizeof(int)*8);
   stuff[k]=0;
   k++;
   for(i=1;i<=6;i++)
   {
      stuff[k]=1;
      k++;
   }
   stuff[k]=0;
   k++;
   k=bstuff(data,stuff,n,k);
   stuff=(int *)realloc(stuff,sizeof(int)*(k+8));
    stuff[k]=0;
    k++;
    for(i=1;i<=6;i++)
    {
        stuff[k]=1;
        k++;
    }
    stuff[k]=0;
    k++;
    printf("Code word\n");
    for(i=0;i<k;i++)
    {
       printf("%d",stuff[i]);
       if((i+1)%8==0)
       {
          printf("\t");
        }
      }
        printf("\n");
        int *dd;
        dd=(int *)malloc(sizeof(int)*0);
        printf("Enter the code word\n");
        printf("Enter the number of bits\n");
        scanf("%d",&k);
        printf("Enter the  bits\n");
        stuff=(int *)malloc(sizeof(int)*k);
        for(i=0;i<k;i++)
         {
              scanf("%d",&stuff[i]);
         }
        n=0;
        n=destuff(stuff,data,k,n);

        return 0;
}




