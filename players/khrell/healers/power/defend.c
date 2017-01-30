defend(str) {
    if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;
    if(defend_var[0] > lev) return 0;
    call_other(POWER,"defend",lv,pow,str);
    lv = 0;
    return 1;
}
