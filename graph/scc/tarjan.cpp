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

vector<int> gh[100010], st;
int id[100010], low[100010], onstack[100010]={0}, cnt=0, cur=0;//cnt:SCC cnt, cur:current id

void dfs(int nd){
    st.push_back(nd);
    onstack[nd]=1;
    id[nd]=cur;
    low[nd]=cur;
    cur++;
    for(auto a:gh[nd]){
        if(id[a]==-1) dfs(a);
        if(onstack[a]) low[nd]=min(low[nd], low[a]);
    }

    if(id[nd]==low[nd]){
        cnt++;
        while(!st.empty()){
            int tmp=st.back();
            onstack[tmp]=0;
            low[tmp]=cnt;
            st.pop_back();
            if(tmp==nd) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    rep(i,0,m){
        cin>>a>>b;
        gh[a-1].EB(b-1);
    }
    
    memset(id, -1, sizeof(id));//-1 represent unvisited
    rep(i,0,n){
        if(id[i]==-1) dfs(i);
    }
}