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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

vector<int> g[30010], ht, node, log_2;
int last[30010];
vector<vector<LL>> sp;

void dfs(int depth, int e){
    for(auto a:g[e]){
        last[e]=ht.size();
        ht.EB(depth);
        node.EB(e);
        dfs(depth+1, a);
    }
    last[e]=ht.size();
    ht.EB(depth);
    node.EB(e);
}

LL query(int l, int r){
    int k=log_2[r-l+1];
    if(ht[sp[l][k]]>ht[sp[r-(1<<k)+1][k]]) return sp[r-(1<<k)+1][k];
    return sp[l][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL n, q, a, b;
    cin>>n>>q;
    rep(i,1,n+1){
        while(cin>>a){
            if(a==0) break;
            g[i].EB(a);
        }
    }

    //eulerian tour
    dfs(1, 1);

    //sparse table
    LL len=ht.size();
    log_2.resize(len+1);
    sp.resize(len+1, vector<LL>(30));
    log_2[1]=0;
    for(int i=2;i<=len;++i) log_2[i]=log_2[i/2]+1;
    rep(i,0,len) sp[i][0]=i;
    for(int j=1;j<=log_2[len];++j){
        for(int i=0;i+(1<<j)<=len;++i){
            if(ht[sp[i][j-1]]>ht[sp[i+(1<<(j-1))][j-1]]) sp[i][j]=sp[i+(1<<(j-1))][j-1];
            else sp[i][j]=sp[i][j-1];
        }
    }

    while(q--){
        cin>>a>>b;
        int pos=query(min(last[a], last[b]), max(last[a], last[b]));
        cout<<node[pos]<<" "<<ht[last[a]]-ht[pos]+ht[last[b]]-ht[pos]<<NL;
    }
}