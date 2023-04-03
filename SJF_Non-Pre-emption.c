#include<stdio.h>
int main()
{
    int bt[20],pr[20],wt[20],tat[20],p,q,n,tot=0,totime=0,pos,tp;
    float avgwttm,avgtatm;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(p=0;p<n;p++)
    {
        printf("p%d:",p+1);
        scanf("%d",&bt[p]);
        pr[p]=p+1;  
    }
 
 
for(p=0;p<n;p++)
    {
        pos=p;
        for(q=p+1;q<n;q++)
        {
            if(bt[q]<bt[pos])
                pos=q;
        }
        tp=bt[p];
        bt[p]=bt[pos];
        bt[pos]=tp;
        tp=pr[p];
        pr[p]=pr[pos];
        pr[pos]=tp;
    }
 
    wt[0]=0;
    for(p=1;p<n;p++)
    {
        wt[p]=0;
        for(q=0;q<p;q++)
            wt[p]+=bt[q];     
        tot+=wt[p];   
    }
    avgwttm=(float)tot/n;  
 
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(p=0;p<n;p++)
    {
        tat[p]=bt[p]+wt[p]; 
        totime+=tat[p];      
        printf("\np%d\t\t %d\t\t %d\t\t\t%d",pr[p],bt[p],wt[p],tat[p]);
    }
 
    avgtatm=(float)totime/n;     
    printf("\nAvg WT=%f\n",avgwttm);
    printf("Avg TT=%f\n",avgtatm);
}