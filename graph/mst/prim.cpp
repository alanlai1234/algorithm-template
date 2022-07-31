#include <bits/stdc++.h>
#define EB emplace_back
#define vci vector<int>
#define PII pair<int,int>
#define F first
#define S second
#define rep(a,b) for(int i=a;i<b;++i)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
#define LL long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, w;
    cin>>n>>m;
    vector<vector<PII>> gh(n, vector<PII>());
    rep(0,m){
        cin>>u>>v>>w;
        gh[u].EB(make_pair(v, w));
        gh[v].EB(make_pair(u, w));
    //doesn't matter if there's multiple line between two nodes, the algorithm will take the least one
    }

    //init
    vector<int> done(n, 0);
    vector<int> parent(n);
    vector<int> dis(n, INT_MAX);
    dis[0]=0; //default dis[s] is 0
    
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({dis[0], 0});
    
    while(!pq.empty()){
        
        PII x=pq.top();
        pq.pop();
        if(done[x.S]) continue;
        done[x.S]=1;
        
        for(auto a:gh[x.S]){
            
            if(done[a.F]) continue; //need to do this
            if(a.S<dis[a.F]){
                dis[a.F]=a.S;
                parent[a.F]=x.S;
                pq.push({dis[a.F], a.F});
            }
            
        }
    }
    
    int sum=0, flag=0;
    rep(0,n){
        if(!done[i]){
            cout << -1 << NL;
            flag=1;
            break;
        }
        sum+=dis[i];
    }
    if(!flag) cout << sum << NL;
}