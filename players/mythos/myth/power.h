/*
#include "/players/mythos/myth/def.h"
*/
#include "/players/mythos/myth/gline.h"
int l_y;

query_prevent_shadow() { return 1; }

reset(arg) {
int ll,mul;
  if(arg) return;
  l_y = allocate(MAX);
  for(ll=0;ll<MAX;ll++) {
    if(ll < 4) mult = ;
    if(ll > 3 && ll < 8) mult = ;
    if(ll > 7 && ll < 10) mult = ;
    if(ll > 9 && ll < 16) mult = ;
    if(ll > 15 && ll < 19) mult = ;
    if(ll == 19) mult = ;
    l_y = ll * mult;
  }
}

check_xp(int j,object targ,int k) {
int lnum,xnum, i, do;
lnum = xnum = i = do = 0;
  if(k == 1) {
    xnum = l_y[j - 1];
    lnum = j;
  } else {
    while(!do && i < MAX) {
      if(j < l_y[i]) lnum = i + 1;
      if(j > (l_y[i] - 1)) do = 0; else do = 1;
    i++; }
    xnum = j; 
  }
  targ->set_cxp(xnum,1);
  targ->set_level(lnum,1);
return 1; }