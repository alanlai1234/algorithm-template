LL b1[500010]={0}, b2[500010]={0};//b1:prefix D, b2:prefix D*i
LL n, q, a, x, y, k;

void upd(LL *bit, LL pos, LL x){
    while(pos<=n){
        bit[pos]+=x;
        pos+=pos & (-pos);
    }
}

void range(LL l, LL r, LL x){
	upd(b1, l, x);
	upd(b1, r+1, -x);
	upd(b2, l, l*x);
	upd(b2, r+1, -(r+1)*x);
}

LL query(LL *bit, LL pos){
    LL res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos & (-pos);
    }
    return res;
}

LL pre_sum(LL pos){
	return (pos+1)*query(b1, pos)-query(b2, pos);
}