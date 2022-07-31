ll n, q, par[200010][21];
vector<int> adj[200010];
int level[200010];
 
void dfs(int v){
    for(auto a:adj[v]){
        par[a][0]=v;
        level[a]=level[v]+1;
        dfs(a);
    }
}
 
ll lca(int a, int b){
    if(level[a]<level[b]) swap(a, b);
    //set a and b to the same level
    int d=level[a]-level[b];
    rep(i,0,21) if(d & (1<<i)) a=par[a][i];
    if(a==b) return a;
    for(int i=20;i>=0;--i){
        if(par[a][i]!=par[b][i]){
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}
 
void solve(){
    cin>>n>>q;
    ll v;
    rep(i,2,n+1){
        cin>>v;
        adj[v].pb(i);
    }
    par[1][0]=1;
    level[1]=1;
    dfs(1);
    for(int j=1;j<=20;++j){
        for(int i=1;i<=n;++i){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    int a, b;
    while(q--){
        cin>>a>>b;
        cout<<lca(a, b)<<NL;
    }
}