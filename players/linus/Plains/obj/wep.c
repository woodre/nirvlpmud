#include "/players/linus/def.h"
inherit "/obj/weapon.c";
 reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name(HIK+"Wraith"+NORM+" - the battleaxe");
 set_short(HIK+"Wraith"+NORM+" - the battleaxe");
 set_long(
  "The black blades of this battleaxe gleam with magical energies.\n"+
  "It has a long handle, the grip wrapped tightly with\n"+
  "leather strapping.  There is an inscription on the handle\n"+
  "written in red lettering.\n");
 set_class(17);
 set_type("axe");
 set_value(1000);
 set_weight(2);
 set_hit_func(TO);
}
init() {
 ::init();
 add_action("read_inscrip","read");
}
read_inscrip(string str) {
 if(!str || str!="inscription") { notify_fail("Read what?\n"); return 0; }
 if(str == "inscription") {
   write(HIR+"   I thirst for BLOOD!!!\n"+NORM);
     return 1;
 }
}
id(str) {
 return str=="wraith" || str=="battleaxe" || str=="axe";
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah >= 3) {
 switch(random(29)) {
  case 0..14:
  say(HIK+"Wraith"+NORM+" gleams with energy.\n\n"+
  "       The blade emits a high-pitched shriek as it crunches through bone.\n");
  write(HIK+"Wraith"+NORM+" gleams with energy.\n\n"+
  "       The blade emits a high-pitched shriek as it crunches through bone.\n");
  return 1;
  break;
  
  case 15..19: 
  say(HIK+"Wraith"+NORM+" takes control of "+TPN+"\n\n"+
   TPN+"intones:  Ladies and gentlemen, boys and girls...\n\n"+
  "                 "+HIR+" DYING TIMES HERE!!!\n"+NORM);
  write(HIK+"Wraith"+NORM+" takes control of you\n\n"+
  "Uncontrollably, you intone:  Ladies and gentlemen, boys and girls...\n\n"+
  "                 "+HIR+" DYING TIMES HERE!!!\n"+NORM);
  return 1+random(2);
  break;
  
  case 20..29:
  say(HIK+"Wraith"+NORM+" strikes true, sending "+RED+"Blood\n"+NORM+
  "                       spraying everywhere!\n");
  write(HIK+"Wraith"+NORM+" strikes true, sending "+RED+"Blood\n"+NORM+
  "                       spraing everywhere!\n");
  break;
  return 1;
  }
 }
}
