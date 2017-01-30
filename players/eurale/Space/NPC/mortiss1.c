#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("mortiss");
set_alias("mortiss 1");
set_race("creature");
set_short("Mortiss");
set_long(
	"  This mortiss is an adult approximately 6 feet in length.  It\n"+
	"is an unsegmented, round worm with a dorsal and ventral rib.\n"+
	"It is eyeless, sensing rather by smell and vibration.  It has\n"+
	"a collar of feathery tendrils ringing it's head.  It has a single\n"+
	"poisonous stinger on the top of it's head and two pairs of op-\n"+
	"posing jaws to latch onto an suck blood from it's prey.\n");

set_level(18);
  set_hp(400 + random(100));
  set_al(0);
  set_wc(26);
  set_ac(12);
  set_aggressive(2 - random(3));

set_chat_chance(10);
  load_chat("The mortiss sways back and forth.....waiting..\n");
set_a_chat_chance(15);
  load_a_chat("\nThe mortiss STABS at you with it's stinger....\n");
  load_a_chat("\nYou feel the sting of the Mortiss's jaws....\n");

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,this_object());
}
