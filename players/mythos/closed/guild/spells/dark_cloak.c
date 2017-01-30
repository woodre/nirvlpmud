#include "/players/mythos/closed/guild/def.h"
int time;

id(str) { return str == "dark_cloak"; }
short(){write(BOLD+"*------=+=------*\n"+NORM);}
drop() { return 1;}
get() { return 0;}

extra_look() { return BOLD+"      [ Dark Mist shrouds "+capitalize(epn)+" ]"+NORM; }

set_time(n) { time = n;}

reset(arg) {
  if(arg) return;
  call_out("check",time);
} 

check() {
time = time - 1;
if(time < 0) { checks(); return 1;}
call_out("check",time);
return 1;}

checks() {
 int li;
 if(ep) {
 tell_object(ep,"The darkness which covers you vanishes!\n");
 li = set_light(0);
 if(li > 0) {
 tell_object(ep,"You feel the hot blaze of the light!\n");
 ep->heal_self(-11-random(10)); } }
 destruct(this_object());
 return 1;
}
