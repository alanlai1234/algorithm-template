#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define rep(X, a,b) for(int X=a;X<b;++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, p;
    cin>>n>>p;
    vector<ll> val(n);
    rep(i,0,n) cin>>val[i];
    vector<ll> lt, rt;
    ll len=n/2;
    for(int i=1;i<(1<<len);++i){
        ll cur=0;
        rep(j,0,len) if(i&(1<<j)) cur+=val[j];
        lt.pb(cur);
    }
    ll len2=n-len;
    for(int i=1;i<(1<<len2);++i){
        ll cur=0;
        rep(j,0,len2) if(i&(1<<j)) cur+=val[len+j];
        rt.pb(cur);
    }
    sort(ALL(lt));
    sort(ALL(rt));
    lt.erase(unique(ALL(lt)), lt.end());
    rt.erase(unique(ALL(rt)), rt.end());
    ll ans=-1e10;
    for(auto a:lt){
        auto it=upper_bound(ALL(rt), p-a);
        if(it!=rt.end()) ans=max(ans, a+*(--it));
    }
    cout<<ans<<NL;
}