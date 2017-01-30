#include "/players/mythos/closed/guild/def.h"
int power, time, pcheck;

id(str) { return str == "circle"; }
short(){write(HIB+"     (CIRCLE)\n"+NORM);
  if(!present(pact,tp) && (tp->query_npc() || pcheck)) { 
  tp->heal_self(-random(100));}
  else { 
  tell_object(tp,"You are repulsed by the grand circle!\n");
  tp->move_player("off the circle#players/mythos/aroom/forestr2.c");}
  }

reset(arg) {
  if(arg) return;
  call_out("circle",3);
}

drop() {return 1;}
get() { return 0;}

set_pcheck(n) { pcheck = n;}
set_power(n) { power = n; time = (power / 2);}
query_power() { return power;}
query_time() { return time;}

circle() {
int nn;
object ob;
if(ep) {
if(time < 0) { 
  tell_room(ep,"The CIRCLE vanishes!\n");
  destruct(this_object());
  return 1;}
ob = all_inventory(ep);
for(nn=0; nn<sizeof(ob); nn++){
  if(!present(pact,ob[nn]) && (ob[nn]->query_npc() || pcheck)) { 
  ob[nn]->heal_self(-random(13));}
  }
time = time - 1;
}
call_out("circle",3);
return 1;}

query_shatter_proof() { return 1;} 
