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

LL bit[1050][1050]={0};
int n;

void update(int x, int y, LL v){
    x++, y++;
    while(x<=n){
        int tmp=y;
        while(tmp<=n){
            bit[x][tmp]+=v;
            tmp+=tmp & (-tmp);
        }
        x+=x & (-x);
    }
}

LL get(int x, int y){
    x++, y++;
    LL res=0;
    while(x>0){
        int tmp=y;
        while(tmp>0){
            res+=bit[x][tmp];
            tmp-=tmp & (-tmp);
        }
        x-=x & (-x);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>n;
    while(cin>>t){
        if(t==0) break;
        if(t==1){
            int a, b, z;
            cin>>a>>b>>z;
            update(a, b, z);
        }
        else{
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<get(x2, y2)-get(x1-1, y2)-get(x2, y1-1)+get(x1-1, y1-1)<<NL;
        }
    }
}