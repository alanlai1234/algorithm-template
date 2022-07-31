struct mat{
    vector<vector<LL>> a;
    int wdt, len;
    // initilize size of matrix
    mat(int x, int y){
        a.resize(x, vector<LL>(y,0));
        len=x;
        wdt=y;
    }

    mat operator*(mat &inp){
        mat res(len, inp.wdt);
        for(int i=0;i<len;++i)
            for(int j=0;j<inp.wdt;++j)
                for(int k=0;k<wdt;++k)
                    res.a[i][j]+=a[i][k]*inp.a[k][j];
        return res;
	}
};

long long fastpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}