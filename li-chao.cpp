struct line{
    ll a, b;
    ll cal(ll x){
        return a*x+b;
    }
};

struct node{
    line val;
    struct node* lft;
    struct node* rgt;
    node(){
        val.a=0;
        val.b=-INT_MAX;
        lft=nullptr;
        rgt=nullptr;
    }
};

void insert(node* tree, ll l, ll r, line inp){
    if(l==r){
        if(inp.cal(l)>tree->val.cal(l)) tree->val=inp;
        return;
    }
    ll mid=(l+r)>>1;
    if(inp.cal(mid)>tree->val.cal(mid)) swap(inp, tree->val);

    if(inp.cal(l)>tree->val.cal(l)){
        if(tree->lft==nullptr) tree->lft=new node();
        insert(tree->lft, l, mid, inp);
    }
    else{
        if(tree->rgt==nullptr) tree->rgt=new node();
        insert(tree->rgt, mid+1, r, inp);
    }
}

ll get(node *tree, ll l, ll r, ll x){
    if(l==r) return tree->val.cal(x);
    int mid=(l+r)>>1;
    if(x<mid) return max(tree->val.cal(x), tree->lft==nullptr?-INT_MAX:get(tree->lft, l, mid, x));
    else return max(tree->val.cal(x), tree->rgt==nullptr?-INT_MAX:get(tree->rgt, mid+1, r, x));
}