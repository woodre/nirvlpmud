#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("lurker");
set_race("demon");
set_short("Lurker");
set_long(
  "A small, deformed piece of flesh, devoid of form.\n");

set_level(10);
set_hp(150);
set_al(-500);
set_wc(14);
set_ac(8);
set_aggressive(1);
set_dead_ob(this_object());
add_money(400 +random(100));

}

monster_died() {
    tell_room(environment(this_object()),
	MAGENTA+"The Lurker bites you in the leg a final time after it dies."+OFF+"\n");
return 0; }
