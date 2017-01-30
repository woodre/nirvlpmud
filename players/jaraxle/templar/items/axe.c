#include "/players/jaraxle/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("axe");
set_short("Templar GreatAxe");
set_long(
"  This is a very large and powerful axe. Its head is made of\n"+
"a thick and heavy steel, and is sharpened to almost razor\n"+
"fineness. The shaft of the weapon is made of a polished\n"+
"oak, with a beautiful cloth wrap around its handle.\n");
		 
set_type("axe");

set_alias("greataxe");
set_class(17);
set_weight(1);
set_value(600);
set_hit_func(this_object());
}

weapon_hit(attacker) {
    if(random(100) < 10){
    write("You swing the axe with deadly precision!\n");
 	return 2;
	}
}
