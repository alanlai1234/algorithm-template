long double l=-1e9, r=1e9, ml, mr;
while(r-l>1e-9){
    mr=(l+r)/2.0;
    ml=(l+mr)/2.0;
    if(check(ml)>check(mr)) l=ml;
    else r=mr;
}