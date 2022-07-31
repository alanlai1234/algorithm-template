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

LL l=1, r=1, ans=1, K;
LL cnt[100010]={0}, num[100010], cntcnt[100010]={0};

struct qy{
	LL l, r, id;
	bool operator<(const qy& q){
		return l/K==q.l/K?r<q.r:l/K<q.l/K;
	}
};

void add(LL a){
	cntcnt[cnt[a]]--;
	cnt[a]++;
	cntcnt[cnt[a]]++;
	ans=max(ans, cnt[a]);
}

void sub(LL a){
	cntcnt[cnt[a]]--;
	cnt[a]--;
	cntcnt[cnt[a]]++;
	if(cnt[a]+1==ans && cntcnt[cnt[a]+1]==0) ans=cnt[a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL n, m;
    cin>>n>>m;
    K=sqrt(n);
    
    vector<qy> qry(m);
    rep(i,1,n+1) cin>>num[i];
    rep(i,0,m){
        cin>>qry[i].l>>qry[i].r;
        qry[i].id=i;
    }
    sort(ALL(qry));
    vector<pair<LL,LL>> res(m);
    
    cnt[num[1]]=1;
    cntcnt[1]=1;
    for(auto a:qry){
        while(l<a.l) sub(num[l++]);
        while(l>a.l) add(num[--l]);
        while(r<a.r) add(num[++r]);
        while(r>a.r) sub(num[r--]);
        res[a.id]={ans, cntcnt[ans]};
    }
	for(auto a:res) cout<<a.F<<" "<<a.S<<NL;
}