#include <stdio.h>
struct Process {
    int prid;
    int brt_tm;
    int avl_tm;
    int prty;
};
void print_table(struct Process pro[], int n, int waiting_time[], int turnaround_time[]) {
    int twt = 0, ttat = 0,i;
    printf("Process ID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pro[i].prid, pro[i].brt_tm, pro[i].avl_tm, pro[i].prty, waiting_time[i], turnaround_time[i]);
       twt += waiting_time[i];
        ttat += turnaround_time[i];
    }
    printf("Average waiting time: %.2f\n", (float)twt / n);
    printf("Average turnaround time: %.2f\n", (float)ttat / n);
}
void priority_preemptive(struct Process pro[], int n) {
    int i,bst_rem[n], time = 0, cmpltd = 0, curnt_proc = -1, cmplt_tm[n], tnd_tm[n], wt_tm[n];
    for (i = 0; i < n; i++) {
        bst_rem[i] = pro[i].brt_tm;
    }
    while (cmpltd != n) {
        int highest_priority = -1;
        for (i = 0; i < n; i++) {
            if (pro[i].avl_tm <= time && bst_rem[i] > 0) {
                if (highest_priority == -1 || pro[i].prty < pro[highest_priority].prty) {
                    highest_priority = i;
                }
            }
        }
        if (curnt_proc != highest_priority) {
            printf("Time %d: %d\n", time, highest_priority != -1 ? pro[highest_priority].prid : -1);
            curnt_proc = highest_priority;
        }
        if (curnt_proc == -1) {
            time++;
            continue;
        }
        bst_rem[curnt_proc]--;
        if (bst_rem[curnt_proc] == 0) {
            cmplt_tm[curnt_proc] = time + 1;
            tnd_tm[curnt_proc] = cmplt_tm[curnt_proc] - pro[curnt_proc].avl_tm;
            wt_tm[curnt_proc] = tnd_tm[curnt_proc] - pro[curnt_proc].brt_tm;
            cmpltd++;
            curnt_proc = -1;
        }
        time++;
    }
    print_table(pro, n, wt_tm, tnd_tm);
}

int main() {
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].brt_tm);
        printf("Enter the arrival time: ");
        scanf("%d", &processes[i].avl_tm);
        printf("Enter the priority: ");
        scanf("%d", &processes[i].prty);
        processes[i].prid = i + 1;
    }
    priority_preemptive(processes, n);
    return 0;