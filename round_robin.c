#include<stdio.h>
int main() 
{
 int p,m,t,rmn,rflg=0,tk;
 int wtk=0,tatk=0,atk[10],btk[10],rtk[10];
 printf("Enter Total Process:\t ");
 scanf("%d",&m);
 rmn=m;
 for(p=0;p<m;p++)
 {
   printf("Enter Arrival Time and Burst Time for Process Process Number %d :",p+1);
   scanf("%d",&atk[p]);
   scanf("%d",&btk[p]);
   rtk[p]=btk[p];
 }
 printf("Enter Time Quantum:\t");
 scanf("%d",&tk);
 printf("\n\nProcess\t|Burst Time|Turnaround Time|Waiting Time\n\n");
 for(t=0,p=0;rmn!=0;)
 {
   if(rtk[p]<=tk && rtk[p]>0)
   {
     t+=rtk[p];
     rtk[p]=0;
     rflg=1;
   }
   else if(rtk[p]>0)
   {
     rtk[p]-=tk;
     t+=tk;
   }
   if(rtk[p]==0 && rflg==1)
   {
     rmn--;
     printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\n",p+1,btk[p],t-atk[p],t-atk[p]-btk[p]);
     wtk+=t-atk[p]-btk[p];
     tatk+=t-atk[p];
     rflg=0;
   }
   if(p==m-1)
     p=0;
   else if(atk[p+1]<=t)
     p++;
   else
     p=0;
 }
 printf("\nAverage Waiting Time= %f\n",wtk*1.0/m);
 printf("Avg Turnaround Time = %f",tatk*1.0/m);
 
 return 0;
}