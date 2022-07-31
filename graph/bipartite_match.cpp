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

//lm: left node pairs, right node pairs, done:visited
vector<int> lm, rm, done;
vector<vector<int>> lg;// edges from the left

bool dfs(int nd){
    done[nd]=1;
    for(auto a:lg[nd]){
        if(rm[a]==-1 || (!done[rm[a]] && dfs(rm[a]))){
            lm[nd]=a;
            rm[a]=nd;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; // left nodes:n, right nodes:m, edges:k
    cin>>n>>m>>k;
    lm.resize(n, -1);
    rm.resize(m, -1);
    done.resize(n);
    lg.resize(n);
    
    int a, b;
    rep(i,0,k){
        cin>>a>>b;
        a--, b--;
        lg[a].EB(b);
    }
    
    LL ans=0;
    rep(i,0,n){
        fill(ALL(done), 0);
        if(dfs(i)) ans++; //有增廣路徑
    }
    cout<<ans<<NL;
}