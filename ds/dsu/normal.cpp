int dsu[1000010];

int get(int x){
	if(dsu[x]==x) return x;
	return dsu[x]=get(dsu[x]);
}

void mrg(int a, int b){
	dsu[get(a)]=get(b);
}