#include "/players/mythos/closed/guild/def.h"
int chance, ti;

id(str) { return str == "mist" || str == "myst"; }
short(){write(HIG+"- * myst * -\n"+NORM);}
long() {write(GRN+"A great cloud of mist.  It seems to obscure the light.\n"+NORM);}
drop() {return 1;}
get() { return 0;}

reset(arg) {
  if(arg) return;
  ti = 0;
  call_out("check",9+chance);
}


set_chance(n) { chance = n;}
  
check() {
if(ep) {
 if(chance < random(20*5) || ti > 12) {
 tell_room(ep,HIG+"The m"+NORM+GRN+"yst fa"+NORM+"des......\n");
 destruct(this_object());
 return 1;}
 ti = ti + 1; }
 call_out("check",9+chance);
 return 1;
}

query_shatter_proof() { return 1;}

query_save_flag() { return 1; }
