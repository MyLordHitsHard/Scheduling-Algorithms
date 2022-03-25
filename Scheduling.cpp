#include "Scheduling.hpp"


// for sorting using burst time
bool sortbysec(const tuple<int, float, int>& a,  const tuple<int, float, int>& b)
{
    return (get<1>(a) < get<1>(b));
}

// for sorting using priority
bool sortbyth(const tuple<int, float, int>& a, const tuple<int, float, int>& b)
{
    return (get<2>(a) < get<2>(b));
}


// Waiting time function
void SA::waitingTime(int choice)
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
        vector<int> bTime;

        vector<int> wTime;
        for (int i = 0; i < n; i++)
        {

            bTime.push_back(get<1>(processes[i]));
        }

        int totalP = n, compP = 0;
        int overallTime = 0;
        int j = 0;
        while (compP != totalP)
        {

            if (bTime[j] <= quantum && bTime[j] != 0)
            {
                overallTime = overallTime + bTime[j];
                wTime.push_back(overallTime - get<1>(processes[j]));
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
void SA::averageWaitingTime(int choice)
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
        vector<int> bTime;

        vector<int> wTime;
        for (int i = 0; i < n; i++)
        {

            bTime.push_back(get<1>(processes[i]));
        }

        int totalP = n, compP = 0;
        int overallTime = 0;
        int j = 0;
        while (compP != totalP)
        {

            if (bTime[j] <= quantum && bTime[j] != 0)
            {
                overallTime = overallTime + bTime[j];
                wTime.push_back(overallTime - get<1>(processes[j]));
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
void SA::turnaroundTime(int choice)
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
        vector<int> bTime;

        vector<int> wTime;
        for (int i = 0; i < n; i++)
        {

            bTime.push_back(get<1>(processes[i]));
        }

        int totalP = n, compP = 0;
        int overallTime = 0;
        int j = 0;
        while (compP != totalP)
        {

            if (bTime[j] <= quantum && bTime[j] != 0)
            {
                overallTime = overallTime + bTime[j];
                wTime.push_back(overallTime);
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