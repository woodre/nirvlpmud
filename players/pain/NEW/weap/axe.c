inherit "players/pain/NEW/weap/p_weap2.c";
#include "/players/pain/color.h"
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      	set_alias("axe");
	set_short("A large steel axe");
	set_long("A large, surprisingly wieldy steel orc axe.\n");
	set_class(17);
	set_weight(4);
	set_value(1500);
	set_name("axe");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s axe lands a "+BOLD+RED+"stunning blow"+END+"!\n");
	write("You swing your axe wide and it lands with a "+BOLD+RED+"stunning blow"+END+".\n");
  return random(4)+2;
    }
   return 0;
}
