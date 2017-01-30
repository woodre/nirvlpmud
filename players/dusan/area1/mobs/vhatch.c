#include "/players/dusan/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hatchling");
set_alias("vraaak");
set_alt_name("vraaak");
set_race("vraaak");
set_short(""+BOLD+""+BLK+"Vraaak hatchling"+NORM+"");
set_long(
  "This two foot long vraaak has razor sharp claws and a\n"+
  "voracious appetite.  Its scaly black hide is covered in\n"+
  "a slimy mucus.\n");

set_level(8);
set_hp(50+random(100));
set_al(-150);
set_wc(10+random(5));
set_ac(5+random(6));
set_heal(3,30);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The hatchling snaps at you. \n");
  load_chat("The hatchling searches for food.\n");
set_a_chat_chance(15);
  load_a_chat("The hatchling bites your knees. \n");

set_chance(10);
set_spell_dam(5+random(5));

set_spell_mess1(
  "The hatchling "+RED+"SLICES"+NORM+" into your leg. \n");
set_spell_mess2(
  " \n");


}

monster_died() {
  object hide;
  hide = clone_object("/players/dusan/area1/items/vhide.c");
  move_object(hide,present("corpse",environment()));
  tell_room(environment(this_object()),
	"\n");
return 0; }
