mystic_transfer(str) {
    string boo,hoo;
    if(mystic_transfer_var[0] > lev) return 0;
    if(!str) { write("mystic_transfer <who> <what>\n"); return 1; }
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"mystic_transfer",lev,pow,boo,hoo); return 1; }
    