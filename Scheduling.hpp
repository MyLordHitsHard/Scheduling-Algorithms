#ifndef SCHEDULING_H
#define SCHEDULING_H


#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;


// for sorting using burst time
bool sortbysec(const tuple<int, float, int>& a,  const tuple<int, float, int>& b);



// for sorting using priority
bool sortbyth(const tuple<int, float, int>& a, const tuple<int, float, int>& b);


class SA {

    private:
        vector<tuple<int, float, int>> processes;
        int n;


    public:

    // Constructor 
        SA(int nu) {

            n = nu;
            for (int i = 0; i < n; i++) {
                float temp1;
                int temp2;
                cout << "Enter the Burst time of P" << i << ": " << endl;
                cin>>temp1;
                cout << "Enter the Priority of P" << i << ": " << endl;
                cin>>temp2;
                processes.push_back(make_tuple(i, temp1, temp2));

            }
        }
    

        // Waiting time function
        void waitingTime (int choice);

        // Average Waiting time
        void averageWaitingTime(int choice);

        // Turnaround Time
        void turnaroundTime(int choice);
};




#endif