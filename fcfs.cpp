#include<iostream>
#include<queue>
using namespace std;
struct process{
    public: 
        int id;
        int arriv;
        int burst;
        int completion;
        int wait;
        int turnaround;
        process(){
            completion = 0;
            wait = 0;
            turnaround = 0;
        }
};
int main(){
    int n ;
    cout<<"Enter the number of process: ";
    cin>>n;
    process arr[n];
    // taking input
    for(int i =0;i<n;i++){
        cout<<"Enter the arrival and burst time for process "<<i+1<<" : ";
        arr[i].id = i+1;
        cin>>arr[i].arriv >>arr[i].burst;
    }

    // sorting process array based on arrival time
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j].arriv > arr[j+1].arriv)
                swap(arr[j],arr[j+1]);
        }
    }
    // calcuating wait time and turn around time;
    int time = 0;
    int completed = 0;
    int i =0;
    while(completed < n){
        if(arr[i].arriv <= time){
            time += arr[i].burst;
            arr[i].completion = time;
            arr[i].turnaround = arr[i].completion - arr[i].arriv;   // ct - at
            arr[i].wait = arr[i].turnaround - arr[i].burst ;        // tat - bt
            completed++ ;
        }
        else time++;
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

    // sort process array based on id
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j].id > arr[j+1].id)
                swap(arr[j],arr[j+1]);
        }
    }

    // printing the process table
    cout<<"P_ID AT BT WT TAT CT\n";
    for(int i =0;i<n;i++){
        cout<<arr[i].id<<"    "<<arr[i].arriv<<"  "<<arr[i].burst<<" "<<arr[i].wait<<"   "<<arr[i].turnaround<<"  "<<arr[i].completion<<"\n";
    }
    cout<<"\n Average Waiting time: "<<avg_waiting;
    cout<<"\n Average Turn Around time: "<<avg_turn_around;


}
