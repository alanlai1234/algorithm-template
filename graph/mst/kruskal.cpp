#include <bits/stdc++.h>
#define EB emplace_back
#define vci vector<int>
#define PII pair<int,int>
#define F first
#define S second
#define rep(X, a,b) for(int X=a;X<b;++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
#define LL long long

using namespace std;

int p[10010];

int fd(int x){
    if(p[x]==x) return x;
    return fd(p[x]);
}

bool un(int a, int b){
    int f1=fd(a), f2=fd(b);
    if(f1==f2) return false;
    p[f2]=f1;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, w;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> gh(n, pair<int, pair<int,int>>());
    //pair: {weight, {node1, node2}}

    rep(i,0,m){
        cin>>u>>v>>w;
        gh.EB(make_pair(w, make_pair(u, v)));
    }
    sort(ALL(gh));

    //init
    rep(i, 0, n) p[i]=i;

    LL cost=0, edge=0;
    for(auto v:gh){
        if(un(v.S.F, v.S.S)){
            edge++;
            cost+=v.F;
        }
    }

    if(edge<n-1) cout << -1 << NL;
    else cout << cost << NL;
}