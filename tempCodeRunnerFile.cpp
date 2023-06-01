#include <iostream>
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