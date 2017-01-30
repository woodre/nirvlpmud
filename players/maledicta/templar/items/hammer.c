#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("hammer");
set_short("Templar WarHammer");
set_long(
"  This is a large and heavy warhammer. The head of it\n"+
"is decorated with carvings of knights charging into\n"+
"battle in full gear.  The shaft is made of a sturdy\n"+
"iron, and the handle is wrapped in leather.\n");
set_type("hammer");

set_alias("warhammer");
set_class(17);
set_weight(1);
set_value(500);
set_hit_func(this_object());
}

weapon_hit(attacker) {
    if(random(100) < 10){
    write("You bash your opponent with a solid strike!\n");
 	return 2;
	}
}
