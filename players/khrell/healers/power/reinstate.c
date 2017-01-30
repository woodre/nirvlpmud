reinstate(str) {
    string boo,hoo;
    if(reinstate_var[0] > lev) return 0;
    if(!str) { write("reinstate <who> <what>"); return 1;}
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"reinstate",lev,pow,boo,hoo); return 1; }