#include <stdio.h>
struct process 
{
    int psnu;
    int artm;
    int brtm;
    int rt; 
};
int srt(struct process proc[],int n,int t) 
{
    int shortest=-1;
    int min_rt=10000,i;
    for (i = 0;i<n;i++) 
    {
        if (proc[i].artm<=t&&proc[i].rt<min_rt&&proc[i].rt>0)
        {
            shortest=i;
            min_rt=proc[i].rt;
        }
    }
    return shortest;
}
int main() 
{
    int m,p,q;
    printf("Enter the number of processes you want: ");
    scanf("%d",&m);
    struct process proc[20],temp ;
    for (p=0;p<m;p++) 
    {
        printf("Enter the arrival time and burst time for process %d: \n",p+1);
        scanf("%d %d",&proc[p].artm,&proc[p].brtm);
        proc[p].psnu=p+1;
        proc[p].rt=proc[p].brtm;
    }
    for (p=0;p<m-1;p++) 
    {
        for (q=p+1;q<m;q++) 
        {
            if (proc[p].artm>proc[q].artm) 
            {
                temp=proc[p];
                proc[p]=proc[q];
                proc[q]=temp;
            }
        }
    }
    int t=0;
    int completed=0,ct=0,tat=0,wttm=0;
    float atat=0,awt=0;
    printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    while (completed<m)
      {
        int shortest=srt(proc,m,t);
        if (shortest==-1) 
        {
            t++;
           continue;
        }
        proc[shortest].rt--;
        t++;
        if (proc[shortest].rt == 0) 
        {
            completed++;
            ct=t;
            tat=ct-proc[shortest].artm;
            wttm=tat-proc[shortest].brtm;
            atat=atat+tat;
            awt=awt+wttm;
            printf("%d\t%d\t%d\t%d\t %d\t%d\n",proc[shortest].psnu,proc[shortest].artm,proc[shortest].brtm,ct,tat,wttm);
        }
    }
    printf("Average waiting time = %f\n",awt/m);
    printf("Average turn around time = %f",atat/m);
    
}