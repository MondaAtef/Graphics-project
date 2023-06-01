#include <bits/stdc++.h>  
using namespace std;  

struct Process {  
   int pid;  
   int burst_time; 
   int arrival_time;
};  
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {  
   for (int i = 0; i < n; i++)  
   tat[i] = proc[i].burst_time + wt[i];  
}  
 
void findWaitingTime(Process proc[], int n, int wt[]) {  
   int rt[n];  
   for (int i = 0; i < n; i++)  
   rt[i] = proc[i].burst_time;  
   int complete = 0, t = 0, minm = INT_MAX;  
   int shortest = 0, finish_time;  
   bool check = false;  
   while (complete != n) {  
      for (int j = 0; j < n; j++)
       {  
         if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {  
            minm = rt[j];  
            shortest = j;  
            check = true;  
         }  
      }  
      if (check == false)
       {  
         t++;  
         continue;  
      }  
      // decrementing the remaining time  
      rt[shortest]--;  
      minm = rt[shortest];  
      if (minm == 0)  
         minm = INT_MAX;  
         // If a process gets completely  
         // executed  
         if (rt[shortest] == 0)
          {  
            complete++;  
            check = false;  
            finish_time = t + 1;  
            // Calculate waiting time  
            wt[shortest] = finish_time - proc[shortest].burst_time - proc[shortest].arrival_time;  
            if (wt[shortest] < 0)  
               wt[shortest] = 0;  
         }  
          
         t++;  
   }  
}  
// Function to calculate average time  
void findavgTime(Process proc[], int n) {  
   int wt[n], tat[n], total_wt = 0,  
   total_tat = 0;  
   
   findWaitingTime(proc, n, wt);  
   
   findTurnAroundTime(proc, n, wt, tat);  
 
   for (int i = 0; i < n; i++) {  
      total_wt = total_wt + wt[i];  
      total_tat = total_tat + tat[i];  
     
   }  
   cout << "\nAverage waiting time = " << total_wt / n; cout << "\nAverage turn around time = " << total_tat / n;  
}  
int main() {  

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