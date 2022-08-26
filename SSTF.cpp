#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;

#define pii pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" \
                 << "\n";
#define no cout << "NO" \
                << "\n";
#define SORT(v) sort(v.begin(), v.end());
#define R_SORT(v) sort(v.begin(), v.end(), greater<lli>());
#define en "\n"
lli s;

bool SORT1(pair<lli, lli> p1, pair<lli, lli> p2)
{
    return p1.first < p2.first;
}
void solve()
{

    vi v;
    vi seq;
    map<lli, lli> mp;

    cout << "Number of Heads: " << endl;
    lli head;
    cin >> head;
    cout << "Cylinder Requests: " << endl;
    for (i = 0; i < head; i++)
    {
        lli x;
        cin >> x;
        v.pb(x);
    }
    cout << "Enter the head position " << endl;
    lli crnHd;
    cin >> crnHd;

    v.pb(crnHd);

  

    SORT(v);

   // for(auto it : v) cout<<it<<" ";

    auto it = find(v.begin(), v.end(), crnHd);

    seq.pb(crnHd);
    // cout << it - v.begin() << endl;
    lli head_pos = it - v.begin();
    lli visit_count = 0;
    lli sm = 0;
    mp[crnHd] = 1;
    while (visit_count != head)
    {
        visit_count++;
        
        lli mn = INT_MAX;
        lli dis, val;
        for (j = 0; j < v.size(); j++)
        { 
            if (mp[v[j]] == 0)
            {
                //cout<<"D";
                dis = abs(crnHd - v[j]);
                if (dis<=mn)
                {
                    mn = dis;
                    val = v[j];
                }
            }
        }
        sm += mn;
        seq.pb(val);
        crnHd=val;
        mp[val] = 1;
       // cout << "Sum- >" << sm << " Val-> " << val << endl;
    }

     cout<<"Cylinder Serving Order: "<<endl;
     for(auto it : seq)
     {
        cout<<it<<"->";
     }
    
    cout<<endl<<"Total Cylinder movement: "<<sm<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    // cout<<"Case "<<l<<": ";
}