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


void solve(){
    ll n,m,k;   cin>>n>>m>>k;
    vector<vector<ll>> v(n,vector<ll>(m));
    loop(i,0,n) loop(j,0,m) cin>>v[i][j];
    vector<vector<ll>> vec = v;
    loop(i,1,n) v[i][0]+=v[i-1][0];
    loop(j,1,m) v[0][j]+=v[0][j-1];
    loop(i,1,n) loop(j,1,m) v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    ll ans = INT_MAX;
    loop(i,0,n){
        loop(j,0,m){
            if(!vec[i][j])  continue;
            ll l = 0,r = max(n,m);
            while(l<=r){
                ll mid = (l+r)/2;
                ll x = min(n-1,i+mid),y = min(m-1,j+mid);
                ll sum = v[x][y];
                if(i-mid>0) sum-=v[i-mid-1][y];
                if(j-mid>0) sum-=v[x][j-mid-1];
                if(i-mid>0 && j-mid > 0)    sum+=v[i-mid-1][j-mid-1];
                if(sum>=k+1)    r = mid-1,ans = min(ans,mid);
                else l = mid+1;
            }
        }
    }
    if(ans == INT_MAX)  ans = -1;
    cout<<ans<<endl;
}


int main()
{
    fast
    int t; cin>>t;
    
    while(t--) solve();
    return 0;
}