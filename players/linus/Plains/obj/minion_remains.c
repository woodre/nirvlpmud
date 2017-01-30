#include "/players/linus/def.h"
inherit "/obj/treasure.c";
object mon;
id(str) { return str=="bones" || str=="skeleton" || str=="pile" || str=="pile of bones"; }
reset(arg) {
 if(arg) return;
 set_short("A pile of bones");
 set_long(
 "  The skeletal remains of a creature.  The bones are cracked and\n"+
 "dirty, and appear to have been damaged in some form of battle.\n"+
 "Something tells you that 'bury'ing the 'bones' would be the right\n"+
 "thing to do.\n");
 set_value(0);
 set_weight(3);
}
init() {
 ::init();
 add_action("Bury_dem_bones","bury");
}
Bury_dem_bones(str) {
 if(!str) { FAIL("What are you trying to bury?\n"); return 0; }
 if(str == "bones") {
 write("You carefully dig a small hole and lay the bones to rest.\n"+
       "           A spirit rises and looks at you with a look of gratitude.\n"+
       "                     It then glances toward the grave you just dug, and vanishes.\n");
 say(TPN+" carefully digs a small hole and lays the bones to rest.\n",({TP}));
  mon = CO("/obj/money.c");
  mon->set_money(1500+random(3500));
 MO(mon, ENV());
 destruct(TO);
 return 1;
 } 
}
