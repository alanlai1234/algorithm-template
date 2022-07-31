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
#define ll long long

using namespace std;

ll seg[5*500000], num[500010];

void upd(int l, int r, int pos, ll x, int v=1){
	if(l==r){
		seg[v]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) upd(l, mid, pos, x, 2*v);
	else upd(mid+1, r, pos, x, 2*v+1);
	seg[v]=min(seg[2*v], seg[2*v+1]);
}
 
ll get(int l, int r, int ql, int qr, int v=1){
	if(l==ql && r==qr) return seg[v];
	int mid=(l+r)>>1;
	if(qr<=mid) return get(l, mid, ql, qr, 2*v);
	else if(ql>mid) return get(mid+1, r, ql, qr, 2*v+1);
	return min(get(l, mid, ql, mid, 2*v), get(mid+1, r, mid+1, qr, 2*v+1));
}