#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define endl '\n'
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int ddx[8]={-1, 0, 1, 0, 1, -1, 1, -1};
const int ddy[8]={0, 1, 0, -1, -1, 1, 1, -1};
const int INF=0x3f3f3f3f;
const int N=5e6+10;
const int M=1010;
int n,m;
int mod,fa[N],sz[N];
ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1){ans*=a;ans=ans%mod;}a=a*a;a%=mod;b>>=1;}return ans;}
// ll gcd(ll a,ll b){ll t=a%b;while(t){a=b;b=t;t=a%b;}return b;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void init() {for(int i=1;i<=n;i++) {fa[i]=i;sz[i]=1;}}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int a,int b) {int x=find(a);int y=find(b);if(x==y) {return;}else{sz[y]+=sz[x];fa[x]=y;}}
bool ask(int a,int b) {return find(a)==find(b);}
int a[N];
void solve()
{
	
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}