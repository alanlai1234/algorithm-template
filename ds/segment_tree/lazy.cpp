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

LL tree[5*500000], num[500010], tag[5*500000]={0};

void push(int v, int l, int r){
	int mid=(l+r)>>1;
	tag[2*v]+=tag[v];
	tag[2*v+1]+=tag[v];
	tree[2*v]+=(mid-l+1)*tag[v];
	tree[2*v+1]+=(r-mid)*tag[v];
	tag[v]=0;
}

void build(int v, int l, int r){
	if(l==r) tree[v]=num[l];
	else{
		int mid=(l+r)>>1;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		tree[v]=tree[2*v]+tree[2*v+1];
	}
}

void modify(int v, int l, int r, int ul, int ur, LL x){
	if(l==ul && r==ur){
		tag[v]+=x;
		tree[v]+=(r-l+1)*x;
		return;
	}
	if(tag[v]) push(v, l, r);
	int mid=(l+r)>>1;
	if(ur<=mid) modify(2*v, l, mid, ul, ur, x);
	else if(ul>mid) modify(2*v+1, mid+1, r, ul, ur, x);
	else{
		modify(2*v, l, mid, ul, mid, x);
		modify(2*v+1, mid+1, r, mid+1, ur, x);
	}
	tree[v]=tree[2*v]+tree[2*v+1];
}

LL query(int v, int l, int r, int ql, int qr){
	if(l==ql && r==qr) return tree[v];
	if(tag[v]) push(v, l, r);
	int mid=(l+r)>>1;
	if(qr<=mid) return query(2*v, l, mid, ql, qr);
	else if(ql>mid) return query(2*v+1, mid+1, r, ql, qr);
	return query(2*v, l, mid, ql, mid)+query(2*v+1, mid+1, r, mid+1, qr);
}