#include<stdio.h>
#include<stdlib.h>
int stuff(int *msg,int *shiftm,int n,int k)
{
        int start=0,i,j;
        for(i=0;i<=n-1;i++)
        {
                if(msg[i]==0)
                {
                        start=1;
                }
                else if(start>0)
                {
                        start++;
                }
                shiftm=(int *)realloc(shiftm,sizeof(int)*(k+1));
                shiftm[k]=msg[i];
                k++;
                if(start==6)
                {
                        shiftm=(int *)realloc(shiftm,sizeof(int)*(k+1));
                        shiftm[k]=0;
                        k++;
                        start=0;
                }

        }
        return k;
}
int destuff(int *msg,int *shiftm,int n,int k)
{
           int start=0,i,j;
           for(i=0;i<=n-1;i++)
           {

                      if(msg[i]==0)
                      {
                                 start=1;
                      }
                      else if(start>0)
                      {
                                 start++;
                      }
                      shiftm=(int *)realloc(shiftm,sizeof(int)*(k+1));
                      shiftm[k]=msg[i];
                        k++;
                        if(start==6)
                           {
                                                if(msg[i+1]==0)
                                                {
                                                        i++;
                                                        start=0;
                                                }
                                                else
                                                {
                                                        if(msg[i+2]==1)
                                                        {
                                                                return 0;
                                                        }
                                                        else
                                                        {
                                                                shiftm=(int *)realloc(shiftm,sizeof(int)*(k-6));
                                                                k=k-6;

                                                                i=i+2;
                                                                start=0;
                                                        }
                                                }

                            }

        }
        return k;
}
void output(int *s,int k)
{
        int i;
        for(i=0;i<k;i++)
                printf("%d",s[i]);
        printf("\n");
}
int main()
{
        int n,k,*stuffm,*msg,i;
        printf("Enter the data\n");
        printf("Enter the number of bits:");
        scanf("%d",&n);
        msg=(int *)malloc(sizeof(int)*n);
        printf("Enter the bits\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&msg[i]);
        }
        stuffm=(int *)malloc(sizeof(int)*8);
        //stuff flag
        k=0;
        stuffm[k]=0;
        k++;
        for(i=1;i<=6;i++)
        {
                stuffm[k]=1;
                k++;
        }
        stuffm[k]=0;
        k++;
        k=stuff(msg,stuffm,n,k);
        //stuff flag
        stuffm=(int *)realloc(stuffm,sizeof(int)*(k+8));
        stuffm[k]=0;
        k++;
        for(i=1;i<=6;i++)
        {
              stuffm[k]=1;
              k++;
        }
        stuffm[k]=0;
        k++;
        printf("Stuffed data\n");
        output(stuffm,k);
        n=0;
        printf("Enter a stuffed data\n");
        printf("Enter the number of bits:");
        scanf("%d",&k);
        stuffm=(int *)realloc(stuffm,sizeof(int)*k);
        msg=(int *)malloc(sizeof(int)*0);
        printf("Enter the bits\n");
        for(i=0;i<k;i++)
        {
               scanf("%d",&stuffm[i]);
        }
        n=destuff(stuffm,msg,k,n);
        if(n==0)
        {
                printf("Error\n");
        }
        else
        {
                printf("Destuffed data\n");
                output(msg,n);
        }
        return 0;
}