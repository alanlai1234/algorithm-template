memset(isprime, 0, sizeof(isprime));
isprime[1]=1;
for(int i=2;i<=100000000;++i){
    if(!isprime[i])
        for(int j=2;i*j<=100000000;++j)
            isprime[i*j]=1;
}