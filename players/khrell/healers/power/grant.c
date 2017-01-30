grant(str) {
    string boo,hoo;
    if(grant_var[0] > lev) return 0;
    if(!str) { write("grant <who> <what>"); return 1;}
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"grant",lev,pow,boo,hoo); return 1; }