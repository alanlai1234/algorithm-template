int ar[1000010];

int get(int x){
	if(ar[x]<0) return x;
	return ar[x]=get(ar[x]);
}

void mrg(int x, int y){
	x=get(x), y=get(y);
	if(ar[x]<ar[y]) swap(x, y);
	ar[y]+=ar[x];
	ar[x]=y;
}