#include <bits/stdc++.h>
#include <queue>
#define pb push_back
#define F first
#define S second
#define rep(X, a,b) for(int X=a;X<b;++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
using namespace std;
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef long long ll;

vector<ll> adj[100010], re_adj[100010], stamp;
int visit[100010];
ll scc[100010];

void dfs1(ll v){
    visit[v]=1;
    for(auto a:adj[v]){
        if(visit[a]) continue;
        dfs1(a);
    }
    stamp.pb(v);
}

void dfs2(ll v, ll cnt){
    visit[v]=1;
    scc[v]=cnt;
    for(auto a:re_adj[v]){
        if(visit[a]) continue;
        dfs2(a, cnt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, a, b;
    cin>>n>>m;
    rep(i,0,m){
        cin>>a>>b;
        adj[a].pb(b);
        re_adj[b].pb(a);
    }
    memset(visit, 0, sizeof(visit));
    for(int i=1;i<=n;++i){
        if(!visit[i]) dfs1(i);
    }
    memset(visit, 0, sizeof(visit));
    ll cnt=0;
    for(int i=stamp.size()-1;i>=0;--i){
        if(!visit[stamp[i]]) dfs2(stamp[i], ++cnt);
    }
    cout<<cnt<<NL;
    rep(i,1,n+1) cout<<scc[i]<<" ";
    cout<<NL;
}