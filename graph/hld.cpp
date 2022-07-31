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

ll n, q, val[200010], tree[800010]={0};
vector<int> adj[200010];
int dep[200010], up[200010], sz[200010], rt[200010], id[200010];//dep:the depth, up:its parent, sz:subtree size, rt:its chain's root, id:pos in segment tree

void upd(int v, int l, int r, int pos, ll x){
    if(l==r){
        tree[v]=x;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) upd(2*v, l, mid, pos, x);
    else if(pos>mid) upd(2*v+1, mid+1, r, pos, x);
    tree[v]=max(tree[2*v], tree[2*v+1]);
}

ll get(int v, int l, int r, int ql, int qr){
    if(l==ql && r==qr) return tree[v];
    int mid=(l+r)>>1;
    if(qr<=mid) return get(2*v, l, mid, ql, qr);
    else if(ql>mid) return get(2*v+1, mid+1, r, ql, qr);
    return max(get(2*v, l, mid, ql, mid), get(2*v+1, mid+1, r, mid+1, qr));
}

void dfs(int v, int par){
    sz[v]=1;
    dep[v]=dep[par]+1;
    for(auto a:adj[v]){
        if(a!=par){
            dfs(a, v);
            sz[v]+=sz[a];
            up[a]=v;
        }
    }
}

int cnt=0;
void hld(int v, int par, int top){
    id[v]=cnt++;
    rt[v]=top;
    upd(1, 0, n, id[v], val[v]);
    int mx=-1, mxi=-1;
    for(auto a:adj[v]){
        if(a!=par) if(sz[a]>mx){
            mx=sz[a];
            mxi=a;
        }
    }
    if(mxi==-1) return;
    hld(mxi, v, top);
    for(auto a:adj[v]){
        if(a!=par && a!=mxi){
            hld(a, v, a);
        }
    }
}

ll query(int a, int b){
    ll res=0;
    //while till the the chain of a, b is the lca
    while(rt[a]!=rt[b]){
        if(dep[rt[a]]<dep[rt[b]]) swap(a, b);
        res=max(res, get(1, 0, n, id[rt[a]], id[a]));
        a=up[rt[a]];
    }
    //walk through the rest
    if(dep[a]>dep[b]) swap(a, b);
    res=max(res, get(1, 0, n, id[a], id[b]));
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    rep(i,1,n+1) cin>>val[i];
    int a, b;
    rep(i,0,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dep[0]=0;
    dfs(1, 0);
    hld(1, 0, 1);
    int c;
    while(q--){
        cin>>c;
        if(c==1){
            ll s, x;
            cin>>s>>x;
            upd(1, 0, n, id[s], x);
        }
        else{
            ll x, y;
            cin>>x>>y;
            cout<<query(x, y)<<" ";
        }
    }
    cout<<NL;
}