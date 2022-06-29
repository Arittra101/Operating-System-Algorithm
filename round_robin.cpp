
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


#define pii  pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define SORT(v) sort(v.begin(),v.end());
#define R_SORT(v) sort(v.begin(),v.end(),greater<lli>());
#define en "\n"

struct process
{
    lli  busrst;
    lli arrTime ;
    lli process_no;
    lli done=0;
};
struct grant
{

    lli process_no;
    lli grn_val=0;

};

arrivel_sort(process a, process b)
{
    return a.arrTime<b.arrTime;
}
int main()
{

    vector<process>v;
    cout<<"Number of Process In the city"<<endl;
    lli n;
    cin>>n;
    cout<<"Input Time quantam"<<endl;
    lli qnt;
    cin>>qnt;

    cout<<"Input Process No Arrival time and Burst Time"<<endl;
    for(lli i=0; i<n; i++)
    {
        lli pno,a,b;
        cin>>pno>>a>>b;
        process p;
        p.arrTime=a;
        p.busrst=b;
        p.process_no=pno;
        v.pb(p);
    }
    cout<<endl;

    sort(v.begin(),v.end(),arrivel_sort);

    for(lli i=0; i<n; i++)
    {

        v[i].process_no =i;
    }
     for(auto it : v)
    {
        cout<<it.process_no<<" ";
        cout<<it.arrTime<<" ";
        cout<<it.busrst<<" ";


        cout<<endl;
    }


    queue<lli>ready;
    ready.push(v[0].process_no); //enter p1


    vector<grant>grn_vector;

    lli sm=0; //grant chart value = ;


    //grant chart work
    grant gnt;
    v[0].done = 1;

    lli prc_cnt=1;

//    gnt.grn_val +=sm;
//    grn_vector.pb(gnt);

    lli k=0;
    lli i;
    while(ready.size()!=0 || prc_cnt<n)
    {
        k++;
        cout<<"Queue size "<<" "<<ready.size()<<"And PRc cnt "<<prc_cnt<<endl;
        i =  ready.front();
        cout<<"Process "<<i<<" "<<endl;
        ready.pop();

        cout<<"I value "<<i<<endl;
        lli brst = v[i].busrst;          //taking burst time after decrement
        if(brst<=qnt)
        {
            v[i].busrst-=brst;
            sm+=brst;
        }
        else
        {
            v[i].busrst-=qnt;
            sm+=qnt;                       //burst decrement in vector
        }






        //working with process;

        //now finding processq
        for( lli j=0; j<v.size(); j++)
        {
            cout<<"Sum "<<sm<<endl;
            lli arv = v[j].arrTime;
            cout<<"New Process "<<j<<" "<<arv<<endl;
            if(arv<=sm &&  v[j].done != 1)
            {
                ready.push(v[j].process_no);
                cout<<"push process "<<" "<<v[j].process_no<<" "<<endl;
                v[j].done=1;
                prc_cnt++;

            }
        }
        cout<<i<<" "<<"Own CPU time "<<v[i].busrst<<endl;
        if(v[i].busrst>0)
        {
            cout<<"push process Own process"<<" "<<v[i].process_no<<" "<<endl;
            ready.push(v[i].process_no);
        }


        //  cout<<ready.size()<<endl;
//



        //checking burst is zero or not
//        lli cnt=0;
//        for(i=0;i<v.size();i++)
//        {
//            if(v[i].busrst==0) cnt++;
//            if(cnt==v.size()) break;
//        }

        grant gnt;                              //grant chart structure
        gnt.process_no = v[i].process_no;
        gnt.grn_val =sm;
        grn_vector.pb(gnt);
    }

    cout<<endl;
    cout<<endl;
    for(auto it : grn_vector)
    {

        //  cout<<it.process_no<<" ";
        cout<<it.grn_val<<" ";
        cout<<endl;
    }

}



