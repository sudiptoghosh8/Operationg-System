#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,i,j,k,n,l,m[10],p[10],po[20],flag,z,y,temp,temp1;
    cout<<"enter memory partition:\t";
    cin>>n;
    cout<<"\nenter memory size for\n";
    for(i=1; i<=n; i++)
    {
        cout<<"\npartition "<<i<<" :\t";
        cin>>m[i];
        po[i]=i;
    }
    cout<<"\nenter process:\t";
    cin>>j;
    cout<<"\nenter memory size for\n";
    for(i=1; i<=j; i++)
    {
        cout<<"\nprocess "<<i<<" :\t";
        cin>>p[i];
    }
    cout<<"\n******** welcome to menu driven program of memory management**********\n1.first fit\n2.best fit\n3.worst fit\nenter choice:\t";
    cin>>c;
    switch(c)
    {
    case 1:
        for(i=1; i<=j; i++)
        {
            flag=1;
            for(k=1; k<=n; k++)
            {
                if(p[i]<=m[k])
                {
                    cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                    m[k]=m[k]-p[i];
                    break;
                }
                else
                {
                    flag++;
                }
            }
            if(flag>n)
            {
                cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";
            }
        }
        break;
    case 2:
        for(y=1; y<=n; y++)
        {
            for(z=y; z<=n; z++)
            {
                if(m[y]>m[z])
                {
                    temp=m[y];
                    m[y]=m[z];
                    m[z]=temp;
                    temp1=po[y];
                    po[y]=po[z];
                    po[z]=temp1;
                }
            }
        }
        for(i=1; i<=j; i++)
        {
            flag=1;
            for(k=1; k<=n; k++)
            {
                if(p[i]<=m[k])
                {
                    cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                    m[k]=m[k]-p[i];
                    break;
                }
                else
                {
                    flag++;
                }
            }
            if(flag>n)
            {
                cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";
            }
        }
        break;
    case 3:
        for(y=1; y<=n; y++)
        {
            for(z=y; z<=n; z++)
            {
                if(m[y]<m[z])
                {
                    temp=m[y];
                    m[y]=m[z];
                    m[z]=temp;
                    temp1=po[y];
                    po[y]=po[z];
                    po[z]=temp1;
                }
            }
        }
        for(i=1; i<=j; i++)
        {
            flag=1;
            for(k=1; k<=n; k++)
            {
                if(p[i]<=m[k])
                {
                    cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                    m[k]=m[k]-p[i];
                    break;
                }
                else
                {
                    flag++;
                }
            }
            if(flag>n)
            {
                cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";
            }
        }
        break;
    }

    return 0;
}
