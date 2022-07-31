#include <bits/stdc++.h>
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
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
template<typename A> ostream& operator<<(ostream &os, const vector<A> &p){
	for(const auto &a:p)
		os << a << " ";
	os << "\n";
	return os;
}

ll num[1000010];
ll pre[1000010], dp[1000010];

struct line{
	ll a, b;
	ll cal(ll x){
		return a*x+b;
	}
	//long double intersec(line l){
		//if(a==l.a) return b<=l.a?-1e18:1e18;
		//return (long double)(b-l.b)/(l.a-a);
	//}
};

bool intersec(line l1, line l2, line l3){
	//if(abs(l2.a-l3.a)==l2.a-l3.a ^ abs(l1.a-l2.a)==l1.a-l2.a)
		//return (l1.b-l2.b)*(l2.a-l3.a)>(l2.b-l3.b)*(l1.a-l2.a);
	return (l1.b-l2.b)*(l2.a-l3.a)>(l2.b-l3.b)*(l1.a-l2.a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, a, b, c;
	cin>>n>>a>>b>>c;
	rep(i,0,n) cin>>num[i];
	pre[0]=num[0];
	rep(i,1,n) pre[i]=pre[i-1]+num[i];
	deque<line> deq;
	deq.push_back({0,0});
	rep(i,0,n){
		while(deq.size()>=2 && deq.front().cal(pre[i])<deq[1].cal(pre[i])) deq.pop_front();
		dp[i]=a*pre[i]*pre[i]+b*pre[i]+c+deq[0].cal(pre[i]);
		line tmp={-2*a*pre[i], a*pre[i]*pre[i]-b*pre[i]+dp[i]};
		while(deq.size()>=2 && intersec(tmp, deq.back(), deq[deq.size()-2])) deq.pop_back();
		deq.push_back(tmp);
		//cout<<dp[i]<<NL;
	}
	cout<<dp[n-1]<<NL;
}