#include <bits/stdc++.h>
#define pb emplace_back
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

ll cross(pll o, pll a, pll b){
    return (a.F-o.F)*(b.S-o.S) - (a.S-o.S)*(b.F-o.F);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<pll> pos(n);
    rep(i,0,n) cin>>pos[i].F>>pos[i].S;
    sort(ALL(pos));

    vector<pll> hull;
    // construct lower hull
    for(int i=0;i<n;++i){
        while(hull.size()>1 && cross(hull[hull.size()-2], hull.back(), pos[i])<0) hull.pop_back();
        hull.push_back(pos[i]);
    }
    //upper hull
    int t=hull.size(); //lower hull length
    // the last point has exsisted in lower hull
    for(int i=n-2;i>=0;--i){
        while(hull.size()>t && cross(hull[hull.size()-2], hull.back(), pos[i])<0) hull.pop_back();
        hull.push_back(pos[i]);
    }
    // delete pos[0] that has been added twice
    hull.pop_back();
    cout<<hull.size()<<NL;
    for(auto a:hull) cout<<a.F<<" "<<a.S<<NL;
}