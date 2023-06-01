#include<iostream>
//#include <bits/stdc++.h>
using namespace std;


// Shortestjob first (SjF)
struct Process {
	int pid; 
	int burst_time; 
	int arrival_time; 
};

void findWaitingTime(Process proc[], int n,	int wt[])
{
	int remain_t[n];

	
	for (int i = 0; i < n; i++)
		remain_t[i] = proc[i].burst_time;

	int complete = 0, t = 0, minm = INT_MAX;            // t= 0______3______9_______16_________24
	int shortest = 0, finish_time;
	
    bool check = false;

	while (complete != n) {

		
		for (int j = 0; j < n; j++) {
			if ((proc[j].arrival_time <= t) &&(remain_t[j] < minm) && remain_t[j] > 0) {
				minm = remain_t[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		
		remain_t[shortest]--;             //reduse the value of duration time of shortest process

		// Update minimum
		minm = remain_t[shortest];   //the new value of minm
		if (minm == 0)
			minm = INT_MAX;

		
		if (remain_t[shortest] == 0) {      //that process complated

			
			complete++;
			check = false;

			
			finish_time = t + 1;

		         //(finish_time -proc[shortest].burst_time)
			wt[shortest] = finish_time -proc[shortest].burst_time -proc[shortest].arrival_time;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
	
		t++;
	}
}


void findTurnAroundTime(Process proc[], int n,int wt[], int tat[])
{
	
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].burst_time + wt[i];
}


void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0,total_tat = 0;

	
	findWaitingTime(proc, n, wt);

	
	findTurnAroundTime(proc, n, wt, tat);

	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}


int main()
{
    int n;
	cin>>n;
    Process pr[n];
		

      for (int i=0;i<n;i++)
	  {
		
		cout << "\nP[" << i+1<< "] "<<endl;
		   cin>>pr[i].arrival_time;
		   cin >>pr[i].burst_time;
		
	  }

	  int array_arrival[n] , array_burst[n];
	  for (int i=0;i<n;i++)
	  {
		array_arrival[i]=pr[i].arrival_time;
        array_burst[i]=pr[i].burst_time;
	  }
        cout<<"|process | arrival_time | burst_time | \n";

	  for (int i=0;i<n;i++)
		{
		   
	      cout<<"|   "<<i+1<<"\t |\t"<<array_arrival[i]<<"\t|\t"<< array_burst[i]<<"    |"<<"\n";	
		  
		}

	findavgTime(pr, n);
	
}
