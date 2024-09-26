#include<iostream>
#include<iomanip>
#include<algorithm>
#include<climits>
using namespace std;
struct process{
    public: 
        int id;
        int arriv;
        int burst;
        int completion;
        int wait;
        int turnaround;
        int executed;
        process(){
            completion = 0;
            wait = 0;
            turnaround = 0;
            executed = 0;
        }
};
int main(){
    int n ;
    cout<<"Enter the number of process: ";
    cin>>n;
    int tq;
    cout<<"Enter the time quantum: ";
    cin>>tq;
    process arr[n];
    // taking input
    for(int i =0;i<n;i++){
        cout<<"Enter the arrival and burst time for process "<<i+1<<" : ";
        arr[i].id = i+1;
        cin>>arr[i].arriv >>arr[i].burst;
    }
    sort(arr,arr+n,[](process &a,process &b){return a.arriv<b.arriv; });
    int time = 0;
    int completed = 0;   
    int i=0;
    while(completed <n ){
        i = i%n;
        if(arr[i].arriv <= time && arr[i].completion == 0){
            if(arr[i].executed + tq <= arr[i].burst){
                arr[i].executed +=tq;
                time +=tq;   
            }else{
                time += arr[i].burst - arr[i].executed;
                arr[i].executed = arr[i].burst;
            }  
            if(arr[i].executed >= arr[i].burst){
                arr[i].completion = time;
                arr[i].turnaround = arr[i].completion - arr[i].arriv;
                arr[i].wait = arr[i].turnaround - arr[i].burst;
                completed++;
            }     
        }
        else {
            time++;
        }
        i++;      
    } 
    
    // Average waiting and turnaround time
    float avg_waiting =0;
    float avg_turn_around = 0;
    for(int i =0;i<n;i++){
        avg_waiting += arr[i].wait;
        avg_turn_around += arr[i].turnaround;
    }
    avg_turn_around /=n;
    avg_waiting /=n;

    // printing the process table
    cout<<"P_ID  AT   BT   WT  TAT  CT\n";
    for(int i =0;i<n;i++){
        cout<<setw(2)<<arr[i].id<<setw(5)<<arr[i].arriv<<setw(5)<<arr[i].burst<<setw(5)<<arr[i].wait<<setw(5)<<arr[i].turnaround<<setw(5)<<arr[i].completion<<"\n";
    }
    cout<<"\n Average Waiting time: "<<avg_waiting;
    cout<<"\n Average Turn Around time: "<<avg_turn_around;


}


