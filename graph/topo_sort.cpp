#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;// n: 點個數 m:邊個數
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> cnt(n, 0);
    int a, b;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        cnt[b]++;
    }
    // find the node with no edge
    queue<int> topo;
    for(int i=0;i<n;++i)
        if(cnt[i]==0)
            topo.push(i);

    vector<int> ans;
    while(!topo.empty()){
        int v=topo.front();
        topo.pop();
        ans.push_back(v);

        for(int a:graph[v]){
            cnt[a]--;
            if(cnt[a]==0)
                topo.push(a);
        }
    }
}