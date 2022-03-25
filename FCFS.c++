#include <bits/stdc++.h>
using namespace std;

// creating class for First Come First Serve Scheduling

class FCFS {

// declaring data members
    private:
        int numberOfProcess[1000] = {0};
        float fBurstTime[1000] = {0};




// declaring member functions
    public:

        // class constructor
        FCFS(int n) {

            printf("\n\n\n");
            for (int i = 0; i < n; i++) {
                numberOfProcess[i] = i;
                cout << "Enter the burst time for process " << i<<endl;
                cin >> fBurstTime[i];
            }
            printf("\n\n\n");
            
        }

        

        // function to calculate the waiting time of each process
        void waitingTime(int n);

        // function to calculate the turn around time of each process
        void turnAroundTime(int n);

        // function to calculate the average waiting time of all the processes
        void averageWaitingTime(int n);

        

};




// function to calculate the waiting time of each process
        void FCFS::waitingTime(int n) {
            double dTimeLen = 0;
            for (int i = 0; i < n; i++) {
                
                cout << "Waiting time for the P" << i << " is " << dTimeLen<<endl;
                printf("\n\n");
                dTimeLen = dTimeLen + fBurstTime[i];
            }
        }




// function to calculate the turn around time of each process
        void FCFS::turnAroundTime(int n) {
            double dTurnaround = 0;
            for (int i = 0; i < n; i++) {
                dTurnaround = dTurnaround + fBurstTime[i];
                cout << "Turnaround time for the P" << i << " is " << dTurnaround << endl;
                printf("\n\n");
                
            }
        }




// function to calculate the average waiting time of all the processes
        void FCFS::averageWaitingTime(int n) {
            double sum = 0;
            double waitTime =0;
            for (int i = 0; i < n-1; i++) {
                waitTime = waitTime + fBurstTime[i];
                sum = sum + waitTime;
            }
            cout << "\n Average waiting time for the given processes is " << sum/n << endl;
            printf("\n\n");
        
        }






int main() {

    FCFS obj1(5);
    obj1.waitingTime(5);
    obj1.turnAroundTime(5);
    obj1.averageWaitingTime(5);
    



    return 0;
}