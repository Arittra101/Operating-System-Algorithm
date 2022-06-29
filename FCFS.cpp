
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i,j;

#define pii  pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define SORT(v) sort(v.begin(),v.end());
#define R_SORT(v) sort(v.begin(),v.end(),greater<lli>());
#define en "\n"


void solve()
{
    lli n;
    cout<<"Number of Proecess"<<endl;
    cin>>n;
    vi aT,bT;
    vi wT (n,0);

    cout<<"Enter the arrival time"<<endl;
    for(i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        aT.pb(x);
    }
    cout<<"Enter the Burst time"<<endl;
    for(i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        bT.pb(x);
    }

    //waiting time
    wT[0]=0;
    lli sm = 0;
    cout<<wT[0]<<" ";
    for(i=1;i<n;i++)
    {
        sm+=bT[i-1];
        if(sm<aT[i]) sm+=abs(sm-aT[i]);
        wT[i] = sm-aT[i];
        cout<<wT[i]<<" ";
    }


}
int main()
{



        //cout<<"Case "<<l<<": ";
        solve();


    return 0;
}



