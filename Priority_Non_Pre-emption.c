#include<stdio.h>
struct process {
    int psnu;
    int prty;
    int brtm;
    int wttm;
    int tartm;
};
int main() 
{
    int m,k,l;
    float awt=0,atartm=0;
    printf("Enter the number of processes you want: ");
    scanf("%d", &m);
    struct process p[m],tp;
    printf("Enter the priority, and burst time\n");
    for(k=0; k<m; k++) 
    {
        printf("Process %d: \n",k+1);
        p[k].psnu=k+1;
        scanf("%d %d",&p[k].prty,&p[k].brtm);
    }
    for(k=0;k<m-1;k++)
    {
        for(l=k+1;l<m;l++) 
        {
            if(p[k].prty>p[l].prty) 
            {
                tp=p[k];
                p[k]=p[l];
                p[l]=tp;
            }
        }
    }
    p[0].wttm=0;
    p[0].tartm=p[0].brtm;
    for(k=1;k<m;k++) 
    {
        p[k].wttm=p[k-1].tartm;
        p[k].tartm=p[k].wttm+p[k].brtm;
    }
    printf("\nProcess\t  Priority\tBurst Time\tWaiting Time\tTurn around Time\n");
    for(k=0;k<m;k++)
    {
        printf("   %d\t     %d\t\t   %d\t\t   %d\t\t   %d\n",p[k].psnu,p[k].prty,p[k].brtm,p[k].wttm,p[k].tartm);
    }
    for(k=0;k<m;k++)
    {
    	atartm=atartm+p[k].tartm;
    	awt=awt+p[k].wttm;
	}
	printf("average waiting time:%f\n", awt/m);
  printf("average turnaround time:%f",atartm/m);
  return 0;
}