#include <bits/stdc++.h>

using namespace std;

// creating class for Priority Scheduling

class PS {

// declaring data members
    private:
        int numberOfProcess[1000] = {0};
        float fBurstTime[1000] = {0};
        int iPriority[1000] = {0};




// declaring member functions
    public:

        // class constructor
        PS(int n) {

            printf("\n\n\n");
            for (int i = 0; i < n; i++) {
                numberOfProcess[i] = i;
                cout << "Enter the burst time for process " << i<<endl;
                cin >> fBurstTime[i];
                if (i == 0) {
                    cout << "\n\nLower the number, higher the priority. (0 is the highest priority)\n\n" << endl;
                }
                cout << "Enter the priority for the process " << i<<endl;
                cin >> iPriority[i];
            }
            
            printf("\n\n\n");
            
        }


        // function to calculate the waiting time of each process
        void waitingTime(int n);
       

        // function to calculate the turn around time of each process
        void turnAroundTime() {
            
        }

        // function to calculate the average wairting time of all the processes
        void averageWaitingTime() {
            
        }

};




 // function to calculate the waiting time of each process
        void PS :: waitingTime(int n) {
            
            double waitTime = 0;

            for (int i = 0; i < n; i++) {
                
                for (int j = 0; j < n; j++) {

                    if (iPriority[j] == i) {
                        cout << "Waiting time for the P" << j << " is " << waitTime<<endl;
                        waitTime = waitTime + fBurstTime[j];
                    }
                
                }
            }

            
        }


int main() {

    PS obj1(4);
    obj1.waitingTime(4);
    



    return 0;
}