#include <bits/stdc++.h>
#define EB emplace_back
#define PII pair<int,int>
#define F first
#define S second
#define NL "\n"

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
            if(done[a.F]) continue; //not necessary
            if(dis[x.S]+a.S<dis[a.F]){
                dis[a.F]=dis[x.S]+a.S;
                parent[a.F]=x.S;
                pq.push({dis[a.F], a.F});
            }
        }
    }
}