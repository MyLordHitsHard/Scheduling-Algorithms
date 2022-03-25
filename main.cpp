#include <iostream>
#include "Scheduling.hpp"

int main() {

    cout << "\n\nEnter the number of processes: " << endl;
    int number_of_processes;
    cin >> number_of_processes;
    SA obj1(number_of_processes);
    int choice;
    do {
        
        cout << "\n\nChoose what you want to calculate: " << endl;
        

        cout << "\n\nFor calculating waiting time of each process, choose 1." << endl;
        cout << "\n\nFor calculating turnaround time of each process, choose 2." << endl;
        cout << "\n\nFor calculating average waiting time, choose 3." << endl;
        cout << "\n\nFor exiting the program, choose 4." << endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            
            cout << "\n\nChoose with scheduling algorithm you are going to use." << endl;
            int choice1;
            cout << "\n\nFor using First Come First Serve (FCFS), enter 1." << endl;
            cout << "\n\nFor using Shortest Job First (SJF), enter 2." << endl;
            cout << "\n\nFor using Priority Scheduling (PS), enter 3." << endl;
            cout << "\n\nFor using Round Robin Scheduling (RR), enter 4." << endl;
            cin >> choice1;
            obj1.waitingTime(choice1);
            break;
        
        
        

        case 2:
            
            cout << "\n\nChoose with scheduling algorithm you are going to use." << endl;
            int choice2;
            cout << "\n\nFor using First Come First Serve (FCFS), enter 1." << endl;
            cout << "\n\nFor using Shortest Job First (SJF), enter 2." << endl;
            cout << "\n\nFor using Priority Scheduling (PS), enter 3." << endl;
            cout << "\n\nFor using Round Robin Scheduling (RR), enter 4." << endl;
            cin >> choice2;
            obj1.turnaroundTime(choice2);
            break;
        
        
        

        case 3:
            
            cout << "\n\nChoose with scheduling algorithm you are going to use." << endl;
            int choice3;
            cout << "\n\nFor using First Come First Serve (FCFS), enter 1." << endl;
            cout << "\n\nFor using Shortest Job First (SJF), enter 2." << endl;
            cout << "\n\nFor using Priority Scheduling (PS), enter 3." << endl;
            cout << "\n\nFor using Round Robin Scheduling (RR), enter 4." << endl;
            cin >> choice3;
            obj1.averageWaitingTime(choice3);
            break;
        
        
        }

        

    } while (choice == 1 || choice == 2 || choice == 3);




return 0;
}