int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vci nums(n);
    rep(0,n) cin>>nums[i];
    stack<PII> st;
    LL res=0;
    rep(0,n){
        while(!st.empty() && st.top().F<=nums[i]){
            st.pop();
        }
        res+= st.empty() ? i+1:i-st.top().S;
        st.push({nums[i], i});
    }
    cout << res << NL;
}