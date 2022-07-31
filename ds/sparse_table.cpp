#include <bits/stdc++.h>
using namespace std;

int num[500001], sp[500001][20], log_2[500001];

int query(int l, int r){
    int k=log_2[r-l+1];
    return min(sp[l][k], sp[r-(1<<k)+1][k]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n
    cin >> n;

    // generates logarithm table of 2 (only needs n value)
    log_2[1]=0;
    for(int i=2;i<=n;++i) log_2[i]=log_2[i/2]+1;

    //build
    for(int i=0;i<n;++i){ //init
        cin >> num[i];
        sp[i][0]=num[i];
    }
    for(int j=1;j<=log_2[n];++j)
        for(int i=0;i+(1<<j)-1<n;++i)
            sp[i][j]=max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
}