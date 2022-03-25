#include <bits/stdc++.h>
using namespace std;

// creating class for Shortest Job First Scheduling

class SJF {

// declaring data members
    private:
        int numberOfProcess[1000] = {0};
        float fBurstTime[1000] = {0};
        float fBurstTime1[1000] = {0};
        float fBurstTime2[1000] = {0};
        




// declaring member functions
    public:

        // class constructor
        SJF(int n) {

            printf("\n\n\n");
            for (int i = 0; i < n; i++) {
                numberOfProcess[i] = i;
                cout << "Enter the burst time for process " << i<<endl;
                cin >> fBurstTime[i];
                fBurstTime1[i] = fBurstTime[i];
                fBurstTime2[i] = fBurstTime[i];
            }
            printf("\n\n\n");
            
        }

        // function to calculate the waiting time of each process
        void waitingTime(int n);

        // function to calculate the turn around time of each process
        void turnAroundTime(int n);

        // function to calculate the average wairting time of all the processes
        void averageWaitingTime(int n);

};





// function to calculate the waiting time of each process
        void SJF::waitingTime(int n) {
            double waitTime = 0;

            for (int i = 0; i < n; i++) {
            int shortest_index = min_element(fBurstTime, fBurstTime+n) - fBurstTime;
             cout << "Waiting time for the P" << shortest_index << " is " << waitTime << endl;
                printf("\n\n");
                waitTime = waitTime + fBurstTime[shortest_index];
                fBurstTime[shortest_index] = 3402823000000000000;
            }

            
        }





// function to calculate the turn around time of each process
        void SJF::turnAroundTime(int n) {
            
                float turnaround = 0;

            for (int i = 0; i < n; i++) {
            int shortest_index = min_element(fBurstTime1, fBurstTime1+n) - fBurstTime1;
            turnaround = turnaround + fBurstTime1[shortest_index];
             cout << "Turnaround time for the P" << shortest_index << " is " << turnaround << endl;
                printf("\n\n");
                fBurstTime1[shortest_index] = 3402823000000000000;
            }
            
        }





// function to calculate the average wairting time of all the processes
        void SJF::averageWaitingTime(int n) {
           
            float sum = 0;
            float waitTime = 0;

            for (int i = 0; i < n-1; i++) {
            int shortest_index = min_element(fBurstTime2, fBurstTime2 + n) - fBurstTime2;
            waitTime = waitTime + fBurstTime2[shortest_index];
             sum = sum + waitTime;
            fBurstTime2[shortest_index] = 3402823000000000000;
            }
             cout << "\n Average waiting time for the given processes is " << sum/n << endl;
            printf("\n\n");
        
        }







int main() {

    SJF obj1(5);
    obj1.waitingTime(5);
    obj1.turnAroundTime(5);
    obj1.averageWaitingTime(5);
    
    



    return 0;
}