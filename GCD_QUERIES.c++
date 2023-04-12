#define ll long long int
#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define s(a) (ll)a.size()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}
vector<multiset<ll>> present(1e6+1);
vector<ll> spf;
void fn(){
    spf.assign(1e6+1,0);
    loop(i,0,1e6+1) spf[i] = i;
    loop(i,2,1e6+1){
        if(spf[i] == i) {
            for(int j = i;j<=1e6;j+=i)  spf[j] = min(spf[j],i);
        }
    }
}



vector<ll> prime_fact(ll n){
    vector<ll> ans;
    while(n>1)  {
        int j = spf[n];
        while(n%j == 0) n/=j;
        ans.pb(j);
    }
    return ans;
}

void solve(){
    ll n;   cin>>n;
    vector<ll> v(n);    in(v,n);
    present[1].clear();
    set<ll> used;
    loop(i,0,n){
        present[1].insert(v[i]);
        vector<ll> fact = prime_fact(v[i]);
        for(auto j:fact)    {
            present[j].insert(v[i]);
            used.insert(j);
        }
    }
    ll q;   cin>>q; 
    while(q--){
        ll x;   cin>>x;
        vector<ll> fact = prime_fact(x);
        ll mi = INT_MAX;
        for(auto i:fact)    
            if(present[i].size() > 0)    mi = min(mi,*present[i].begin());
        if(mi == INT_MAX){
            mi = *present[1].begin();
        }
        fact = prime_fact(mi);
        present[1].erase(present[1].find(mi));
        for(auto i:fact)    {
            present[i].erase(present[i].find(mi));
        }
        cout<<mi<<' ';
    }
    cout<<endl;
    for(auto i:used)    present[i].clear();
}


int main()
{
    fast
    fn();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}