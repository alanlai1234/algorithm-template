#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
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
 
int f[1000010]={0};
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin>>a>>b;
	int lena=a.size(), lenb=b.size();
	// build failure function
	f[0]=-1;
	int j=-1;
	rep(i,1,lenb){
		while(j!=-1 && b[j+1]!=b[i]) j=f[j];
		if(b[j+1]==b[i]) j++;
		f[i]=j;
	}
	//match
	int ans=0;
	j=-1;
	for(int i=0;i<lena;++i){
		while(j!=-1 && a[i]!=b[j+1]) j=f[j];
		if(a[i]==b[j+1]) j++;
		if(j==lenb-1) ans++, j=f[j];
	}
	cout<<ans<<NL;
}