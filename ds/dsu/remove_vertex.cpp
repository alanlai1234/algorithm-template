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

vector<LL> arr, ind;// arr is dsu array, ind is the map of each element

LL fd(LL x){
    if(arr[x]<0) return x;
    return arr[x]=fd(arr[x]);
}

void un(LL x, LL y){
    LL g1=fd(x), g2=fd(y);
    if(g1!=g2){
        arr[g1]+=arr[g2];
        arr[g2]=g1;
    }
}

// separation
void sep(LL x){
    arr.EB(-1);
    ind[x]=arr.size()-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL n, m, x, y, a;
    while(cin>>n>>m){
        arr.resize(n);
        ind.resize(n);
        rep(i,0,n) arr[i]=-1, ind[i]=i;
        rep(i,0,m){
            cin>>a;
            if(a==1){
                cin>>x>>y;
                x--, y--;
                // fd傳入ind[x](x之對應位置)
                if(fd(ind[x])!=fd(ind[y])){
                    un(ind[x], ind[y]);
                    n--;
                }
            }
            else{
                cin>>x;
                x--;
                LL f=fd(ind[x]);
                // 如果這個集合只有自己一個，那它已經是獨立的了
                if(arr[f]!=-1){
                    arr[f]++;// value is negative so add one to represent minus one
                    sep(x);
                    n++;
                }
            }
        }
        cout << n << NL;
    }
}