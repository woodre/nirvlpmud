static int rage;
int xstr; /*  Additional Strength Bonus */
set_xstr(int i){ xstr = i; }
add_xstr(int i){ xstr += i; }
query_xstr(){ return xstr; }
