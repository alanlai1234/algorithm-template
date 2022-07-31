void update(int pos, int x){
    while(pos<=n){
        bit[pos]+=x;
        pos+=pos & (-pos);
    }
}

int query(int pos){
    int res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos & (-pos);
    }
    return res;
}