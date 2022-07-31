#include <bits/stdc++.h>
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

vector<int> adj[200010];
set<int> nd[200010];
int cnt[200010];

void dfs(int v, int par){
    for(auto a:adj[v]){
        if(a!=par){
            dfs(a, v);
            if(nd[a].size()>nd[v].size()) swap(nd[a], nd[v]);
            for(auto tmp:nd[a]) nd[v].insert(tmp);
        }
    }
    cnt[v]=nd[v].size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a, b;
    rep(i,1,n+1){
        cin>>a;
        nd[i].insert(a);
    }
    rep(i,0,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    rep(i,1,n+1) cout<<cnt[i]<<" ";
    cout<<NL;
}