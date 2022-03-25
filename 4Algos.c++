#include <bits/stdc++.h>
#include <tuple>
using namespace std;

// for sorting using burst time
bool sortbysec(const tuple<int, float, int> &a, const tuple<int, float, int> &b)
{
    return (get<1>(a) < get<1>(b));
}

// for sorting using priority
bool sortbyth(const tuple<int, float, int> &a, const tuple<int, float, int> &b)
{
    return (get<2>(a) < get<2>(b));
}

class SA
{

private:
    vector<tuple<int, float, int>> processes;

public:
    // Constructor
    SA(int n)
    {

        for (int i = 0; i < n; i++)
        {
            float temp1;
            int temp2;
            cout << "Enter the Burst time of P" << i << ": " << endl;
            cin >> temp1;
            cout << "Enter the Priority of P" << i << ": " << endl;
            cin >> temp2;
            processes.push_back(make_tuple(i, temp1, temp2));
        }
    }

    // Waiting time function
    void waitingTime(int n, int choice)
    {
        switch (choice)
        {

        case 1:

        {
            // for FCFS
            double dTimeLen = 0;
            for (int i = 0; i < n; i++)
            {

                cout << "\nWaiting time for the P" << i << " is " << dTimeLen << endl;

                dTimeLen = dTimeLen + get<1>(processes[i]);
            }
            printf("\n\n");
            break;
        }

        case 2:

        {
            // for SJF
            sort(processes.begin(), processes.end(), sortbysec);
            double dTimeLen1 = 0;
            for (int i = 0; i < n; i++)
            {

                cout << "\nWaiting time for the P" << i << " is " << dTimeLen1 << endl;

                dTimeLen1 = dTimeLen1 + get<1>(processes[i]);
            }
            printf("\n\n");
            break;
        }

        case 3:

        {
            // for PS with same arrival time
            sort(processes.begin(), processes.end(), sortbyth);
            double dTimeLen2 = 0;
            for (int i = 0; i < n; i++)
            {

                cout << "\nWaiting time for the P" << i << " is " << dTimeLen2 << endl;

                dTimeLen2 = dTimeLen2 + get<1>(processes[i]);
            }
            printf("\n\n");
            break;
        }
        case 4:

        {
            // for RR
            cout << "Enter the quantum value: " << endl;
            int quantum;
            cin >> quantum;
            int bTime[n];

            int wTime[n];
            for (int i = 0; i < n; i++)
            {

                bTime[i] = get<1>(processes[i]);
            }

            int totalP = n, compP = 0;
            int overallTime = 0;
            int j = 0;
            while (compP != totalP)
            {

                if (bTime[j] <= quantum && bTime[j] != 0)
                {
                    overallTime = overallTime + bTime[j];
                    wTime[j] = (overallTime - get<1>(processes[j]));
                    bTime[j] = 0;
                    compP++;
                }

                else if (bTime[j] > quantum)
                {
                    overallTime = overallTime + quantum;
                    bTime[j] = bTime[j] - quantum;
                }

                if (j == n - 1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << "Waiting time for P" << i << " is " << wTime[i] << endl;
            }
            printf("\n\n");

            break;
        }
        }
    }

    // Average Waiting time
    void averageWaitingTime(int n, int choice)
    {
        switch (choice)
        {

        case 1:

        {
            // for FCFS
            double dTimeLen = 0;
            double sum = 0;
            for (int i = 0; i < n - 1; i++)
            {

                dTimeLen = dTimeLen + get<1>(processes[i]);
                sum = sum + dTimeLen;
            }

            cout << "\n\nThe average waiting time for the given processes is " << sum / n << " Units\n\n\n"
                 << endl;
            break;
        }

        case 2:

        {
            // for SJF
            sort(processes.begin(), processes.end(), sortbysec);
            double dTimeLen1 = 0;
            double sum = 0;
            for (int i = 0; i < n - 1; i++)
            {

                dTimeLen1 = dTimeLen1 + get<1>(processes[i]);
                sum = sum + dTimeLen1;
            }
            cout << "\n\nThe average waiting time for the given processes is " << sum / n << " Units\n\n\n"
                 << endl;
            break;
        }

        case 3:

        {
            // for PS with same arrival time
            sort(processes.begin(), processes.end(), sortbyth);
            double dTimeLen2 = 0;
            double sum = 0;
            for (int i = 0; i < n - 1; i++)
            {

                dTimeLen2 = dTimeLen2 + get<1>(processes[i]);
                sum = sum + dTimeLen2;
            }
            cout << "\n\nThe average waiting time for the given processes is " << sum / n << " Units\n\n\n"
                 << endl;
            break;
        }
        case 4:

        {
            // for RR
            cout << "Enter the quantum value: " << endl;
            int quantum;
            cin >> quantum;
            int bTime[n];

            int wTime[n];
            for (int i = 0; i < n; i++)
            {

                bTime[i] = get<1>(processes[i]);
            }

            int totalP = n, compP = 0;
            int overallTime = 0;
            int j = 0;
            while (compP != totalP)
            {

                if (bTime[j] <= quantum && bTime[j] != 0)
                {
                    overallTime = overallTime + bTime[j];
                    wTime[j] = (overallTime - get<1>(processes[j]));
                    bTime[j] = 0;
                    compP++;
                }

                else if (bTime[j] > quantum)
                {
                    overallTime = overallTime + quantum;
                    bTime[j] = bTime[j] - quantum;
                }

                if (j == n - 1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
            double dTimeLen3 = 0;
            for (int i = 0; i < n - 1; i++)
            {
                dTimeLen3 = dTimeLen3 + wTime[i];
            }

            cout << "\n\nThe average waiting time for the given processes is " << dTimeLen3 / n << " Units\n\n\n"
                 << endl;

            break;
        }
        }
    }

    // Turnaround Time
    void turnaroundTime(int n, int choice)
    {
        switch (choice)
        {

        case 1:

        {
            // for FCFS
            double dTimeLen = 0;
            for (int i = 0; i < n; i++)
            {

                dTimeLen = dTimeLen + get<1>(processes[i]);
                cout << "\nTurnaround time for the P" << i << " is " << dTimeLen << endl;
            }
            printf("\n\n");
            break;
        }

        case 2:

        {
            // for SJF
            sort(processes.begin(), processes.end(), sortbysec);
            double dTimeLen1 = 0;
            for (int i = 0; i < n; i++)
            {

                dTimeLen1 = dTimeLen1 + get<1>(processes[i]);
                cout << "\nTurnaround time for the P" << i << " is " << dTimeLen1 << endl;
            }
            printf("\n\n");
            break;
        }

        case 3:

        {
            // for PS with same arrival time
            sort(processes.begin(), processes.end(), sortbyth);
            double dTimeLen2 = 0;
            for (int i = 0; i < n; i++)
            {

                dTimeLen2 = dTimeLen2 + get<1>(processes[i]);
                cout << "\nTurnaround time for the P" << i << " is " << dTimeLen2 << endl;
            }
            printf("\n\n");
            break;
        }

        case 4:

        {
            // for RR
            cout << "Enter the quantum value: " << endl;
            int quantum;
            cin >> quantum;
            int bTime[n];

            int wTime[n];
            for (int i = 0; i < n; i++)
            {

                bTime[i] = get<1>(processes[i]);
            }

            int totalP = n, compP = 0;
            int overallTime = 0;
            int j = 0;
            while (compP != totalP)
            {

                if (bTime[j] <= quantum && bTime[j] != 0)
                {
                    overallTime = overallTime + bTime[j];
                    wTime[j] = (overallTime);
                    bTime[j] = 0;
                    compP++;
                }

                else if (bTime[j] > quantum)
                {
                    overallTime = overallTime + quantum;
                    bTime[j] = bTime[j] - quantum;
                }

                if (j == n - 1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << "Turnaround time for P" << i << " is " << wTime[i] << endl;
            }
            printf("\n\n");

            break;
        }
        }
    }
};

int main()
{

    cout << "\n\nEnter the number of processes: " << endl;
    int number_of_processes;
    cin >> number_of_processes;
    SA obj1(number_of_processes);
    int choice;
    do
    {

        cout << "\n\nChoose what you want to calculate: " << endl;

        cout << "\n\nFor calculating waiting time of each process, choose 1." << endl;
        cout << "\n\nFor calculating turnaround time of each process, choose 2." << endl;
        cout << "\n\nFor calculating average waiting time, choose 3." << endl;
        cout << "\n\nFor exiting the program, choose 4." << endl;
        cin >> choice;

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
            obj1.waitingTime(number_of_processes, choice1);
            break;

        case 2:

            cout << "\n\nChoose with scheduling algorithm you are going to use." << endl;
            int choice2;
            cout << "\n\nFor using First Come First Serve (FCFS), enter 1." << endl;
            cout << "\n\nFor using Shortest Job First (SJF), enter 2." << endl;
            cout << "\n\nFor using Priority Scheduling (PS), enter 3." << endl;
            cout << "\n\nFor using Round Robin Scheduling (RR), enter 4." << endl;
            cin >> choice2;
            obj1.turnaroundTime(number_of_processes, choice2);
            break;

        case 3:

            cout << "\n\nChoose with scheduling algorithm you are going to use." << endl;
            int choice3;
            cout << "\n\nFor using First Come First Serve (FCFS), enter 1." << endl;
            cout << "\n\nFor using Shortest Job First (SJF), enter 2." << endl;
            cout << "\n\nFor using Priority Scheduling (PS), enter 3." << endl;
            cout << "\n\nFor using Round Robin Scheduling (RR), enter 4." << endl;
            cin >> choice3;
            obj1.averageWaitingTime(number_of_processes, choice3);
            break;
        }

    } while (choice == 1 || choice == 2 || choice == 3);

    return 0;
}