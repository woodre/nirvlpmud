#include "/players/jaraxle/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("mace");
set_short("Templar Mace");
set_long(
"  This is a large mace.  It is over 3 feet in length\n"+
"with a large spiked head.  The head is made of a\n"+
"heavy steel.  The handle is wrapped in leather.\n");
set_type("club");

set_alias("mace");
set_class(15);
set_weight(1);
set_value(425);
set_hit_func(this_object());
}

weapon_hit(attacker) {
    if(random(100) < 10){
    write("You bash your opponent with a solid strike!\n");
 	return 2;
	}
}
