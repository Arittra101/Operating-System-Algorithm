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
    lli sm = 0;

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
    
    lli first_head = 0;
    v.pb(first_head);
    lli last_req = 199;
    v.pb(last_req);


    cout << "Enter the head position " << endl;

    lli crnHd;
    cin >> crnHd;
    v.pb(crnHd);

    SORT(v);
    auto it = find(v.begin(), v.end(), crnHd);

    cout << "Cylinder Serving Order: " << endl;
    cout << crnHd;

    lli head_pos = it - v.begin();

    for (i = head_pos+1; i < v.size(); i++)
    {
        cout << "-> ";
        sm += abs(crnHd - v[i]);

        cout << v[i] << " ";
        crnHd = v[i];
    }
    
    for (i = 0; i < head_pos; i++)
    {
        cout << "-> ";
        sm += abs(crnHd - v[i]);

        cout << v[i] << " ";
        crnHd = v[i];
    }
    cout << endl<< "Total Cylinder movement: " << sm << endl;
}
int main()
{
  

    solve();

    // cout<<"Case "<<l<<": ";
}