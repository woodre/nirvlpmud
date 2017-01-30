#include "/players/catwoman/closed/color.h"
inherit "obj/weapon";



reset(x) {
  ::reset(x);
  if (!x) {
    set_name("guitar");
    set_alias("guitar");
    set_short("Jimi's guitar");
    set_class(18);
    set_value(1900);
    set_weight(3);
    set_hit_func(this_object());
  }
}

weapon_hit(attacker) {
	string align;
	write("The tone cuts deep and blood squirts everywhere.\n");
	say("You see a hunk of flesh go flying by.\n SPLAT the flesh hits the ground.\n");
	return 1;
}


