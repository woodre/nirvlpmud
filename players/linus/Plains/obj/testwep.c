#include "/players/linus/def.h"
inherit "/obj/weapon.c";
 reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("sword");
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
 set_read(RED+"I hunger for BLOOD!!!\n"+NORM);
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah >= 3) {
 switch(random(10)) {
  case 0..3: say(HIK+"  Wraith"+NORM+" gleams with energy.\n\n"+
  "       The blade emits a high-pitched shriek as it crunches through bone.\n");
 break;
 case 4..6: say(HIK+" Wraith"+NORM+" takes control of "+TPN+"\n\n"+
  TPN+" intones:  Ladies and gentlemen, boys and girls...\n"+
  "                 "+HIR+" DYING TIMES HERE!!!\n"+NORM);
break;
 case 7..9: say(HIK+"Wraith"+NORM+" strikes true, sending "+RED+"Blood"+NORM+
  "        spraying everywhere!\n");
 break;
}
}
}
