#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define rep(X, a,b) for(int X=a;X<b;++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
#define ll long long
using namespace std;

ll mod;

ll fpow(ll &base, ll x){
    if(x==1) return base%mod;
    ll res=fpow(base, x/2)%mod;
    if(x&1) return (res*res*base)%mod;
    return (res*res)%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n>>mod;
    vector<vector<ll> > equ(n, vector<ll>(n+1,0));
    rep(i,0,n) cin>>equ[i][n];
    rep(i,0,n) rep(j,0,n) cin>>equ[j][i];
    // solve
    for(int i=0;i<n;++i){ // column
        //if equ[i][i] is 0 means can't do elimination so switch with other
        int cur=i;
        while(cur<n && equ[cur][i]==0) cur++;
        if(cur==n) break;// if all column i is 0 then nothing to elinimate
        if(cur!=i) swap(equ[i], equ[cur]);

        ll tmp=equ[i][i];
        // change equ[i][i] to 1 using inverse mod
        for(int j=i;j<=n;++j) equ[i][j]=(equ[i][j]*fpow(tmp, mod-2))%mod;
        
        for(int k=0;k<n;++k){
            if(k==i) continue;
            ll tmp=equ[k][i];
            for(int j=i;j<=n;++j) equ[k][j]=(equ[k][j]%mod-equ[i][j]*tmp%mod+mod)%mod;
        }
    }
    for(int i=0;i<n;++i) cout<<equ[i][n]%mod<<" ";
    cout<<NL;
}