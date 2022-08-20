#include <bits/stdc++.h>
using namespace std;

const int N=100005;

struct process
{
    int priority;
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
};

int n;
process P[N];

bool operator<(process A, process B)
{
    if(A.priority < B.priority)
    {
        return true;
    }
    if(A.priority == B.priority)
    {
        return A.arrival_time < B.arrival_time;
    }
    return false;
}


void Priority(void)
{
    sort(P, P+n);
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;

    for(int i=0; i<n; i++)
    {
        P[i].finishing_time = P[i-1].finishing_time + P[i].burst_time;
        P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
        P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;

        total_waiting_time += P[i].waiting_time;
        total_turn_around_time += P[i].turn_around_time;
    }
    cout<<fixed<<setprecision(2);
    cout<<"Average Waiting Time: "<<(total_waiting_time/n)<<"\n";
    cout<<"Average Turn Around Time: "<<(total_turn_around_time/n)<<"\n";
    return;
}

int main()
{
    cout<<"Number of P: ";
    cin>>n;

    cout<<"Process Ids:\n";
    for(int i=0; i<n; i++) cin>>P[i].id;

    cout<<"Process Burst Times:\n";
    for(int i=0; i<n; i++) cin>>P[i].burst_time;

    cout<<"Process Arrival Times:\n";
    for(int i=0; i<n; i++) cin>>P[i].arrival_time;

    cout<<"Process Priorities:\n";
    for(int i=0; i<n; i++) cin>>P[i].priority;

    Priority();

    return 0;
}
