#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("horseman");
  set_alias("headless horseman");
  set_alt_name("headless");
  set_race("human");
  set_short("Headless Horseman");
set_long(
	"  Wild laughter on a black steed.  This specter of the night\n"+
	"is dressed in all black and wears a flame red cape.  The \n"+
	"headless body is muscled and ready for battle...\n");
  set_hp(550);
  set_level(20);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_heal(2,7);
  set_aggressive(1);
  set_dead_ob(this_object());
if(!present("head")) {
move_object(clone_object("players/eurale/Dis/Slpy/OBJ/pumpkin"),
	this_object()); }

  set_chat_chance(15);
  set_a_chat_chance(20);
  load_chat("The sound of a rider approaching......\n");
  load_chat("Red eyes gleam in the darkness....\n");
  load_chat("The horseman's horse rears.......\n");
  load_a_chat("The Horseman nicks your ear with a swing of his sword..\n");
  load_a_chat("The head laughs in the night....\n");
  set_chance(10);
  set_spell_dam(50);
set_spell_mess1(
  "\nThe Horseman T H R O W S something at it's target...\n\n");
set_spell_mess2(
	"\n\nThe Horseman T H R O W S something at you...\n\n");

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
    "\n\nThe Horseman gasps: It was just a joke....\n\n");
return 0; }
