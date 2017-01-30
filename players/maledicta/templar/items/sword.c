#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sword");
set_alias("broadsword");
set_short("a fine steel broadsword");
set_long(
"  This is a large broadsword. It is finely crafted and made of\n"+
"steel. It appears to have a cross on the guard and pommel. It\n"+
"is heavy.\n");
set_type("sword"); 
set_class(16);
set_weight(2);
set_value(500);
set_hit_func(this_object());
}


weapon_hit(attacker) {
    if(random(100) < 10){
    write("You lunge forward and slice at your opponent!\n");
 	return 2;
	}
}