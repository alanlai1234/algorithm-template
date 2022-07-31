#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define rep(X, a,b) for(int X=a;X<b;++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
using namespace std;

ll num[100010], arr[100010][22];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    rep(i,1,n+1) cin>>num[i];
    rep(i,1,n+1) arr[i][0]=num[i];
    for(int j=1;j<=20;++j){
        for(int i=1;i<n+1;++i){
            arr[i][j]=arr[arr[i][j-1]][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll a, b;
        cin>>a>>b;
        for(int k=0;k<=20;++k){
            if(b & (1<<k)){
                a=arr[a][k];
            }
        }
        cout<<a<<NL;
    }
}