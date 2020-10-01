#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* Structure to hold the input  */

struct process
{
	int at;
	int bt;
	int pr;
	int pno; 
}proc[50];

;

/* Comparator function to sort according to priority in case of same arrival time  */

bool comp(struct process a, struct process b){
	if(a.at==b.at){
		return a.pr<b.pr;
	}
	else {
		return a.at<b.at;
	}
}

/* Using fcfs algorithm to find the waiting time */

void get_wt_time(int wt[],int totalprocess){
	int service[50];
	service[0] = proc[0].at;
	wt[0]=0;
	for(int i=1;i<totalprocess;i++){

	service[i]=proc[i-1].bt+service[i-1];
	wt[i]=service[i]-proc[i].at;
	
	/* If waiting time is negative, change it to zero  */
	if(wt[i]<0){
		wt[i]=0;
		}
	
	}
}


void get_tat_time(int tat[],int wt[],int totalprocess){

	/* Filling turnaround time array  */
 
	for(int i=0; i < totalprocess; i++){
		tat[i] = proc[i].bt + wt[i];
	}	
}

void findgc(int totalprocess){
	/* Declare waiting time and turnaround time array */
	int wt[50],tat[50];
	float wavg=0;
	float tavg=0;
	/* Function call for waiting time array */
	get_wt_time(wt,totalprocess);
	/* Function call for turnaround time */
	get_tat_time(tat,wt,totalprocess);
	
	int stime[50],ctime[50];
	stime[0]=proc[0].at;
	ctime[0]=stime[0]+tat[0];

	/* Calculating starting time and ending time */
	for (int i = 1; i < totalprocess; i++)
	{
		stime[i]=ctime[i-1];
		ctime[i]=stime[i]+tat[i]-wt[i]; 
	}
	printf("Process No\tStart time\tComplete time\tTurn Around time\tWaiting Time\n");
	/* Display process details */
	for (int i = 0; i < totalprocess; i++)
	{
		wavg += wt[i];
		tavg += tat[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d",proc[i].pno,stime[i],ctime[i],tat[i],wt[i]);
		printf("\n");

	}
	printf("Average waiting time :");
	printf("%f",wavg/totalprocess);
	printf("\nAverage turnaround time :");
	printf("%f",tavg/totalprocess);
	
}

int main(){
	int arrivaltime[20];
	int bursttime[20];
	int priority[20];
	int n;
	printf("Enter the total number of processes : ");
	scanf("%d",&n);
	/* Input data */
	for (int i = 0; i < n; i++)
	{
		printf("Enter the arrival time, burst time and priority for process %d: ", i+1);
		scanf("%d%d%d",&arrivaltime[i],&bursttime[i],&priority[i]);	
	}
	
	for (int i = 0; i < n; i++)
	{
		proc[i].at=arrivaltime[i];
		proc[i].bt=bursttime[i];
		proc[i].pr=priority[i];
		proc[i].pno=i+1;
	}

	int comp_ (const void * a, const void * b){
		return ( *(int*)a - *(int*)b );
	}
	/* Using an inbuilt qsort function */
	
	qsort(proc,n, sizeof(int),comp_);
	findgc(n);
	return 0;

	
}