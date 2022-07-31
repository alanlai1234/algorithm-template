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
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
template<typename A> ostream& operator<<(ostream &os, const vector<A> &p){
	//return os << '(' << p.first << ", " << p.second << ')';
	for(const auto &a:p)
		os << a << " ";
	os << "\n";
	return os;
}

const int mod=1e9+7;

struct trie{
	bool isword;
	struct trie *mp[30];
};

trie* new_node(){
	trie* tmp=new trie;
	tmp->isword=0;
	memset(tmp->mp, 0, sizeof(tmp->mp));
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str, buf;
	cin>>str;
	int n;
	cin>>n;
	trie *top=new_node();
    
	rep(i,0,n){
		cin>>buf;
		trie *cur=top;
		for(auto a:buf){
			if(cur->mp[a-'a']) cur=cur->mp[a-'a'];
			else{
				cur->mp[a-'a']=new_node();
				cur=cur->mp[a-'a'];
			}
		}
		cur->isword=1;
	}
    
	int len=str.size();
	vector<LL> dp(len+1, 0);
	dp[len]=1;
	for(int i=len-1;i>=0;--i){
		trie *cur=top;
		for(int j=i;j<len;++j){
			if(cur->mp[str[j]-'a']) { cur=cur->mp[str[j]-'a'];
			}else break;

			if(cur->isword) dp[i]=(dp[i]+dp[j+1])%mod;
		}
	}
	cout<<dp[0]<<NL;
}