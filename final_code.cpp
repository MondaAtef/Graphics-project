 //*******************************FCFS***************************************
#include <iostream>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void calculateWaitingTime(Process* processes, int numProcesses, int* waitingTime) {
    waitingTime[0] = 0; // The first process has no waiting time
    
    for (int i = 1; i < numProcesses; i++) {
        waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
    }
}

void calculateTurnaroundTime(Process* processes, int numProcesses, int* waitingTime, int* turnaroundTime) {
    for (int i = 0; i < numProcesses; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void calculateAverageTimes(Process* processes, int numProcesses, int* waitingTime, int* turnaroundTime) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    
    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    
    double averageWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double averageTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    
    std::cout << "Average Waiting Time: " << averageWaitingTime << std::endl;
    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << std::endl;
}

void displayGanttChart(Process* processes, int numProcesses, int* waitingTime) {
    std::cout << "\nGantt Chart:" << std::endl;
    // for (int i = 0; i < numProcesses; i++) {
    //     std::cout << "P" << processes[i].id << " ";
    // }
    // std::cout << std::endl;
    
    // for (int i = 0; i < numProcesses; i++) {
    //     std::cout << waitingTime[i] << "   ";
    // }
    //std::cout << std::endl;
    for (int i = 0; i < numProcesses; i++)
	{
		std::cout << "----------------------------------\n";
		std::cout<< "|Process|Burst Time|Arrival Time|\n";
		std::cout<< "|p[" << i + 1 << "]:   	" 
		<< processes[i].burstTime <<"         "<< processes[i].arrivalTime << "         |\n";
	}
}

int main() {
    int numProcesses;
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;
    
    Process* processes = new Process[numProcesses];
    int* waitingTime = new int[numProcesses];
    int* turnaroundTime = new int[numProcesses];
    
    for (int i = 0; i < numProcesses; i++) {
        processes[i].id = i + 1;
        
        std::cout << "Enter arrival time for Process " << i + 1 << ": ";
        std::cin >> processes[i].arrivalTime;
        
        std::cout << "Enter burst time for Process " << i + 1 << ": ";
        std::cin >> processes[i].burstTime;
    }
    
    calculateWaitingTime(processes, numProcesses, waitingTime);
    calculateTurnaroundTime(processes, numProcesses, waitingTime, turnaroundTime);
    
    displayGanttChart(processes, numProcesses, waitingTime);
    calculateAverageTimes(processes, numProcesses, waitingTime, turnaroundTime);
    
    return 0;
}
// //**********************************SJF_preemtive*******************************************

// #include <bits/stdc++.h>
// using namespace std;


// // Shortestjob first (SjF)
// struct Process {
// 	int pid; 
// 	int burst_time; 
// 	int arrival_time; 
// };

// void findWaitingTime(Process proc[], int n,	int wt[])
// {
// 	int remain_t[n];

	
// 	for (int i = 0; i < n; i++)
// 		remain_t[i] = proc[i].burst_time;

// 	int complete = 0, t = 0, minm = INT_MAX;            // t= 0______3______9_______16_________24
// 	int shortest = 0, finish_time;
	
//     bool check = false;

// 	while (complete != n) {

		
// 		for (int j = 0; j < n; j++) {
// 			if ((proc[j].arrival_time <= t) &&(remain_t[j] < minm) && remain_t[j] > 0) {
// 				minm = remain_t[j];
// 				shortest = j;
// 				check = true;
// 			}
// 		}

// 		if (check == false) {
// 			t++;
// 			continue;
// 		}

		
// 		remain_t[shortest]--;             //reduse the value of duration time of shortest process

// 		// Update minimum
// 		minm = remain_t[shortest];   //the new value of minm
// 		if (minm == 0)
// 			minm = INT_MAX;

		
// 		if (remain_t[shortest] == 0) {      //that process complated

			
// 			complete++;
// 			check = false;

			
// 			finish_time = t + 1;

// 		         //(finish_time -proc[shortest].burst_time)==زمن دخولها
// 			wt[shortest] = finish_time -proc[shortest].burst_time -proc[shortest].arrival_time;

// 			if (wt[shortest] < 0)
// 				wt[shortest] = 0;
// 		}
	
// 		t++;
// 	}
// }


// void findTurnAroundTime(Process proc[], int n,int wt[], int tat[])
// {
	
// 	for (int i = 0; i < n; i++)
// 		tat[i] = proc[i].burst_time + wt[i];
// }


// void findavgTime(Process proc[], int n)
// {
// 	int wt[n], tat[n], total_wt = 0,total_tat = 0;

	
// 	findWaitingTime(proc, n, wt);

	
// 	findTurnAroundTime(proc, n, wt, tat);

// 	for (int i = 0; i < n; i++) {
// 		total_wt = total_wt + wt[i];
// 		total_tat = total_tat + tat[i];
// 	}

// 	cout << "\nAverage waiting time = "
// 		<< (float)total_wt / (float)n;
// 	cout << "\nAverage turn around time = "
// 		<< (float)total_tat / (float)n;
// }


// int main()
// {
//     int n;
// 	cin>>n;
//     Process pr[n];
		

//       for (int i=0;i<n;i++)
// 	  {
		
// 		cout << "\nP[" << i+1<< "] "<<endl;
// 		   cin>>pr[i].arrival_time;
// 		   cin >>pr[i].burst_time;
		
// 	  }

// 	  int array_arrival[n] , array_burst[n];
// 	  for (int i=0;i<n;i++)
// 	  {
// 		array_arrival[i]=pr[i].arrival_time;
//         array_burst[i]=pr[i].burst_time;
// 	  }
//         cout<<"|process | arrival_time | burst_time | \n";

// 	  for (int i=0;i<n;i++)
// 		{
		   
// 	      cout<<"|   "<<i+1<<"\t |\t"<<array_arrival[i]<<"\t|\t"<< array_burst[i]<<"    |"<<"\n";	
		  
// 		}

// 	findavgTime(pr, n);
	
// }
// //****************************** SJF_Non_preemtive ***************************************
// #include <bits/stdc++.h>  
// using namespace std;  

// struct Process {  
//    int pid;  
//    int burst_time; 
//    int arrival_time;
// };  
// void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {  
//    for (int i = 0; i < n; i++)  
//    tat[i] = proc[i].burst_time + wt[i];  
// }  
 
// void findWaitingTime(Process proc[], int n, int wt[]) {  
//    int rt[n];  
//    for (int i = 0; i < n; i++)  
//    rt[i] = proc[i].burst_time;  
//    int complete = 0, t = 0, minm = INT_MAX;  
//    int shortest = 0, finish_time;  
//    bool check = false;  
//    while (complete != n) {  
//       for (int j = 0; j < n; j++)
//        {  
//          if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {  
//             minm = rt[j];  
//             shortest = j;  
//             check = true;  
//          }  
//       }  
//       if (check == false)
//        {  
//          t++;  
//          continue;  
//       }  
//       // decrementing the remaining time  
//       rt[shortest]--;  
//       minm = rt[shortest];  
//       if (minm == 0)  
//          minm = INT_MAX;  
//          // If a process gets completely  
//          // executed  
//          if (rt[shortest] == 0)
//           {  
//             complete++;  
//             check = false;  
//             finish_time = t + 1;  
//             // Calculate waiting time  
//             wt[shortest] = finish_time - proc[shortest].burst_time - proc[shortest].arrival_time;  
//             if (wt[shortest] < 0)  
//                wt[shortest] = 0;  
//          }  
          
//          t++;  
//    }  
// }  
// // Function to calculate average time  
// void findavgTime(Process proc[], int n) {  
//    int wt[n], tat[n], total_wt = 0,  
//    total_tat = 0;  
   
//    findWaitingTime(proc, n, wt);  
   
//    findTurnAroundTime(proc, n, wt, tat);  
 
//    for (int i = 0; i < n; i++) {  
//       total_wt = total_wt + wt[i];  
//       total_tat = total_tat + tat[i];  
     
//    }  
//    cout << "\nAverage waiting time = " << total_wt / n; cout << "\nAverage turn around time = " << total_tat / n;  
// }  
// int main() {  

// int n;
// 	cin>>n;
//     Process pr[n];
		

//       for (int i=0;i<n;i++)
// 	  {
		
// 		cout << "\nP[" << i+1<< "] "<<endl;
// 		   cin>>pr[i].arrival_time;
// 		   cin >>pr[i].burst_time;
		
// 	  }

// 	  int array_arrival[n] , array_burst[n];
// 	  for (int i=0;i<n;i++)
// 	  {
// 		array_arrival[i]=pr[i].arrival_time;
//         array_burst[i]=pr[i].burst_time;
// 	  }
//         cout<<"|process | arrival_time | burst_time | \n";

// 	  for (int i=0;i<n;i++)
// 		{
		   
// 	      cout<<"|   "<<i+1<<"\t |\t"<<array_arrival[i]<<"\t|\t"<< array_burst[i]<<"    |"<<"\n";	
		  
// 		}

//       findavgTime(pr, n); 
// }
//**************************** Round Robin ***********************************************
// #include <iostream>
// #include<math.h>
// using namespace std;

// void RR()
// {
// 	int n, quantum, Arrival_time[10], duration_time[10], start_time[10], end_time[10];
// 	int  waiting_time[10], turn_around_time[10], t_waiting_time = 0, t_turn_around_time = 0;

// 	double avwt=0, avtat=0;
// 	cout << "Enter number of process: ";
// 	cin >> n;
// 	//getting duration time and arrrival time for each process

// 	cout << "Enter Arrival time and duration time : ";
// 	for (int i = 0;i < n;i++) {
// 		cout << "\nP[" << i + 1 << "] ";
		
// 		cin >> Arrival_time[i]>> duration_time[i] ;
// 	}

// 	cout << "Enter the quantum: ";
// 	cin >> quantum;
	
	 
// 	if (quantum<=0)
// 	{
// 		cout<<"|process | arrival_time |  burst_time| \n";
// 		for (int i=0;i<n;i++)
// 		{
// 	      cout<<"|   "<<i+1<<"\t |\t"<<Arrival_time[i]<<"\t|\t"<<duration_time[i]<<"    |"<<"\n";	
// 		}
	
// 		cout<<"wrong value "<<endl;	
// 	}

//    else
//     {
// 	int remain[10];
// 	for (int i = 0;i < n;i++)
// 		remain[i] = duration_time[i];

// 	int time = 0;        //time refers to time interval
// 	int executed = 0;   //executed refers to processes which has been executed
// 	while (executed != n) {

// 		for (int i = 0;i < n;i++) {

// 			if (remain[i] > 0) {

// 				if (remain[i] == duration_time[i]) 
// 				{

// 					start_time[i] = max(time, Arrival_time[i]);
// 					time = start_time[i];
// 				}

// 				if (remain[i] > quantum) 
// 				{
// 					time += quantum;
// 					remain[i] -= quantum;
// 				}
// 				else    //remain<=quantum
// 				{
// 					executed++;
// 					time += remain[i];
// 					waiting_time[i] = time - duration_time[i];
// 					remain[i] = 0;
// 					end_time[i] = time;
// 					turn_around_time[i] =  end_time[i] - Arrival_time[i]; 
// 					t_turn_around_time += turn_around_time[i];
// 					t_waiting_time += waiting_time[i];

					
// 				}
// 			}
// 		}
		 
// 	}
// 	 avtat = (float)t_turn_around_time / n;
// 		avwt = (float)t_waiting_time / n; 
        
//         cout<<"|process | arrival_time |  burst_time| \n";
// 		for (int i=0;i<n;i++)
// 		{
// 	      cout<<"|   "<<i+1<<"\t |\t"<<Arrival_time[i]<<"\t|\t"<<duration_time[i]<<"    |"<<"\n";	
// 		}
//       cout <<"\n"<<"avarage waiting time = "<<avwt<<"\n";
//       cout <<"avarage turnaround time = "<<avtat<<"\n";
//  }
// }
// int main()
// {
//     RR();
// }