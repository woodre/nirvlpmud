#include "/players/mythos/closed/guild/def.h"
string place;
int strength;
id(str) {return str == "chains";}

get() { return 0;}
drop() { return 1;}

set_place(str) { place = str;}
set_strength(n) { strength = n; }

reset(arg) {
if(arg) return;
  call_out("chained",3);
}

chained() {
string here;
if(ep) {
  here =(ep->query_current_room());
  if(here != place) {
  move_object(ep,place); 
  tell_room(environment(ep),"The chains keep "+epn+" locked to one spot!\n");}
  if(random(22) > strength) {
  tell_room(environment(ep),"The chains vanish!\n");
  destruct(this_object()); 
  return 1;} }
  call_out("chained",3);
return 1;}
