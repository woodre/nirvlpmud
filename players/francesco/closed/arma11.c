#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;


set_name("hammer");
  set_alias("hammer");
set_alt_name("blade");
set_short("Francesco's weapon");
set_long(
   "This heavy hammer is usually used by the technicians\n");
set_type("sword");
  set_class(999);
  set_weight(2);
  set_value(1000);
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
say(
"\n        The gleaming broadsword whistles through the air and..\n"+
"\n"+
BOLD+"                         C A R V E S "+NORM+"\n"+
"\n"+
"               a  huge "+RED+" G A S H "+NORM+" in it's target!\n\n");

write(
"\n          Your gleaming broadsword whistles through the air and..\n"+
"\n"+
BOLD+"                               C A R V E S "+NORM+"\n"+
"\n"+
"                   a huge "+RED+" G A S H "+NORM+"in your target!\n\n");
  return 6;
   }
return;
}

init() {
  ::init();
if(!environment()) return;
if(environment()->query_real_name() != "francesco") return;
}

query_wear() {
  int wear;
  wear = 3*misses/4 + 4*hits/18;
  return wear;
}

get() {return 0;}

drop() {destruct(this_object()); return 1;}
