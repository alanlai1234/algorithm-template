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

struct node{
    char c;
    int key, pri;
    node *left, *right;
    node(char x): c(x), key(1), pri(rand()), left(nullptr), right(nullptr){}
};

int sz(node *nd){
    return nd?nd->key:0;
}

void split(node *root, node *&a, node *&b, int val){
    if(!root){a=b=nullptr; return;}
    else if(sz(root->left)+1<=val){
        a=root;
        split(root->right, a->right, b, val-sz(root->left)-1);
    }
    else{
        b=root;
        split(root->left, a, b->left, val);
    }
    root->key=1+sz(root->left)+sz(root->right);
}

void merge(node *&root, node *a, node *b){
    if(!a){root=b; return;}
    if(!b){root=a; return;}
    if(a->pri>b->pri){
        merge(a->right, a->right, b);
        root=a;
    }
    else{
        merge(b->left, a, b->left);
        root=b;
    }
    root->key=1+sz(root->left)+sz(root->right);
}

void print(node *node){
    if(!node) return;
    print(node->left);
    cout<<node->c;
    print(node->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    string str;
    cin>>str;
    srand(time(NULL));
    node *tree=nullptr;
    for(auto a:str) merge(tree, tree, new node(a));
    int l, r;
    rep(i,0,m){
        cin>>l>>r;
        node *a, *b, *c, *d;
        split(tree, a, b, l-1);
        split(b, c, d, r-l+1);
        merge(tree, a, d);
        merge(tree, tree, c);
    }
    print(tree);
}