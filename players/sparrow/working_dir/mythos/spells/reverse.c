#include "/players/mythos/closed/guild/def.h"
int line, last;
object atts;
string atn;

id(str) { return str == "reverse"; }

drop() {return 1;}
get() { return 0;}

extra_look() { return HIB+"\n\tSomething seems very odd....\n"+NORM; }

set_line(n) { line = n; last = line;}
query_line() { return line;}

reset(arg) {
  if(arg) return;
  atts = 0;
  atn = 0;
  call_out("hp_check",3);
}
  
hp_check() {
if(ep) {
  if(environment(ep)) {
  if(!(ep->query_attack())) { 
   tell_room(environment(ep),"The Dark Line vanishes!\n"); 
  destruct(this_object());
   return 1;}
  if(!atts) { atts = ep->query_attack(); atn = atts->query_real_name();}
  if(ep->query_attack() != atts || !present(atn,environment(ep))) { 
    tell_room(environment(ep),"The Dark Line vanishes!\n"); 
  destruct(this_object());
   return 1;}
  if(!(atts->query_npc()) && !epp) {
  tell_object(ep,"You may not use 'reverse' against a player at this time.\n");
  reverse_off(); return 1;}
  if(ep->query_hp() < line) {
  if(last < ep->query_hp()) { last = ep->query_hp(); }
  if(atts) { 
  tell_object(atts,"You feel great pain!\n");
  if(atts->query_hp() > 5 + last - ep->query_hp()) atts->heal_self(-(last - (ep->query_hp())));
  tell_room(environment(ep),"Energy pulses through the dark line...\n"); }
  if(last > ep->query_hp()) { last = ep->query_hp(); }
  } else { last = line; } } }
  call_out("hp_check",3);
return 1;}

reverse_off() { 
if(ep) {
  tell_room(environment(ep),"The Dark Line vanishes!\n"); }
  destruct(this_object());
  return 1;}
