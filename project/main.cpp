#include <bits/stdc++.h>
using namespace std;

int buyer_num = 0;

string buyers[] = {"BUYER001","BUYER002","BUYER003","BUYER004","BUYER0005"};

struct WorkTime{
    string start, finish;
};

struct Activitiy
{
    int task_num, start, finish;
    string time[2];
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
    if (n == 0){
        return;
    }

    int tasks_available[n];

    for(int y =0;y<n;y++){
        tasks_available[y] = 1;
    }

    cout << "Activities selected for buyer " << buyers[buyer_num] << ": " << endl;

    // FIRST TASK
    int i = 0;
    cout << "Your task: " << arr[i].task_num << " starts at " << arr[i].time[0] << " and ends at " << arr[i].time[1] << "." << endl ;
    tasks_available[i] = 0;



    for (int j = 1; j < n; j++){
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (arr[j].start >= arr[i].finish){
          cout << "Your task: " << arr[j].task_num << " starts at " << arr[j].time[0] << " and ends at " << arr[j].time[1] << "." << endl ;
          i = j;
          // when task selected set task availability to 0
          tasks_available[j] = 0;
      }
    }

    int counter = 0;
    cout << endl;

    if (n != 1){
        cout << "To be distributed:"<< endl;
    }

    // Checking tasks availability
    for(i=0;i<n;i++){
        if (tasks_available[i] == 1){
            cout << "Task: " << arr[i].task_num << " unassigned." << endl;
            counter += 1;
        }
    }

    Activitiy rest_arr[counter];

    counter = 0;
    for(i=0;i<n;i++){
        if (tasks_available[i] == 1){
            rest_arr[counter].task_num = arr[i].task_num;
            rest_arr[counter].start = arr[i].start;
            rest_arr[counter].finish = arr[i].finish;
            rest_arr[counter].time[0] = arr[i].time[0];
            rest_arr[counter].time[1] = arr[i].time[1];
            counter += 1;
        }
    }

    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;

    buyer_num += 1;

    printMaxActivities(rest_arr, counter);

}

// Driver program
int main()
{
    Activitiy arr[] = { {1, 0, 4,{"7:00 AM","11:00 AM"}},
                        {2, 1, 2,{"8:00 AM","9:00 AM"}},
                        {3, 2, 4,{"9:00 AM","11:00 AM"}},
                        {4, 3, 5,{"10:00 AM","12:00 AM"}},
                        {5, 3, 6,{"10:00 AM","1:00 PM"}},
                        {6, 5, 6,{"12:00 AM","1:00 PM"}},
                        {7, 5, 7,{"12:00 AM","2:00 PM"}},
                        {8, 6, 7,{"1:00 PM","2:00 PM"}},
                        {9, 7, 9,{"2:00 PM","4:00 PM"}},
                        {10, 8, 10,{"3:00 PM","5:00 PM"}}
                        };

    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}
