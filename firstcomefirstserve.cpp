#include<bits/stdc++.h>
using namespace std;

struct process_struct
{
    int process_id;
    int arrival_time;
    int cup_burst_time;
    int completion,waiting_time,turn_around_time,response_time,startingtime;

} process[100];

bool comparatorAT(struct process_struct a, struct process_struct b)
{

    int x=a.arrival_time;
    int y=b.arrival_time;
    if(x>y)
        return false;
    return true;
}
bool comparatorPID(struct process_struct a, process_struct b)
{
    int x=a.process_id;
    int y=b.process_id;
    return x<y;
}

int main()
{
    int n;
    cout<<"Enter Total Number of Process: ";
    cin>>n;
    float sum_turn_aroundtime=0;
    float sum_waiting_time=0;
    float sum_response_time=0;
    int length_cycle;
    int total_ideal_time=0;
    float cpu_utilization;

    cout<<fixed<<setprecision(2);

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Process "<<i<<"Arrival Time: ";
        cin>>process[i].arrival_time;
        process[i].process_id=i;
    }

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Process "<<i<<"Burst Time: ";
        cin>>process[i].cup_burst_time;
    }

    sort(process,process+n,comparatorAT);

    for(int i=0; i<n; i++)
    {
        process[i].startingtime = (i==0) ? process[i].arrival_time : max(process[i].arrival_time, process[i-1].completion);
        process[i].completion = process[i].startingtime + process[i].cup_burst_time;
        process[i].turn_around_time = process[i].completion - process[i].arrival_time;
        process[i].waiting_time = process[i].turn_around_time - process[i].cup_burst_time;
        process[i].response_time = process[i].waiting_time;


        sum_turn_aroundtime += process[i].turn_around_time;
        sum_waiting_time += process[i].waiting_time;
        sum_response_time += process[i].response_time;
        total_ideal_time += (i==0) ? 0 : (process[i].startingtime - process[i-1].completion);

    }

    length_cycle = process[n-1].completion - process[0].startingtime;
    sort(process,process+n, comparatorPID);

    cout<<"\nProcess no. \tAT\tCPU Burst Time\tCT\t\TAT\tWT\tRT\n";
    for(int i=0; i<n; i++)
        cout<<i<<"\t\t"<<process[i].arrival_time<<"\t"<<process[i].cup_burst_time<<"\t\t"<<process[i].completion<<"\t"<<process[i].turn_around_time<<"\t"<<process[i].waiting_time<<"\t"<<process[i].response_time<<endl;
    cout<<endl;

    cpu_utilization = (float)(length_cycle - total_ideal_time)/ length_cycle;

    cout<<"\nAverage Turn Around time= "<< sum_turn_aroundtime/n;
    cout<<"\nAverage Waiting Time= "<<sum_waiting_time/n;
    cout<<"\nAverage Response Time= "<<sum_response_time/n;
    cout<<"\nThroughput= "<<n/(float)length_cycle;
    cout<<"\nCPU Utilization(Percentage)= " << cpu_utilization*100;

}
