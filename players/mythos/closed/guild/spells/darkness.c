#include "/players/mythos/closed/guild/def.h"
int chance, ti;

id(str) { return str == "darkness"; }
short(){write(BOLD+"] DARKNESS [\n"+NORM);}
long() {write(BOLD+"A big blotch of DARKNESS.\n"+NORM);}
drop() {return 1;}
get() { return 0;}

reset(arg) {
  if(arg) return;
  ti = 0;
  call_out("check",13+chance);
}

set_chance(n) { chance = n;}
  
check() {
if(ep) {
 if(chance < random(20*10) || ti > chance) {
 tell_room(ep,BOLD+"THE DARKNESS fa"+NORM+"des......\n");
 destruct(this_object());
 return 1;}
 ti = ti + 1;
 }
 call_out("check",13+chance);
}

query_shatter_proof() { return 1;} 

query_save_flag() { return 1; }
